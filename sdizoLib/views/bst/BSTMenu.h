#pragma once
#include "views/genericView/GenericView.h"
class BSTMenu :
	public GenericView
{
public:
	BSTMenu() = default;
	virtual ~BSTMenu() = default;

	virtual void print();
};

