#pragma once
#include "source\controllers\testControllers\genericTestController\genericTestController.h"
#include "source\structures\genericStructure\GenericStructure.h"

class structureTestController :
	public genericTestController
{
public:
	structureTestController() = delete;
	structureTestController(GenericStructure* structure, std::string structureName);
	virtual ~structureTestController() = default;

	virtual void insertionTests();
	virtual void deletionTests();
	virtual void findTests();

	void insertAtBeginning();
	void insertAtEnd();
	void insertAtRandom();

	void deleteAtBeginning();
	void deleteAtEnd();
	void deleteAtRandom();

	void findAtBeginning();
	void findAtEnd();
	void findAtRandom();
};

