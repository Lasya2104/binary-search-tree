#ifndef binary_tree
#define binary_tree
#include <iostream>
using namespace std;
struct treenode
{
	int data;
	treenode *left;
	treenode *right;
	treenode(int val)
	{
		data=val;
		left=right=NULL;
	}
};
struct bst
{
	treenode *root=NULL;
	treenode *ADD(int val,treenode *root)
	{
		if(root==NULL)return new treenode(val);
		else if(val<root->data)
		{
			root->left=ADD(val,root->left);
		}
		else
		{
			root->right=ADD(val,root->right);
		}
	}
	void insert(int val)
	{
		root=ADD(val,root);
	}
	void inorder(treenode *root)
	{
		if(root==NULL)return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
};
#endif