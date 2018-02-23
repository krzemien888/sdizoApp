#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
class ListController :
	public GenericController
{
public:
	virtual ~ListController() {};
	virtual void init();

private:
	virtual void addToStructure();
	virtual void addAtEnd();
	virtual void addAtBeginning();
	virtual void findInStructure();
	virtual void testStructure();
};

