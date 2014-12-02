#pragma once
#include "list_node.h"
#include "list_iter.h"
#include "functor.h"
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
	/*destruct*/
	~List()
	{
		ListNode<D>* pcurrent = pfirst;
		ListNode<D>* pnext;
		while(pcurrent != NULL)
		{
			pnext = pcurrent->pnext;
			delete pcurrent;
			pcurrent = pnext;
		}
	}
	/*get size of list*/
	int Size() const
	{
		return size;
	}
	/*get iterator to first node
	null if there isn't one*/
	ListIter<D> First() const
	{
		return ListIter<D>(pfirst);
	}
	/*get iterator to last node
	null if there isn't one*/
	ListIter<D> Last() const
	{
		return ListIter<D>(plast);
	}

	/*Find and return iterator to the first matching node.
	  null if not found*/
	ListIter<D> Find(Functor<bool, D const&> const& isMatch)
	{
		return Find(First(), isMatch);
	}

	/*a more general Find, starts search from an iterator*/
	ListIter<D> Find(ListIter<D> iter, Functor<bool, D const&> const& isMatch)
	{
		ListNode<D>* pnode = iter.pnode;
		while(pnode != NULL && !isMatch(pnode->data))
		{
			pnode = pnode->pnext;
		}
		return ListIter<D>(pnode);
	}

	/*Insert after where the iterator is pointing
	  NULL iterator means insert as first*/
	ListIter<D> Insert(ListIter<D> iter, D const& data)
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
		return ListIter<D>(pnode);
	}

	/*delete a node pointed by an iterator*/
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

	/*merge a list into this list. will keep order using < operator 
	:/*/
	List<D>& Merge(List<D> const& other)
	{
		ListIter<D> pcurrent = First();
		ListIter<D> pprev = NULL;
		ListIter<D> pother = other.First();
		while(pother != NULL)
		{
			if(pcurrent == NULL || *pother < *pcurrent)
			{
				/*insert after prev*/
				pprev = Insert(pprev, *pother);
			}
			else
			{
				/*insert after current*/
				pprev = Insert(pcurrent, *pother);
				++(++pcurrent);
			}
			++pother;
		}
		return *this;
	}

private:
	ListNode<D>* pfirst;
	ListNode<D>* plast;
	int size;
};
