#pragma once
#include <stdlib.h>

template <class R, class P>
class Functor
{
public:
	virtual R operator ()(P param) const = 0;
};
