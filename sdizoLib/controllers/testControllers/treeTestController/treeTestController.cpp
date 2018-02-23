#include "stdafx.h"
#include "source\controllers\testControllers\treeTestController\treeTestController.h"
#include "source\structures\array\Array.h"
#include "source\structures\bst\BST.h"

using namespace std;

treeTestController::treeTestController(GenericStructure * structure, std::string structureName)
{
	m_structure = structure;
	filename = structureName;
	filename.append(".csv");

	// Clearing the file
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	saveToFile(structureName);

	srand((unsigned int)time(NULL));
}

void treeTestController::insertionTests()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;


	saveToFile("Insertion");

	cout << "Test: wstawianie do drzewa" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(i);


		for (int i = testCase * 1000; i < testCase * 1000 + 1000; ++i) 
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->addElement(i);

			endTime = chrono::high_resolution_clock::now();

			m_structure->removeElement(i);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;

		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: wstawianie do drzewa" << endl;

}

void treeTestController::deletionTests()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;


	int totalTime = 0;

	saveToFile("Deletion");

	cout << "Test: usuwanie z drzewa" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{

		cout << "n = " << testCase * 1000 << endl;

		for (int i = testCase * 1000 - 1; i >= 0; --i)
			m_structure->addElement(i);

		for (int i = testCase * 1000; i < testCase * 1000 + 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->removeElement(i);

			endTime = chrono::high_resolution_clock::now();

			m_structure->addElement(i);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;


		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: usuwanie z drzewa" << endl;
}

void treeTestController::findTests()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Finding");

	cout << "Test: wyszukiwanie w drzewie" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(i);

		for (int i = 0; i < 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(i);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;

		m_structure->clearStructure();
	}
	cout << "Zakoñczono test: wyszukiwanie w drzewie" << endl;
}