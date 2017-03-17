/**** Maxime Maurin - Projet Long N7 2017 ****/

#include <ros/ros.h>
#include "scheduler.h"

// Construteur
Scheduler::Scheduler()
{
	numberOfProduct = 0;
	nextCount = 0;
	lastLaunchDate = 0;
	maxShuttleNumber = 6;
}

// Initialisation de l'objet 
bool Scheduler::init(ros::NodeHandle nh, std::string executionPath)
{
	// Services Initialisation
	client_simRosGetInfo = nh.serviceClient<vrep_common::simRosGetInfo>("/vrep/simRosGetInfo");
	client_GetShuttleStatus = nh.serviceClient<shuttles::srvGetShuttleStatus>("/commande_navette/srvGetShuttleStatus");
	// Subscribers Initialisation
	subEndOfProductManufacture = nh.subscribe("/A3/ShuttleOut", 10 , &Scheduler::productOutCallBack,this);
	subManualLaunchOfProduct = nh.subscribe("/scheduling/ManualLaunch", 10 , &Scheduler::ManualLaunchCallBack,this);
	// Publishers Initialisation
	pubCreateShuttle = nh.advertise<scheduling::Msg_LoadShuttle>("/scheduling/NextProduct",10);
	pubDelShuttle = nh.advertise<std_msgs::Int32>("/commande_navette/DelShuttle",10);

// Récupération du chemin vers le Working_Folder
int count = 0 ;
int pos = 0 ;
while (count < 4)
	{
	if(executionPath[pos] == '/') count++;
	pos++;
	}
std::string Working_Folder = executionPath.substr(0,pos);
ROS_INFO ("$%s$", Working_Folder.c_str()) ;

	
//Initialisation des produits à l'aide du fichier de configuration

	//Définition du chemin du fichier de config et log
configFile = Working_Folder + "/ProductConfiguration.config";
logFile = Working_Folder + "/Statistic.txt";

std::ifstream streamConfigFile(configFile.c_str(), std::ios::in);
	
if (streamConfigFile)
{
	std::string pNameFF,destinationPart,launchDatePart,jobTimePart,maxShuttlePart,contents;

	//saut des lignes d'entêtes, repèrage du start.
	while(1){
	std::getline(streamConfigFile,contents);
	std::size_t found = contents.find("Start");
  	if (found!=std::string::npos)
		{
		break;
		}
	}
	//Configuration nombre max de shuttle
	std::getline(streamConfigFile,contents);
	//ROS_INFO("%s",contents.c_str())	;
	std::size_t pos0 = contents.find(":");
	maxShuttlePart = contents.substr(pos0+1);
	//ROS_INFO("maxShuttlePart =%s",maxShuttlePart.c_str());
	maxShuttleNumber = atoi( maxShuttlePart.c_str());
	ROS_INFO("maxShuttleNumber = %d",maxShuttleNumber);

	//Configuration temps entre lancement
	std::getline(streamConfigFile,contents);
	//ROS_INFO("%s",contents.c_str())	;
	std::size_t pos1 = contents.find(":");
	launchDatePart = contents.substr(pos1+1);
	
	char * cstr1 = new char [launchDatePart.length()+1]; //
  	std::strcpy (cstr1, launchDatePart.c_str());	// création objet cstring

  		// cstr now contains a c-string copy of str
		int n1 = 0; //compteur sur les dates de lancement 
 	 	char * p1 = std::strtok (cstr1," "); // cf strtok sur cplusplus.com, permet un découpage du cstring
  		while (p1!=0)
  			{
    			//ROS_INFO ("p1 = %s",p1) ;
			scheduledLaunchDate[n1++] = atoi(p1);		
			ROS_INFO ("launch time entre %d et %d = %d",n1,n1+1,scheduledLaunchDate[n1-1]);
  			p1 = std::strtok(NULL," ");
  			}
  		delete[] cstr1; // comme la création est dynamique, on supprime l'objet pour libèrer la mémoire
	

	while (std::getline(streamConfigFile, contents))
		{
		if (contents.find(':') != std::string::npos )
			{
			
			//ROS_INFO("%s",contents.c_str())	;
			std::size_t pos2 = contents.find(":");
			std::size_t pos3 = contents.find_last_of(":");
		
			pNameFF = contents.substr(0,pos2);
			ROS_INFO("Product %s",pNameFF.c_str());
			destinationPart = contents.substr(pos2+1,pos3-pos2-1);
			//ROS_INFO("destination part =%s",destinationPart.c_str());
			jobTimePart = contents.substr(pos3+1);
			//ROS_INFO("jobTimePart =%s",jobTimePart.c_str());
			int destination[10];
			int jobTime[10];
			int manRSize = 0; //manufacturing range size of the produit = number of operation

			char * cstr2 = new char [destinationPart.length()+1]; 
	  		std::strcpy (cstr2, destinationPart.c_str());	// création objet cstring
			char * cstr3 = new char [jobTimePart.length()+1]; 
	  		std::strcpy (cstr3, jobTimePart.c_str());
			//ROS_INFO(" cstr2 =%s ", cstr2);
			//ROS_INFO(" cstr3 =%s ", cstr3); 	

	  		// cstr now contains a c-string copy of str
			int n2 = 0; //compteur sur les destinations
			int n3 = 0; //compteur sur les temps de fabrications
	 	 	

			char * p2 = std::strtok (cstr2," ");
	  		while (p2!=NULL)
	  			{
	    			//ROS_INFO ("p2 = %s",p2) ;
				destination[n2++] = atoi(p2);
				manRSize++ ;
				ROS_INFO ("destination %d = %d",n2-1,destination[n2-1]);
	  			p2 = std::strtok(NULL," ");
				//ROS_INFO ("p2 = %s",p2) ;
	  			}

			char * p3 = std::strtok (cstr3," ");
			while (p3!=NULL)
	  			{
	    			//ROS_INFO ("p3 = %s",p3) ;
				jobTime[n3++] = atoi(p3);
				ROS_INFO ("jobTime %d = %d",n3-1,jobTime[n3-1]);
	  			p3 = std::strtok(NULL," ");
				//ROS_INFO ("p3 = %s",p3);
	  			}

	  		delete[] cstr2;
			delete[] cstr3; 


			char charName;
			charName = char(pNameFF.c_str()[0]-16);
			//ROS_INFO("CharNAME = %d",charName);
			int pNumber = atoi(&charName) * 10 ; 
			//ROS_INFO("pNumber = %d",pNumber);
			numberOfProduct++;
			initProduct(pNameFF,destination[0], pNumber, manRSize,numberOfProduct);
			}
		
		}
	ROS_INFO("Number of Product = %d", numberOfProduct);
	iteratorPMap = ProductsMap.begin();
	nextCount = numberOfProduct-1; // Permet de bien placer les delays dans launch next schedule
	client_simRosGetInfo.call(srv_GetInfoVREP);
	lastLaunchDate = srv_GetInfoVREP.response.simulationTime; //Initialise le temps de simulation
	
	streamConfigFile.close(); //fermeture du fichier ProductConfiguration.txt ouvert en lecture//

	
	//Creation du fichier de statistique :
	
	std::ofstream StatsFile(logFile.c_str(), std::ios::out | std::ios::app);
	if(StatsFile)  // si l'ouverture a réussi...
	        {
		//Récupération date de lancement//////////////////////
		time_t rawtime;
		struct tm * timeinfo;
		time (&rawtime);
		timeinfo = localtime (&rawtime);
		//////////////////////////////////////////////////////
		ROS_INFO("Statistic.txt file ok \n");
		char logLine[1000];
		sprintf(logLine, "\nNouveau lancement du programme / date : %s\n", asctime(timeinfo));//Construction entête
		ROS_INFO("Nouveau lancement du programme / date : %s\n", asctime(timeinfo));
		StatsFile << logLine; // Ecriture dans le fichier
	       	StatsFile.close();  // on referme le fichier Statistic.txt

        	}
       	else ROS_ERROR("Impossible de creer ou ouvrir le fichier Statistic.txt !");
	return true;

}
else ROS_ERROR("Impossible d'ouvrir le fichier ProductConfiguration.txt !");
return false;
}

// Destructor
Scheduler::~Scheduler()
{
}


// Scheduling Function
void Scheduler::launchNextSchedule(){

if (maxShuttleNumber >0)
	{

	int nextDelay = scheduledLaunchDate[nextCount];

	// Récupération temps VREP ////////////// SERVICE simRosGetInfo de VREP ////////////

		client_simRosGetInfo.call(srv_GetInfoVREP);
		float timeDelta = srv_GetInfoVREP.response.simulationTime - lastLaunchDate;
		
	////////////////////////////////////////////////////////////////////////////////////

	if (timeDelta > nextDelay)
		{

		ROS_INFO("Execution de launchNextSchedule (launch date reach)");
		lastLaunchDate = srv_GetInfoVREP.response.simulationTime;
		
		if (iteratorPMap == ProductsMap.end()) 
			{

			iteratorPMap = ProductsMap.begin();
			//ROS_WARN("Reset iterateur");

			}

		Product* productPointer;
		productPointer = iteratorPMap->second;	
		scheduling::Msg_LoadShuttle mymsg;
		mymsg.shuttleType = 'F';
		mymsg.firstDestination = productPointer->firstDestination;
		mymsg.product = productPointer->productNumber;

		ROS_INFO("ORDO Creation navette avec produit %s numero = %d ",productPointer->name.c_str(), mymsg.product);
		pubCreateShuttle.publish(mymsg);

		//ECRITURE LOG FILE///////////////////////////////////////////////////////////////////////////

		std::ofstream StatsFile(logFile.c_str(), std::ios::out | std::ios::app);
		if(StatsFile)  // si l'ouverture a réussi...
			{

			//ROS_INFO("Statistic.txt file ok");
			char logLine[1000];
			// Construction Ligne avec notamment la date de lancement 
			sprintf(logLine, "Produit %s lance a temps Vrep = %f s\n",productPointer->name.c_str(), srv_GetInfoVREP.response.simulationTime);
			ROS_INFO("Produit %s lance a temps Vrep = %f s",productPointer->name.c_str(), srv_GetInfoVREP.response.simulationTime);
			StatsFile << logLine; // Ecriture dans le fichier 
		       	StatsFile.close();  // on referme le fichier Statistic.txt

			}

	       	else ROS_ERROR("Impossible de creer ou ouvrir le fichier Statistic.txt !");

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		maxShuttleNumber--; 	// diminution du nombre de produit instantiable
		iteratorPMap++;		// avance dans la map produit
		nextCount++; 		// permet d'être en phase vis à vis du tableau des temps entre les lancements des produits
		nextCount = nextCount%numberOfProduct;
		nextDelay = scheduledLaunchDate[nextCount]; // juste pour l'affichage...
		ROS_INFO("Je vais attendre = %d s VREP avant le lancement du prochain produit (si le nombre de navette max est atteint, je vais attendre qu'une sorte)",nextDelay);

		}
	}
}

// Création de produit
void Scheduler::initProduct(std::string pName, int pFirstDestination, int initProductNumber, int pManRSize, int order)
{
	ROS_INFO("Creation Produit %s, first destination = %d, numero produit = %d , taille gamme = %d", pName.c_str(), pFirstDestination,initProductNumber, pManRSize);

		// Création dynamique de l'object product
	Product* newProduct = new Product(pName,pFirstDestination,initProductNumber, pManRSize);

		// Insertion dans le map de la classe de la paire <key=handle,T=Product*>

	std::pair<std::map<int,Product*>::iterator,bool> ret;			// ret permet d'avoir un retour de la fonction insert, il est faux si la key existe dèjà dans la map
	ret = ProductsMap.insert(std::pair<int,Product*>(order,newProduct));
	//ROS_INFO("Product pointer : %p ", newProduct);

	if (ret.second==false)	// Si un produit avec le même nom existe dèjà, celui-ci n'est pas ajouté à la collection
	{
    		ROS_WARN("Ordonnanceur : Un produit de ce nom existe deja ! (%s) ", newProduct->name.c_str()); 
  	} 
} 

// Subscribers Callback (Product end of manifacture)

void Scheduler::productOutCallBack(const std_msgs::Int32::ConstPtr& msg)
{
	srv_GetShuttleStatus.request.handle = msg->data;
	client_GetShuttleStatus.call(srv_GetShuttleStatus);
	client_simRosGetInfo.call(srv_GetInfoVREP);

	std::string finalProductName;
	Product* productPointer;
	
	ROS_INFO ( "srv_GetShuttleStatus.response.product = %d " ,srv_GetShuttleStatus.response.product);

	for (iteratorPMapOut=ProductsMap.begin(); iteratorPMapOut!=ProductsMap.end(); ++iteratorPMapOut)	// On parcours l'ensemble de la collection
	{
		productPointer = iteratorPMapOut->second;
		if ( productPointer->productNumber == (srv_GetShuttleStatus.response.product - productPointer->manRangeSize)) // Trouve le nom du produit fini
		{
			ROS_INFO ( "productPointer->manRangeSize = %d ", productPointer->manRangeSize); 
			//ROS_INFO ( "j'ai trouvé le nom du produit !!");
			finalProductName = productPointer->name;
		}
	}
	
	//ECRITURE LOG FILE///////////////////////////////////////////////////////////////////////////
	std::ofstream StatsFile(logFile.c_str(), std::ios::out | std::ios::app);
	if(StatsFile)  // si l'ouverture a réussi...
		{
		ROS_INFO("Statistic.txt file ok");
		char logLine[1000];
		// Construction Ligne avec notamment la date de lancement 
		sprintf(logLine, "Produit %s termine a temps Vrep = %f s\n",finalProductName.c_str(), srv_GetInfoVREP.response.simulationTime);
		ROS_INFO("Produit %s termine a temps Vrep = %f s\n",finalProductName.c_str(), srv_GetInfoVREP.response.simulationTime);
		StatsFile << logLine; // Ecriture dans le fichier 
		StatsFile.close();  // on referme le fichier Statistic.txt
		}
	else ROS_ERROR("Impossible de creer ou ouvrir le fichier Statistic.txt !");
	/////////////////////////////////////////////////////////////////////////////////////////////

	// Suppression de la navette du noeud shuttles :
	std_msgs::Int32 msgdel;
	msgdel.data = msg->data;
	pubDelShuttle.publish(msgdel);
	maxShuttleNumber++; // augmentation du nombre de produit instantiable

}

void Scheduler::ManualLaunchCallBack(const std_msgs::Bool::ConstPtr& msg)
{
if (msg->data) maxShuttleNumber--;
}



	
