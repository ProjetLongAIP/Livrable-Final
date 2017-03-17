/**** Maxime Maurin - Projet Long N7 2017 ****/

#include <ros/ros.h>
#include "scheduler.h"

#include <std_msgs/Bool.h>


bool on = false ;


void changeModeCallBack(const std_msgs::Bool::ConstPtr& msg)
{

on = msg->data;
ROS_INFO(" reception message : %d ",msg->data); 

}



int main (int argc, char **argv)
{

// Initialisation du noeud
ros::init(argc, argv, "ordonnancement");	
ros::NodeHandle nh;

ROS_INFO(" Path exe : %s " , argv[0] ) ;

// Définition de la fréquence
ros::Rate loop_rate(10);
std::string name = ros::this_node::getName();

// Souscription 
ros::Subscriber subMode = nh.subscribe("/ordonnancement/On_Off",10,changeModeCallBack);

// Initialisation de "l'ordonnanceur"
Scheduler myScheduler;
if(myScheduler.init(nh,argv[0]))
	{

	ROS_INFO("Noeud ordonnancement initialise : %s", name.c_str());

	sleep(1);

  	while (ros::ok())
  		{
		
		if (on)
			{
			//ROS_INFO(" Ordo Start ");			
			myScheduler.launchNextSchedule();
			ros::spinOnce();
			loop_rate.sleep();
			}
		else	
			{ 
			//ROS_INFO(" Ordo Stop ");
			ros::spinOnce();
			loop_rate.sleep();
			}
  		}
	}
else
	{
	ROS_ERROR("Probleme lors de l'initialiastion du noeud d'ordonnancement, verifier le fichier de configuration ! Lancement Annule");  
	}

return 0;

}



