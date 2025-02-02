// Copyright 2006-2015 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// -------------------------------------------------------------------
// THIS FILE IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// You are free to use/modify/distribute this file for whatever purpose!
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.2.3 rev4 on December 21st 2015

// Make sure to have the server side running in V-REP: 
// in a child script of a V-REP scene, add following command
// to be executed just once, at simulation start:
//
// simExtRemoteApiStart(19999)
//
// then start simulation, and run this program.
//
// IMPORTANT: for each successful call to simxStart, there
// should be a corresponding call to simxFinish at the end!

#include <stdio.h>
#include <stdlib.h>

extern "C" {
    #include "extApi.h"
}

int main(int argc,char* argv[])
{
	int clientID=simxStart((simxChar*)"127.0.0.1",19999,true,true,2000,5);
	if (clientID!=-1)
	{
		printf("Connected to remote API server\n");

		// Now try to retrieve data in a blocking fashion (i.e. a service call):
		int objectCount;
		int* objectHandles;
		int ret=simxGetObjects(clientID,sim_handle_all,&objectCount,&objectHandles,simx_opmode_oneshot_wait);
		if (ret==simx_return_ok)
			printf("Number of objects in the scene: %d\n",objectCount);
		else
			printf("Remote API function call returned with error code: %d\n",ret);

		extApi_sleepMs(2000);

		// Now retrieve streaming data (i.e. in a non-blocking fashion):
		int startTime=extApi_getTimeInMs();
		int mouseX;
		simxGetIntegerParameter(clientID,sim_intparam_mouse_x,&mouseX,simx_opmode_streaming); // Initialize streaming
		while (extApi_getTimeDiffInMs(startTime) < 5000)
		{
			ret=simxGetIntegerParameter(clientID,sim_intparam_mouse_x,&mouseX,simx_opmode_buffer); // Try to retrieve the streamed data
			if (ret==simx_return_ok) // After initialization of streaming, it will take a few ms before the first value arrives, so check the return code
				printf("Mouse position x: %d\n",mouseX); // Mouse position x is actualized when the cursor is over V-REP's window
		}
		
		// Now send some data to V-REP in a non-blocking fashion:
		simxAddStatusbarMessage(clientID,"Hello V-REP!",simx_opmode_oneshot);

		// Before closing the connection to V-REP, make sure that the last command sent out had time to arrive. You can guarantee this with (for example):
		int pingTime;
		simxGetPingTime(clientID,&pingTime);

		// Now close the connection to V-REP:	
		simxFinish(clientID);
	}
	return(0);
}
