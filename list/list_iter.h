#pragma once
#include "list_node.h"
#include <stdlib.h>

/*iterator wraps up a node pointer for outside use*/

/*declare friends*/
template <class D> class List;

template <class D>
class ListIter
{
friend List<D>;
public:
	/*construct empty*/
	ListIter()
	:
	pnode(NULL)
	{
	}

	/*construct*/
	ListIter(ListNode<D>* pnod)
	:
	pnode(pnod)
	{
	}

	/*better not call this with NULL iterator*/
	D& operator *()
	{
		return pnode->data;
	}
	
	ListIter& operator ++()
	{
		if(pnode != NULL)
		{
			pnode = pnode->pnext;
		}
	}
	
	ListIter& operator --()
	{
		if(pnode != NULL)
		{
			pnode = pnode->pprev;
		}
	}

	friend bool operator ==(ListIter const& iter1, ListIter const& iter2)
	{
		return iter1.pnode == iter2.pnode;
	}

	friend bool operator !=(ListIter const& iter1, ListIter const& iter2)
	{
		return iter1.pnode != iter2.pnode;
	}

private:
	ListNode<D>* pnode;

};
