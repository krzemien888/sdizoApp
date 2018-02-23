#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
#include "../../utilities/NotImplementedException.h"

class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() = default;
		virtual void parseInput(const std::string &input);
		virtual void printView();
		virtual void loadFromFile() { throw new NotImplementedException; };
		virtual void deleteFromStructure() { throw new NotImplementedException; };
		virtual void addToStructure() { throw new NotImplementedException; };
		virtual void findInStructure() { throw new NotImplementedException; };
		virtual void generateStructure() { throw new NotImplementedException; };
		virtual void clearStrucutre() { throw new NotImplementedException; };

		virtual void init();	
	private:
		void runAllTests();

		std::unique_ptr<GenericController> controller;
};

