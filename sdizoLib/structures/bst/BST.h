#pragma once
#include "../genericStructure/GenericStructure.h"
#include "stdafx.h"

using namespace std;

class BST :
	public GenericStructure
{
public:
	BST() = default;
	virtual ~BST() = default;

	virtual void addElement(int value);
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);
	virtual void printData();
	virtual void fixBalance();

	virtual int getSize();

private:
	struct Node {
		Node* parent = nullptr;
		unique_ptr<Node> right = nullptr;
		unique_ptr<Node> left = nullptr;
		int	  value;
	};
	
	unique_ptr<Node> root = nullptr;
	unsigned int size = 0;

	void rotateLeft(Node* axis);
	void rotateRight(Node* axis);
	void makeLinear();
	void makeBalanced();
	Node* getNode(Node* startPoint, int value);
	unique_ptr<Node>* getUniqueNode(Node* toGet);
	Node* getMin(Node* searchPoint);
	Node* getMax(Node* searchPoint);
	Node* getPredecessor(Node* searchPoint);
	Node* getSuccessor(Node* searchPoint);
	bool isLeftChild(Node* child);
	bool isRightChild(Node* child);
	void removeNode(Node* toDelete);
	void printNode(std::string &sMiddle, std::string &sBefore, unique_ptr<Node> &currNode);
};

