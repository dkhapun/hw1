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

class Equals : public Functor<bool, int const&>
{
public:
	/*constructor inits operand2*/
	Equals(int i)
	:
	operand2(i)
	{
	}

	bool operator ()(int const& operand1) const
	{
		return operand1 == operand2;
	}
private:
	int operand2;
};

/*list test*/
//int main()
int someLie()
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

	while(list.First() != NULL)
	{
	 list.Delete(list.First());
	}
	Print(list);

	list.Insert(NULL, 44);
	for(int i = 10; i > 0; --i)
	{
		list.Insert(list.Last(), i);
	}
	Print(list);


	iter = list.Find(Equals(7));
	if(iter != NULL) {printf("%d\n", *iter);} else {printf("is null\n");}
	
	iter = list.Find(Equals(55));
	if(iter != NULL) {printf("%d\n", *iter);} else {printf("is null\n");}

	list.Insert(NULL, 55);
	list.Insert(list.Last(), 55);
	Print(list);

	iter = list.Find(Equals(55));
	if(iter != NULL) {printf("next %d\n", *(++iter));} else {printf("is null\n");}

	/*find start at iter*/
	/*at start*/
	iter = list.First();
	iter = list.Find(iter, Equals(55));
	if(iter != NULL) {printf("next %d\n", *(++iter));} else {printf("is null\n");}
	/*at end*/
	iter = ++(list.First());
	iter = list.Find(iter, Equals(55));
	if(iter != NULL) {printf("prev %d\n", *(--iter));} else {printf("is null\n");}
	
	/*merge test
	**************/	
	List<int> otherList;
	while(list.First() != NULL) {list.Delete(list.First());}
	/*empty empty*/
	list.Merge(otherList);
	Print(list);	 
	/*notempty empty*/
	for(int i = 10; i > 0; --i)
	{
		list.Insert(NULL, i);
	}
	list.Merge(otherList);
	Print(list);		 
	/*empty notempty*/
	otherList.Merge(list);
	Print(otherList);		 
	/*notempty notempty*/		 
	list.Merge(otherList);
	Print(list);

	return 0;
}
