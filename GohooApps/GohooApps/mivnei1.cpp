// mivnei1.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include"AVLTree.h"
using namespace std;

 
/*
 * Main Contains Menu
 */
int test()
{
    //int choice = 40, item = 44;
	avl_tree::AVLTree<int, int, avl_tree::DefaultKeyGetter<int, int> > avl;
 /*   while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            avl.insert(item);
            break;
        case 2:
			if (avl.empty())
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display( 1);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorder();
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            avl.preorder();
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder();    
            cout<<endl;
            break;
        case 6:
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }*/
    return 0;
}
 

int main(int argc, char* argv[])
{
	return 0;
}

