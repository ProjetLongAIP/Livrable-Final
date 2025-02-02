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

#include "v_repExtBubbleRob.h"
#include "luaFunctionData.h"
#include <iostream>
#include "v_repLib.h"

#ifdef _WIN32
	#ifdef QT_COMPIL
		#include <direct.h>
	#else
		#include <shlwapi.h>
		#pragma comment(lib, "Shlwapi.lib")
	#endif
#endif /* _WIN32 */
#if defined (__linux) || defined (__APPLE__)
	#include <unistd.h>
	#define WIN_AFX_MANAGE_STATE
#endif /* __linux || __APPLE__ */

#define CONCAT(x,y,z) x y z
#define strConCat(x,y,z)	CONCAT(x,y,z)

LIBRARY vrepLib;

struct sBubbleRob
{
	int handle;
	int motorHandles[2];
	int sensorHandle;
	float backRelativeVelocities[2];
	float duration;
	float backMovementDuration;
	char* waitUntilZero;
};

std::vector<sBubbleRob> allBubbleRobs;
int nextBubbleRobHandle=0;

int getBubbleRobIndexFromHandle(int bubbleRobHandle)
{
	for (unsigned int i=0;i<allBubbleRobs.size();i++)
	{
		if (allBubbleRobs[i].handle==bubbleRobHandle)
			return(i);
	}
	return(-1);
}

// --------------------------------------------------------------------------------------
// simExtBubble_create
// --------------------------------------------------------------------------------------
#define LUA_CREATE_COMMAND "simExtBubble_create"

const int inArgs_CREATE[]={
	3,
    sim_lua_arg_int|sim_lua_arg_table,2,
	sim_lua_arg_int,0,
	sim_lua_arg_float|sim_lua_arg_table,2,
};

void LUA_CREATE_CALLBACK(SLuaCallBack* p)
{
	p->outputArgCount=0;
	CLuaFunctionData D;
	int handle=-1;
	if (D.readDataFromLua(p,inArgs_CREATE,inArgs_CREATE[0],LUA_CREATE_COMMAND))
	{
		std::vector<CLuaFunctionDataItem>* inData=D.getInDataPtr();
		sBubbleRob bubbleRob;
		handle=nextBubbleRobHandle++;
		bubbleRob.handle=handle;
		bubbleRob.motorHandles[0]=inData->at(0).intData[0];
		bubbleRob.motorHandles[1]=inData->at(0).intData[1];
		bubbleRob.sensorHandle=inData->at(1).intData[0];
		bubbleRob.backRelativeVelocities[0]=inData->at(2).floatData[0];
		bubbleRob.backRelativeVelocities[1]=inData->at(2).floatData[1];
		bubbleRob.waitUntilZero=NULL;
		bubbleRob.duration=0.0f;
		allBubbleRobs.push_back(bubbleRob);
	}
	D.pushOutData(CLuaFunctionDataItem(handle));
	D.writeDataToLua(p);
}
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------
// simExtBubble_destroy
// --------------------------------------------------------------------------------------
#define LUA_DESTROY_COMMAND "simExtBubble_destroy"

const int inArgs_DESTROY[]={
	1,
    sim_lua_arg_int,0,
};

void LUA_DESTROY_CALLBACK(SLuaCallBack* p)
{
	p->outputArgCount=0;
	CLuaFunctionData D;
	bool success=false;
	if (D.readDataFromLua(p,inArgs_DESTROY,inArgs_DESTROY[0],LUA_DESTROY_COMMAND))
	{
		std::vector<CLuaFunctionDataItem>* inData=D.getInDataPtr();
		int handle=inData->at(0).intData[0];
		int index=getBubbleRobIndexFromHandle(handle);
		if (index>=0)
		{
			if (allBubbleRobs[index].waitUntilZero!=NULL)
				allBubbleRobs[index].waitUntilZero[0]=0; // free the blocked thread
			allBubbleRobs.erase(allBubbleRobs.begin()+index);
			success=true;
		}
		else
			simSetLastError(LUA_DESTROY_COMMAND,"Invalid BubbleRob handle.");
	}
	D.pushOutData(CLuaFunctionDataItem(success));
	D.writeDataToLua(p);
}
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------
// simExtBubble_start
// --------------------------------------------------------------------------------------
#define LUA_START_COMMAND "simExtBubble_start"

const int inArgs_START[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_bool,0,
};

void LUA_START_CALLBACK(SLuaCallBack* p)
{
	p->outputArgCount=0;
	CLuaFunctionData D;
	bool success=false;
	if (D.readDataFromLua(p,inArgs_START,inArgs_START[0]-1,LUA_START_COMMAND)) // -1 because the last argument is optional
	{
		std::vector<CLuaFunctionDataItem>* inData=D.getInDataPtr();
		int handle=inData->at(0).intData[0];
		float duration=inData->at(1).floatData[0];
		bool leaveDirectly=false;
		if (inData->size()>2)
			leaveDirectly=inData->at(2).boolData[0];
		int index=getBubbleRobIndexFromHandle(handle);
		if (index!=-1)
		{
			if (duration<=0.0f)
				leaveDirectly=true;
			allBubbleRobs[index].backMovementDuration=0.0f;
			allBubbleRobs[index].duration=duration;
			if (!leaveDirectly)
				p->waitUntilZero=1; // the effect of this is that when we leave the callback, the Lua script gets control
									// back only when this value turns zero. This allows for "blocking" functions 
			success=true;
		}
		else
			simSetLastError(LUA_START_COMMAND,"Invalid BubbleRob handle.");
	}
	D.pushOutData(CLuaFunctionDataItem(success));
	D.writeDataToLua(p);
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
// simExtBubble_stop
// --------------------------------------------------------------------------------------
#define LUA_STOP_COMMAND "simExtBubble_stop"

const int inArgs_STOP[]={
	1,
    sim_lua_arg_int,0,
};

void LUA_STOP_CALLBACK(SLuaCallBack* p)
{
	p->outputArgCount=0;
	CLuaFunctionData D;
	bool success=false;
	if (D.readDataFromLua(p,inArgs_STOP,inArgs_STOP[0],LUA_STOP_COMMAND))
	{
		std::vector<CLuaFunctionDataItem>* inData=D.getInDataPtr();
		int handle=inData->at(0).intData[0];
		int index=getBubbleRobIndexFromHandle(handle);
		if (index!=-1)
		{
			if (allBubbleRobs[index].waitUntilZero!=NULL)
			{
				allBubbleRobs[index].waitUntilZero[0]=0; // free the blocked thread
				allBubbleRobs[index].waitUntilZero=NULL;
			}
			allBubbleRobs[index].duration=0.0f;
			success=true;
		}
		else
			simSetLastError(LUA_STOP_COMMAND,"Invalid BubbleRob handle.");
	}
	D.pushOutData(CLuaFunctionDataItem(success));
	D.writeDataToLua(p);
}
// --------------------------------------------------------------------------------------


VREP_DLLEXPORT unsigned char v_repStart(void* reservedPointer,int reservedInt)
{ // This is called just once, at the start of V-REP.
	// Dynamically load and bind V-REP functions:
	char curDirAndFile[1024];
#ifdef _WIN32
	#ifdef QT_COMPIL
		_getcwd(curDirAndFile, sizeof(curDirAndFile));
	#else
		GetModuleFileName(NULL,curDirAndFile,1023);
		PathRemoveFileSpec(curDirAndFile);
	#endif
#elif defined (__linux) || defined (__APPLE__)
	getcwd(curDirAndFile, sizeof(curDirAndFile));
#endif

	std::string currentDirAndPath(curDirAndFile);
	std::string temp(currentDirAndPath);

#ifdef _WIN32
	temp+="\\v_rep.dll";
#elif defined (__linux)
	temp+="/libv_rep.so";
#elif defined (__APPLE__)
	temp+="/libv_rep.dylib";
#endif /* __linux || __APPLE__ */

	vrepLib=loadVrepLibrary(temp.c_str());
	if (vrepLib==NULL)
	{
		std::cout << "Error, could not find or correctly load v_rep.dll. Cannot start 'BubbleRob' plugin.\n";
		return(0); // Means error, V-REP will unload this plugin
	}
	if (getVrepProcAddresses(vrepLib)==0)
	{
		std::cout << "Error, could not find all required functions in v_rep.dll. Cannot start 'BubbleRob' plugin.\n";
		unloadVrepLibrary(vrepLib);
		return(0); // Means error, V-REP will unload this plugin
	}

	// Check the V-REP version:
	int vrepVer;
	simGetIntegerParameter(sim_intparam_program_version,&vrepVer);
	if (vrepVer<30200) // if V-REP version is smaller than 3.02.00
	{
		std::cout << "Sorry, your V-REP copy is somewhat old, V-REP 3.2.0 or higher is required. Cannot start 'BubbleRob' plugin.\n";
		unloadVrepLibrary(vrepLib);
		return(0); // Means error, V-REP will unload this plugin
	}

	// Register 4 new Lua commands:
	std::vector<int> inArgs;

	CLuaFunctionData::getInputDataForFunctionRegistration(inArgs_CREATE,inArgs);
	simRegisterCustomLuaFunction(LUA_CREATE_COMMAND,strConCat("number bubbleRobHandle=",LUA_CREATE_COMMAND,"(table_2 motorJointHandles,number sensorHandle,table_2 backRelativeVelocities)"),&inArgs[0],LUA_CREATE_CALLBACK);

	CLuaFunctionData::getInputDataForFunctionRegistration(inArgs_DESTROY,inArgs);
	simRegisterCustomLuaFunction(LUA_DESTROY_COMMAND,strConCat("boolean result=",LUA_DESTROY_COMMAND,"(number bubbleRobHandle)"),&inArgs[0],LUA_DESTROY_CALLBACK);

	CLuaFunctionData::getInputDataForFunctionRegistration(inArgs_START,inArgs);
	simRegisterCustomLuaFunction(LUA_START_COMMAND,strConCat("boolean result=",LUA_START_COMMAND,"(number bubbleRobHandle,number duration,boolean returnDirectly=false)"),&inArgs[0],LUA_START_CALLBACK);

	CLuaFunctionData::getInputDataForFunctionRegistration(inArgs_STOP,inArgs);
	simRegisterCustomLuaFunction(LUA_STOP_COMMAND,strConCat("boolean result=",LUA_STOP_COMMAND,"(number bubbleRobHandle)"),&inArgs[0],LUA_STOP_CALLBACK);

	return(7); // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
	// version 1 was for V-REP versions before V-REP 2.5.12
	// version 2 was for V-REP versions before V-REP 2.6.0
	// version 5 was for V-REP versions before V-REP 3.1.0 
	// version 6 is for V-REP versions after V-REP 3.1.3
	// version 7 is for V-REP versions after V-REP 3.2.0 (completely rewritten)
}

VREP_DLLEXPORT void v_repEnd()
{ // This is called just once, at the end of V-REP
	unloadVrepLibrary(vrepLib); // release the library
}

VREP_DLLEXPORT void* v_repMessage(int message,int* auxiliaryData,void* customData,int* replyData)
{ // This is called quite often. Just watch out for messages/events you want to handle
	// This function should not generate any error messages:
	int errorModeSaved;
	simGetIntegerParameter(sim_intparam_error_report_mode,&errorModeSaved);
	simSetIntegerParameter(sim_intparam_error_report_mode,sim_api_errormessage_ignore);

	void* retVal=NULL;

	if (message==sim_message_eventcallback_modulehandle)
	{
		if ( (customData==NULL)||(std::string("BubbleRob").compare((char*)customData)==0) ) // is the command also meant for BubbleRob?
		{
			float dt=simGetSimulationTimeStep();
			for (unsigned int i=0;i<allBubbleRobs.size();i++)
			{
				if (allBubbleRobs[i].duration>0.0f)
				{ // movement mode
					if (simReadProximitySensor(allBubbleRobs[i].sensorHandle,NULL,NULL,NULL)>0)
						allBubbleRobs[i].backMovementDuration=3.0f; // we detected an obstacle, we move backward for 3 seconds
					if (allBubbleRobs[i].backMovementDuration>0.0f)
					{ // We move backward
						simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[0],-3.1415f*allBubbleRobs[i].backRelativeVelocities[0]);
						simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[1],-3.1415f*allBubbleRobs[i].backRelativeVelocities[1]);
						allBubbleRobs[i].backMovementDuration-=dt;
					}
					else
					{ // We move forward
						simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[0],3.1415f);
						simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[1],3.1415f);
					}
					allBubbleRobs[i].duration-=dt;
				}
				else
				{ // stopped mode
					if (allBubbleRobs[i].waitUntilZero!=NULL)
					{
						allBubbleRobs[i].waitUntilZero[0]=0;
						allBubbleRobs[i].waitUntilZero=NULL;
					}
					simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[0],0.0f);
					simSetJointTargetVelocity(allBubbleRobs[i].motorHandles[1],0.0f);
				}
			}
		}
	}

	if (message==sim_message_eventcallback_simulationended)
	{ // simulation ended. Destroy all BubbleRob instances:
		allBubbleRobs.clear();
	}

	simSetIntegerParameter(sim_intparam_error_report_mode,errorModeSaved); // restore previous settings
	return(retVal);
}
