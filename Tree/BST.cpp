#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
	
	node(int val)
	{
		data =val;
		left = nullptr;
		right = nullptr;
	}
	
};

class tree{
	public:
	node * insert(int val, node* tree)
	{
		if(tree == nullptr)
		{
		return new node(val);
		}
		else if(val < tree->data)
		{
			tree->left = insert(val,tree->left);
		}
		else if(val > tree->data)
		{
			tree->right= insert(val,tree->right);
		}
		return tree;
	}
	int found =0;
	void inorder(node *tree)
	{
		
		
		if(tree!= nullptr)
		{
		found =1;
		inorder(tree->left);
		cout<<tree->data<<" ";
		inorder(tree->right);
		}
		if(found ==0 && tree==nullptr)
		{
			cout<<"NO element"<<endl;
		}
	}
	void preorder(node *tree)
	{
		
		if(tree!= nullptr)
		{
		cout<<tree->data<<" ";
		preorder(tree->left);
		preorder(tree->right);
		}
	}
	void postorder(node *tree)
	{
		
		if(tree!= nullptr)
		{
		postorder(tree->left);
		postorder(tree->right);
		cout<<tree->data<<" ";
		}
	}
	node * findmax(node *tree)
	{	
		if(tree ==nullptr)
		return nullptr;
		if(tree->right ==nullptr)
		return tree;
		else
		return findmax(tree->right);
	}
	node * findmin(node *tree)
	{
		if(tree==nullptr)
		return nullptr;
		if(tree->left ==nullptr)
		return tree;
		else
		return findmin(tree->left);
	}
	node * deletion(int x, node* tree)
	{
			int found =0;
		
			if(tree!=nullptr && x<tree->data )
			{
				tree->left = deletion(x,tree->left);
				
			}
			else if(tree!=nullptr && x>tree->data  )
			{
				tree->right = deletion(x,tree->right);
			}
			else if(tree!=nullptr && x==tree->data ) //(found the node to delete)
			{
				found =1;
			
				if(tree->left ==nullptr && tree->right ==nullptr)//no child
				{
					
					delete tree;
					return nullptr;
				}
				else if(tree->left!=nullptr && tree->right!=nullptr)//two child
				{
					node * temp = findmin(tree->right);
					tree->data = temp->data;
					tree->right = deletion(temp->data,tree->right);
				}
				
				else if(tree->left ==nullptr && tree->right!=nullptr)//only right child
				{
					node * temp = findmin(tree->right);
					tree->data = temp->data;
					tree->right = deletion(temp->data,tree->right);
				}
				else if(tree->right ==nullptr && tree->right!=nullptr)//only left child
				{
					node * temp = findmax(tree->left);
					tree->data = temp->data;
					tree->left = deletion(temp->data, tree->left);
				}
				
			}
			if( tree==nullptr && found ==0 )//not found
			{
				cout<<"Entered value does not Exist in the Tress "<<endl;
			}
			return tree;
		
	}
	
};
int main()
{
	tree obj;
	int c ;
	cout<<"Enter the data of root node : ";
	cin>>c;
	node* root = new node(c);
	int choice;
	do{
	cout<<"1.insert()"<<endl;
	cout<<"2.delete()"<<endl;
	cout<<"3.Inorder display()"<<endl;
	cout<<"4.preorder display()"<<endl;
	cout<<"5.postorder display()"<<endl;
	cout<<"6.exit"<<endl;
	cout<<"Enter your choice : "<<endl;
	cin>>choice;
		switch(choice)
		{
			case 1:
				int a;
				cout<<"Enter the value of node : ";
				cin>>a;
				obj.insert(a,root);
				cout<<endl;
				break;
			case 2:
				int b;
				cout<<"Enter the value of the node:";
				cin>>b;
				obj.deletion(b,root);
				cout<<endl;
				break;
			case 3:
				obj.inorder(root);
				cout<<endl;
				cout<<endl;
				break;
			case 4:
				obj.preorder(root);
				cout<<endl;
				cout<<endl;
				break;
			case 5:
				obj.postorder(root);
				cout<<endl;
				cout<<endl;
				break;
			case 6:
				break;

			default:
				break;
				
		}
	}while(choice!=6);
}
