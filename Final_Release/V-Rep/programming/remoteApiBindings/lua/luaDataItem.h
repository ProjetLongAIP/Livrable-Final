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

#pragma once

#include <vector>
#include <string>

class CLuaDataItem
{
public:
	CLuaDataItem();
	CLuaDataItem(bool v);
	CLuaDataItem(int v);
	CLuaDataItem(float v);
    CLuaDataItem(double v);
    CLuaDataItem(const std::string& v);
    CLuaDataItem(const char* bufferPtr,unsigned int bufferLength);

	CLuaDataItem(const std::vector<bool>& v);
	CLuaDataItem(const std::vector<int>& v);
	CLuaDataItem(const std::vector<float>& v);
    CLuaDataItem(const std::vector<double>& v);
    CLuaDataItem(const std::vector<std::string>& v);

	virtual ~CLuaDataItem();

	bool isTable();
	int getType();
	void setNilTable(int size);
	int getNilTableSize();

	std::vector<bool> boolData;
	std::vector<int> intData;
	std::vector<float> floatData;
    std::vector<double> doubleData;
    std::vector<std::string> stringData;

protected:
	int _nilTableSize;
	bool _isTable;
    int _type; // -1=nil,0=bool,1=int,2=float,3=string,4=buffer,5=double
};
