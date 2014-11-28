#pragma once
class AVLTree
{
public:
	AVLTree(void);
	~AVLTree(void);
};

/*
 * C++ program to Implement AVL Tree
 */

 
/*
 * Node Declaration
 */
template<class V>
class AVLNode
{
	AVLNode(const V& data);
    V data;
	short bf;
    AVLNode *left;
    AVLNode *right;
	~AVLNode();
};
 
/*
 * Class Declaration
 */
template<class V, class K>
class AVLTree
{
    public:
        int height(AVLNode<V> *);
        int diff(AVLNode<V> *);

		void insert(V);
		void find(K);
		void remove(K);
        void display(AVLNode<V> *, V);
        void inorder(AVLNode<V> *);
        void preorder(AVLNode<V> *);
        void postorder(AVLNode<V> *);
		
	private:
		AVLNode<V>* balance(AVLNode<V> *);
        AVLNode<V>* insert(AVLNode<V> *, V);
        AVLNode<V> *rr_rotation(AVLNode<V> *);
        AVLNode<V> *ll_rotation(AVLNode<V> *);
        AVLNode<V> *lr_rotation(AVLNode<V> *);
        AVLNode<V> *rl_rotation(AVLNode<V> *);
		
        AVLTree();
		
		~AVLTree();
		AVLNode<V> mRoot;
};