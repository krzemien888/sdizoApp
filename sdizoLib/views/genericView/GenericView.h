#pragma once

#include "stdafx.h"

class GenericView
{
    public:
		virtual ~GenericView() = default;
        virtual void print() = 0;
};

