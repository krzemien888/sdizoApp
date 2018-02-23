#pragma once

#include "stdafx.h"
#include "../../views/genericView/GenericView.h"
#include "../../utilities/NotImplementedException.h"

class GenericStructure
{
public:
	virtual ~GenericStructure() = default;

	virtual void addElement(int value) { throw NotImplementedException(); };
	virtual void addElement(int index, int value) { throw NotImplementedException(); };
	virtual void pushBack(int value) { throw NotImplementedException(); };
	virtual void pushFront(int value) { throw NotImplementedException(); };
	virtual void removeElement(int value) = 0;
	virtual void clearStructure() = 0;
	virtual bool findValue(int toFind) = 0;
	virtual void printData() = 0;
	virtual int getSize() = 0;

};

