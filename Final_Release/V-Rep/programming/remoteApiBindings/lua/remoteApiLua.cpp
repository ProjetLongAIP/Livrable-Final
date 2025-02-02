// This file is part of the REMOTE API
// 
// Copyright 2006-2015 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// The REMOTE API is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The REMOTE API is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// THE REMOTE API IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the REMOTE API.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.2.3 rev4 on December 21st 2015

#include "luaData.h"
#include <boost/lexical_cast.hpp>

extern "C" {
    #include "extApi.h"
/*	#include "extApiCustom.h" if you wanna use custom remote API functions! */
}


// --------------------------------------------------------------------------------------
#define LUA_START_COMMAND "simxStart"
const int inArgs_START[]={
	6,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_bool,0,
    sim_lua_arg_bool,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0, // optional argument
};
int LUA_START_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_START,inArgs_START[0]-1,LUA_START_COMMAND)) // -1 because the last arg is optional
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		std::string ipAddress(inData->at(0).stringData[0]);
		if (ipAddress.length()==0)
			ipAddress="127.0.0.1";
		int port=inData->at(1).intData[0];
		bool waitUntilConnected=inData->at(2).boolData[0];
		bool doNotReconnect=inData->at(3).boolData[0];
		int timeOut=inData->at(4).intData[0];
		int cycle=5;
		if (inData->size()>=6)
			cycle=inData->at(5).intData[0];
		int _clientId=simxStart(ipAddress.c_str(),port,waitUntilConnected,doNotReconnect,timeOut,cycle);
		D.pushOutData(CLuaDataItem(_clientId));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_FINISH_COMMAND "simxFinish"
const int inArgs_FINISH[]={
	1,
    sim_lua_arg_int,0,
};
int LUA_FINISH_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_FINISH,inArgs_FINISH[0],LUA_FINISH_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		simxFinish(_clientId);
		extApi_sleepMs(500);
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------
#define LUA_ADDSTATUSBARMESSAGE_COMMAND "simxAddStatusbarMessage"
const int inArgs_ADDSTATUSBARMESSAGE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_ADDSTATUSBARMESSAGE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_ADDSTATUSBARMESSAGE,inArgs_ADDSTATUSBARMESSAGE[0],LUA_ADDSTATUSBARMESSAGE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxAddStatusbarMessage(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_AUXILIARYCONSOLECLOSE_COMMAND "simxAuxiliaryConsoleClose"
const int inArgs_AUXILIARYCONSOLECLOSE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_AUXILIARYCONSOLECLOSE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_AUXILIARYCONSOLECLOSE,inArgs_AUXILIARYCONSOLECLOSE[0],LUA_AUXILIARYCONSOLECLOSE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxAuxiliaryConsoleClose(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_AUXILIARYCONSOLEOPEN_COMMAND "simxAuxiliaryConsoleOpen"
const int inArgs_AUXILIARYCONSOLEOPEN[]={
	9,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,2,
    sim_lua_arg_int|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,2,
    sim_lua_arg_float|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,3,
    sim_lua_arg_float|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,3,
    sim_lua_arg_int,0,
};
int LUA_AUXILIARYCONSOLEOPEN_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_AUXILIARYCONSOLEOPEN,inArgs_AUXILIARYCONSOLEOPEN[0],LUA_AUXILIARYCONSOLEOPEN_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int* pos=NULL;
		int* size=NULL;
		float* frgb=NULL;
		float* brgb=NULL;
		if (inData->at(4).intData.size()>=2)
			pos=&inData->at(4).intData[0];
		if (inData->at(5).intData.size()>=2)
			size=&inData->at(5).intData[0];
		if (inData->at(6).floatData.size()>=3)
			frgb=&inData->at(6).floatData[0];
		if (inData->at(7).floatData.size()>=3)
			brgb=&inData->at(7).floatData[0];
		int consoleHandle;
		int res=simxAuxiliaryConsoleOpen(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0],inData->at(3).intData[0],pos,size,frgb,brgb,&consoleHandle,inData->at(8).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(consoleHandle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_AUXILIARYCONSOLEPRINT_COMMAND "simxAuxiliaryConsolePrint"
const int inArgs_AUXILIARYCONSOLEPRINT[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_string|SIM_LUA_ARG_NIL_ALLOWED,0,
    sim_lua_arg_int,0,
};
int LUA_AUXILIARYCONSOLEPRINT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_AUXILIARYCONSOLEPRINT,inArgs_AUXILIARYCONSOLEPRINT[0],LUA_AUXILIARYCONSOLEPRINT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		char* txt=NULL;
		if (inData->at(2).stringData.size()==1)
			txt=(char*)inData->at(2).stringData[0].c_str();
		int res=simxAuxiliaryConsolePrint(_clientId,inData->at(1).intData[0],txt,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_AUXILIARYCONSOLESHOW_COMMAND "simxAuxiliaryConsoleShow"
const int inArgs_AUXILIARYCONSOLESHOW[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_bool,0,
    sim_lua_arg_int,0,
};
int LUA_AUXILIARYCONSOLESHOW_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_AUXILIARYCONSOLESHOW,inArgs_AUXILIARYCONSOLESHOW[0],LUA_AUXILIARYCONSOLESHOW_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxAuxiliaryConsoleShow(_clientId,inData->at(1).intData[0],inData->at(2).boolData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_BREAKFORCESENSOR_COMMAND "simxBreakForceSensor"
const int inArgs_BREAKFORCESENSOR[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_BREAKFORCESENSOR_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_BREAKFORCESENSOR,inArgs_BREAKFORCESENSOR[0],LUA_BREAKFORCESENSOR_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxBreakForceSensor(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_CLEARFLOATSIGNAL_COMMAND "simxClearFloatSignal"
const int inArgs_CLEARFLOATSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_CLEARFLOATSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_CLEARFLOATSIGNAL,inArgs_CLEARFLOATSIGNAL[0],LUA_CLEARFLOATSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxClearFloatSignal(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_CLEARINTEGERSIGNAL_COMMAND "simxClearIntegerSignal"
const int inArgs_CLEARINTEGERSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_CLEARINTEGERSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_CLEARINTEGERSIGNAL,inArgs_CLEARINTEGERSIGNAL[0],LUA_CLEARINTEGERSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxClearIntegerSignal(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_CLEARSTRINGSIGNAL_COMMAND "simxClearStringSignal"
const int inArgs_CLEARSTRINGSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_CLEARSTRINGSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_CLEARSTRINGSIGNAL,inArgs_CLEARSTRINGSIGNAL[0],LUA_CLEARSTRINGSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxClearStringSignal(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTHANDLE_COMMAND "simxGetObjectHandle"
const int inArgs_GETOBJECTHANDLE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTHANDLE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTHANDLE,inArgs_GETOBJECTHANDLE[0],LUA_GETOBJECTHANDLE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handle;
		int res=simxGetObjectHandle(_clientId,inData->at(1).stringData[0].c_str(),&handle,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(handle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_CLOSESCENE_COMMAND "simxCloseScene"
const int inArgs_CLOSESCENE[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_CLOSESCENE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_CLOSESCENE,inArgs_CLOSESCENE[0],LUA_CLOSESCENE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxCloseScene(_clientId,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_COPYPASTEOBJECTS_COMMAND "simxCopyPasteObjects"
const int inArgs_COPYPASTEOBJECTS[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int|sim_lua_arg_table,1, // at least one item in the table
    sim_lua_arg_int,0,
};
int LUA_COPYPASTEOBJECTS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_COPYPASTEOBJECTS,inArgs_COPYPASTEOBJECTS[0],LUA_COPYPASTEOBJECTS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int cnt;
		int* newHandles;
		int res=simxCopyPasteObjects(_clientId,&inData->at(1).intData[0],(int)inData->at(1).intData.size(),&newHandles,&cnt,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<int> nobj;
			for (int i=0;i<cnt;i++)
				nobj.push_back(newHandles[i]);
			D.pushOutData(CLuaDataItem(nobj));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_LOADSCENE_COMMAND "simxLoadScene"
const int inArgs_LOADSCENE[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_LOADSCENE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_LOADSCENE,inArgs_LOADSCENE[0],LUA_LOADSCENE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::string fileAndPath(inData->at(1).stringData[0]);
		int res=simxLoadScene(_clientId,fileAndPath.c_str(),inData->at(2).intData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_LOADMODEL_COMMAND "simxLoadModel"
const int inArgs_LOADMODEL[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_LOADMODEL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_LOADMODEL,inArgs_LOADMODEL[0],LUA_LOADMODEL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::string fileAndPath(inData->at(1).stringData[0]);
		int baseHandle;
		int res=simxLoadModel(_clientId,fileAndPath.c_str(),inData->at(2).intData[0],&baseHandle,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(baseHandle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_LOADUI_COMMAND "simxLoadUI"
const int inArgs_LOADUI[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_LOADUI_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_LOADUI,inArgs_LOADUI[0],LUA_LOADUI_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::string fileAndPath(inData->at(1).stringData[0]);
		int cnt;
		int* handles;
		int res=simxLoadUI(_clientId,fileAndPath.c_str(),inData->at(2).intData[0],&cnt,&handles,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<int> handlesR;
			for (int i=0;i<cnt;i++)
				handlesR.push_back(handles[i]);
			D.pushOutData(CLuaDataItem(handlesR));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETBOOLEANPARAMETER_COMMAND "simxSetBooleanParameter"
const int inArgs_SETBOOLEANPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_bool,0,
    sim_lua_arg_int,0,
};
int LUA_SETBOOLEANPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETBOOLEANPARAMETER,inArgs_SETBOOLEANPARAMETER[0],LUA_SETBOOLEANPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetBooleanParameter(_clientId,inData->at(1).intData[0],inData->at(2).boolData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_STARTSIMULATION_COMMAND "simxStartSimulation"
const int inArgs_STARTSIMULATION[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_STARTSIMULATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_STARTSIMULATION,inArgs_STARTSIMULATION[0],LUA_STARTSIMULATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxStartSimulation(_clientId,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_STOPSIMULATION_COMMAND "simxStopSimulation"
const int inArgs_STOPSIMULATION[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_STOPSIMULATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_STOPSIMULATION,inArgs_STOPSIMULATION[0],LUA_STOPSIMULATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxStopSimulation(_clientId,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETFLOATINGPARAMETER_COMMAND "simxSetFloatingParameter"
const int inArgs_SETFLOATINGPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETFLOATINGPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETFLOATINGPARAMETER,inArgs_SETFLOATINGPARAMETER[0],LUA_SETFLOATINGPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetFloatingParameter(_clientId,inData->at(1).intData[0],inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETINTEGERPARAMETER_COMMAND "simxSetIntegerParameter"
const int inArgs_SETINTEGERPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_SETINTEGERPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETINTEGERPARAMETER,inArgs_SETINTEGERPARAMETER[0],LUA_SETINTEGERPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetIntegerParameter(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETARRAYPARAMETER_COMMAND "simxSetArrayParameter"
const int inArgs_SETARRAYPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
	sim_lua_arg_float|sim_lua_arg_table,3,
    sim_lua_arg_int,0,
};
int LUA_SETARRAYPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETARRAYPARAMETER,inArgs_SETARRAYPARAMETER[0],LUA_SETARRAYPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetArrayParameter(_clientId,inData->at(1).intData[0],&inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETBOOLEANPARAMETER_COMMAND "simxGetBooleanParameter"
const int inArgs_GETBOOLEANPARAMETER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETBOOLEANPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETBOOLEANPARAMETER,inArgs_GETBOOLEANPARAMETER[0],LUA_GETBOOLEANPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char p;
		int res=simxGetBooleanParameter(_clientId,inData->at(1).intData[0],&p,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(p!=0));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETFLOATINGPARAMETER_COMMAND "simxGetFloatingParameter"
const int inArgs_GETFLOATINGPARAMETER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETFLOATINGPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETFLOATINGPARAMETER,inArgs_GETFLOATINGPARAMETER[0],LUA_GETFLOATINGPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float p;
		int res=simxGetFloatingParameter(_clientId,inData->at(1).intData[0],&p,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(p));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETINTEGERPARAMETER_COMMAND "simxGetIntegerParameter"
const int inArgs_GETINTEGERPARAMETER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETINTEGERPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETINTEGERPARAMETER,inArgs_GETINTEGERPARAMETER[0],LUA_GETINTEGERPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int p;
		int res=simxGetIntegerParameter(_clientId,inData->at(1).intData[0],&p,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(p));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETARRAYPARAMETER_COMMAND "simxGetArrayParameter"
const int inArgs_GETARRAYPARAMETER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETARRAYPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETARRAYPARAMETER,inArgs_GETARRAYPARAMETER[0],LUA_GETARRAYPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<float> p(3,0.0f);
		int res=simxGetArrayParameter(_clientId,inData->at(1).intData[0],&p[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(p));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETSTRINGPARAMETER_COMMAND "simxGetStringParameter"
const int inArgs_GETSTRINGPARAMETER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETSTRINGPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETSTRINGPARAMETER,inArgs_GETSTRINGPARAMETER[0],LUA_GETSTRINGPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		char* p;
		int res=simxGetStringParameter(_clientId,inData->at(1).intData[0],&p,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(std::string(p)));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETFLOATSIGNAL_COMMAND "simxSetFloatSignal"
const int inArgs_SETFLOATSIGNAL[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETFLOATSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETFLOATSIGNAL,inArgs_SETFLOATSIGNAL[0],LUA_SETFLOATSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetFloatSignal(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETINTEGERSIGNAL_COMMAND "simxSetIntegerSignal"
const int inArgs_SETINTEGERSIGNAL[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_SETINTEGERSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETINTEGERSIGNAL,inArgs_SETINTEGERSIGNAL[0],LUA_SETINTEGERSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetIntegerSignal(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETSTRINGSIGNAL_COMMAND "simxSetStringSignal"
const int inArgs_SETSTRINGSIGNAL[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_charbuff,0,
    sim_lua_arg_int,0,
};
int LUA_SETSTRINGSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETSTRINGSIGNAL,inArgs_SETSTRINGSIGNAL[0],LUA_SETSTRINGSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetStringSignal(_clientId,inData->at(1).stringData[0].c_str(),(unsigned char*)inData->at(2).stringData[0].c_str(),(int)inData->at(2).stringData[0].size(),inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETFLOATSIGNAL_COMMAND "simxGetFloatSignal"
const int inArgs_GETFLOATSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETFLOATSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETFLOATSIGNAL,inArgs_GETFLOATSIGNAL[0],LUA_GETFLOATSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float signalValue;
		int res=simxGetFloatSignal(_clientId,inData->at(1).stringData[0].c_str(),&signalValue,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(signalValue));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETINTEGERSIGNAL_COMMAND "simxGetIntegerSignal"
const int inArgs_GETINTEGERSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETINTEGERSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETINTEGERSIGNAL,inArgs_GETINTEGERSIGNAL[0],LUA_GETINTEGERSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int signalValue;
		int res=simxGetIntegerSignal(_clientId,inData->at(1).stringData[0].c_str(),&signalValue,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(signalValue));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETSTRINGSIGNAL_COMMAND "simxGetStringSignal"
const int inArgs_GETSTRINGSIGNAL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETSTRINGSIGNAL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETSTRINGSIGNAL,inArgs_GETSTRINGSIGNAL[0],LUA_GETSTRINGSIGNAL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int signalLength;
		unsigned char* signalValue;
		int res=simxGetStringSignal(_clientId,inData->at(1).stringData[0].c_str(),&signalValue,&signalLength,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem((char*)signalValue,signalLength));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_CREATEDUMMY_COMMAND "simxCreateDummy"
const int inArgs_CREATEDUMMY[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,12,
    sim_lua_arg_int,0,
};
int LUA_CREATEDUMMY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_CREATEDUMMY,inArgs_CREATEDUMMY[0],LUA_CREATEDUMMY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int dummyHandle;
		unsigned char* cols=NULL;
		unsigned char colors[12];
		if (inData->at(2).intData.size()>=12)
		{
			for (int i=0;i<12;i++)
				colors[i]=(unsigned char)inData->at(2).intData[i];
			cols=colors;
		}
		int res=simxCreateDummy(_clientId,inData->at(1).floatData[0],cols,&dummyHandle,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(dummyHandle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_DISPLAYDIALOG_COMMAND "simxDisplayDialog"
const int inArgs_DISPLAYDIALOG[]={
	8,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_float|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,6,
    sim_lua_arg_float|sim_lua_arg_table|SIM_LUA_ARG_NIL_ALLOWED,6,
    sim_lua_arg_int,0,
};
int LUA_DISPLAYDIALOG_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_DISPLAYDIALOG,inArgs_DISPLAYDIALOG[0],LUA_DISPLAYDIALOG_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int dlgHandle;
		int uiHandle;
		float* tcols=NULL;
		float tcolors[6];
		float* dcols=NULL;
		float dcolors[6];
		if (inData->at(5).floatData.size()>=6)
		{
			for (int i=0;i<6;i++)
				tcolors[i]=inData->at(5).floatData[i];
			tcols=tcolors;
		}
		if (inData->at(6).floatData.size()>=6)
		{
			for (int i=0;i<6;i++)
				dcolors[i]=inData->at(6).floatData[i];
			dcols=dcolors;
		}
		int res=simxDisplayDialog(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).stringData[0].c_str(),inData->at(3).intData[0],inData->at(4).stringData[0].c_str(),tcols,dcols,&dlgHandle,&uiHandle,inData->at(7).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(dlgHandle));
			D.pushOutData(CLuaDataItem(uiHandle));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_ENDDIALOG_COMMAND "simxEndDialog"
const int inArgs_ENDDIALOG[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_ENDDIALOG_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_ENDDIALOG,inArgs_ENDDIALOG[0],LUA_ENDDIALOG_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxEndDialog(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETDIALOGINPUT_COMMAND "simxGetDialogInput"
const int inArgs_GETDIALOGINPUT[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETDIALOGINPUT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETDIALOGINPUT,inArgs_GETDIALOGINPUT[0],LUA_GETDIALOGINPUT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		char* input;
		int res=simxGetDialogInput(_clientId,inData->at(1).intData[0],&input,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(std::string(input)));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETDIALOGRESULT_COMMAND "simxGetDialogResult"
const int inArgs_GETDIALOGRESULT[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETDIALOGRESULT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETDIALOGRESULT,inArgs_GETDIALOGRESULT[0],LUA_GETDIALOGRESULT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int result;
		int res=simxGetDialogResult(_clientId,inData->at(1).intData[0],&result,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(result));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_ERASEFILE_COMMAND "simxEraseFile"
const int inArgs_ERASEFILE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_ERASEFILE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_ERASEFILE,inArgs_ERASEFILE[0],LUA_ERASEFILE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxEraseFile(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETCOLLISIONHANDLE_COMMAND "simxGetCollisionHandle"
const int inArgs_GETCOLLISIONHANDLE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETCOLLISIONHANDLE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETCOLLISIONHANDLE,inArgs_GETCOLLISIONHANDLE[0],LUA_GETCOLLISIONHANDLE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handle;
		int res=simxGetCollisionHandle(_clientId,inData->at(1).stringData[0].c_str(),&handle,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(handle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETCONNECTIONID_COMMAND "simxGetConnectionId"
const int inArgs_GETCONNECTIONID[]={
	1,
    sim_lua_arg_int,0,
};
int LUA_GETCONNECTIONID_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETCONNECTIONID,inArgs_GETCONNECTIONID[0],LUA_GETCONNECTIONID_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxGetConnectionId(_clientId);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETDISTANCEHANDLE_COMMAND "simxGetDistanceHandle"
const int inArgs_GETDISTANCEHANDLE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETDISTANCEHANDLE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETDISTANCEHANDLE,inArgs_GETDISTANCEHANDLE[0],LUA_GETDISTANCEHANDLE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handle;
		int res=simxGetDistanceHandle(_clientId,inData->at(1).stringData[0].c_str(),&handle,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(handle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETCOLLECTIONHANDLE_COMMAND "simxGetCollectionHandle"
const int inArgs_GETCOLLECTIONHANDLE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETCOLLECTIONHANDLE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETCOLLECTIONHANDLE,inArgs_GETCOLLECTIONHANDLE[0],LUA_GETCOLLECTIONHANDLE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handle;
		int res=simxGetCollectionHandle(_clientId,inData->at(1).stringData[0].c_str(),&handle,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(handle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETINMESSAGEINFO_COMMAND "simxGetInMessageInfo"
const int inArgs_GETINMESSAGEINFO[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETINMESSAGEINFO_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETINMESSAGEINFO,inArgs_GETINMESSAGEINFO[0],LUA_GETINMESSAGEINFO_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int info;
		int res=simxGetInMessageInfo(_clientId,inData->at(1).intData[0],&info);
		D.pushOutData(CLuaDataItem(res));
		if (res!=-1)
			D.pushOutData(CLuaDataItem(info));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOUTMESSAGEINFO_COMMAND "simxGetOutMessageInfo"
const int inArgs_GETOUTMESSAGEINFO[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOUTMESSAGEINFO_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOUTMESSAGEINFO,inArgs_GETOUTMESSAGEINFO[0],LUA_GETOUTMESSAGEINFO_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int info;
		int res=simxGetOutMessageInfo(_clientId,inData->at(1).intData[0],&info);
		D.pushOutData(CLuaDataItem(res));
		if (res!=-1)
			D.pushOutData(CLuaDataItem(info));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETJOINTFORCE_COMMAND "simxGetJointForce"
const int inArgs_GETJOINTFORCE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETJOINTFORCE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETJOINTFORCE,inArgs_GETJOINTFORCE[0],LUA_GETJOINTFORCE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float force;
		int res=simxGetJointForce(_clientId,inData->at(1).intData[0],&force,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(force));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETJOINTMATRIX_COMMAND "simxGetJointMatrix"
const int inArgs_GETJOINTMATRIX[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETJOINTMATRIX_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETJOINTMATRIX,inArgs_GETJOINTMATRIX[0],LUA_GETJOINTMATRIX_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<float> matrix(12,0.0f);
		int res=simxGetJointMatrix(_clientId,inData->at(1).intData[0],&matrix[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(matrix));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETJOINTPOSITION_COMMAND "simxGetJointPosition"
const int inArgs_GETJOINTPOSITION[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETJOINTPOSITION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETJOINTPOSITION,inArgs_GETJOINTPOSITION[0],LUA_GETJOINTPOSITION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float position;
		int res=simxGetJointPosition(_clientId,inData->at(1).intData[0],&position,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(position));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETLASTCMDTIME_COMMAND "simxGetLastCmdTime"
const int inArgs_GETLASTCMDTIME[]={
	1,
    sim_lua_arg_int,0,
};
int LUA_GETLASTCMDTIME_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETLASTCMDTIME,inArgs_GETLASTCMDTIME[0],LUA_GETLASTCMDTIME_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int timInMs=simxGetLastCmdTime(_clientId);
		D.pushOutData(CLuaDataItem(timInMs));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETLASTERRORS_COMMAND "simxGetLastErrors"
const int inArgs_GETLASTERRORS[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETLASTERRORS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETLASTERRORS,inArgs_GETLASTERRORS[0],LUA_GETLASTERRORS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int errorCnt;
		char* errorStrings;
		int res=simxGetLastErrors(_clientId,&errorCnt,&errorStrings,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<std::string> errs;
			int off=0;
			for (int i=0;i<errorCnt;i++)
			{
				errs.push_back(std::string(errorStrings+off));
				off+=int(strlen(errorStrings+off))+1;
			}
			D.pushOutData(CLuaDataItem(errs));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETMODELPROPERTY_COMMAND "simxGetModelProperty"
const int inArgs_GETMODELPROPERTY[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETMODELPROPERTY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETMODELPROPERTY,inArgs_GETMODELPROPERTY[0],LUA_GETMODELPROPERTY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int prop;
		int res=simxGetModelProperty(_clientId,inData->at(1).intData[0],&prop,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(prop));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTCHILD_COMMAND "simxGetObjectChild"
const int inArgs_GETOBJECTCHILD[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTCHILD_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTCHILD,inArgs_GETOBJECTCHILD[0],LUA_GETOBJECTCHILD_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int child;
		int res=simxGetObjectChild(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&child,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(child));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTFLOATPARAMETER_COMMAND "simxGetObjectFloatParameter"
const int inArgs_GETOBJECTFLOATPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTFLOATPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTFLOATPARAMETER,inArgs_GETOBJECTFLOATPARAMETER[0],LUA_GETOBJECTFLOATPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float param;
		int res=simxGetObjectFloatParameter(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&param,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(param));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTINTPARAMETER_COMMAND "simxGetObjectIntParameter"
const int inArgs_GETOBJECTINTPARAMETER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTINTPARAMETER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTINTPARAMETER,inArgs_GETOBJECTINTPARAMETER[0],LUA_GETOBJECTINTPARAMETER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int param;
		int res=simxGetObjectIntParameter(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&param,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(param));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTGROUPDATA_COMMAND "simxGetObjectGroupData"
const int inArgs_GETOBJECTGROUPDATA[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTGROUPDATA_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTGROUPDATA,inArgs_GETOBJECTGROUPDATA[0],LUA_GETOBJECTGROUPDATA_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handlesCount;
		int* handles;
		int intDataCount;
		int* intData;
		int floatDataCount;
		float* floatData;
		int stringDataCount;
		char* stringData;
		int res=simxGetObjectGroupData(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&handlesCount,&handles,&intDataCount,&intData,&floatDataCount,&floatData,&stringDataCount,&stringData,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<int> _handles;
			for (int i=0;i<handlesCount;i++)
				_handles.push_back(handles[i]);
			D.pushOutData(CLuaDataItem(_handles));

			std::vector<int> _intData;
			for (int i=0;i<intDataCount;i++)
				_intData.push_back(intData[i]);
			D.pushOutData(CLuaDataItem(_intData));

			std::vector<float> _floatData;
			for (int i=0;i<floatDataCount;i++)
				_floatData.push_back(floatData[i]);
			D.pushOutData(CLuaDataItem(_floatData));

			std::vector<std::string> str;
			int off=0;
			for (int i=0;i<stringDataCount;i++)
			{
				str.push_back(std::string(stringData+off));
				off+=int(strlen(stringData+off))+1;
			}
			D.pushOutData(CLuaDataItem(str));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTORIENTATION_COMMAND "simxGetObjectOrientation"
const int inArgs_GETOBJECTORIENTATION[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTORIENTATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTORIENTATION,inArgs_GETOBJECTORIENTATION[0],LUA_GETOBJECTORIENTATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<float> euler(3,0.0f);
		int res=simxGetObjectOrientation(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&euler[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(euler));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTPOSITION_COMMAND "simxGetObjectPosition"
const int inArgs_GETOBJECTPOSITION[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTPOSITION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTPOSITION,inArgs_GETOBJECTPOSITION[0],LUA_GETOBJECTPOSITION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<float> pos(3,0.0f);
		int res=simxGetObjectPosition(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&pos[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(pos));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTPARENT_COMMAND "simxGetObjectParent"
const int inArgs_GETOBJECTPARENT[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTPARENT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTPARENT,inArgs_GETOBJECTPARENT[0],LUA_GETOBJECTPARENT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int parent;
		int res=simxGetObjectParent(_clientId,inData->at(1).intData[0],&parent,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(parent));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTS_COMMAND "simxGetObjects"
const int inArgs_GETOBJECTS[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTS,inArgs_GETOBJECTS[0],LUA_GETOBJECTS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handlesCount;
		int* handles;
		int res=simxGetObjects(_clientId,inData->at(1).intData[0],&handlesCount,&handles,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<int> _handles;
			for (int i=0;i<handlesCount;i++)
				_handles.push_back(handles[i]);
			D.pushOutData(CLuaDataItem(_handles));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTSELECTION_COMMAND "simxGetObjectSelection"
const int inArgs_GETOBJECTSELECTION[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTSELECTION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTSELECTION,inArgs_GETOBJECTSELECTION[0],LUA_GETOBJECTSELECTION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handlesCount;
		int* handles;
		int res=simxGetObjectSelection(_clientId,&handles,&handlesCount,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			std::vector<int> _handles;
			for (int i=0;i<handlesCount;i++)
				_handles.push_back(handles[i]);
			D.pushOutData(CLuaDataItem(_handles));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETOBJECTVELOCITY_COMMAND "simxGetObjectVelocity"
const int inArgs_GETOBJECTVELOCITY[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETOBJECTVELOCITY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETOBJECTVELOCITY,inArgs_GETOBJECTVELOCITY[0],LUA_GETOBJECTVELOCITY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<float> lVel(3,0.0f);
		std::vector<float> aVel(3,0.0f);
		int res=simxGetObjectVelocity(_clientId,inData->at(1).intData[0],&lVel[0],&aVel[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(lVel));
			D.pushOutData(CLuaDataItem(aVel));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETPINGTIME_COMMAND "simxGetPingTime"
const int inArgs_GETPINGTIME[]={
	1,
    sim_lua_arg_int,0,
};
int LUA_GETPINGTIME_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETPINGTIME,inArgs_GETPINGTIME[0],LUA_GETPINGTIME_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int ptime;
		int res=simxGetPingTime(_clientId,&ptime);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(ptime));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETUIBUTTONPROPERTY_COMMAND "simxGetUIButtonProperty"
const int inArgs_GETUIBUTTONPROPERTY[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETUIBUTTONPROPERTY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETUIBUTTONPROPERTY,inArgs_GETUIBUTTONPROPERTY[0],LUA_GETUIBUTTONPROPERTY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int prop;
		int res=simxGetUIButtonProperty(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&prop,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(prop));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETUIEVENTBUTTON_COMMAND "simxGetUIEventButton"
const int inArgs_GETUIEVENTBUTTON[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETUIEVENTBUTTON_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETUIEVENTBUTTON,inArgs_GETUIEVENTBUTTON[0],LUA_GETUIEVENTBUTTON_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int butt;
		std::vector<int> auxVals(2,0);
		int res=simxGetUIEventButton(_clientId,inData->at(1).intData[0],&butt,&auxVals[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(butt));
			D.pushOutData(CLuaDataItem(auxVals));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETUIHANDLE_COMMAND "simxGetUIHandle"
const int inArgs_GETUIHANDLE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_GETUIHANDLE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETUIHANDLE,inArgs_GETUIHANDLE[0],LUA_GETUIHANDLE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int handle;
		int res=simxGetUIHandle(_clientId,inData->at(1).stringData[0].c_str(),&handle,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(handle));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETUISLIDER_COMMAND "simxGetUISlider"
const int inArgs_GETUISLIDER[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETUISLIDER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETUISLIDER,inArgs_GETUISLIDER[0],LUA_GETUISLIDER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int pos;
		int res=simxGetUISlider(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&pos,inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(pos));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETVISIONSENSORDEPTHBUFFER_COMMAND "simxGetVisionSensorDepthBuffer"
const int inArgs_GETVISIONSENSORDEPTHBUFFER[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETVISIONSENSORDEPTHBUFFER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETVISIONSENSORDEPTHBUFFER,inArgs_GETVISIONSENSORDEPTHBUFFER[0],LUA_GETVISIONSENSORDEPTHBUFFER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<int> resolution(2,0);
		float* buffer;
		int res=simxGetVisionSensorDepthBuffer(_clientId,inData->at(1).intData[0],&resolution[0],&buffer,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(std::vector<float>(buffer,buffer+resolution[0]*resolution[1])));
			D.pushOutData(CLuaDataItem(resolution));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_GETVISIONSENSORIMAGE_COMMAND "simxGetVisionSensorImage"
const int inArgs_GETVISIONSENSORIMAGE[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_GETVISIONSENSORIMAGE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_GETVISIONSENSORIMAGE,inArgs_GETVISIONSENSORIMAGE[0],LUA_GETVISIONSENSORIMAGE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		std::vector<int> resolution(2,0);
		unsigned char* img;
		int res=simxGetVisionSensorImage(_clientId,inData->at(1).intData[0],&resolution[0],&img,inData->at(2).intData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			int byteNb=3;
			if (inData->at(2).intData[0]&1)
				byteNb=1;
			D.pushOutData(CLuaDataItem((char*)img,resolution[0]*resolution[1]*byteNb));
			D.pushOutData(CLuaDataItem(resolution));
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETVISIONSENSORIMAGE_COMMAND "simxSetVisionSensorImage"
const int inArgs_SETVISIONSENSORIMAGE[]={
	5,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_charbuff,1,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_SETVISIONSENSORIMAGE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETVISIONSENSORIMAGE,inArgs_SETVISIONSENSORIMAGE[0],LUA_SETVISIONSENSORIMAGE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int options=inData->at(3).intData[0];
		int res=simxSetVisionSensorImage(_clientId,inData->at(1).intData[0],(unsigned char*)&inData->at(2).stringData[0][0],(int)inData->at(2).stringData[0].size(),options,inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_PAUSECOMMUNICATION_COMMAND "simxPauseCommunication"
const int inArgs_PAUSECOMMUNICATION[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_bool,0,
};
int LUA_PAUSECOMMUNICATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_PAUSECOMMUNICATION,inArgs_PAUSECOMMUNICATION[0],LUA_PAUSECOMMUNICATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxPauseCommunication(_clientId,inData->at(1).boolData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_PAUSESIMULATION_COMMAND "simxPauseSimulation"
const int inArgs_PAUSESIMULATION[]={
	2,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_PAUSESIMULATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_PAUSESIMULATION,inArgs_PAUSESIMULATION[0],LUA_PAUSESIMULATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxPauseSimulation(_clientId,inData->at(1).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_QUERY_COMMAND "simxQuery"
const int inArgs_QUERY[]={
	5,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_charbuff,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_QUERY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_QUERY,inArgs_QUERY[0],LUA_QUERY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char* retSignalValue;
		int retSignalLength;
		int res=simxQuery(_clientId,inData->at(1).stringData[0].c_str(),(unsigned char*)inData->at(2).stringData[0].c_str(),(int)inData->at(2).stringData[0].size(),inData->at(3).stringData[0].c_str(),&retSignalValue,&retSignalLength,inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem((char*)retSignalValue,retSignalLength));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READCOLLISION_COMMAND "simxReadCollision"
const int inArgs_READCOLLISION[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_READCOLLISION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READCOLLISION,inArgs_READCOLLISION[0],LUA_READCOLLISION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char collState;
		int res=simxReadCollision(_clientId,inData->at(1).intData[0],&collState,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(collState!=0));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READDISTANCE_COMMAND "simxReadDistance"
const int inArgs_READDISTANCE[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_READDISTANCE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READDISTANCE,inArgs_READDISTANCE[0],LUA_READDISTANCE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		float dist;
		int res=simxReadDistance(_clientId,inData->at(1).intData[0],&dist,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem(dist));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READFORCESENSOR_COMMAND "simxReadForceSensor"
const int inArgs_READFORCESENSOR[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_READFORCESENSOR_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READFORCESENSOR,inArgs_READFORCESENSOR[0],LUA_READFORCESENSOR_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char state;
		std::vector<float> force(3,0.0f);
		std::vector<float> torque(3,0.0f);
		int res=simxReadForceSensor(_clientId,inData->at(1).intData[0],&state,&force[0],&torque[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(state));
			if ((state&3)==1)
			{
				D.pushOutData(CLuaDataItem(force));
				D.pushOutData(CLuaDataItem(torque));
			}
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READPROXIMITYSENSOR_COMMAND "simxReadProximitySensor"
const int inArgs_READPROXIMITYSENSOR[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_READPROXIMITYSENSOR_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READPROXIMITYSENSOR,inArgs_READPROXIMITYSENSOR[0],LUA_READPROXIMITYSENSOR_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char state;
		std::vector<float> point(3,0.0f);
		int handle;
		std::vector<float> normal(3,0.0f);
		int res=simxReadProximitySensor(_clientId,inData->at(1).intData[0],&state,&point[0],&handle,&normal[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(state!=0));
			if (state!=0)
			{
				D.pushOutData(CLuaDataItem(point));
				D.pushOutData(CLuaDataItem(handle));
				D.pushOutData(CLuaDataItem(normal));
			}
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READSTRINGSTREAM_COMMAND "simxReadStringStream"
const int inArgs_READSTRINGSTREAM[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_int,0,
};
int LUA_READSTRINGSTREAM_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READSTRINGSTREAM,inArgs_READSTRINGSTREAM[0],LUA_READSTRINGSTREAM_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char* signalValue;
		int signalLength;
		int res=simxReadStringStream(_clientId,inData->at(1).stringData[0].c_str(),&signalValue,&signalLength,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
			D.pushOutData(CLuaDataItem((char*)signalValue,signalLength));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_WRITESTRINGSTREAM_COMMAND "simxWriteStringStream"
const int inArgs_WRITESTRINGSTREAM[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_string,0,
    sim_lua_arg_charbuff,0,
    sim_lua_arg_int,0,
};
int LUA_WRITESTRINGSTREAM_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_WRITESTRINGSTREAM,inArgs_WRITESTRINGSTREAM[0],LUA_WRITESTRINGSTREAM_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxWriteStringStream(_clientId,inData->at(1).stringData[0].c_str(),(unsigned char*)inData->at(2).stringData[0].c_str(),(int)inData->at(2).stringData[0].size(),inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_READVISIONSENSOR_COMMAND "simxReadVisionSensor"
const int inArgs_READVISIONSENSOR[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_READVISIONSENSOR_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_READVISIONSENSOR,inArgs_READVISIONSENSOR[0],LUA_READVISIONSENSOR_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		unsigned char detectionState;
		float* auxValues;
		int* auxValuesCount;
		int res=simxReadVisionSensor(_clientId,inData->at(1).intData[0],&detectionState,&auxValues,&auxValuesCount,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
		if (res==0)
		{
			D.pushOutData(CLuaDataItem(detectionState!=0));
			int packets=auxValuesCount[0];
			int off=0;
			for (int i=0;i<packets;i++)
			{
				std::vector<float> packet;
				for (int j=0;j<auxValuesCount[1+i];j++)
					packet.push_back(auxValues[off++]);
				D.pushOutData(CLuaDataItem(packet));
			}
		}
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_REMOVEMODEL_COMMAND "simxRemoveModel"
const int inArgs_REMOVEMODEL[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_REMOVEMODEL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_REMOVEMODEL,inArgs_REMOVEMODEL[0],LUA_REMOVEMODEL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxRemoveModel(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_REMOVEOBJECT_COMMAND "simxRemoveObject"
const int inArgs_REMOVEOBJECT[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_REMOVEOBJECT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_REMOVEOBJECT,inArgs_REMOVEOBJECT[0],LUA_REMOVEOBJECT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxRemoveObject(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_REMOVEUI_COMMAND "simxRemoveUI"
const int inArgs_REMOVEUI[]={
	3,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
};
int LUA_REMOVEUI_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_REMOVEUI,inArgs_REMOVEUI[0],LUA_REMOVEUI_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxRemoveUI(_clientId,inData->at(1).intData[0],inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETJOINTFORCE_COMMAND "simxSetJointForce"
const int inArgs_SETJOINTFORCE[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETJOINTFORCE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETJOINTFORCE,inArgs_SETJOINTFORCE[0],LUA_SETJOINTFORCE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetJointForce(_clientId,inData->at(1).intData[0],inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETJOINTPOSITION_COMMAND "simxSetJointPosition"
const int inArgs_SETJOINTPOSITION[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETJOINTPOSITION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETJOINTPOSITION,inArgs_SETJOINTPOSITION[0],LUA_SETJOINTPOSITION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetJointPosition(_clientId,inData->at(1).intData[0],inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETJOINTTARGETPOSITION_COMMAND "simxSetJointTargetPosition"
const int inArgs_SETJOINTTARGETPOSITION[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETJOINTTARGETPOSITION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETJOINTTARGETPOSITION,inArgs_SETJOINTTARGETPOSITION[0],LUA_SETJOINTTARGETPOSITION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetJointTargetPosition(_clientId,inData->at(1).intData[0],inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETJOINTTARGETVELOCITY_COMMAND "simxSetJointTargetVelocity"
const int inArgs_SETJOINTTARGETVELOCITY[]={
	4,
    sim_lua_arg_int,0,
    sim_lua_arg_int,0,
    sim_lua_arg_float,0,
    sim_lua_arg_int,0,
};
int LUA_SETJOINTTARGETVELOCITY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETJOINTTARGETVELOCITY,inArgs_SETJOINTTARGETVELOCITY[0],LUA_SETJOINTTARGETVELOCITY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetJointTargetVelocity(_clientId,inData->at(1).intData[0],inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETMODELPROPERTY_COMMAND "simxSetModelProperty"
const int inArgs_SETMODELPROPERTY[]={
	4,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
};
int LUA_SETMODELPROPERTY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETMODELPROPERTY,inArgs_SETMODELPROPERTY[0],LUA_SETMODELPROPERTY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetModelProperty(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETOBJECTORIENTATION_COMMAND "simxSetObjectOrientation"
const int inArgs_SETOBJECTORIENTATION[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_float|sim_lua_arg_table,3,
	sim_lua_arg_int,0,
};
int LUA_SETOBJECTORIENTATION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETOBJECTORIENTATION,inArgs_SETOBJECTORIENTATION[0],LUA_SETOBJECTORIENTATION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetObjectOrientation(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&inData->at(3).floatData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETOBJECTPOSITION_COMMAND "simxSetObjectPosition"
const int inArgs_SETOBJECTPOSITION[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_float|sim_lua_arg_table,3,
	sim_lua_arg_int,0,
};
int LUA_SETOBJECTPOSITION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETOBJECTPOSITION,inArgs_SETOBJECTPOSITION[0],LUA_SETOBJECTPOSITION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetObjectPosition(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],&inData->at(3).floatData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETOBJECTPARENT_COMMAND "simxSetObjectParent"
const int inArgs_SETOBJECTPARENT[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_bool,0,
	sim_lua_arg_int,0,
};
int LUA_SETOBJECTPARENT_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETOBJECTPARENT,inArgs_SETOBJECTPARENT[0],LUA_SETOBJECTPARENT_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetObjectParent(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).boolData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETOBJECTSELECTION_COMMAND "simxSetObjectSelection"
const int inArgs_SETOBJECTSELECTION[]={
	3,
	sim_lua_arg_int,0,
	sim_lua_arg_int|sim_lua_arg_table,0,
	sim_lua_arg_int,0,
};
int LUA_SETOBJECTSELECTION_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETOBJECTSELECTION,inArgs_SETOBJECTSELECTION[0],LUA_SETOBJECTSELECTION_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int cnt=(int)inData->at(1).intData.size();
		int* handlesPtr=NULL;
		if (cnt>0)
			handlesPtr=&inData->at(1).intData[0];
		int res=simxSetObjectSelection(_clientId,handlesPtr,cnt,inData->at(2).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETSPHERICALJOINTMATRIX_COMMAND "simxSetSphericalJointMatrix"
const int inArgs_SETSPHERICALJOINTMATRIX[]={
	4,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_float|sim_lua_arg_table,12,
	sim_lua_arg_int,0,
};
int LUA_SETSPHERICALJOINTMATRIX_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETSPHERICALJOINTMATRIX,inArgs_SETSPHERICALJOINTMATRIX[0],LUA_SETSPHERICALJOINTMATRIX_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int operationMode=inData->at(3).intData[0];
		int res=simxSetSphericalJointMatrix(_clientId,inData->at(1).intData[0],&inData->at(2).floatData[0],inData->at(3).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETUIBUTTONLABEL_COMMAND "simxSetUIButtonLabel"
const int inArgs_SETUIBUTTONLABEL[]={
	6,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_string,0,
	sim_lua_arg_string,0,
	sim_lua_arg_int,0,
};
int LUA_SETUIBUTTONLABEL_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETUIBUTTONLABEL,inArgs_SETUIBUTTONLABEL[0],LUA_SETUIBUTTONLABEL_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetUIButtonLabel(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).stringData[0].c_str(),inData->at(4).stringData[0].c_str(),inData->at(5).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETUIBUTTONPROPERTY_COMMAND "simxSetUIButtonProperty"
const int inArgs_SETUIBUTTONPROPERTY[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
};
int LUA_SETUIBUTTONPROPERTY_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETUIBUTTONPROPERTY,inArgs_SETUIBUTTONPROPERTY[0],LUA_SETUIBUTTONPROPERTY_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetUIButtonProperty(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).intData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SETUISLIDER_COMMAND "simxSetUISlider"
const int inArgs_SETUISLIDER[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
};
int LUA_SETUISLIDER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SETUISLIDER,inArgs_SETUISLIDER[0],LUA_SETUISLIDER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSetUISlider(_clientId,inData->at(1).intData[0],inData->at(2).intData[0],inData->at(3).intData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SYNCHRONOUS_COMMAND "simxSynchronous"
const int inArgs_SYNCHRONOUS[]={
	2,
	sim_lua_arg_int,0,
	sim_lua_arg_bool,0,
};
int LUA_SYNCHRONOUS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SYNCHRONOUS,inArgs_SYNCHRONOUS[0],LUA_SYNCHRONOUS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSynchronous(_clientId,inData->at(1).boolData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_SYNCHRONOUSTRIGGER_COMMAND "simxSynchronousTrigger"
const int inArgs_SYNCHRONOUSTRIGGER[]={
	1,
	sim_lua_arg_int,0,
};
int LUA_SYNCHRONOUSTRIGGER_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_SYNCHRONOUSTRIGGER,inArgs_SYNCHRONOUSTRIGGER[0],LUA_SYNCHRONOUSTRIGGER_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxSynchronousTrigger(_clientId);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_TRANSFERFILE_COMMAND "simxTransferFile"
const int inArgs_TRANSFERFILE[]={
	5,
	sim_lua_arg_int,0,
	sim_lua_arg_string,0,
	sim_lua_arg_string,0,
	sim_lua_arg_int,0,
	sim_lua_arg_int,0,
};
int LUA_TRANSFERFILE_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_TRANSFERFILE,inArgs_TRANSFERFILE[0],LUA_TRANSFERFILE_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		int _clientId=inData->at(0).intData[0];
		int res=simxTransferFile(_clientId,inData->at(1).stringData[0].c_str(),inData->at(2).stringData[0].c_str(),inData->at(3).intData[0],inData->at(4).intData[0]);
		D.pushOutData(CLuaDataItem(res));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_PACKINTS_COMMAND "simxPackInts"
const int inArgs_PACKINTS[]={
	1,
	sim_lua_arg_int|sim_lua_arg_table,1,
};
int LUA_PACKINTS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_PACKINTS,inArgs_PACKINTS[0],LUA_PACKINTS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		D.pushOutData(CLuaDataItem((char*)&inData->at(0).intData[0],(unsigned int)sizeof(int)*inData->at(0).intData.size()));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_PACKFLOATS_COMMAND "simxPackFloats"
const int inArgs_PACKFLOATS[]={
	1,
	sim_lua_arg_float|sim_lua_arg_table,1,
};
int LUA_PACKFLOATS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_PACKFLOATS,inArgs_PACKFLOATS[0],LUA_PACKFLOATS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		D.pushOutData(CLuaDataItem((char*)&inData->at(0).floatData[0],(unsigned int)sizeof(float)*inData->at(0).floatData.size()));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_UNPACKINTS_COMMAND "simxUnpackInts"
const int inArgs_UNPACKINTS[]={
	1,
	sim_lua_arg_charbuff,4,
};
int LUA_UNPACKINTS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_UNPACKINTS,inArgs_UNPACKINTS[0],LUA_UNPACKINTS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		std::vector<int> table;
		for (unsigned int i=0;i<inData->at(0).stringData[0].size()/4;i++)
			table.push_back(((int*)(&inData->at(0).stringData[0][0]))[i]);
		D.pushOutData(CLuaDataItem(table));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
#define LUA_UNPACKFLOATS_COMMAND "simxUnpackFloats"
const int inArgs_UNPACKFLOATS[]={
	1,
	sim_lua_arg_charbuff,4,
};
int LUA_UNPACKFLOATS_CALLBACK(lua_State* L)
{
	CLuaData D;
	if (D.readDataFromLua(L,inArgs_UNPACKFLOATS,inArgs_UNPACKFLOATS[0],LUA_UNPACKFLOATS_COMMAND))
	{
		std::vector<CLuaDataItem>* inData=D.getInDataPtr();
		std::vector<float> table;
		for (unsigned int i=0;i<inData->at(0).stringData[0].size()/4;i++)
			table.push_back(((float*)(&inData->at(0).stringData[0][0]))[i]);
		D.pushOutData(CLuaDataItem(table));
	}
	return(D.writeDataToLua(L));
}
// --------------------------------------------------------------------------------------

void registerVariable(lua_State *L,const char* a,const char* b)
{
	std::string tmp(a);
	tmp+="="+std::string(b);
	luaL_dostring(L,tmp.c_str());
}

#ifdef _WIN32
extern "C" __declspec(dllexport) int luaopen_remoteApiLua(lua_State *L) {
#else
extern "C" int luaopen_remoteApiLua(lua_State *L) {
#endif

	lua_register(L,LUA_START_COMMAND,LUA_START_CALLBACK);
	lua_register(L,LUA_FINISH_COMMAND,LUA_FINISH_CALLBACK);
	lua_register(L,LUA_ADDSTATUSBARMESSAGE_COMMAND,LUA_ADDSTATUSBARMESSAGE_CALLBACK);
	lua_register(L,LUA_AUXILIARYCONSOLECLOSE_COMMAND,LUA_AUXILIARYCONSOLECLOSE_CALLBACK);
	lua_register(L,LUA_AUXILIARYCONSOLEOPEN_COMMAND,LUA_AUXILIARYCONSOLEOPEN_CALLBACK);
	lua_register(L,LUA_AUXILIARYCONSOLEPRINT_COMMAND,LUA_AUXILIARYCONSOLEPRINT_CALLBACK);
	lua_register(L,LUA_AUXILIARYCONSOLESHOW_COMMAND,LUA_AUXILIARYCONSOLESHOW_CALLBACK);
	lua_register(L,LUA_BREAKFORCESENSOR_COMMAND,LUA_BREAKFORCESENSOR_CALLBACK);
	lua_register(L,LUA_CLEARFLOATSIGNAL_COMMAND,LUA_CLEARFLOATSIGNAL_CALLBACK);
	lua_register(L,LUA_CLEARINTEGERSIGNAL_COMMAND,LUA_CLEARINTEGERSIGNAL_CALLBACK);
	lua_register(L,LUA_CLEARSTRINGSIGNAL_COMMAND,LUA_CLEARSTRINGSIGNAL_CALLBACK);
	lua_register(L,LUA_GETOBJECTHANDLE_COMMAND,LUA_GETOBJECTHANDLE_CALLBACK);
	lua_register(L,LUA_CLOSESCENE_COMMAND,LUA_CLOSESCENE_CALLBACK);
	lua_register(L,LUA_COPYPASTEOBJECTS_COMMAND,LUA_COPYPASTEOBJECTS_CALLBACK);
	lua_register(L,LUA_LOADSCENE_COMMAND,LUA_LOADSCENE_CALLBACK);
	lua_register(L,LUA_LOADMODEL_COMMAND,LUA_LOADMODEL_CALLBACK);
	lua_register(L,LUA_LOADUI_COMMAND,LUA_LOADUI_CALLBACK);
	lua_register(L,LUA_SETBOOLEANPARAMETER_COMMAND,LUA_SETBOOLEANPARAMETER_CALLBACK);
	lua_register(L,LUA_STARTSIMULATION_COMMAND,LUA_STARTSIMULATION_CALLBACK);
	lua_register(L,LUA_STOPSIMULATION_COMMAND,LUA_STOPSIMULATION_CALLBACK);
	lua_register(L,LUA_SETFLOATINGPARAMETER_COMMAND,LUA_SETFLOATINGPARAMETER_CALLBACK);
	lua_register(L,LUA_SETINTEGERPARAMETER_COMMAND,LUA_SETINTEGERPARAMETER_CALLBACK);
	lua_register(L,LUA_SETARRAYPARAMETER_COMMAND,LUA_SETARRAYPARAMETER_CALLBACK);
	lua_register(L,LUA_GETBOOLEANPARAMETER_COMMAND,LUA_GETBOOLEANPARAMETER_CALLBACK);
	lua_register(L,LUA_GETFLOATINGPARAMETER_COMMAND,LUA_GETFLOATINGPARAMETER_CALLBACK);
	lua_register(L,LUA_GETINTEGERPARAMETER_COMMAND,LUA_GETINTEGERPARAMETER_CALLBACK);
	lua_register(L,LUA_GETARRAYPARAMETER_COMMAND,LUA_GETARRAYPARAMETER_CALLBACK);
	lua_register(L,LUA_GETSTRINGPARAMETER_COMMAND,LUA_GETSTRINGPARAMETER_CALLBACK);
	lua_register(L,LUA_SETFLOATSIGNAL_COMMAND,LUA_SETFLOATSIGNAL_CALLBACK);
	lua_register(L,LUA_SETINTEGERSIGNAL_COMMAND,LUA_SETINTEGERSIGNAL_CALLBACK);
	lua_register(L,LUA_SETSTRINGSIGNAL_COMMAND,LUA_SETSTRINGSIGNAL_CALLBACK);
	lua_register(L,LUA_GETFLOATSIGNAL_COMMAND,LUA_GETFLOATSIGNAL_CALLBACK);
	lua_register(L,LUA_GETINTEGERSIGNAL_COMMAND,LUA_GETINTEGERSIGNAL_CALLBACK);
	lua_register(L,LUA_GETSTRINGSIGNAL_COMMAND,LUA_GETSTRINGSIGNAL_CALLBACK);
	lua_register(L,LUA_CREATEDUMMY_COMMAND,LUA_CREATEDUMMY_CALLBACK);
	lua_register(L,LUA_DISPLAYDIALOG_COMMAND,LUA_DISPLAYDIALOG_CALLBACK);
	lua_register(L,LUA_ENDDIALOG_COMMAND,LUA_ENDDIALOG_CALLBACK);
	lua_register(L,LUA_GETDIALOGINPUT_COMMAND,LUA_GETDIALOGINPUT_CALLBACK);
	lua_register(L,LUA_GETDIALOGRESULT_COMMAND,LUA_GETDIALOGRESULT_CALLBACK);
	lua_register(L,LUA_ERASEFILE_COMMAND,LUA_ERASEFILE_CALLBACK);
	lua_register(L,LUA_GETCOLLISIONHANDLE_COMMAND,LUA_GETCOLLISIONHANDLE_CALLBACK);
	lua_register(L,LUA_GETCONNECTIONID_COMMAND,LUA_GETCONNECTIONID_CALLBACK);
	lua_register(L,LUA_GETDISTANCEHANDLE_COMMAND,LUA_GETDISTANCEHANDLE_CALLBACK);
	lua_register(L,LUA_GETCOLLECTIONHANDLE_COMMAND,LUA_GETCOLLECTIONHANDLE_CALLBACK);
	lua_register(L,LUA_GETINMESSAGEINFO_COMMAND,LUA_GETINMESSAGEINFO_CALLBACK);
	lua_register(L,LUA_GETOUTMESSAGEINFO_COMMAND,LUA_GETOUTMESSAGEINFO_CALLBACK);
	lua_register(L,LUA_GETJOINTFORCE_COMMAND,LUA_GETJOINTFORCE_CALLBACK);
	lua_register(L,LUA_GETJOINTMATRIX_COMMAND,LUA_GETJOINTMATRIX_CALLBACK);
	lua_register(L,LUA_GETJOINTPOSITION_COMMAND,LUA_GETJOINTPOSITION_CALLBACK);
	lua_register(L,LUA_GETLASTCMDTIME_COMMAND,LUA_GETLASTCMDTIME_CALLBACK);
	lua_register(L,LUA_GETLASTERRORS_COMMAND,LUA_GETLASTERRORS_CALLBACK);
	lua_register(L,LUA_GETMODELPROPERTY_COMMAND,LUA_GETMODELPROPERTY_CALLBACK);
	lua_register(L,LUA_GETOBJECTCHILD_COMMAND,LUA_GETOBJECTCHILD_CALLBACK);
	lua_register(L,LUA_GETOBJECTFLOATPARAMETER_COMMAND,LUA_GETOBJECTFLOATPARAMETER_CALLBACK);
	lua_register(L,LUA_GETOBJECTINTPARAMETER_COMMAND,LUA_GETOBJECTINTPARAMETER_CALLBACK);
	lua_register(L,LUA_GETOBJECTGROUPDATA_COMMAND,LUA_GETOBJECTGROUPDATA_CALLBACK);
	lua_register(L,LUA_GETOBJECTORIENTATION_COMMAND,LUA_GETOBJECTORIENTATION_CALLBACK);
	lua_register(L,LUA_GETOBJECTPOSITION_COMMAND,LUA_GETOBJECTPOSITION_CALLBACK);
	lua_register(L,LUA_GETOBJECTPARENT_COMMAND,LUA_GETOBJECTPARENT_CALLBACK);
	lua_register(L,LUA_GETOBJECTS_COMMAND,LUA_GETOBJECTS_CALLBACK);
	lua_register(L,LUA_GETOBJECTSELECTION_COMMAND,LUA_GETOBJECTSELECTION_CALLBACK);
	lua_register(L,LUA_GETOBJECTVELOCITY_COMMAND,LUA_GETOBJECTVELOCITY_CALLBACK);
	lua_register(L,LUA_GETPINGTIME_COMMAND,LUA_GETPINGTIME_CALLBACK);
	lua_register(L,LUA_GETUIBUTTONPROPERTY_COMMAND,LUA_GETUIBUTTONPROPERTY_CALLBACK);
	lua_register(L,LUA_GETUIEVENTBUTTON_COMMAND,LUA_GETUIEVENTBUTTON_CALLBACK);
	lua_register(L,LUA_GETUIHANDLE_COMMAND,LUA_GETUIHANDLE_CALLBACK);
	lua_register(L,LUA_GETUISLIDER_COMMAND,LUA_GETUISLIDER_CALLBACK);
	lua_register(L,LUA_GETVISIONSENSORDEPTHBUFFER_COMMAND,LUA_GETVISIONSENSORDEPTHBUFFER_CALLBACK);
	lua_register(L,LUA_GETVISIONSENSORIMAGE_COMMAND,LUA_GETVISIONSENSORIMAGE_CALLBACK);
	lua_register(L,LUA_SETVISIONSENSORIMAGE_COMMAND,LUA_SETVISIONSENSORIMAGE_CALLBACK);
	lua_register(L,LUA_PAUSECOMMUNICATION_COMMAND,LUA_PAUSECOMMUNICATION_CALLBACK);
	lua_register(L,LUA_PAUSESIMULATION_COMMAND,LUA_PAUSESIMULATION_CALLBACK);
	lua_register(L,LUA_QUERY_COMMAND,LUA_QUERY_CALLBACK);
	lua_register(L,LUA_READCOLLISION_COMMAND,LUA_READCOLLISION_CALLBACK);
	lua_register(L,LUA_READDISTANCE_COMMAND,LUA_READDISTANCE_CALLBACK);
	lua_register(L,LUA_READFORCESENSOR_COMMAND,LUA_READFORCESENSOR_CALLBACK);
	lua_register(L,LUA_READPROXIMITYSENSOR_COMMAND,LUA_READPROXIMITYSENSOR_CALLBACK);
	lua_register(L,LUA_READSTRINGSTREAM_COMMAND,LUA_READSTRINGSTREAM_CALLBACK);
	lua_register(L,LUA_WRITESTRINGSTREAM_COMMAND,LUA_WRITESTRINGSTREAM_CALLBACK);
	lua_register(L,LUA_READVISIONSENSOR_COMMAND,LUA_READVISIONSENSOR_CALLBACK);
	lua_register(L,LUA_REMOVEMODEL_COMMAND,LUA_REMOVEMODEL_CALLBACK);
	lua_register(L,LUA_REMOVEOBJECT_COMMAND,LUA_REMOVEOBJECT_CALLBACK);
	lua_register(L,LUA_REMOVEUI_COMMAND,LUA_REMOVEUI_CALLBACK);
	lua_register(L,LUA_SETJOINTFORCE_COMMAND,LUA_SETJOINTFORCE_CALLBACK);
	lua_register(L,LUA_SETJOINTPOSITION_COMMAND,LUA_SETJOINTPOSITION_CALLBACK);
	lua_register(L,LUA_SETJOINTTARGETPOSITION_COMMAND,LUA_SETJOINTTARGETPOSITION_CALLBACK);
	lua_register(L,LUA_SETJOINTTARGETVELOCITY_COMMAND,LUA_SETJOINTTARGETVELOCITY_CALLBACK);
	lua_register(L,LUA_SETMODELPROPERTY_COMMAND,LUA_SETMODELPROPERTY_CALLBACK);
	lua_register(L,LUA_SETOBJECTORIENTATION_COMMAND,LUA_SETOBJECTORIENTATION_CALLBACK);
	lua_register(L,LUA_SETOBJECTPOSITION_COMMAND,LUA_SETOBJECTPOSITION_CALLBACK);
	lua_register(L,LUA_SETOBJECTPARENT_COMMAND,LUA_SETOBJECTPARENT_CALLBACK);
	lua_register(L,LUA_SETOBJECTSELECTION_COMMAND,LUA_SETOBJECTSELECTION_CALLBACK);
	lua_register(L,LUA_SETSPHERICALJOINTMATRIX_COMMAND,LUA_SETSPHERICALJOINTMATRIX_CALLBACK);
	lua_register(L,LUA_SETUIBUTTONLABEL_COMMAND,LUA_SETUIBUTTONLABEL_CALLBACK);
	lua_register(L,LUA_SETUIBUTTONPROPERTY_COMMAND,LUA_SETUIBUTTONPROPERTY_CALLBACK);
	lua_register(L,LUA_SETUISLIDER_COMMAND,LUA_SETUISLIDER_CALLBACK);
	lua_register(L,LUA_SYNCHRONOUS_COMMAND,LUA_SYNCHRONOUS_CALLBACK);
	lua_register(L,LUA_SYNCHRONOUSTRIGGER_COMMAND,LUA_SYNCHRONOUSTRIGGER_CALLBACK);
	lua_register(L,LUA_TRANSFERFILE_COMMAND,LUA_TRANSFERFILE_CALLBACK);

	lua_register(L,LUA_PACKINTS_COMMAND,LUA_PACKINTS_CALLBACK);
	lua_register(L,LUA_PACKFLOATS_COMMAND,LUA_PACKFLOATS_CALLBACK);
	lua_register(L,LUA_UNPACKINTS_COMMAND,LUA_UNPACKINTS_CALLBACK);
	lua_register(L,LUA_UNPACKFLOATS_COMMAND,LUA_UNPACKFLOATS_CALLBACK);

	registerVariable(L,"sim_object_shape_type",(boost::lexical_cast<std::string>(int(sim_object_shape_type))).c_str());
	registerVariable(L,"sim_object_joint_type",(boost::lexical_cast<std::string>(int(sim_object_joint_type))).c_str());
	registerVariable(L,"sim_object_graph_type",(boost::lexical_cast<std::string>(int(sim_object_graph_type))).c_str());
	registerVariable(L,"sim_object_camera_type",(boost::lexical_cast<std::string>(int(sim_object_camera_type))).c_str());
	registerVariable(L,"sim_object_dummy_type",(boost::lexical_cast<std::string>(int(sim_object_dummy_type))).c_str());
	registerVariable(L,"sim_object_proximitysensor_type",(boost::lexical_cast<std::string>(int(sim_object_proximitysensor_type))).c_str());
	registerVariable(L,"sim_object_reserved1",(boost::lexical_cast<std::string>(int(sim_object_reserved1))).c_str());
	registerVariable(L,"sim_object_reserved2",(boost::lexical_cast<std::string>(int(sim_object_reserved2))).c_str());
	registerVariable(L,"sim_object_path_type",(boost::lexical_cast<std::string>(int(sim_object_path_type))).c_str());
	registerVariable(L,"sim_object_visionsensor_type",(boost::lexical_cast<std::string>(int(sim_object_visionsensor_type))).c_str());
	registerVariable(L,"sim_object_volume_type",(boost::lexical_cast<std::string>(int(sim_object_volume_type))).c_str());
	registerVariable(L,"sim_object_mill_type",(boost::lexical_cast<std::string>(int(sim_object_mill_type))).c_str());
	registerVariable(L,"sim_object_forcesensor_type",(boost::lexical_cast<std::string>(int(sim_object_forcesensor_type))).c_str());
	registerVariable(L,"sim_object_light_type",(boost::lexical_cast<std::string>(int(sim_object_light_type))).c_str());
	registerVariable(L,"sim_object_mirror_type",(boost::lexical_cast<std::string>(int(sim_object_mirror_type))).c_str());
	registerVariable(L,"sim_object_type_end",(boost::lexical_cast<std::string>(int(sim_object_type_end))).c_str());

	registerVariable(L,"sim_appobj_object_type",(boost::lexical_cast<std::string>(int(sim_appobj_object_type))).c_str());
	registerVariable(L,"sim_appobj_collision_type",(boost::lexical_cast<std::string>(int(sim_appobj_collision_type))).c_str());
	registerVariable(L,"sim_appobj_distance_type",(boost::lexical_cast<std::string>(int(sim_appobj_distance_type))).c_str());
	registerVariable(L,"sim_appobj_simulation_type",(boost::lexical_cast<std::string>(int(sim_appobj_simulation_type))).c_str());
	registerVariable(L,"sim_appobj_ik_type",(boost::lexical_cast<std::string>(int(sim_appobj_ik_type))).c_str());
	registerVariable(L,"sim_appobj_constraintsolver_type",(boost::lexical_cast<std::string>(int(sim_appobj_constraintsolver_type))).c_str());
	registerVariable(L,"sim_appobj_collection_type",(boost::lexical_cast<std::string>(int(sim_appobj_collection_type))).c_str());
	registerVariable(L,"sim_appobj_ui_type",(boost::lexical_cast<std::string>(int(sim_appobj_ui_type))).c_str());
	registerVariable(L,"sim_appobj_script_type",(boost::lexical_cast<std::string>(int(sim_appobj_script_type))).c_str());
	registerVariable(L,"sim_appobj_pathplanning_type",(boost::lexical_cast<std::string>(int(sim_appobj_pathplanning_type))).c_str());
	registerVariable(L,"sim_appobj_texture_type",(boost::lexical_cast<std::string>(int(sim_appobj_texture_type))).c_str());
	registerVariable(L,"sim_appobj_motionplanning_type",(boost::lexical_cast<std::string>(int(sim_appobj_motionplanning_type))).c_str());

	registerVariable(L,"sim_light_omnidirectional_subtype",(boost::lexical_cast<std::string>(int(sim_light_omnidirectional_subtype))).c_str());
	registerVariable(L,"sim_light_spot_subtype",(boost::lexical_cast<std::string>(int(sim_light_spot_subtype))).c_str());
	registerVariable(L,"sim_light_directional_subtype",(boost::lexical_cast<std::string>(int(sim_light_directional_subtype))).c_str());
	registerVariable(L,"sim_joint_revolute_subtype",(boost::lexical_cast<std::string>(int(sim_joint_revolute_subtype))).c_str());
	registerVariable(L,"sim_joint_prismatic_subtype",(boost::lexical_cast<std::string>(int(sim_joint_prismatic_subtype))).c_str());
	registerVariable(L,"sim_joint_spherical_subtype",(boost::lexical_cast<std::string>(int(sim_joint_spherical_subtype))).c_str());
	registerVariable(L,"sim_shape_simpleshape_subtype",(boost::lexical_cast<std::string>(int(sim_shape_simpleshape_subtype))).c_str());
	registerVariable(L,"sim_shape_multishape_subtype",(boost::lexical_cast<std::string>(int(sim_shape_multishape_subtype))).c_str());
	registerVariable(L,"sim_proximitysensor_pyramid_subtype",(boost::lexical_cast<std::string>(int(sim_proximitysensor_pyramid_subtype))).c_str());
	registerVariable(L,"sim_proximitysensor_cylinder_subtype",(boost::lexical_cast<std::string>(int(sim_proximitysensor_cylinder_subtype))).c_str());
	registerVariable(L,"sim_proximitysensor_disc_subtype",(boost::lexical_cast<std::string>(int(sim_proximitysensor_disc_subtype))).c_str());
	registerVariable(L,"sim_proximitysensor_cone_subtype",(boost::lexical_cast<std::string>(int(sim_proximitysensor_cone_subtype))).c_str());
	registerVariable(L,"sim_proximitysensor_ray_subtype",(boost::lexical_cast<std::string>(int(sim_proximitysensor_ray_subtype))).c_str());
	registerVariable(L,"sim_mill_pyramid_subtype",(boost::lexical_cast<std::string>(int(sim_mill_pyramid_subtype))).c_str());
	registerVariable(L,"sim_mill_cylinder_subtype",(boost::lexical_cast<std::string>(int(sim_mill_cylinder_subtype))).c_str());
	registerVariable(L,"sim_mill_disc_subtype",(boost::lexical_cast<std::string>(int(sim_mill_disc_subtype))).c_str());
	registerVariable(L,"sim_mill_cone_subtype",(boost::lexical_cast<std::string>(int(sim_mill_cone_subtype))).c_str());
	registerVariable(L,"sim_object_no_subtype",(boost::lexical_cast<std::string>(int(sim_object_no_subtype))).c_str());

	registerVariable(L,"sim_objectspecialproperty_collidable",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_collidable))).c_str());
	registerVariable(L,"sim_objectspecialproperty_measurable",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_measurable))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_ultrasonic",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_ultrasonic))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_infrared",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_infrared))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_laser",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_laser))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_inductive",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_inductive))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_capacitive",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_capacitive))).c_str());
	registerVariable(L,"sim_objectspecialproperty_renderable",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_renderable))).c_str());
	registerVariable(L,"sim_objectspecialproperty_detectable_all",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_detectable_all))).c_str());
	registerVariable(L,"sim_objectspecialproperty_cuttable",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_cuttable))).c_str());
	registerVariable(L,"sim_objectspecialproperty_pathplanning_ignored",(boost::lexical_cast<std::string>(int(sim_objectspecialproperty_pathplanning_ignored))).c_str());

	registerVariable(L,"sim_modelproperty_not_collidable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_collidable))).c_str());
	registerVariable(L,"sim_modelproperty_not_measurable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_measurable))).c_str());
	registerVariable(L,"sim_modelproperty_not_renderable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_renderable))).c_str());
	registerVariable(L,"sim_modelproperty_not_detectable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_detectable))).c_str());
	registerVariable(L,"sim_modelproperty_not_cuttable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_cuttable))).c_str());
	registerVariable(L,"sim_modelproperty_not_dynamic",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_dynamic))).c_str());
	registerVariable(L,"sim_modelproperty_not_respondable",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_respondable))).c_str());
	registerVariable(L,"sim_modelproperty_not_reset",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_reset))).c_str());
	registerVariable(L,"sim_modelproperty_not_visible",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_visible))).c_str());
	registerVariable(L,"sim_modelproperty_scripts_inactive",(boost::lexical_cast<std::string>(int(sim_modelproperty_scripts_inactive))).c_str());
	registerVariable(L,"sim_modelproperty_not_model",(boost::lexical_cast<std::string>(int(sim_modelproperty_not_model))).c_str());

	registerVariable(L,"sim_objectproperty_collapsed",(boost::lexical_cast<std::string>(int(sim_objectproperty_collapsed))).c_str());
	registerVariable(L,"sim_objectproperty_selectable",(boost::lexical_cast<std::string>(int(sim_objectproperty_selectable))).c_str());
	registerVariable(L,"sim_objectproperty_selectmodelbaseinstead",(boost::lexical_cast<std::string>(int(sim_objectproperty_selectmodelbaseinstead))).c_str());
	registerVariable(L,"sim_objectproperty_dontshowasinsidemodel",(boost::lexical_cast<std::string>(int(sim_objectproperty_dontshowasinsidemodel))).c_str());
	registerVariable(L,"sim_objectproperty_canupdatedna",(boost::lexical_cast<std::string>(int(sim_objectproperty_canupdatedna))).c_str());
	registerVariable(L,"sim_objectproperty_selectinvisible",(boost::lexical_cast<std::string>(int(sim_objectproperty_selectinvisible))).c_str());
	registerVariable(L,"sim_objectproperty_depthinvisible",(boost::lexical_cast<std::string>(int(sim_objectproperty_depthinvisible))).c_str());

	registerVariable(L,"sim_ui_property_visible",(boost::lexical_cast<std::string>(int(sim_ui_property_visible))).c_str());
	registerVariable(L,"sim_ui_property_visibleduringsimulationonly",(boost::lexical_cast<std::string>(int(sim_ui_property_visibleduringsimulationonly))).c_str());
	registerVariable(L,"sim_ui_property_moveable",(boost::lexical_cast<std::string>(int(sim_ui_property_moveable))).c_str());
	registerVariable(L,"sim_ui_property_relativetoleftborder",(boost::lexical_cast<std::string>(int(sim_ui_property_relativetoleftborder))).c_str());
	registerVariable(L,"sim_ui_property_relativetotopborder",(boost::lexical_cast<std::string>(int(sim_ui_property_relativetotopborder))).c_str());
	registerVariable(L,"sim_ui_property_fixedwidthfont",(boost::lexical_cast<std::string>(int(sim_ui_property_fixedwidthfont))).c_str());
	registerVariable(L,"sim_ui_property_systemblock",(boost::lexical_cast<std::string>(int(sim_ui_property_systemblock))).c_str());
	registerVariable(L,"sim_ui_property_settocenter",(boost::lexical_cast<std::string>(int(sim_ui_property_settocenter))).c_str());
	registerVariable(L,"sim_ui_property_rolledup",(boost::lexical_cast<std::string>(int(sim_ui_property_rolledup))).c_str());
	registerVariable(L,"sim_ui_property_selectassociatedobject",(boost::lexical_cast<std::string>(int(sim_ui_property_selectassociatedobject))).c_str());
	registerVariable(L,"sim_ui_property_visiblewhenobjectselected",(boost::lexical_cast<std::string>(int(sim_ui_property_visiblewhenobjectselected))).c_str());
	registerVariable(L,"sim_ui_property_systemblockcanmovetofront",(boost::lexical_cast<std::string>(int(sim_ui_property_systemblockcanmovetofront))).c_str());
	registerVariable(L,"sim_ui_property_pauseactive",(boost::lexical_cast<std::string>(int(sim_ui_property_pauseactive))).c_str());

	registerVariable(L,"sim_buttonproperty_button",(boost::lexical_cast<std::string>(int(sim_buttonproperty_button))).c_str());
	registerVariable(L,"sim_buttonproperty_label",(boost::lexical_cast<std::string>(int(sim_buttonproperty_label))).c_str());
	registerVariable(L,"sim_buttonproperty_slider",(boost::lexical_cast<std::string>(int(sim_buttonproperty_slider))).c_str());
	registerVariable(L,"sim_buttonproperty_editbox",(boost::lexical_cast<std::string>(int(sim_buttonproperty_editbox))).c_str());
	registerVariable(L,"sim_buttonproperty_staydown",(boost::lexical_cast<std::string>(int(sim_buttonproperty_staydown))).c_str());
	registerVariable(L,"sim_buttonproperty_enabled",(boost::lexical_cast<std::string>(int(sim_buttonproperty_enabled))).c_str());
	registerVariable(L,"sim_buttonproperty_borderless",(boost::lexical_cast<std::string>(int(sim_buttonproperty_borderless))).c_str());
	registerVariable(L,"sim_buttonproperty_horizontallycentered",(boost::lexical_cast<std::string>(int(sim_buttonproperty_horizontallycentered))).c_str());
	registerVariable(L,"sim_buttonproperty_ignoremouse",(boost::lexical_cast<std::string>(int(sim_buttonproperty_ignoremouse))).c_str());
	registerVariable(L,"sim_buttonproperty_isdown",(boost::lexical_cast<std::string>(int(sim_buttonproperty_isdown))).c_str());
	registerVariable(L,"sim_buttonproperty_transparent",(boost::lexical_cast<std::string>(int(sim_buttonproperty_transparent))).c_str());
	registerVariable(L,"sim_buttonproperty_nobackgroundcolor",(boost::lexical_cast<std::string>(int(sim_buttonproperty_nobackgroundcolor))).c_str());
	registerVariable(L,"sim_buttonproperty_rollupaction",(boost::lexical_cast<std::string>(int(sim_buttonproperty_rollupaction))).c_str());
	registerVariable(L,"sim_buttonproperty_closeaction",(boost::lexical_cast<std::string>(int(sim_buttonproperty_closeaction))).c_str());
	registerVariable(L,"sim_buttonproperty_verticallycentered",(boost::lexical_cast<std::string>(int(sim_buttonproperty_verticallycentered))).c_str());
	registerVariable(L,"sim_buttonproperty_downupevent",(boost::lexical_cast<std::string>(int(sim_buttonproperty_downupevent))).c_str());

	registerVariable(L,"sim_handle_all",(boost::lexical_cast<std::string>(int(sim_handle_all))).c_str());
	registerVariable(L,"sim_handle_all_except_explicit",(boost::lexical_cast<std::string>(int(sim_handle_all_except_explicit))).c_str());
	registerVariable(L,"sim_handle_self",(boost::lexical_cast<std::string>(int(sim_handle_self))).c_str());
	registerVariable(L,"sim_handle_main_script",(boost::lexical_cast<std::string>(int(sim_handle_main_script))).c_str());
	registerVariable(L,"sim_handle_tree",(boost::lexical_cast<std::string>(int(sim_handle_tree))).c_str());
	registerVariable(L,"sim_handle_chain",(boost::lexical_cast<std::string>(int(sim_handle_chain))).c_str());
	registerVariable(L,"sim_handle_single",(boost::lexical_cast<std::string>(int(sim_handle_single))).c_str());
	registerVariable(L,"sim_handle_default",(boost::lexical_cast<std::string>(int(sim_handle_default))).c_str());
	registerVariable(L,"sim_handle_all_except_self",(boost::lexical_cast<std::string>(int(sim_handle_all_except_self))).c_str());
	registerVariable(L,"sim_handle_parent",(boost::lexical_cast<std::string>(int(sim_handle_parent))).c_str());
	registerVariable(L,"sim_handle_scene",(boost::lexical_cast<std::string>(int(sim_handle_scene))).c_str());

	registerVariable(L,"sim_handleflag_assembly",(boost::lexical_cast<std::string>(int(sim_handleflag_assembly))).c_str());
	registerVariable(L,"sim_handleflag_model",(boost::lexical_cast<std::string>(int(sim_handleflag_model))).c_str());
	registerVariable(L,"sim_handleflag_rawvalue",(boost::lexical_cast<std::string>(int(sim_handleflag_rawvalue))).c_str());

	registerVariable(L,"sim_dlgstyle_message",(boost::lexical_cast<std::string>(int(sim_dlgstyle_message))).c_str());
	registerVariable(L,"sim_dlgstyle_input",(boost::lexical_cast<std::string>(int(sim_dlgstyle_input))).c_str());
	registerVariable(L,"sim_dlgstyle_ok",(boost::lexical_cast<std::string>(int(sim_dlgstyle_ok))).c_str());
	registerVariable(L,"sim_dlgstyle_ok_cancel",(boost::lexical_cast<std::string>(int(sim_dlgstyle_ok_cancel))).c_str());
	registerVariable(L,"sim_dlgstyle_yes_no",(boost::lexical_cast<std::string>(int(sim_dlgstyle_yes_no))).c_str());
	registerVariable(L,"sim_dlgstyle_dont_center",(boost::lexical_cast<std::string>(int(sim_dlgstyle_dont_center))).c_str());

	registerVariable(L,"sim_dlgret_still_open",(boost::lexical_cast<std::string>(int(sim_dlgret_still_open))).c_str());
	registerVariable(L,"sim_dlgret_ok",(boost::lexical_cast<std::string>(int(sim_dlgret_ok))).c_str());
	registerVariable(L,"sim_dlgret_cancel",(boost::lexical_cast<std::string>(int(sim_dlgret_cancel))).c_str());
	registerVariable(L,"sim_dlgret_yes",(boost::lexical_cast<std::string>(int(sim_dlgret_yes))).c_str());
	registerVariable(L,"sim_dlgret_no",(boost::lexical_cast<std::string>(int(sim_dlgret_no))).c_str());

	registerVariable(L,"sim_boolparam_hierarchy_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_hierarchy_visible))).c_str());
	registerVariable(L,"sim_boolparam_console_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_console_visible))).c_str());
	registerVariable(L,"sim_boolparam_collision_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_collision_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_distance_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_distance_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_ik_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_ik_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_gcs_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_gcs_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_dynamics_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_dynamics_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_proximity_sensor_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_proximity_sensor_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_vision_sensor_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_vision_sensor_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_mill_handling_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_mill_handling_enabled))).c_str());
	registerVariable(L,"sim_boolparam_browser_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_browser_visible))).c_str());
	registerVariable(L,"sim_boolparam_scene_and_model_load_messages",(boost::lexical_cast<std::string>(int(sim_boolparam_scene_and_model_load_messages))).c_str());
	registerVariable(L,"sim_boolparam_shape_textures_are_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_shape_textures_are_visible))).c_str());
	registerVariable(L,"sim_boolparam_display_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_display_enabled))).c_str());
	registerVariable(L,"sim_boolparam_infotext_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_infotext_visible))).c_str());
	registerVariable(L,"sim_boolparam_statustext_open",(boost::lexical_cast<std::string>(int(sim_boolparam_statustext_open))).c_str());
	registerVariable(L,"sim_boolparam_fog_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_fog_enabled))).c_str());
	registerVariable(L,"sim_boolparam_rml2_available",(boost::lexical_cast<std::string>(int(sim_boolparam_rml2_available))).c_str());
	registerVariable(L,"sim_boolparam_rml4_available",(boost::lexical_cast<std::string>(int(sim_boolparam_rml4_available))).c_str());
	registerVariable(L,"sim_boolparam_mirrors_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_mirrors_enabled))).c_str());
	registerVariable(L,"sim_boolparam_aux_clip_planes_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_aux_clip_planes_enabled))).c_str());
	registerVariable(L,"sim_boolparam_realtime_simulation",(boost::lexical_cast<std::string>(int(sim_boolparam_realtime_simulation))).c_str());
	registerVariable(L,"sim_boolparam_use_glfinish_cmd",(boost::lexical_cast<std::string>(int(sim_boolparam_use_glfinish_cmd))).c_str());
	registerVariable(L,"sim_boolparam_force_show_wireless_emission",(boost::lexical_cast<std::string>(int(sim_boolparam_force_show_wireless_emission))).c_str());
	registerVariable(L,"sim_boolparam_force_show_wireless_reception",(boost::lexical_cast<std::string>(int(sim_boolparam_force_show_wireless_reception))).c_str());
	registerVariable(L,"sim_boolparam_video_recording_triggered",(boost::lexical_cast<std::string>(int(sim_boolparam_video_recording_triggered))).c_str());
	registerVariable(L,"sim_boolparam_reserved1",(boost::lexical_cast<std::string>(int(sim_boolparam_reserved1))).c_str());
	registerVariable(L,"sim_boolparam_reserved2",(boost::lexical_cast<std::string>(int(sim_boolparam_reserved2))).c_str());
	registerVariable(L,"sim_boolparam_threaded_rendering_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_threaded_rendering_enabled))).c_str());
	registerVariable(L,"sim_boolparam_fullscreen",(boost::lexical_cast<std::string>(int(sim_boolparam_fullscreen))).c_str());
	registerVariable(L,"sim_boolparam_headless",(boost::lexical_cast<std::string>(int(sim_boolparam_headless))).c_str());
	registerVariable(L,"sim_boolparam_hierarchy_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_hierarchy_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_browser_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_browser_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_objectshift_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_objectshift_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_objectrotate_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_objectrotate_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_force_calcstruct_all_visible",(boost::lexical_cast<std::string>(int(sim_boolparam_force_calcstruct_all_visible))).c_str());
	registerVariable(L,"sim_boolparam_force_calcstruct_all",(boost::lexical_cast<std::string>(int(sim_boolparam_force_calcstruct_all))).c_str());
	registerVariable(L,"sim_boolparam_exit_request",(boost::lexical_cast<std::string>(int(sim_boolparam_exit_request))).c_str());
	registerVariable(L,"sim_boolparam_play_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_play_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_pause_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_pause_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_stop_toolbarbutton_enabled",(boost::lexical_cast<std::string>(int(sim_boolparam_stop_toolbarbutton_enabled))).c_str());
	registerVariable(L,"sim_boolparam_waiting_for_trigger",(boost::lexical_cast<std::string>(int(sim_boolparam_waiting_for_trigger))).c_str());

	registerVariable(L,"sim_intparam_error_report_mode",(boost::lexical_cast<std::string>(int(sim_intparam_error_report_mode))).c_str());
	registerVariable(L,"sim_intparam_program_version",(boost::lexical_cast<std::string>(int(sim_intparam_program_version))).c_str());
	registerVariable(L,"sim_intparam_instance_count",(boost::lexical_cast<std::string>(int(sim_intparam_instance_count))).c_str());
	registerVariable(L,"sim_intparam_custom_cmd_start_id",(boost::lexical_cast<std::string>(int(sim_intparam_custom_cmd_start_id))).c_str());
	registerVariable(L,"sim_intparam_compilation_version",(boost::lexical_cast<std::string>(int(sim_intparam_compilation_version))).c_str());
	registerVariable(L,"sim_intparam_current_page",(boost::lexical_cast<std::string>(int(sim_intparam_current_page))).c_str());
	registerVariable(L,"sim_intparam_flymode_camera_handle",(boost::lexical_cast<std::string>(int(sim_intparam_flymode_camera_handle))).c_str());
	registerVariable(L,"sim_intparam_dynamic_step_divider",(boost::lexical_cast<std::string>(int(sim_intparam_dynamic_step_divider))).c_str());
	registerVariable(L,"sim_intparam_dynamic_engine",(boost::lexical_cast<std::string>(int(sim_intparam_dynamic_engine))).c_str());
	registerVariable(L,"sim_intparam_server_port_start",(boost::lexical_cast<std::string>(int(sim_intparam_server_port_start))).c_str());
	registerVariable(L,"sim_intparam_server_port_range",(boost::lexical_cast<std::string>(int(sim_intparam_server_port_range))).c_str());
	registerVariable(L,"sim_intparam_visible_layers",(boost::lexical_cast<std::string>(int(sim_intparam_visible_layers))).c_str());
	registerVariable(L,"sim_intparam_infotext_style",(boost::lexical_cast<std::string>(int(sim_intparam_infotext_style))).c_str());
	registerVariable(L,"sim_intparam_settings",(boost::lexical_cast<std::string>(int(sim_intparam_settings))).c_str());
	registerVariable(L,"sim_intparam_edit_mode_type",(boost::lexical_cast<std::string>(int(sim_intparam_edit_mode_type))).c_str());
	registerVariable(L,"sim_intparam_server_port_next",(boost::lexical_cast<std::string>(int(sim_intparam_server_port_next))).c_str());
	registerVariable(L,"sim_intparam_qt_version",(boost::lexical_cast<std::string>(int(sim_intparam_qt_version))).c_str());
	registerVariable(L,"sim_intparam_event_flags_read",(boost::lexical_cast<std::string>(int(sim_intparam_event_flags_read))).c_str());
	registerVariable(L,"sim_intparam_event_flags_read_clear",(boost::lexical_cast<std::string>(int(sim_intparam_event_flags_read_clear))).c_str());
	registerVariable(L,"sim_intparam_platform",(boost::lexical_cast<std::string>(int(sim_intparam_platform))).c_str());
	registerVariable(L,"sim_intparam_scene_unique_id",(boost::lexical_cast<std::string>(int(sim_intparam_scene_unique_id))).c_str());
	registerVariable(L,"sim_intparam_work_thread_count, /* 0-256. 0 to disable",(boost::lexical_cast<std::string>(int(sim_intparam_work_thread_count))).c_str());
	registerVariable(L,"sim_intparam_mouse_x",(boost::lexical_cast<std::string>(int(sim_intparam_mouse_x))).c_str());
	registerVariable(L,"sim_intparam_mouse_y",(boost::lexical_cast<std::string>(int(sim_intparam_mouse_y))).c_str());
	registerVariable(L,"sim_intparam_core_count",(boost::lexical_cast<std::string>(int(sim_intparam_core_count))).c_str());
	registerVariable(L,"sim_intparam_work_thread_calc_time_ms",(boost::lexical_cast<std::string>(int(sim_intparam_work_thread_calc_time_ms))).c_str());
	registerVariable(L,"sim_intparam_idle_fps",(boost::lexical_cast<std::string>(int(sim_intparam_idle_fps))).c_str());
	registerVariable(L,"sim_intparam_prox_sensor_select_down",(boost::lexical_cast<std::string>(int(sim_intparam_prox_sensor_select_down))).c_str());
	registerVariable(L,"sim_intparam_prox_sensor_select_up",(boost::lexical_cast<std::string>(int(sim_intparam_prox_sensor_select_up))).c_str());
	registerVariable(L,"sim_intparam_stop_request_counter",(boost::lexical_cast<std::string>(int(sim_intparam_stop_request_counter))).c_str());
	registerVariable(L,"sim_intparam_program_revision",(boost::lexical_cast<std::string>(int(sim_intparam_program_revision))).c_str());
	registerVariable(L,"sim_intparam_mouse_buttons",(boost::lexical_cast<std::string>(int(sim_intparam_mouse_buttons))).c_str());
	registerVariable(L,"sim_intparam_dynamic_warning_disabled_mask",(boost::lexical_cast<std::string>(int(sim_intparam_dynamic_warning_disabled_mask))).c_str());
	registerVariable(L,"sim_intparam_simulation_warning_disabled_mask",(boost::lexical_cast<std::string>(int(sim_intparam_simulation_warning_disabled_mask))).c_str());
	registerVariable(L,"sim_intparam_scene_index",(boost::lexical_cast<std::string>(int(sim_intparam_scene_index))).c_str());
	registerVariable(L,"sim_intparam_motionplanning_seed",(boost::lexical_cast<std::string>(int(sim_intparam_motionplanning_seed))).c_str());
	registerVariable(L,"sim_intparam_speedmodifier",(boost::lexical_cast<std::string>(int(sim_intparam_speedmodifier))).c_str());

	registerVariable(L,"sim_floatparam_rand",(boost::lexical_cast<std::string>(int(sim_floatparam_rand))).c_str());
	registerVariable(L,"sim_floatparam_simulation_time_step",(boost::lexical_cast<std::string>(int(sim_floatparam_simulation_time_step))).c_str());
	registerVariable(L,"sim_floatparam_stereo_distance",(boost::lexical_cast<std::string>(int(sim_floatparam_stereo_distance))).c_str());

	registerVariable(L,"sim_stringparam_application_path",(boost::lexical_cast<std::string>(int(sim_stringparam_application_path))).c_str());
	registerVariable(L,"sim_stringparam_video_filename",(boost::lexical_cast<std::string>(int(sim_stringparam_video_filename))).c_str());
	registerVariable(L,"sim_stringparam_app_arg1",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg1))).c_str());
	registerVariable(L,"sim_stringparam_app_arg2",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg2))).c_str());
	registerVariable(L,"sim_stringparam_app_arg3",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg3))).c_str());
	registerVariable(L,"sim_stringparam_app_arg4",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg4))).c_str());
	registerVariable(L,"sim_stringparam_app_arg5",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg5))).c_str());
	registerVariable(L,"sim_stringparam_app_arg6",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg6))).c_str());
	registerVariable(L,"sim_stringparam_app_arg7",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg7))).c_str());
	registerVariable(L,"sim_stringparam_app_arg8",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg8))).c_str());
	registerVariable(L,"sim_stringparam_app_arg9",(boost::lexical_cast<std::string>(int(sim_stringparam_app_arg9))).c_str());
	registerVariable(L,"sim_stringparam_additional_addonscript_firstscene",(boost::lexical_cast<std::string>(int(sim_stringparam_additional_addonscript_firstscene))).c_str());
	registerVariable(L,"sim_stringparam_additional_addonscript",(boost::lexical_cast<std::string>(int(sim_stringparam_additional_addonscript))).c_str());
	registerVariable(L,"sim_stringparam_scene_path_and_name",(boost::lexical_cast<std::string>(int(sim_stringparam_scene_path_and_name))).c_str());

	registerVariable(L,"sim_arrayparam_gravity",(boost::lexical_cast<std::string>(int(sim_arrayparam_gravity))).c_str());
	registerVariable(L,"sim_arrayparam_fog",(boost::lexical_cast<std::string>(int(sim_arrayparam_fog))).c_str());
	registerVariable(L,"sim_arrayparam_fog_color",(boost::lexical_cast<std::string>(int(sim_arrayparam_fog_color))).c_str());
	registerVariable(L,"sim_arrayparam_background_color1",(boost::lexical_cast<std::string>(int(sim_arrayparam_background_color1))).c_str());
	registerVariable(L,"sim_arrayparam_background_color2",(boost::lexical_cast<std::string>(int(sim_arrayparam_background_color2))).c_str());
	registerVariable(L,"sim_arrayparam_ambient_light",(boost::lexical_cast<std::string>(int(sim_arrayparam_ambient_light))).c_str());
	registerVariable(L,"sim_arrayparam_random_euler",(boost::lexical_cast<std::string>(int(sim_arrayparam_random_euler))).c_str());

	registerVariable(L,"sim_jointmode_passive",(boost::lexical_cast<std::string>(int(sim_jointmode_passive))).c_str());
	registerVariable(L,"sim_jointmode_motion",(boost::lexical_cast<std::string>(int(sim_jointmode_motion_deprecated))).c_str());
	registerVariable(L,"sim_jointmode_ik",(boost::lexical_cast<std::string>(int(sim_jointmode_ik))).c_str());
	registerVariable(L,"sim_jointmode_dependent",(boost::lexical_cast<std::string>(int(sim_jointmode_dependent))).c_str());
	registerVariable(L,"sim_jointmode_force",(boost::lexical_cast<std::string>(int(sim_jointmode_force))).c_str());

	registerVariable(L,"simx_return_ok",(boost::lexical_cast<std::string>(int(simx_return_ok))).c_str());	
	registerVariable(L,"simx_return_novalue_flag",(boost::lexical_cast<std::string>(int(simx_return_novalue_flag))).c_str());	
	registerVariable(L,"simx_return_timeout_flag",(boost::lexical_cast<std::string>(int(simx_return_timeout_flag))).c_str());	
	registerVariable(L,"simx_return_illegal_opmode_flag",(boost::lexical_cast<std::string>(int(simx_return_illegal_opmode_flag))).c_str());	
	registerVariable(L,"simx_return_remote_error_flag",(boost::lexical_cast<std::string>(int(simx_return_remote_error_flag))).c_str());	
	registerVariable(L,"simx_return_split_progress_flag",(boost::lexical_cast<std::string>(int(simx_return_split_progress_flag))).c_str());	
	registerVariable(L,"simx_return_local_error_flag",(boost::lexical_cast<std::string>(int(simx_return_local_error_flag))).c_str());	
	registerVariable(L,"simx_return_initialize_error_flag",(boost::lexical_cast<std::string>(int(simx_return_initialize_error_flag))).c_str());	

	registerVariable(L,"simx_opmode_oneshot",(boost::lexical_cast<std::string>(int(simx_opmode_oneshot))).c_str());	
	registerVariable(L,"simx_opmode_oneshot_wait",(boost::lexical_cast<std::string>(int(simx_opmode_oneshot_wait))).c_str());	
	registerVariable(L,"simx_opmode_streaming",(boost::lexical_cast<std::string>(int(simx_opmode_streaming))).c_str());	
	registerVariable(L,"simx_opmode_oneshot_split",(boost::lexical_cast<std::string>(int(simx_opmode_oneshot_split))).c_str());	
	registerVariable(L,"simx_opmode_streaming_split",(boost::lexical_cast<std::string>(int(simx_opmode_streaming_split))).c_str());	
	registerVariable(L,"simx_opmode_discontinue",(boost::lexical_cast<std::string>(int(simx_opmode_discontinue))).c_str());	
	registerVariable(L,"simx_opmode_buffer",(boost::lexical_cast<std::string>(int(simx_opmode_buffer))).c_str());	
	registerVariable(L,"simx_opmode_remove",(boost::lexical_cast<std::string>(int(simx_opmode_remove))).c_str());	

	registerVariable(L,"simx_headeroffset_version",(boost::lexical_cast<std::string>(int(simx_headeroffset_version))).c_str());	
	registerVariable(L,"simx_headeroffset_message_id",(boost::lexical_cast<std::string>(int(simx_headeroffset_message_id))).c_str());	
	registerVariable(L,"simx_headeroffset_client_time",(boost::lexical_cast<std::string>(int(simx_headeroffset_client_time))).c_str());	
	registerVariable(L,"simx_headeroffset_server_time",(boost::lexical_cast<std::string>(int(simx_headeroffset_server_time))).c_str());	
	registerVariable(L,"simx_headeroffset_scene_id",(boost::lexical_cast<std::string>(int(simx_headeroffset_scene_id))).c_str());	
	registerVariable(L,"simx_headeroffset_server_state",(boost::lexical_cast<std::string>(int(simx_headeroffset_server_state))).c_str());	

	registerVariable(L,"simx_cmdheaderoffset_mem_size",(boost::lexical_cast<std::string>(int(simx_cmdheaderoffset_mem_size))).c_str());	
	registerVariable(L,"simx_cmdheaderoffset_full_mem_size",(boost::lexical_cast<std::string>(int(simx_cmdheaderoffset_full_mem_size))).c_str());	
	registerVariable(L,"simx_cmdheaderoffset_cmd",(boost::lexical_cast<std::string>(int(simx_cmdheaderoffset_cmd))).c_str());	
	registerVariable(L,"simx_cmdheaderoffset_sim_time",(boost::lexical_cast<std::string>(int(simx_cmdheaderoffset_sim_time))).c_str());	
	registerVariable(L,"simx_cmdheaderoffset_status",(boost::lexical_cast<std::string>(int(simx_cmdheaderoffset_status))).c_str());	

	return 1;
}
