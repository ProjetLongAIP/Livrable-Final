/*
 * ********************************* *
 * Copyright 2016, STEC Projet Long. *
 * All rights reserved.  	     *
 * ********************************* *
*/


#ifndef VAR_UI
#define VAR_UI

#include <ros/ros.h>
#include <string>
#include <math.h>

// Image Streaming
#include <image_transport/image_transport.h>

#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/Bool.h>
#include <commande_locale/Msg_SensorState.h>
#include "vrepController.h"
#include "configuration.h"
#include <ros/package.h>



class UI
{
	private:
		vrepController* VREPController; 
		Configuration* configuration;
		
		cv::Mat imageSensor;
		cv::Mat imageSimu;
		cv::Mat imageTot;
		cv::Mat playButton;
		cv::Mat playButton_Down;
		cv::Mat playButton_On;
		cv::Mat pauseButton;
		cv::Mat pauseButton_Down;
		cv::Mat pauseButton_On;
		cv::Mat shuttleButton;
		cv::Mat shuttleButton_Down;
		cv::Mat shuttleButton_On;
		cv::Mat modeButton;
		cv::Mat modeButton_On;
		cv::Mat modeRandButton;
		cv::Mat modeRandButton_On;
		cv::Mat modeManuButton;
		cv::Mat modeManuButton_On;
		cv::Mat modeAutoButton;
		cv::Mat modeAutoButton_On;


		int mode;
		int modeShuttle;
		
		int typeNextShuttle; 

		image_transport::Subscriber subImage;
		ros::Publisher pubStateButton;

	public:
		UI(vrepController* VREPContrl, Configuration* config);
		void DrawRailSensorImg(commande_locale::Msg_SensorState SensorState);
		void DrawStopSensorImg(commande_locale::Msg_SensorState SensorState);
		void DrawStationSensorImg(commande_locale::Msg_SensorState SensorState);
		void DrawSwitchSensorImg(commande_locale::Msg_SensorState SensorState);
		void init(ros::NodeHandle nh);
		void update();
		void getSimuStream(const sensor_msgs::ImageConstPtr& msg);
		void onMouse_internal( int event, int x, int y);
		friend void onMouse(int event, int x, int y, int, void* userdata);
		void close();
		bool checkWindow(); 
		
	
};

#endif
