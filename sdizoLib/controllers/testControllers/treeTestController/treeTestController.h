#pragma once
#include "source\controllers\testControllers\genericTestController\genericTestController.h"
#include "source\structures\genericStructure\GenericStructure.h"

class treeTestController :
	public genericTestController
{
public:
	treeTestController() = delete;
	treeTestController(GenericStructure* structure, std::string structureName);
	virtual ~treeTestController() = default;

	virtual void insertionTests();
	virtual void deletionTests();
	virtual void findTests();
};

