#pragma once
#include "../genericStructure/GenericStructure.h"
#include "stdafx.h"

class List :
	public GenericStructure
{
public:
	virtual ~List() {};

	virtual void printData();
	
	virtual void pushBack(int value);
	virtual void pushFront(int value);
	virtual void addElement(int index, int value);
	virtual void addElement(int value);
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);

	virtual int getSize();

private:
	class Node {
	public:
		Node(int value) : data(value) {};
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
		int	data;
	};

	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
	bool isEmpty();
	std::shared_ptr<Node> getNodePtr(int index);
	int size = 0;
};

