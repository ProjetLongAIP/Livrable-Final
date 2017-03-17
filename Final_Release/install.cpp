/*----------------------------------------------------*/
/*
	To compile me:
		$ g++ install.cpp -o setup
	To execute me:
		$ ./setup [name_of_the_folder] 
		(ie. $ ./setup Working_Folder_TER )
*/
/*---------------------------------------------------*/



#include <iostream>
#include <stdlib.h>  
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
  if (argc < 2) {
	cout << "Please state the name of the folder" << endl;
	    return 1;
     }


char* folderName = argv[1]; 
cout << endl <<"---------------------------------------------------"<< endl;
cout << "Initializing the Working Folder: " << folderName;
cout << endl <<"---------------------------------------------------"<< endl<<endl;

/* Creating the folder of the working space */
char aux[1000];
sprintf(aux, "mkdir -p -v ~/%s", folderName);
// printf("%s$\n",  aux);
system(aux);


/*
///////////////////////////////////////////////////
int a;
cout << endl<< "fait tonc truc"<< endl;
cin >> a; 
///////////////////////////////////////////////////
*/

sprintf(aux, "mkdir -p -v ~/%s/ros_ws/src", folderName);
system(aux);


sprintf(aux, "catkin_init_workspace ~/%s/ros_ws/src", folderName);
system(aux);


sprintf(aux, "catkin_make -C ~/%s/ros_ws", folderName);
int ok = system(aux);

cout << endl <<"---------------------------------------------------"<< endl;
if (ok == 0) cout << "     Working Folder '" << folderName <<"' was set up successfully";
else cout << "\t Ops ... Something went wrong ";
cout << endl << "---------------------------------------------------"<< endl<<endl;




/* Copying the necessary ROS packages */
cout << endl <<"--------------------------------------"<< endl;
cout << "  Copying necessary ROS packages ..."<<endl;
cout << "--------------------------------------"<< endl<< endl;

	/* automates */
	cout << "\tCopying 'automates' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/automates/. ~/%s/ros_ws/src/automates/", folderName);
	system(aux);
	cout << endl;

	/* commande */
	cout << "\tCopying 'commande' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/commande/. ~/%s/ros_ws/src/commande/", folderName);
	system(aux);
	cout << endl;

	/* commande_locale */
	cout << "\tCopying 'commande_locale' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/commande_locale/. ~/%s/ros_ws/src/commande_locale/", folderName);
	system(aux);
	cout << endl;

	/* communication */
	cout << "\tCopying 'communication' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/communication/. ~/%s/ros_ws/src/communication/", folderName);
	system(aux);
	cout << endl;

	/* vrep_common */
	cout << "\tCopying 'vrep_common' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/vrep_common/. ~/%s/ros_ws/src/vrep_common/", folderName);
	system(aux);
	cout << endl;

	/* robot */
	cout << "\tCopying 'robots' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/robots/. ~/%s/ros_ws/src/robots/", folderName);
	system(aux);
	cout << endl;

	/* shuttles */
	cout << "\tCopying 'shuttles' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/shuttles/. ~/%s/ros_ws/src/shuttles/", folderName);
	system(aux);
	cout << endl;

	/* aiguillages */
	cout << "\tCopying 'aiguillages' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/aiguillages/. ~/%s/ros_ws/src/aiguillages/", folderName);
	system(aux);
	cout << endl;

	/* postes */
	cout << "\tCopying 'postes' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/postes/. ~/%s/ros_ws/src/postes/", folderName);
	system(aux);
	cout << endl;

	/* scheduling */
	cout << "\tCopying 'scheduling' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/scheduling/. ~/%s/ros_ws/src/scheduling/", folderName);
	system(aux);
	cout << endl;

	/* taches */
	cout << "\tCopying 'taches' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/taches/. ~/%s/ros_ws/src/taches/", folderName);
	system(aux);
	cout << endl;

	/* launcher */
	cout << "\tCopying 'launcher' ..."<< endl;
	sprintf(aux, "cp -a  ros_ws/src/launcher/. ~/%s/ros_ws/src/launcher/", folderName);
	system(aux);
	cout << endl;

/* Il faudra inclure les packages qu'on va faire :)*/


/* Final catkin_make */
/*
sprintf(aux, "catkin_make install -C ~/%s/ros_ws --pkg automates", folderName);
ok = system(aux);
*/
sprintf(aux, "catkin_make -j1 -C ~/%s/ros_ws", folderName);
ok = system(aux);

cout << endl <<"-----------------------------------------------------------"<< endl;
if (ok == 0) cout << "      Final catkin_make done in '" << folderName <<"'"<< endl<< "\tCompilation successful" ;
else cout << "     Ops ... Something went wrong. Make sure you copied all the necessary files ";
cout << endl <<"-----------------------------------------------------------"<< endl<<endl;

/* Copying the necessary files */
	
	/* V-Rep */
	cout << "\tCopying 'V-Rep' ..."<< endl;
	sprintf(aux, "cp -a  V-Rep/. ~/%s/V-Rep", folderName);
	system(aux);
	cout << endl;	

	/* Simulation file (*.ttt) */
	cout << "\tCopying simulation file (*.ttt)  ..."<< endl;
	sprintf(aux, "cp -a  sim/. ~/%s/sim", folderName);
	system(aux);
	cout << endl;

	/* Config File (*.config) */
	cout << "\tCopying config File (*.config) ..."<< endl;
	sprintf(aux, "cp -a  ProductConfiguration.config ~/%s", folderName);
	system(aux);
	cout << endl;

	/* Launch file (launch.sh) */
	cout << "\tCopying launch file (launch.sh) ..."<< endl;
	sprintf(aux, "cp -a  launch.sh ~/%s", folderName);
	system(aux);
	cout << endl;

/*Authorize the launch file to be executed*/
	system("chmod +x launch.sh");

/*Final instructions*/
	system("clear");
	cout << endl <<"-------------------------------------------------------------------"<< endl;
	cout << "\t  The simulation is ready to be launched \n" ;
	cout << "  In a NEW terminal, type the following command line. \n";
	cout << "  This will launch the default simulation file"<< endl;
	cout << "     $ cd ~/"<<folderName<<" && ./launch.sh"<< endl<<endl;
	
	cout << "  If you want to launch a specific simulation file, type: \n";
	cout << "     $ cd ~/"<<folderName<<" && ./launch.sh [Simulation_File]"<< endl;
	cout << endl <<"-------------------------------------------------------------------"<< endl<<endl;

    return 0;
}



