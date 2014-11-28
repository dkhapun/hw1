#include "AVLTree.h"
#define pow2(n) (1 << (n))

AVLTree<V>::AVLTree(void)
{
}


AVLTree<V>::~AVLTree(void)
{
}
/*
 * Height of AVL Tree
 */
int AVLTree<V>::height(AVLNode *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
/*
 * Height Difference 
 */
int AVLTree<V>::diff(AVLNode *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
/*
 * Right- Right Rotation
 */
AVLNode *AVLTree<V>::rr_rotation(AVLNode *parent)
{
    AVLNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
AVLNode *AVLTree<V>::ll_rotation(AVLNode *parent)
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
/*
 * Left - Right Rotation
 */
AVLNode *AVLTree<V>::lr_rotation(AVLNode *parent)
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
/*
 * Right- Left Rotation
 */
AVLNode *AVLTree<V>::rl_rotation(AVLNode *parent)
{
    AVLNode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
/*
 * Balancing AVL Tree
 */
AVLNode *AVLTree<V>::balance(AVLNode *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) >= 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) <= 0)
			temp = rr_rotation (temp);   
        else
            temp = rl_rotation (temp);
    }
    return temp;
}
 
/*
 * Insert Element into the tree
 */
AVLNode *AVLTree<V>::insert(AVLNode *root, int value)
{
    if (root == NULL)
    {
        root = new AVLNode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 
/*
 * Display AVL Tree
 */
void AVLTree<V>::display(AVLNode *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
 
/*
 * Inorder Traversal of AVL Tree
 */
void AVLTree<V>::inorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
void AVLTree<V>::preorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);
 
}
 
/*
 * Postorder Traversal of AVL Tree
 */
void AVLTree<V>::postorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}
