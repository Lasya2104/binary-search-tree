#ifndef binary_search_tree
#define binary_search__tree
#include <iostream>
using namespace std;
class bst
{
	private:
		struct treenode
		{
			int data;
			treenode *left;
			treenode *right;
			treenode(int val):data(val),left(NULL),right(NULL){}
		};
		treenode *root;
		treenode *ADD(treenode *node,int val)
		{
			if(node==NULL)return new treenode(val);
			else if(val<node->data)
			{
				node->left=ADD(node->left,val);
			}
			else
			{
				node->right=ADD(node->right,val);
			}
			return node;
		}
		treenode *min(treenode *node)
		{
			while(node && node->left)
			{
				node=node->left;
				return node;
			}
		}
		treenode *deleted(treenode *node,int val)
		{
			if(node==NULL)return NULL;
			else if(val<node->data)
			{
				node->left=deleted(node->left,val);
			}
			else if(val>node->data)
			{
				node->right=deleted(node->right,val);
			}
			else
			{
				if(node->left==NULL)
				{
					treenode *temp=node->right;
					delete node;
					return temp;
				}
				else if(node->right==NULL)
				{
					treenode *temp=node->left;
					delete node;
					return temp;
				}
				else
				{
					treenode *temp=min(node->right);
					node->data=temp->data;
					node->right=deleted(node->right,temp->data);
				}
			}
			return node;
		}
		bool search(treenode *node,int val) const
		{
			if(node==NULL)return false;
			else if(val==node->data)return true;
			else if(val<node->data)return search(node->left,val);
			return search(node->right,val);
		}
		void inorder(treenode *node)const
		{
			if(node)
			{
				inorder(node->left);
				cout<<node->data<<" ";
				inorder(node->right);
			}
		}
		void free(treenode *node)
		{
			if(node)
			{
				free(node->left);
				free(node->right);
				delete node;
			}
		}
		public:
			bst():root(NULL){}
			~bst()
			{
				free(root);
			}
			void insert(int val)
			{
				root=ADD(root,val);
			}
			void remove(int val)
			{
				root=deleted(root,val);
			}
			bool exists(int val)
			{
				return search(root,val);
			}
			void printinorder()const
			{
				inorder(root);
				cout<<endl;
			}
};
#endif