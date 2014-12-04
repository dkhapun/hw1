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
	msize(0)
	{
	}

	/*construct copy*/
	List(List<D> const& other)
	:
	pfirst(NULL),
	plast(NULL),
	msize(0)
	{
		merge(other);
	}

	/*assignment*/
	List<D>& operator =(List<D> const& other)
	{
		removeAll();
		merge(other);
		return *this;
	}

	/*destruct*/
	~List()
	{
		removeAll();
	}

	/*remove all nodes*/
	void removeAll()
	{
		ListNode<D>* pcurrent = pfirst;
		ListNode<D>* pnext;
		while(pcurrent != NULL)
		{
			pnext = pcurrent->pnext;
			delete pcurrent;
			pcurrent = pnext;
		}
		pfirst = NULL;
		plast = NULL;
		msize = 0;
	}

	/*get size of list*/
	int size() const
	{
		return msize;
	}

	/*check if empty*/
	int empty() const
	{
		return pfirst == 0;
	}
	
	/*get iterator to first node
	null if there isn't one*/
	ListIter<D> begin() const
	{
		return ListIter<D>(pfirst);
	}
	/*get iterator to last node
	null if there isn't one*/
	ListIter<D> end() const
	{
		return ListIter<D>(plast);
	}

	/*find data of first match, null if not found*/
	template<typename K>
	D* find(K key)
	{
		ListNode<D>* pnode = begin().pnode;
		while (pnode != NULL && K(*pnode->pdata) != key)
		{
			pnode = pnode->pnext; 
		}
		if(pnode != NULL)
		{
			return pnode->pdata;
		}
		else
		{
			return NULL;
		}
	}

	/*find and return iterator to the first matching node.
	null if not found*/
	ListIter<D> find(Functor<bool, D const&> const& isMatch, bool)
	{
		return find(begin(), isMatch);
	}

	/*a more general find, starts search from an iterator*/
	ListIter<D> find(ListIter<D> iter, Functor<bool, D const&> const& isMatch)
	{
		ListNode<D>* pnode = iter.pnode;
		while(pnode != NULL && !isMatch(*(pnode->pdata)))
		{
			pnode = pnode->pnext;
		}
		return ListIter<D>(pnode);
	}


	/*insert after where the iterator is pointing
	  NULL iterator means insert as first*/
	ListIter<D> insert(ListIter<D> iter, D const& data)
	{
		/*create node*/
		ListNode<D>* pnode = new ListNode<D>(data);
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
		++msize;
		return ListIter<D>(pnode);
	}

	/*delete a node pointed by an iterator*/
	void remove(ListIter<D> iter)
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
		--msize;
		delete iter.pnode;
		iter.pnode = NULL;
	}

	/*merge a list into this list. will keep increasing order using operator < */
	List<D>& merge(List<D> const& other)
	{
		ListIter<D> pcurrent = begin();
		ListIter<D> pprev = NULL;
		ListIter<D> pother = other.begin();
		while(pother != NULL)
		{
			if(pcurrent == NULL || *pother < *pcurrent)
			{
				/*insert after prev*/
				pprev = insert(pprev, *pother);
			}
			else
			{
				/*insert after current*/
				pprev = insert(pcurrent, *pother);
				++(++pcurrent);
			}
			++pother;
		}
		return *this;
	}

private:
	ListNode<D>* pfirst;
	ListNode<D>* plast;
	int msize;
};
