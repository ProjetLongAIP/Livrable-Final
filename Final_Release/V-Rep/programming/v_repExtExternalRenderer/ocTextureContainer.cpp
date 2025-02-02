// This file is part of the EXTERNAL RENDERER PLUGIN for V-REP
// 
// Copyright 2006-2015 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// The EXTERNAL RENDERER PLUGIN is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The EXTERNAL RENDERER PLUGIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// THE EXTERNAL RENDERER PLUGIN IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
//  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the EXTERNAL RENDERER PLUGIN.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.2.3 rev4 on December 21st 2015

#include "ocTextureContainer.h"

COcTextureContainer::COcTextureContainer()
{
}

COcTextureContainer::~COcTextureContainer()
{
	for (int i=0;i<int(_textures.size());i++)
		delete _textures[i];
}

void COcTextureContainer::decrementAllUsedCount()
{
	for (int i=0;i<int(_textures.size());i++)
		_textures[i]->decrementUsedCount();
}

void COcTextureContainer::removeAllUnused()
{
	for (int i=0;i<int(_textures.size());i++)
	{
		if (_textures[i]->getUsedCount()<=0)
		{
			delete _textures[i];
			_textures.erase(_textures.begin()+i);
			i--; // reprocess this position
		}
	}
}

COcTexture* COcTextureContainer::getFromId(int id)
{
	for (int i=0;i<int(_textures.size());i++)
	{
		if (_textures[i]->getId()==id)
			return(_textures[i]);
	}
	return(0);
}

void COcTextureContainer::add(COcTexture* texture)
{
	_textures.push_back(texture);
}
