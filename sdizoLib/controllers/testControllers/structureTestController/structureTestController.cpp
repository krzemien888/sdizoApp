#include "stdafx.h"
#include "structureTestController.h"
#include "source\structures\array\Array.h"
#include "source\structures\list\List.h"

using namespace std;

structureTestController::structureTestController(GenericStructure * structure, std::string structureName)
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

void structureTestController::insertionTests()
{
	insertAtBeginning();
	insertAtEnd();
	insertAtRandom();

	cout << "Testy dodawania zakoñczone" << endl;
}

void structureTestController::deletionTests()
{
	deleteAtBeginning();
	deleteAtEnd();
	deleteAtRandom();
	cout << "Testy usuwania zakoñczone" << endl;
}

void structureTestController::findTests()
{
	findAtBeginning();
	findAtEnd();
	findAtRandom();
	cout << "Testy wyszukiwania zakoñczone" << endl;
}

void structureTestController::insertAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	bool byValue = (dynamic_cast<Array*>(m_structure) == nullptr);

	saveToFile("Insert at beginning");

	cout << "Test: wstawianie na pocz¹tku" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i) 
		{
			startTime = chrono::high_resolution_clock::now();
		
			m_structure->addElement(0, i);

			endTime = chrono::high_resolution_clock::now();

			if (byValue)
				m_structure->removeElement(i);
			else
				m_structure->removeElement(0);
			

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: wstawianie na pocz¹tku" << endl;
}

void structureTestController::insertAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;
	bool byValue = (dynamic_cast<Array*>(m_structure) == nullptr);

	saveToFile("Insert at end");

	cout << "Test: wstawianie na koñcu" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i) {
			startTime = chrono::high_resolution_clock::now();

			m_structure->addElement((m_structure->getSize() - 1 <0)? 0 : m_structure->getSize() - 1);

			endTime = chrono::high_resolution_clock::now();

			
			m_structure->removeElement((m_structure->getSize() - 1 < 0) ? 0 : m_structure->getSize() - 1);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();

	}

	cout << "Zakoñczono test: wstawianie na koñcu" << endl;
}

void structureTestController::insertAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;
	
	saveToFile("Insert at random");

	bool byValue = (dynamic_cast<Array*>(m_structure) == nullptr);
	cout << "Test: wstawianie losowe" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i) {

			startTime = chrono::high_resolution_clock::now();

			m_structure->addElement(rand() % m_structure->getSize(), i);

			endTime = chrono::high_resolution_clock::now();

			if (byValue)
				m_structure->removeElement(i);
			else
				m_structure->removeElement(0);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}
	cout << "Zakoñczono test: wstawianie losowe" << endl;
}

void structureTestController::deleteAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	Array* arr = dynamic_cast<Array*>(m_structure);
	List* list = dynamic_cast<List*>(m_structure);

	

	saveToFile("Delete at beginning");

	cout << "Test: usuwanie na pocz¹tku" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{

		cout << "n = " << testCase * 1000 << endl;

		for (int i = testCase * 1000 - 1; i >= 0; --i)
			m_structure->addElement(0, i);

		for (int i = 0; i <  1000; ++i) 
		{
			startTime = chrono::high_resolution_clock::now();

			if (arr != nullptr)
				arr->removeElement(0);
			else if (list != nullptr)
				list->removeElement(i);
			else
				m_structure->removeElement(i);

			endTime = chrono::high_resolution_clock::now();

			m_structure->addElement(i);


			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: usuwanie na pocz¹tku" << endl;

}



void structureTestController::deleteAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Delete at end");
	bool byValue = (dynamic_cast<Array*>(m_structure) == nullptr);
	cout << "Test: usuwanie na koñcu" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{

		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			if (byValue)
				m_structure->removeElement(testCase * 1000 - 1 - i);
			else
				m_structure->removeElement(m_structure->getSize() - 1);

			endTime = chrono::high_resolution_clock::now();

			m_structure->addElement(i);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: usuwanie na koñcu" << endl;

}

void structureTestController::deleteAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;
	int deletedIndex;
	Array arr;

	bool byValue = (dynamic_cast<Array*>(m_structure) == nullptr);

	saveToFile("Delete at random");

	cout << "Test: usuwanie losowe" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(i);

		if (byValue) 
			for (int i = 0; i < testCase * 1000; ++i)
				arr.addElement(i);

		for (int i = 0; i < 1000; ++i)
		{
			if (byValue)
				deletedIndex = rand() % arr.getSize();
			
			startTime = chrono::high_resolution_clock::now();

			try
			{
				if (byValue)
					m_structure->removeElement(arr.getValue(deletedIndex));
				else
					m_structure->removeElement(rand() % m_structure->getSize());
			}
			catch (invalid_argument &e)
			{
				cout << e.what() << endl;
				cout << "tried to delete: " << (deletedIndex) << endl;
				system("pause");
				return;
			}

			endTime = chrono::high_resolution_clock::now();

			m_structure->addElement(i);

			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

			if(byValue)
				arr.removeElement(deletedIndex);

		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: usuwanie losowe" << endl;

}

void structureTestController::findAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at beginning");

	cout << "Test: wyszukiwanie na pocz¹tku" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(testCase * 1000 - rand() % 30);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: wyszukiwanie na pocz¹tku" << endl;

}

void structureTestController::findAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at end");

	cout << "Test: wyszukiwanie na koñcu" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(0 + rand() % 30);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: wyszukiwanie na koñcu" << endl;

}

void structureTestController::findAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at random");

	cout << "Test: wyszukiwanie losowe" << endl;

	for (int testCase = 1; testCase < 11; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(rand() % m_structure->getSize());

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

		}
		saveToFile(testCase * 1000, totalTime/1000);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zakoñczono test: wyszukiwanie losowe" << endl;

}
