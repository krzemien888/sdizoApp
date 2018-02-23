#include "stdafx.h"
#include "Heap.h"

using namespace std;

Heap::Heap()
{
	array = make_unique<Array>(20);
}

Heap::Heap(int size)
{
	array = make_unique<Array>(size * 2);
}

void Heap::printData()
{
	printNode(string(""), string(""), 0);
	array->printData();
}

void Heap::addElement(int value)
{
	int lastIndex = array->getSize();
	array->pushBack(value);
	fixUp();
	++m_size;
}

void Heap::removeElement(int value)
{
	if (array->findValue(value))
	{
		int indexFound = -1;
		int lastElementIndex = -1;
		for (int index = 0; index < array->getSize(); ++index)
			if (array->operator[](index) == value)
			{
				indexFound = index;
				lastElementIndex = array->getSize() - 1;	
				break;
			}

		cout << "Pre delete" << endl;
		printData();

		array->swap(indexFound, lastElementIndex);
		array->removeElement(lastElementIndex);
		fixDown(indexFound);
		--m_size;
	}
}

void Heap::clearStructure()
{
	array->clearStructure();
	m_size = 0;
}

bool Heap::findValue(int toFind)
{
	if (array->isEmpty())
		return false;

	if (array->getValue(0) < toFind)
		return false;
	return array->findValue(toFind);
}

int Heap::getSize()
{
	return m_size;
}

void Heap::fixUp()
{
	if (array->getSize() < 1)
		return;
	int currNode = array->getSize() - 1;
	int parentNode = (currNode - ((currNode % 2 == 0)? 2:1)) / 2;
	while (currNode != 0)
	{
		if (array->getValue(parentNode) < array->getValue(currNode))
			array->swap(parentNode, currNode);
		currNode = parentNode;
		parentNode = (currNode - ((currNode % 2 == 0) ? 2 : 1)) / 2;
	}
}

void Heap::fixDown(int index)
{
	int leftChild;
	int rightChild;
	int parent;
	bool isLeft, isRight, shifted;
	isLeft = isRight = shifted = true;

	cout << "pre fix" << endl;
	printData();

	while ((isLeft || isRight) && shifted)
	{
		isLeft = isRight = true;
		shifted = false;
		leftChild = index * 2 + 1;
		rightChild = index * 2 + 2;

		isLeft = (leftChild < array->getSize());
		isRight = (rightChild < array->getSize());
		parent = (int)(index - 1) / 2;

		if (parent >= 0)
			if (array->getValue(parent) < array->getValue(index))
			{
				fixDown(parent);
				return;
			}

		if (isRight && isLeft)
		{
			if (array->getValue(rightChild) > array->getValue(leftChild))
			{
				if (array->getValue(rightChild) > array->getValue(index))
				{
					array->swap(index, rightChild);
					index = rightChild;
					shifted = true;
				}
			}
			else
			{
				if (array->getValue(leftChild) > array->getValue(index))
				{
					array->swap(index, leftChild);
					index = leftChild;
					shifted = true;
				}
			}
		}
		else if (isRight)
		{
			if (array->getValue(rightChild) > array->getValue(index))
			{
				array->swap(index, rightChild);
				index = rightChild;
				shifted = true;
			}
		}
		else if (isLeft)
		{
			if (array->getValue(leftChild) > array->getValue(index))
			{
				array->swap(index, leftChild);
				index = leftChild;
				shifted = true;
			}
		}
		cout << "fixing for index : " << index << endl;
		printData();
		system("pause");
	}
}

void Heap::printNode(string& sMiddle, string &sBefore, int currNode)
{
	string s;
	if (currNode < array->getSize())
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << (*array)[currNode] << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), 2 * currNode + 1);
	}
}
