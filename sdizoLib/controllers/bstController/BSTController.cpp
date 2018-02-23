#include "stdafx.h"
#include "controllers\bstController\BSTController.h"
#include "structures\bst\BST.h"
#include "views\bst\BSTMenu.h"
#include "controllers\testControllers\treeTestController\treeTestController.h"

using namespace std;

void BSTController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	system("cls");
	switch (parsedInput)
	{
	case 0:
		this->Stop();
		break;
	case 1:
		this->loadFromFile();
		break;
	case 2:
		this->deleteFromStructure();
		break;
	case 3:
		this->addToStructure();
		break;
	case 4:
		this->findInStructure();
		break;
	case 5:
		this->generateStructure();
		break;
	case 6:
		//Structure is displayed no matter what after every action
		break;
	case 7:
		this->testStructure();
		break;
	case 8:
		this->clearStructure();
		break;
	case 9:
		this->repair();
		break;
	default:
		throw std::invalid_argument("Unknown controller input");
		break;
	}
	system("cls");
}

void BSTController::init()
{
	structure = std::make_unique<BST>();
	menu = std::make_unique<BSTMenu>();
}

void BSTController::testStructure()
{
	treeTestController tester(structure.get(), "Drzewo BST");

	tester.runAllTests();
}

void BSTController::findInStructure()
{
	int value = 0;
	cout << "Podaj warto��: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta warto�� zosta�a znaleziona w drzewie!\n";
	else
		cout << "Ta warto�� nie zosta�a znaleziona w drzewie!\n";
	system("pause");
}

void BSTController::repair()
{
	GenericStructure* pointerToCast = structure.get();
	BST* castedPointer = (BST*)pointerToCast;
	castedPointer->fixBalance();
}
