#include "stdafx.h"
#include "ArrayController.h"

#include "../../structures/array/Array.h"
#include "../../views/array/ArrayMenu.h"
#include "source\controllers\testControllers\structureTestController\structureTestController.h"

using namespace std;

void ArrayController::init()
{
	structure = std::make_unique<Array>();
	menu = std::make_unique<ArrayMenu>();
}

void ArrayController::deleteFromStructure()
{
	int index = 0;
	cout << "Podaj indeks: ";
	cin >> index;

	try
	{
		structure->removeElement(index);
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void ArrayController::addToStructure()
{
	int index = 0, value = 0;

	cout << "Podaj indeks: ";
	cin >> index;
	cout << "Podaj wartoœæ: ";
	cin >> value;

	try 
	{
		structure->addElement(index, value);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		system("pause");
	}

}

void ArrayController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w tablicy!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w tablicy!\n";
	system("pause");
}

void ArrayController::testStructure()
{
	Array arr;
	structureTestController tester(&arr, "Tablica");

	tester.runAllTests();
}
