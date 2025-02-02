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

#include "visionVelodyneVPL16Cont.h"
#include "v_repLib.h"

CVisionVelodyneVPL16Cont::CVisionVelodyneVPL16Cont()
{
}

CVisionVelodyneVPL16Cont::~CVisionVelodyneVPL16Cont()
{
	removeAll();
}

int CVisionVelodyneVPL16Cont::addObject(CVisionVelodyneVPL16* obj)
{
	_allObjects.push_back(obj);
	return(obj->getVelodyneHandle());
}

bool CVisionVelodyneVPL16Cont::removeObject(int velodyneHandle)
{
	for (int i=0;i<int(_allObjects.size());i++)
	{
		if (_allObjects[i]->getVelodyneHandle()==velodyneHandle)
		{
			delete _allObjects[i];
			_allObjects.erase(_allObjects.begin()+i);
			return(true);
		}
	}
	return(false);
}

void CVisionVelodyneVPL16Cont::removeAll()
{
	for (int i=0;i<int(_allObjects.size());i++)
		delete _allObjects[i];
	_allObjects.clear();
}

CVisionVelodyneVPL16* CVisionVelodyneVPL16Cont::getObject(int velodyneHandle)
{
	for (int i=0;i<int(_allObjects.size());i++)
	{
		if (_allObjects[i]->getVelodyneHandle()==velodyneHandle)
			return(_allObjects[i]);
	}
	return(0);
}
