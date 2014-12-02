// mivnei1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include "avltree\AVLTree.h"
using namespace std;


struct App
{
	int id;
	int down;
	int ver;
};
class GetID
{
public:
	int operator()(App in)
	{
		return in.id;
	}
};

class GetDownloads
{
public: 
	int operator()(App in)
	{
		return in.down;
	}
};

void printNode(int data)
{
	cout << "'" << data << "',";
}
/*
 * Main Contains Menu
 */
int test()
{
	avl_tree::AVLTree<int, int> avl;
	assert(avl.empty() == true);
	avl.insert(8);
	assert(avl.empty() == false);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(5);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(4);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(11);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(15);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(3);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(6);
	avl.display(1);
	cout << endl << "-------------------------------" << endl;
	avl.insert(2);
	avl.display(1);
	cout << endl << "-------------------------------" << endl; 
	avl.preorder();
	cout << endl << "-------------------------------" << endl;
	avl.postorder();
	cout << endl << "-------------------------------" << endl;
	avl.inorder();
	cout << endl << "-------------------------------" << endl;
	avl.for_each_inorder(printNode);

	assert(avl.find(20) == 0);
	assert(*(avl.find(5)) == 5);
	assert(*(avl.find(15)) == 15);
	assert(*(avl.find(4)) == 4);
	assert(avl.find(7) == 0);
	assert(*(avl.max()) == 15);

	avl.remove(4);
	avl.remove(2);
	avl.display(1);
	avl.remove(5);
	avl.display(1);
    return 0;
}
 
void test2()
{
	App a1 = { 1, 2, 3 };
	App a2 = { 2, 3, 4 };
	App a3 = { 3, 4, 5 };
	App a4 = { 4, 5, 6 };
	App a5 = { 5, 6, 7 };
	App a6 = { 6, 7, 8 };

	avl_tree::AVLTree<App, int> avl;
}
int main(int argc, char* argv[])
{
	cout << "testing";
	test();
	return 0;
}

