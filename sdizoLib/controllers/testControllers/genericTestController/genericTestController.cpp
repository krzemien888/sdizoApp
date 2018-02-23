#include "stdafx.h"
#include "genericTestController.h"

using namespace std;

void genericTestController::setStructure(GenericStructure * structure, std::string structureName)
{
	m_structure->clearStructure();
	m_structure = structure;
	filename = structureName;
}

void genericTestController::runAllTests()
{
	m_structure->clearStructure();
	insertionTests();
	deletionTests();
	findTests();
}

void genericTestController::saveToFile(int testSize, int time)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
	{
		try {
			file << testSize << ";" << time << endl;
		}
		catch (...)
		{
			cout << "Gotcha!" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void genericTestController::saveToFile(std::string message)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
		file << message << endl;
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}
