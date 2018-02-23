#pragma once

#include "stdafx.h"
#include "../../structures/genericStructure/GenericStructure.h"
#include "../../views/genericView/GenericView.h"
class GenericController
{
public:
	GenericController() : running(false) {};
	virtual ~GenericController() = default;
	virtual void parseInput(const std::string &input);
	virtual void printView();
	virtual void loadFromFile();
	virtual void deleteFromStructure();
	virtual void addToStructure();
	virtual void findInStructure();
	virtual void testStructure() { throw new NotImplementedException; };
	virtual void generateStructure();
	virtual void clearStructure();
	bool isRunning();
	void Run();
	void Stop();

protected:
	std::unique_ptr<GenericStructure> structure;
	std::unique_ptr<GenericView> menu;

	virtual void init() = 0;

private:
	bool running;

};

