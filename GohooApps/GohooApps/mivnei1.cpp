// mivnei1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include "AVLTree.h"
using namespace std;


/*
 * Main Contains Menu
 */
int test()
{
	avl_tree::AVLTree<int, int, avl_tree::DefaultKeyGetter<int, int> > avl;
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
	
    return 0;
}
 

int main(int argc, char* argv[])
{
	cout << "testing";
	test();
	return 0;
}

