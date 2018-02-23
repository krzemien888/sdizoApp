#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
class ArrayController :
	public GenericController
{
public:
	virtual ~ArrayController() {};
	virtual void init();

private:
	virtual void deleteFromStructure();
	virtual void addToStructure();
	virtual void findInStructure();
	virtual void testStructure();
};

