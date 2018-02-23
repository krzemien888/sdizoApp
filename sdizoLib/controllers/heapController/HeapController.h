#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
class HeapController :
	public GenericController
{
public:
	virtual ~HeapController() = default;
	virtual void init();
	virtual void findInStructure();
	virtual void testStructure();

};

