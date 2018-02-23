#include "stdafx.h"
#include "List.h"

using namespace std;

void List::printData()
{
	if (!isEmpty()) 
	{
		Node* tmp = head.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->next.get();
		}
		cout << endl;

		tmp = tail.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->prev.get();
		}
		cout << endl;
	}	
	else 
		cout << "Lista jest pusta" << endl;
}

void List::pushBack(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);
	
	if (!isEmpty()) 
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else 
	{
		tail = newNode;
		head = newNode;
	}

	++size;
}

void List::pushFront(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);

	if (!isEmpty())
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		tail = newNode;
		head = newNode;
	}

	++size;
}

void List::addElement(int index, int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);
	shared_ptr<Node> currNode = getNodePtr(index);

	if (index == 0)
	{
		pushFront(value);
		return;
	}

	if (index == size )
	{
		pushBack(value);
		return;
	}

	if (currNode != nullptr)
	{
		if (currNode->prev == nullptr)
			head = newNode;
		else
			currNode->prev->next = newNode;
		if (currNode->next == nullptr)
			tail = currNode;
		newNode->prev = currNode->prev;
		currNode->prev = newNode;
		newNode->next = currNode;
		++size;
	}
	else if (size == 0 && index == 0)
	{
		pushFront(value);
	}
	else
		throw invalid_argument("Indeks poza zakresem");

}

void List::addElement(int value)
{
	pushBack(value);
}

void List::removeElement(int value)
{
	if (findValue(value))
		--size;

	shared_ptr<Node> toDelete = head;
	while (toDelete != nullptr)
	{
		if (toDelete->data == value)
			break;
		toDelete = toDelete->next;
	}

	if (toDelete != nullptr)
	{
		if (toDelete->prev == nullptr)
			head = toDelete->next;
		else
			toDelete->prev->next = toDelete->next;

		if (toDelete->next == nullptr)
			tail = toDelete->prev;
		else
			toDelete->next->prev = toDelete->prev;

		toDelete->prev.reset();
		toDelete->next.reset();
	}
	
}

void List::clearStructure()
{
	if (!isEmpty())
	{
		shared_ptr<Node> currNode = head;
		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
			currNode->prev->next.reset();
			currNode->prev.reset();
		}
		head.reset();
		tail.reset();
		size = 0;
	}
}

bool List::findValue(int toFind)
{
	if (isEmpty())
		return false;

	shared_ptr<Node> currNode = head;
	while (currNode != nullptr)
	{
		if (currNode->data == toFind)
			return true;
		currNode = currNode->next;
	}
	return false;
}

int List::getSize()
{
	return size;
}

bool List::isEmpty()
{
	return size == 0;
}

shared_ptr<List::Node> List::getNodePtr(int index)
{
	if (isEmpty())
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode;
}