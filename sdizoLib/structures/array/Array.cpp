#include "stdafx.h"
#include "Array.h"

#include "../../views/array/ArrayMenu.h"

Array::Array() :
	isCheap(true)
	, allocatedSize(0)
	, currSize(0)
{}

Array::Array(int size) :
	data(std::make_unique<int[]>(size))
{
	allocatedSize = size;
	isCheap = false;
}

void Array::printData()
{
	if (!isEmpty())
		for (int index = 0; index < this->currSize; index++)
			std::cout << data[index] << ' ';
	else
		std::cout << "Tablica jest pusta!";
	std::cout << std::endl;
}

void Array::addElement(int index, int value)
{
	if (isEmpty() && index == 0)
	{
		data = std::make_unique<int[]>(1);
		allocatedSize = 1;
		data[index] = value;
		++currSize;
	}
	else if (index >= 0 && index < currSize)
	{
		if (allocatedSize < currSize + 1)
			this->realocate(allocatedSize + 1);
		moveElementsRight(index);
		data[index] = value;
		++currSize;
	}
	else if (index == currSize)
		pushBack(value);
	else
	{
		throw std::invalid_argument("Indeks poza zasiêgiem tablicy");
	}
	
	
}

void Array::addElement(int value)
{
	pushBack(value);
}

void Array::pushBack(int value)
{
	if (allocatedSize < currSize + 1)
		this->realocate(allocatedSize + 1);
	currSize++;
	data[currSize - 1] = value;
}

void Array::removeElement(int index)
{
	if (index >= 0 && index < getSize())
	{
		moveElementsLeft(index);
		realocate(allocatedSize - 1);
	}
	else
	{
		std::stringstream ss;
		ss << "Indeks poza zasiêgiem tablicy( podano: " << index << " max: " << getSize();
		throw std::invalid_argument(ss.str());
	}

}

void Array::clearStructure()
{
	data.reset();
	currSize = 0;
	allocatedSize = 0;
}

void Array::realocate(int newSize)
{
	if (newSize == 0)
	{
		data.reset();
		currSize = 0;
		allocatedSize = 0;
	}

	std::unique_ptr<int[]> newData = std::make_unique<int[]>(newSize);
	int moveDataToIndex = (newSize > currSize) ? currSize : newSize;
	for (int index = 0; index < moveDataToIndex; index++)
		newData[index] = data[index];
	data.reset();
	data = std::move(newData);
	allocatedSize = newSize;
	currSize = moveDataToIndex;
}

bool Array::findValue(int toFind)
{
	for (int index = 0; index < currSize; index++)
		if (data[index] == toFind)
			return true;
	return false;
}

void Array::realocateByStep()
{
	realocate(allocatedSize * 2);
}

int Array::getSize()
{
	return currSize;
}

bool Array::isEmpty()
{
	return (currSize == 0);
}

int Array::getValue(int index)
{
	if (index >= currSize)
		throw std::invalid_argument("Out of array range");
	return data[index];
}

void Array::setValue(int index, int value)
{
	if (index >= currSize)
		throw std::invalid_argument("Out of array range");
	data[index] = value;
}

void Array::swap(int b, int a)
{
	int tmp = data[b];
	data[b] = data[a];
	data[a] = tmp;
}

int Array::operator[](int index)
{
	return data[index];
}

void Array::moveElementsRight(int index)
{
	for (int i = allocatedSize - 1; i > index; --i)
		data[i] = data[i - 1];
}

void Array::moveElementsLeft(int index)
{
	for (int i = index; i < currSize - 1; ++i)
		data[i] = data[i + 1];
}