#pragma once
#include "controllers\genericController\GenericController.h"
class rbTreeController :
	public GenericController
{
public:
	rbTreeController() = default;
	virtual ~rbTreeController() = default;

	virtual void init();
	virtual void testStructure();

};

