#include "stdafx.h"
#include "AppController.h"
#include "views\app\appMenu.h"

#include "controllers\appController\AppController.h"
#include "controllers\listController/ListController.h"
#include "controllers\heapController/HeapController.h"
#include "controllers\bstController/BSTController.h"
#include "controllers\rbTreeController/rbTreeController.h"
#include "controllers\arrayController\ArrayController.h"

#include "structures\array\Array.h"
#include "structures\bst\BST.h"
#include "structures\heap\Heap.h"
#include "structures\list\List.h"
#include "structures\rbTree\rbTree.h"

#include "controllers\testControllers\structureTestController\structureTestController.h"
#include "controllers\testControllers\treeTestController\treeTestController.h"

using namespace std;

AppController::AppController() : GenericController()
{
	setlocale(LC_ALL, "Polish");
}

void AppController::parseInput(const std::string &input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	switch (parsedInput) 
	{
		case 0:
			this->Stop();
			break;
		case 1:
			controller = std::make_unique<ArrayController>();
			controller->Run();
			break;
		case 2:
			controller = std::make_unique<ListController>();
			controller->Run();
			break;
		case 3:
			controller = std::make_unique<HeapController>();
			controller->Run();
			break;
		case 4:
			controller = std::make_unique<BSTController>();
			controller->Run();
			break;
		case 5:
			controller = std::make_unique<rbTreeController>();
			controller->Run();
			break;
		case 6:
			runAllTests();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
			break;
	}
}

void AppController::printView()
{
	menu->print();
}

void AppController::init()
{
	menu = std::make_unique<appMenu>();
	srand((unsigned int)time(NULL));
}

void AppController::runAllTests()
{
	Array arr;
	List list;
	Heap heap;
	rbTree rbT;
	BST bst;
	structureTestController arrTester(&arr, "Tablica");
	structureTestController listTester(&list, "Lista");
	treeTestController heapTester(&heap, "Kopiec");
	treeTestController rbTreeTester(&rbT, "Drzewo czerwono-czarne");
	treeTestController bstTreeTester(&bst, "Drzewo BST");

	cout << "Tablica" << endl;
	arrTester.runAllTests();
	cout << "Lista" << endl;
	listTester.runAllTests();
	cout << "Kopiec" << endl;
	heapTester.runAllTests();
	cout << "Drzewo czerwono-czarne" << endl;
	rbTreeTester.runAllTests();
	cout << "Drzewo BST" << endl;
	bstTreeTester.runAllTests();
}

