#pragma once

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
		AVLNode<V> mRoot;
	};
}