#include "stdafx.h"
#include "rbTreeController.h"

#include <vector>


#include "views\rbTree\rbTreeMenu.h"
#include "structures\rbTree\rbTree.h"
#include "controllers\testControllers\treeTestController\treeTestController.h"

void rbTreeController::init()
{
	structure = std::make_unique<rbTree>();
	menu = std::make_unique<rbTreeMenu>();
}

void rbTreeController::testStructure()
{
	treeTestController tester(structure.get(), "Drzewo czerwono-czarne");

	tester.runAllTests();
}
