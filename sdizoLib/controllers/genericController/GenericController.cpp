#include "stdafx.h"
#include "GenericController.h"

using namespace std;

void GenericController::parseInput(const std::string & input)
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
	default:
		throw std::invalid_argument("Unknown controller input");
		break;
	}
	system("cls");
}

void GenericController::printView()
{
	structure->printData();
	menu->print();
}

void GenericController::loadFromFile()
{
	string userInput = "";
	int currentData;
	string line = "";

	cout << "Podaj nazwę pliku: ";
	cin >> userInput;
	structure->clearStructure();

	ifstream fileStream(userInput);

	if (!fileStream.is_open())
	{
		cout << "Plik nie został odnaleziony" << endl;
		system("pause");
		return;
	}

	// Missing size number
	getline(fileStream, line);

	while (getline(fileStream, line))
	{
		if (!line.empty())
		{
			istringstream iss(line);
			while (iss >> currentData)
				structure->addElement(currentData);
		}
	}
}

void GenericController::deleteFromStructure()
{
	int value = 0;
	cout << "Podaj wartość: ";
	cin >> value;	
	try {
		structure->removeElement(value);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void GenericController::addToStructure()
{
	int value = 0;
	cout << "Podaj wartość: ";
	cin >> value;
	try {
		structure->addElement(value);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void GenericController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartość: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartość została znaleziona w strukturze!\n";
	else
		cout << "Ta wartość nie została znaleziona w strukturze!\n";
	system("pause");
}

void GenericController::Run()
{
	init();
	running = true;
	string userInput;
	do {
		system("cls");
		this->printView();
		cout << "Podaj opcję: " << endl;
		cin >> userInput;

		try
		{
			this->parseInput(userInput);
		}
		catch (invalid_argument&)
		{
			cout << "Nieprawidłowy argument" << endl;
			system("pause");
		}
	} while (this->isRunning());
}

void GenericController::Stop()
{
	running = false;
}

void GenericController::generateStructure()
{
	int min, max, amount;
	cout << "Podaj minimalną wartość: ";
	cin >> min;
	cout << "Podaj maksymalną wartość: ";
	cin >> max;
	cout << "Podaj ilość: ";
	cin >> amount;

	structure->clearStructure();

	for (int i = 0; i < amount; ++i)
		structure->addElement(rand() % max + min);
}

void GenericController::clearStructure()
{
	structure->clearStructure();
}

bool GenericController::isRunning()
{
	return running;
}
