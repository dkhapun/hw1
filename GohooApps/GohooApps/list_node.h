#pragma once
#include <stdlib.h>

template <class D>
class ListNode
{
public:
	ListNode<D>* pnext;
	ListNode<D>* pprev;
	D* pdata;

	ListNode(D const& data)
	{
		pdata = new D(data);
	}

	~ListNode()
	{
		delete pdata;
	}
};
