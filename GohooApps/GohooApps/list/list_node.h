#pragma once
#include <stdlib.h>

template <class D>
class ListNode
{
public:
	ListNode<D>* pnext;
	ListNode<D>* pprev;
	D* data;
};
