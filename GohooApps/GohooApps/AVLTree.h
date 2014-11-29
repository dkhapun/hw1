#pragma once
#define pow2(n) (1 << (n))

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
		V mdata;
		short bf;
		AVLNode *left;
		AVLNode *right;
		~AVLNode();
	};
	template<typename V, typename K>
	class DefaultKeyGetter
	{
		K operator()(V in)
		{
			return K(in);
		}
	};

	/*
	 * Class Declaration
	 */
	template<typename V, typename K, class KeyGetter>
	class AVLTree
	{
	public:
		V* find(K);
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
		AVLNode<V> *insert(AVLNode<V> *, V);
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

	public:
		AVLTree();
		~AVLTree();
		AVLNode<V>* mRoot;
	};


template<typename V>
AVLNode<V>::AVLNode(const V& data) : left(0), right(0)
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


template<typename V, typename K, class KeyGetter>
AVLTree<V, K, KeyGetter>::AVLTree(void) : mRoot(0)
{
}

template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
int AVLTree<V, K, KeyGetter>::height(AVLNode<V> *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}
template<typename V, typename K, class KeyGetter>
int AVLTree<V, K, KeyGetter>::height()
{
	return height(mRoot);
}
/*
* Height Difference
*/
template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
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
template<typename V, typename K, class KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::balance(AVLNode<V> *temp)
{
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
	return temp;
}

/*
* Insert Element into the tree
*/
template<typename V, typename K, class KeyGetter>
AVLNode<V> *AVLTree<V, K, KeyGetter>::insert(AVLNode<V> *root, V value)
{
	if (root == NULL)
	{
		root = new AVLNode<V>;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::insert(V value)
{
	insert(mRoot, value);
}

template<typename V, typename K, class KeyGetter>
bool AVLTree<V, K, KeyGetter>::empty()
{
	return mRoot == 0;
}

/*
* Display AVL Tree
*/
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::display(AVLNode<V> *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

/*
* Inorder Traversal of AVL Tree
*/
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::inorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::inorder()
{
	inorder(mRoot);
}
/*
* Preorder Traversal of AVL Tree
*/
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::preorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	preorder(tree->left);
	preorder(tree->right);

}
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::preorder()
{
	preorder(mRoot);
}
/*
* Postorder Traversal of AVL Tree
*/
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::postorder(AVLNode<V> *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << "  ";
}
template<typename V, typename K, class KeyGetter>
void AVLTree<V, K, KeyGetter>::postorder()
{
	postorder(mRoot);
}

}