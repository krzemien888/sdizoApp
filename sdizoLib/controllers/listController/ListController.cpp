#include "stdafx.h"
#include "ListController.h"

#include "../../structures/list/List.h"
#include "../../views/list/listMenu.h"
#include "source\controllers\testControllers\structureTestController\structureTestController.h"

using namespace std;


void ListController::init()
{
	structure = std::make_unique<List>();
	menu = std::make_unique<listMenu>();
}

void ListController::addToStructure()
{
	int index = 0, value = 0, parsedInput = -1;
	string input = "";

	cout << "p - dodaj na pocz¹tku" << endl;
	cout << "k - dodaj na koñcu" << endl;
	cout << "i - dodaj w œrodku" << endl;
	cout << "Twój wybór: ";
	cin >> input;


	switch (input.c_str()[0])
	{
		case 'p':
			addAtBeginning();
			break;
		case 'k':
			addAtEnd();
			break;
		case 'i':
			cout << "Podaj indeks: ";
			cin >> index;
			cout << "Podaj wartoœæ: ";
			cin >> value;
			structure->addElement(index, value);
			break;
		default:
			throw std::invalid_argument("Unknown action input");
	}
}

void ListController::addAtEnd()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	try
	{
		structure->pushBack(value);
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void ListController::addAtBeginning()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	try
	{
		structure->pushFront(value);
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void ListController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w liœcie!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w liœcie!\n";
	system("pause");
}

void ListController::testStructure()
{
	List l;
	structureTestController tester(&l , "Lista");

	tester.runAllTests();
}
