#pragma once
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "list.h"
#define pow2(n) (1 << (n))

using std::cout;
using std::endl;
using std::cin;

/*
 * C++ program to Implement AVL Tree
 */

namespace avl_tree
{
	/**********************************************************
	 * Node Declaration
	 * this is a node for the AVL tree
	 * V is the data stored in each node
	 **********************************************************/
	template<class V>
	class AVLNode
	{
	public:

		AVLNode(const V& data);
		AVLNode(const V& data, AVLNode *left, AVLNode *right);

		V* mdata;
		short bf; /*balance factor*/
		AVLNode *left;
		AVLNode *right;
		~AVLNode();
	};

	/*********************************************************
	 * AVLTree Declaration
	 * V is the value/data stored in each node. It should support a
	 * conversion to K.
	 * K is the key that is in the data
	 *********************************************************/
	template<typename V, typename K>
	class AVLTree
	{
	public:
		/*getnum of node in tree*/
		int size() const;
		/*find value by key, return 0 if not found*/
		V* find(K);
		/*get the value with max key*/
		V* max();
		/*get the value with min key*/
		V* min();
		/*get height of tree*/
		int height();
		/*check if empty*/
		bool empty();
		/*insert new value to the tree*/
		V* insert(V);
		/*remove value from the tree, by its key*/
		void remove(K);
		/*print out the values ordered like a tree*/
		void display(int level);
		/*print out values inorder*/
		void inorder();
		/*print out values preorder*/
		void preorder();
		/*print out values postorder*/
		void postorder();
		/*creates an inrodered list of the values that are in the tree*/
		List<V> toList();
		/*generic foreach*/
		template<class Do>
		void forEachInorder(Do& callback);
		template<class Do>
		void forEachInorderReverse(Do& callback);

	private:
		AVLNode<V> *balance(AVLNode<V> *);
		AVLNode<V> *insert(AVLNode<V> *, V , AVLNode<V> **inserted);
		AVLNode<V> *find(AVLNode<V> * root, K key);
		AVLNode<V> *remove(AVLNode<V> * root, K key);
		
		AVLNode<V> *rr_rotation(AVLNode<V> *);
		AVLNode<V> *ll_rotation(AVLNode<V> *);
		AVLNode<V> *lr_rotation(AVLNode<V> *);
		AVLNode<V> *rl_rotation(AVLNode<V> *);

		int height(AVLNode<V> *);
		int diff(AVLNode<V> *);
		void updateMinMax();
		void display(AVLNode<V> *, int level);
		AVLNode<V> * findMin(AVLNode<V> *);
		template<class Do>
		void forEachInorder(AVLNode<V> *, Do& callback);
		template<class Do>
		void forEachInorderReverse(AVLNode<V> *, Do& callback);
		

		void inorder(AVLNode<V> *);
		void preorder(AVLNode<V> *);
		void postorder(AVLNode<V> *);
		
		class ListGatherer
		{
		public:
			List<V> list;
			void operator()(V data)
			{
				list.insert(list.begin(), data);
			}

		};

		AVLNode<V>* mRoot;
		AVLNode<V>* mMax;
		AVLNode<V>* mMin;
		int msize;
	public:
		/*construct empty*/
		AVLTree();
		/*destruct*/
		~AVLTree();
		
	};


/*********************************************************
* Node implementation
*********************************************************/
template<typename V>
AVLNode<V>::AVLNode(const V& data) : left(0), right(0)
{
	mdata = new V(data);
}
template<typename V>
AVLNode<V>::AVLNode(const V& data, AVLNode *left, AVLNode *right) : left(left), right(right)
{
	mdata = new V(data);
}
template<typename V> 
AVLNode<V>::~AVLNode()
{
	if (left != 0)
	{
		delete left;
	}
	if (right != 0)
	{
		delete right;
	}
	if (mdata != 0)
	{
		delete mdata;
	}
}

/*********************************************************
* AVLTree implementation
*********************************************************/

template<typename V, typename K>
AVLTree<V, K>::AVLTree(void) : mRoot(0), msize(0)
{
}


template<typename V, typename K>
AVLTree<V, K>::~AVLTree(void)
{
	if (mRoot != 0)
	{
		delete mRoot;
	}
}

template<typename V, typename K>
int AVLTree<V, K>::size() const
{
	return msize;
}

template<typename V, typename K>
int AVLTree<V, K>::height(AVLNode<V> *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

template<typename V, typename K>
int AVLTree<V, K>::height()
{
	return height(mRoot);
}


template<typename V, typename K>
AVLNode<V> * AVLTree<V, K>::find(AVLNode<V> * root, K key)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (key < (K)(*(root->mdata)))
	{
		root = find(root->left, key);
	}
	else if (key > (K)(*(root->mdata)))
	{
		root = find(root->right, key);
	}
	return root;
}
template<typename V, typename K>
V* AVLTree<V, K>::find(K key)
{
	AVLNode<V> * temp = find(mRoot, key);
	if (temp == 0)
		return 0;
	return temp->mdata;
}
template<typename V, typename K>
V* AVLTree<V, K>::max()
{
	return mMax->mdata;
}

/*
* Height Difference
*/
template<typename V, typename K>
int AVLTree<V, K>::diff(AVLNode<V> *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::rr_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::ll_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
* Left - Right Rotation
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::lr_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::rl_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::balance(AVLNode<V> *temp)
{
	AVLNode<V> *parent = temp;
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) >= 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) <= 0)
			temp = rr_rotation(temp);
		else
			temp = rl_rotation(temp);
	}
	if (parent == mRoot)
		mRoot = temp;
	return temp;
}

/*
* insert Element into the tree
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::insert(AVLNode<V> *root, V value, AVLNode<V> **inserted)
{
	AVLNode<V> * tmp = 0;
	if (root == NULL)
	{
		root = new AVLNode<V>(value);
		*inserted = root;
		++msize;
		return root;
	}
	else if ((K) (value) < (K) (*(root->mdata)))
	{
		if (((tmp = insert(root->left, value, inserted)) == 0))
			return 0;
		root->left = tmp;
		root = balance(root);
	}
	else if ((K) (value) > (K) (*(root->mdata)))
	{
		if (((tmp = insert(root->right, value, inserted)) == 0))
			return 0;
		root->right = tmp;
		root = balance(root);
	}
	else if ((K) (value) == (K) (*(root->mdata)))
	{
		return 0;
	}

	return root;
}
template<typename V, typename K>
V* AVLTree<V, K>::insert(V value)
{
	AVLNode<V>* inserted = 0;
	AVLNode<V>* cur = insert(mRoot, value, &inserted);
	if (mRoot == 0)
	{
		mRoot = cur;
	}
	updateMinMax();
	return inserted == 0 ? 0 : inserted->mdata;
	
}

template<typename V, typename K>
void AVLTree<V, K>::updateMinMax()
{
	AVLNode<V> * temp = mRoot;
	if (temp == 0)
	{
		return;
	}
	while (temp->left != 0)
	{
		temp = temp->left;
	}
	mMin = temp;

	temp = mRoot;
	while (temp->right != 0)
	{
		temp = temp->right;
	}
	mMax = temp;
}


template<typename V, typename K>
V* AVLTree<V, K>::min()
{
	return mMin->mdata;
}

template<typename V, typename K>
AVLNode<V>* AVLTree<V, K>::findMin(AVLNode<V> * temp)
{

	while (temp->left != 0)
	{
		temp = temp->left;
	}
	return temp;
}



/*
* remove element from the tree
*/
template<typename V, typename K>
AVLNode<V> *AVLTree<V, K>::remove(AVLNode<V> *root, K value)
{
	if (root == NULL)
	{
		return root;
	}
	AVLNode<V> * toremove = 0;
	AVLNode<V> ** rootside = 0;
	
	//test if we found the node to remove

	if (root->left && (K)(value) == (K) (*(root->left->mdata)))
	{
		toremove = root->left;
		rootside = &root->left;
	}
	else if (root->right && (K)(value) == (K) (*(root->right->mdata)))
	{
		toremove = root->right;
		rootside = &root->right;
	}
	if (toremove != 0)
	{
		if (toremove->left == 0 && toremove->right == 0)
		{
			*rootside = 0;
		}
		if (toremove->left == 0 && toremove->right != 0)
		{
			*rootside = toremove->right;
		}
		else if (toremove->left != 0 && toremove->right == 0)
		{
			*rootside = toremove->left;
		}
		else if (toremove->left != 0 && toremove->right != 0)
		{
			//goto to minimum in the right subtree
			AVLNode<V> * mind = findMin(toremove->right);
			V* tval = new V(*mind->mdata);
			remove(mRoot, (K)(*tval));
			toremove->mdata = tval;
		}
		return toremove;
	}
	else if ((K)(value) < (K)(*(root->mdata)))
	{
		toremove = remove(root->left, value);
	}
	else if ((K)(value) > (K)((*root->mdata)))
	{
		toremove = remove(root->right, value);
	}
	if (toremove != 0)
	{
		delete toremove;
		root = balance(root);
	}
	return root;
}
template<typename V, typename K>
void AVLTree<V, K>::remove(K value)
{
	if (empty())
		return;

	AVLNode<V>* cur;

	if ((K) (value) == (K) (*(mRoot->mdata)))
	{
		//goto to minimum in the right subtree
		if (mRoot->right == 0)
		{
			cur = mRoot;
			mRoot = mRoot->left;
			delete cur;
		}
		else
		{
			AVLNode<V> * mind = findMin(mRoot->right);
			V* tval = new V(*mind->mdata);
			remove(mRoot, (K) (*tval));
			mRoot->mdata = tval;
			cur = mRoot;
		}
	}
	else
	{
		cur = remove(mRoot, value);
	}
	
	updateMinMax();
	if (cur != 0)
	{
	//	delete cur;
	}
	else
	{
		throw std::logic_error("node not found");
	}
}

template<typename V, typename K>
List<V> AVLTree<V, K>::toList()
{
	ListGatherer getter;
	forEachInorder(mRoot, getter);
	return getter.list;
}

template<typename V, typename K>
bool AVLTree<V, K>::empty()
{
	return mRoot == 0;
}

/*
* Display AVL Tree
*/
template<typename V, typename K>
void AVLTree<V, K>::display(AVLNode<V> *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == mRoot)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != mRoot; i++)
			cout << "        ";
		cout << *(ptr->mdata);
		display(ptr->left, level + 1);
	}
}
template<typename V, typename K>
void AVLTree<V, K>::display(int level)
{
	display(mRoot, level);
}
/*
* Inorder Traversal of AVL Tree
*/
template<typename V, typename K>
void AVLTree<V, K>::inorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << *(tree->mdata) << "  ";
	inorder(tree->right);
}
template<typename V, typename K>
void AVLTree<V, K>::inorder()
{
	inorder(mRoot);
}

template<typename V, typename K>
template<class Do>
void AVLTree<V, K>::forEachInorder(AVLNode<V> *tree, Do& callback)
{
	if(tree == NULL)
		return;
	forEachInorder(tree->left, callback);
	callback(*(tree->mdata));
	forEachInorder(tree->right, callback);
}

template<typename V, typename K>
template<class Do>
void AVLTree<V, K>::forEachInorderReverse(AVLNode<V> *tree, Do& callback)
{
	if(tree == NULL)
		return;
	forEachInorderReverse(tree->right, callback);
	callback(*(tree->mdata));
	forEachInorderReverse(tree->left, callback);
}

template<typename V, typename K>
template<class Do>
void AVLTree<V, K>::forEachInorder(Do& callback)
{
	forEachInorder(mRoot, callback);
}

template<typename V, typename K>
template<class Do>
void AVLTree<V, K>::forEachInorderReverse(Do& callback)
{
	forEachInorderReverse(mRoot, callback);
}

/*
* Preorder Traversal of AVL Tree
*/
template<typename V, typename K>
void AVLTree<V, K>::preorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	cout << *(tree->mdata) << "  ";
	preorder(tree->left);
	preorder(tree->right);

}
template<typename V, typename K>
void AVLTree<V, K>::preorder()
{
	preorder(mRoot);
}
/*
* Postorder Traversal of AVL Tree
*/
template<typename V, typename K>
void AVLTree<V, K>::postorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << *(tree->mdata) << "  ";
}
template<typename V, typename K>
void AVLTree<V, K>::postorder()
{
	postorder(mRoot);
}

}