#pragma once

#include "../genericStructure/GenericStructure.h"

using namespace std;

class rbTree :
	public GenericStructure
{
public:
	rbTree() = default;
	virtual ~rbTree() = default;

	virtual void addElement(int value);
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);
	virtual void printData();
	virtual int getSize();

	bool isBalanced();
private:

	enum Color { Black, Red };

	struct Node {
		Node* parent = nullptr;
		std::unique_ptr<Node> right = nullptr;
		std::unique_ptr<Node> left = nullptr;
		int	  value;
		Color color;
	};

	std::unique_ptr<Node> root = nullptr;
	unsigned int size = 0;

	bool checkColor(Node* toCheck);
	void fixColors(Node* startNode);
	void fixColorsRedRoot();
	void fixColorsRedUncle(Node* startNode);
	void fixColorsBlackUncleRightChild(Node* startNode);
	void fixColorsBlackUncleLeftChild(Node* startNode);

	Node* createGuardianNodeSibling(Node* parent);
	Node* createGuardianNode(Node * parent, bool createOnLeft);
	void deleteGuardianNode(Node* guardian);

	void rotateLeft(Node* axis);
	void rotateRight(Node* axis);
	void swapColors(Node* x, Node* y);
	void doubleBlackFix(Node* doubleBlackNode);

	Node* getNode(Node* startPoint, int value);
	std::unique_ptr<Node>* getUniqueNode(Node* toGet);
	Node* getMin(Node* searchPoint);
	Node* getMax(Node* searchPoint);
	Node* getUncle(Node* child);
	Node* getPredecessor(Node* searchPoint);
	Node* getSuccessor(Node* searchPoint);
	Node* getSibling(Node* child);
	Node* getOutterChild(Node* parent);
	Node* getInnerChild(Node* parent);

	bool isLeftChild(Node* child);
	bool isRightChild(Node* child);
	bool isBlack(Node* node);
	bool isRed(Node* node);
	void removeNode(Node* toDelete);
	void printNode(std::string &sMiddle, std::string &sBefore, unique_ptr<Node> &currNode);

	bool isBalancedUtil(Node* root, int &maxh, int &minh);
};

