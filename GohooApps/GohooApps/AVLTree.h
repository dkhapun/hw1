#pragma once
#include <stdexcept>
#include <iostream>
#define pow2(n) (1 << (n))

using std::cout;
using std::endl;
using std::cin;

/*
 * C++ program to Implement AVL Tree
 */

namespace avl_tree
{
	/*
	 * Node Declaration
	 */
	template<class V>
	class AVLNode
	{
	public:

		AVLNode(const V& data);
		AVLNode(const V& data, AVLNode *left, AVLNode *right);

		V mdata;
		short bf;
		AVLNode *left;
		AVLNode *right;
		~AVLNode();
	};
	template<typename V, typename K>
	class DefaultKeyGetter
	{
	public:
		K operator()(V in)
		{
			return K(in);
		}
	};

	/*
	 * Class Declaration
	 */
	template<typename V, typename K, typename KeyGetter>
	class AVLTree
	{
	public:
		V* find(K);
		V* max();
		int height();
		bool empty();
		void insert(V);
		void remove(K);
		void display(int level);
		void inorder();
		void preorder();
		void postorder();

	private:
		AVLNode<V> *balance(AVLNode<V> *);
		AVLNode<V> *insert(AVLNode<V> *, V, int lefts);
		AVLNode<V> *find(AVLNode<V> * root, K key);
		AVLNode<V> *remove(AVLNode<V> * root, K key);
		AVLNode<V> *min(AVLNode<V> * root);
		AVLNode<V> *rr_rotation(AVLNode<V> *);
		AVLNode<V> *ll_rotation(AVLNode<V> *);
		AVLNode<V> *lr_rotation(AVLNode<V> *);
		AVLNode<V> *rl_rotation(AVLNode<V> *);

		int height(AVLNode<V> *);
		int diff(AVLNode<V> *);
		
		void display(AVLNode<V> *, int level);
		void inorder(AVLNode<V> *);
		void preorder(AVLNode<V> *);
		void postorder(AVLNode<V> *);

		KeyGetter GetKey;
		AVLNode<V>* mRoot;
		AVLNode<V>* mMax;
	public:
		AVLTree();
		~AVLTree();
		
	};


template<typename V>
AVLNode<V>::AVLNode(const V& data) : left(0), right(0)
{
	mdata = data;
}
template<typename V>
AVLNode<V>::AVLNode(const V& data, AVLNode *left, AVLNode *right) : left(left), right(right)
{
	mdata = data;
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
}

template<typename V, typename K, typename KeyGetter>
AVLTree<V, K, KeyGetter>::AVLTree(void) : mRoot(0)
{
}

template<typename V, typename K, typename KeyGetter>
AVLTree<V, K, KeyGetter>::~AVLTree(void)
{
	if (mRoot != 0)
	{
		delete mRoot;
	}
}
/*
* Height of AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
int AVLTree<V, K, KeyGetter>::height(AVLNode<V> *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = ::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}
template<typename V, typename K, typename KeyGetter>
int AVLTree<V, K, KeyGetter>::height()
{
	return height(mRoot);
}


template<typename V, typename K, typename KeyGetter>
AVLNode<V> * AVLTree<V, K, KeyGetter>::find(AVLNode<V> * root, K key)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (key < GetKey(root->mdata))
	{
		root = find(root->left, key);
	}
	else if (key > GetKey(root->mdata))
	{
		root = find(root->right, key);
	}
	return root;
}
template<typename V, typename K, typename KeyGetter>
V* AVLTree<V, K, KeyGetter>::find(K key)
{
	AVLNode<V> * temp = find(mRoot, key);
	if (temp == 0)
		return 0;
	return &(temp->mdata);
}
template<typename V, typename K, typename KeyGetter>
V* AVLTree<V, K, KeyGetter>::max()
{
	return &(mMax->mdata);
}

/*
* Height Difference
*/
template<typename V, typename K, typename KeyGetter>
int AVLTree<V, K, KeyGetter>::diff(AVLNode<V> *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::rr_rotation(AVLNode<V> *parent)
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
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::ll_rotation(AVLNode<V> *parent)
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
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::lr_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::rl_rotation(AVLNode<V> *parent)
{
	AVLNode<V> *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::balance(AVLNode<V> *temp)
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
* Insert Element into the tree
*/
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::insert(AVLNode<V> *root, V value, int lefts)
{
	if (root == NULL)
	{
		root = new AVLNode<V>(value);
		if (lefts == 0)
		{
			mMax = root;
		}
		return root;
	}
	else if (GetKey(value) < GetKey(root->mdata))
	{
		root->left = insert(root->left, value, ++lefts);
		root = balance(root);
	}
	else if (GetKey(value) >= GetKey(root->mdata))
	{
		root->right = insert(root->right, value, lefts);
		root = balance(root);
	}
	return root;
}
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::insert(V value)
{
	AVLNode<V>* cur = insert(mRoot, value, 0);
	if (mRoot == 0)
	{
		mRoot = cur;
	}
	
}

template<typename V, typename K, typename KeyGetter>
AVLNode<V> * AVLTree<V, K, KeyGetter>::min(AVLNode<V> * root)
{
	AVLNode<V> * temp = root;
	while (temp->left != 0)
	{
		temp = temp->left;
	}
	return temp;
}
/*
* Insert Element into the tree
*/
template<typename V, typename K, typename KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::remove(AVLNode<V> *root, K value)
{
	if (root == NULL)
	{
		return root;
	}
	AVLNode<V> * toremove = 0;
	AVLNode<V> ** rootside = 0;
	
	//test if we found the node to remove
	if (GetKey(value) == GetKey(root->left->mdata))
	{
		toremove = root->left;
		rootside = &root->left;
	}
	else if (GetKey(value) == GetKey(root->right->mdata))
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
			AVLNode<V> * mind = min(toremove->right);
			V tval = mind->mdata;
			remove(mRoot, GetKey(tval));
			toremove->mdata = tval;
		}
		return toremove;
	}
	else if (GetKey(value) < GetKey(root->mdata))
	{
		toremove = remove(root->left, value);
	}
	else if (GetKey(value) > GetKey(root->mdata))
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
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::remove(K value)
{
	AVLNode<V>* cur = remove(mRoot, value);
	if (cur != 0)
	{
	//	delete cur;
	}
	else
	{
		throw std::logic_error("node not found");
	}

}



template<typename V, typename K, typename KeyGetter>
bool AVLTree<V, K, KeyGetter>::empty()
{
	return mRoot == 0;
}

/*
* Display AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::display(AVLNode<V> *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == mRoot)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != mRoot; i++)
			cout << "        ";
		cout << ptr->mdata;
		display(ptr->left, level + 1);
	}
}
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::display(int level)
{
	display(mRoot, level);
}
/*
* Inorder Traversal of AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::inorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->mdata << "  ";
	inorder(tree->right);
}
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::inorder()
{
	inorder(mRoot);
}
/*
* Preorder Traversal of AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::preorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	cout << tree->mdata << "  ";
	preorder(tree->left);
	preorder(tree->right);

}
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::preorder()
{
	preorder(mRoot);
}
/*
* Postorder Traversal of AVL Tree
*/
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::postorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->mdata << "  ";
}
template<typename V, typename K, typename KeyGetter>
void AVLTree<V, K, KeyGetter>::postorder()
{
	postorder(mRoot);
}

}