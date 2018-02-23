#include "stdafx.h"
#include "rbTreeController.h"

#include <vector>


#include "source\views\rbTree\rbTreeMenu.h"
#include "source\structures\rbTree\rbTree.h"
#include "source\controllers\testControllers\treeTestController\treeTestController.h"

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
