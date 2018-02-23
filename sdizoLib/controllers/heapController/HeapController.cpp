#include "stdafx.h"
#include "HeapController.h"

#include "source\structures\heap\Heap.h"
#include "source\views\heap\heapMenu.h"
#include "source\controllers\testControllers\treeTestController\treeTestController.h"

using namespace std;

void HeapController::init()
{
	structure = std::make_unique<Heap>();
	menu = std::make_unique<heapMenu>();
	srand((unsigned int)time(NULL));
}

void HeapController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w kopcu!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w kopcu!\n";
	system("pause");
}

void HeapController::testStructure()
{
	treeTestController tester(structure.get(), "Kopiec");

	tester.runAllTests();
}
