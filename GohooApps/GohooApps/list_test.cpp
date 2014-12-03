#include "list.h"
#include <stdio.h>

void Print(List<int> const& list)
{
	ListIter<int> iter;
	for(ListIter<int> iter = list.begin(); iter != NULL; ++iter)
	{
		printf("%d  ", *iter);
	}
	printf("\n");
	printf("size %d\n", list.size());
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
	list.insert(NULL, 33);
	Print(list);

	for(int i = 10; i > 0; --i)
	{
		list.insert(NULL, i);
	}
	Print(list);


	while(*list.begin() != 10)
	{
	 list.remove(list.begin());
	}
	Print(list);

	while(list.begin() != NULL)
	{
	 list.remove(list.begin());
	}
	Print(list);

	list.insert(NULL, 44);
	for(int i = 10; i > 0; --i)
	{
		list.insert(list.end(), i);
	}
	Print(list);


	iter = list.find(Equals(7), true);
	if(iter != NULL) {printf("%d\n", *iter);} else {printf("is null\n");}
	
	iter = list.find(Equals(55), true);
	if(iter != NULL) {printf("%d\n", *iter);} else {printf("is null\n");}

	list.insert(NULL, 55);
	list.insert(list.end(), 55);
	Print(list);

	iter = list.find(Equals(55), true);
	if(iter != NULL) {printf("next %d\n", *(++iter));} else {printf("is null\n");}

	/*find start at iter*/
	/*at start*/
	iter = list.begin();
	iter = list.find(iter, Equals(55));
	if(iter != NULL) {printf("next %d\n", *(++iter));} else {printf("is null\n");}
	/*at end*/
	iter = ++(list.begin());
	iter = list.find(iter, Equals(55));
	if(iter != NULL) {printf("prev %d\n", *(--iter));} else {printf("is null\n");}
	
	/*merge test
	**************/	
	List<int> otherList;
	list.removeAll();
	/*empty empty*/
	list.merge(otherList);
	Print(list);	 
	/*notempty empty*/
	for(int i = 10; i > 0; --i)
	{
		list.insert(NULL, i);
	}
	list.merge(otherList);
	Print(list);		 
	/*empty notempty*/
	otherList.merge(list);
	Print(otherList);		 
	/*notempty notempty*/		 
	list.merge(otherList);
	Print(list);

	return 0;
}
