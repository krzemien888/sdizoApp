#include "stdafx.h"
#include "BST.h"

void BST::addElement(int value)
{
	if (root == nullptr)
	{
		root = make_unique<Node>();
		root->value = value;
		++size;
		return;
	}

	Node* tmp = root.get();

	while (true)
	{
		if (value < tmp->value)
		{
			if (tmp->left == nullptr)
			{
				tmp->left = make_unique<Node>();
				tmp->left->value = value;
				tmp->left->parent = tmp;
				++size;
				return;
			}
			tmp = tmp->left.get();
		}
		else
		{
			if (tmp->right == nullptr)
			{
				tmp->right = make_unique<Node>();
				tmp->right->value = value;
				tmp->right->parent = tmp;
				++size;
				return;
			}
			tmp = tmp->right.get();
		}
	}
}

void BST::removeElement(int value)
{
	Node* toDelete = getNode(root.get(), value);
	if (toDelete != nullptr)
	{
		removeNode(toDelete);
		--size;
	}
}

void BST::clearStructure()
{
	root.reset();
	size = 0;
}

bool BST::findValue(int toFind)
{
	Node* searchPoint = root.get();
	while (searchPoint != nullptr && searchPoint->value != toFind)
	{
		if (toFind < searchPoint->value)
			searchPoint = searchPoint->left.get();
		else
			searchPoint = searchPoint->right.get();
	}
	return (searchPoint != nullptr);
}

void BST::printData()
{
	printNode(string(""), string(""), root);
}

void BST::fixBalance()
{
	if (root != nullptr)
	{
		makeLinear();
		makeBalanced();
	}
}

int BST::getSize()
{
	return size;
}

void BST::rotateLeft(Node * axis)
{
	if (axis->right == nullptr)
		return;

	bool isAxisLeftChild = isLeftChild(axis);

	//Creating hooks
	unique_ptr<BST::Node>* axisUniquePtr = getUniqueNode(axis);
	unique_ptr<BST::Node> axisUnique = move(*axisUniquePtr);

	Node* rightChild = axis->right.get();
	unique_ptr<BST::Node>* rightChildUniquePtr = getUniqueNode(rightChild);
	unique_ptr<BST::Node> rightChildUnique = move(*rightChildUniquePtr);

	//Moving childs
	if (rightChild->left != nullptr)
	{
		axis->right = move(rightChild->left);
		axis->right->parent = axis;
	}
	rightChild->left = move(axisUnique);

	//Resettings parents child pointers
	if (axis->parent != nullptr)
	{
		if (isAxisLeftChild)
			axis->parent->left = move(rightChildUnique);
		else
			axis->parent->right = move(rightChildUnique);
	}

	//Setting parents
	rightChild->parent = axis->parent;
	axis->parent = rightChild;

	//Resetting root to correct place if needed
	if (rightChild->parent == nullptr)
		root = move(rightChildUnique);
}

void BST::rotateRight(Node * axis)
{
	if (axis->left == nullptr)
		return;

	bool isAxisLeftChild = isLeftChild(axis);

	//Creating hooks
	unique_ptr<BST::Node>* axisUniquePtr = getUniqueNode(axis);
	unique_ptr<BST::Node> axisUnique = move(*axisUniquePtr);

	Node* leftChild = axis->left.get();
	unique_ptr<BST::Node>* leftChildUniquePtr = getUniqueNode(leftChild);
	unique_ptr<BST::Node> leftChildUnique = move(*leftChildUniquePtr);
	
	//Moving childs
	if (leftChild->right != nullptr) 
	{
		axis->left = move(leftChild->right);
		axis->left->parent = axis;
	}
	leftChild->right = move(axisUnique);

	//Resettings parents child pointers
	if (axis->parent != nullptr)
	{
		if (isAxisLeftChild)
			axis->parent->left = move(leftChildUnique);
		else
			axis->parent->right = move(leftChildUnique);
	}

	//Setting parents
	leftChild->parent = axis->parent;
	axis->parent = leftChild;

	//Resetting root to correct place if needed
	if (leftChild->parent == nullptr)
		root = move(leftChildUnique);
}

void BST::makeLinear()
{
	Node* currentAxis = root.get();
	while (currentAxis != nullptr)
	{
		if (currentAxis->left != nullptr)
		{
			rotateRight(currentAxis);
			currentAxis = currentAxis->parent;
		}
		else
			currentAxis = currentAxis->right.get();
	}
}

void BST::makeBalanced()
{
	unsigned int secondRotationRound = (unsigned int)pow(2, floor(log2(size + 1))) - 1;
	unsigned int firstRotationRound = size - secondRotationRound;

	Node* currAxis = root.get();
	for (unsigned int i = 0; i < firstRotationRound; ++i)
	{
		rotateLeft(currAxis);
		currAxis = currAxis->parent->right.get();
	}

	while (secondRotationRound > 1)
	{
		currAxis = root.get();
		secondRotationRound = (unsigned int)floor(secondRotationRound / 2);
		for(unsigned int i = 0; i < secondRotationRound; ++i)
		{
			rotateLeft(currAxis);
			currAxis = currAxis->parent->right.get();
		}
	}
}

BST::Node * BST::getNode(Node * startPoint, int value)
{
	while (startPoint != nullptr && startPoint->value != value)
	{
		if (value < startPoint->value)
			startPoint = startPoint->left.get();
		else
			startPoint = startPoint->right.get();
	}
	return startPoint;
}

unique_ptr<BST::Node>* BST::getUniqueNode(Node * toGet)
{
	if (toGet->parent == nullptr)
		return &root;
	Node* parent = toGet->parent;
	if (parent->left.get() == toGet)
		return &(parent->left);
	else
		return &(parent->right);
}

BST::Node * BST::getMin(Node * searchPoint)
{
	while (searchPoint->left != nullptr)
		searchPoint = searchPoint->left.get();
	return searchPoint;
}

BST::Node * BST::getMax(Node * searchPoint)
{
	while (searchPoint->right != nullptr)
		searchPoint = searchPoint->right.get();
	return searchPoint;
}

BST::Node * BST::getPredecessor(Node * searchPoint)
{
	if (searchPoint->left != nullptr)
		return getMax(searchPoint->left.get());
	Node* parentNode = searchPoint->parent;
	while (parentNode != nullptr && parentNode->right.get() != searchPoint)
	{
		searchPoint = parentNode;
		parentNode = searchPoint->parent;
	}
	return parentNode;
}

BST::Node * BST::getSuccessor(Node * searchPoint)
{
	if (searchPoint->right != nullptr)
		return getMin(searchPoint->right.get());
	Node* parentNode = searchPoint->parent;
	while (parentNode != nullptr && parentNode->left.get() != searchPoint)
	{
		searchPoint = parentNode;
		parentNode = searchPoint->parent;
	}
	return parentNode;
}

bool BST::isLeftChild(Node * child)
{
	if(child->parent == nullptr)
		return false;

	Node* parent = child->parent;
	return (parent->left.get() == child);
}

bool BST::isRightChild(Node * child)
{
	if (child->parent == nullptr)
		return false;

	Node* parent = child->parent;
	return (parent->right.get() == child);
}

void BST::removeNode(Node * toDelete)
{
	Node* childNode = nullptr;
	Node* parentNode = nullptr;


	//No child case
	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		//Root case
		if (toDelete == root.get())
		{
			this->clearStructure();
			return;
		}

		parentNode = toDelete->parent;
		if (parentNode->left.get() == toDelete)
			parentNode->left.reset();
		else
			parentNode->right.reset();
		return;
	}

	//One child case
	if ((toDelete->left == nullptr) != (toDelete->right == nullptr) && toDelete->parent != nullptr)
	{
		parentNode = toDelete->parent;

		if (parentNode->left.get() == toDelete)
		{
			if (toDelete->left != nullptr)
				parentNode->left = move(toDelete->left);
			else
				parentNode->left = move(toDelete->right);
			parentNode->left->parent = parentNode;
			
		}
		else
		{
			if (toDelete->left != nullptr)
				parentNode->right = move(toDelete->left);
			else
				parentNode->right = move(toDelete->right);
			parentNode->right->parent = parentNode;
		}
		return;
	}

	//To child case
	if (toDelete->left != nullptr && toDelete->right != nullptr || toDelete->parent == nullptr)
	{
		childNode = getSuccessor(toDelete);
		if (childNode == nullptr)
			childNode = getPredecessor(toDelete);
		toDelete->value = childNode->value;

		removeNode(childNode);
	}
}

void BST::printNode(std::string & sMiddle, std::string & sBefore, unique_ptr<Node> &currNode)
{
	string s;
	if (currNode != nullptr)
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), currNode->right);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << currNode->value << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), currNode->left);
	}
}

