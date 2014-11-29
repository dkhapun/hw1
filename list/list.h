#pragma once
#include "list_node.h"
#include "list_iter.h"
#include <stdlib.h>

template <class D>
class List
{
public:
	/*construct empty*/
	List()
	:
	pfirst(NULL),
	plast(NULL),
	size(0)
	{
	}

	/*todo? construct copy*/
	/*todo? operator =*/

	~List()
	{
		
	}

	int Size() const
	{
		return size;
	}

	ListIter<D> First() const
	{
		return ListIter<D>(pfirst);
	}

	ListIter<D> Last() const
	{
		return ListIter<D>(plast);
	}

	/*Insert after where the iterator is pointing
	  NULL iterator means insert as first*/
	void Insert(ListIter<D> iter, D const& data)
	{
		/*create node*/
		ListNode<D>* pnode = new ListNode<D>;
		pnode->data = D(data);
		/*connect it*/
		pnode->pprev = iter.pnode;
		if(iter.pnode != NULL)
		{
			pnode->pnext = iter.pnode->pnext;
			iter.pnode->pnext = pnode;
		}
		else
		{
			pnode->pnext = pfirst;
			pfirst = pnode;
		}
		if(pnode->pnext != NULL)
		{
			pnode->pnext->pprev = pnode;
		}
		else
		{
			plast = pnode;
		}
		/**/
		++size;
	}

	void Delete(ListIter<D> iter)
	{
		/*nothing to delete*/
		if(iter.pnode == NULL){
			return;
		}

		/*disconnect it*/
		if(iter.pnode->pnext != NULL)
		{
			iter.pnode->pnext->pprev = iter.pnode->pprev;
		}
		else
		{
			plast = iter.pnode->pprev;
		}
		if(iter.pnode->pprev != NULL)
		{
			iter.pnode->pprev->pnext = iter.pnode->pnext;
		}
		else
		{
			pfirst = iter.pnode->pnext;
		}
		/**/
		--size;
		delete iter.pnode;
		iter.pnode = NULL;
	}

private:
	ListNode<D>* pfirst;
	ListNode<D>* plast;
	int size;
};
