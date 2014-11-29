#include "list.h"
#include <stdio.h>

void Print(List<int> const& list)
{
	ListIter<int> iter;
	for(ListIter<int> iter = list.First(); iter != NULL; ++iter)
	{
		printf("%d  ", *iter);
	}
	printf("\n");
	printf("size %d\n", list.Size());
}

int main()
{
	List<int> list;
	ListIter<int> iter;
	
	Print(list);
	list.Insert(NULL, 33);
	Print(list);


	for(int i = 10; i > 0; --i)
	{
		list.Insert(NULL, i);
	}
	Print(list);


	while(*list.First() != 10)
	{
	 list.Delete(list.First());
	}
	Print(list);


	for(int i = 10; i > 0; --i)
	{
		list.Insert(list.Last(), i);
	}
	Print(list);


	while(list.First() != NULL)
	{
	 list.Delete(list.First());
	}
	Print(list);


	return 0;
}
