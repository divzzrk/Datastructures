//binary tree
#include<iostream>
using namespace std;
typedef struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
}TREENODE;
class bintree
{
	private: TREENODE *tree;
	public: bintree();
			void maketree(int num);
			void postfix(TREENODE *t);
			void infix(TREENODE *t);
			void prefix(TREENODE *t);
			void setleft(int data,TREENODE *p,TREENODE *newnode);
			void setright(int data,TREENODE *p,TREENODE *newnode);
			TREENODE *getHead();
};
bintree::bintree()
{
	tree=NULL;
}
void bintree::maketree(int num)
{
	TREENODE *newnode,*p,*q;
	newnode=(TREENODE *)malloc(sizeof(TREENODE));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	p=tree;
	q=tree;
	if(tree==NULL){
		tree=newnode;
	}
	else{
		while(q!=NULL && newnode->data!=p->data)
		{
			p=q;
			if(newnode->data<p->data)
				q=p->left;
			else
				q=p->right;
		}
		if(newnode->data==p->data)
			cout<<"Trying to insert a duplicate element!!\n";
		else if(newnode->data<p->data)
			setleft(newnode->data,p,newnode);
		else
			setright(newnode->data,p,newnode);
	}
}
void bintree::setleft(int data,TREENODE *p,TREENODE *newnode)
{
	TREENODE *q;
	q=p->left;
	if(q!=NULL)
		cout<<"Invalid location!";
	else
		p->left=newnode;
}
void bintree::setright(int data,TREENODE *p,TREENODE *newnode)
{
	TREENODE *q;
	q=p->right;
	if(q!=NULL)
		cout<<"Invalid location!";
	else
		p->right=newnode;
}	
TREENODE *bintree::getHead()
{
	return tree;
}
void bintree::infix(TREENODE *t)
{
	if(t!=NULL){
		infix(t->left);
		cout<<t->data<<" ";
		infix(t->right);
	}
}
void bintree::postfix(TREENODE *t)
{
	if(t!=NULL){
		postfix(t->left);
		postfix(t->right);
		cout<<t->data<<" ";
	}
}
void bintree::prefix(TREENODE *t)
{
	if(t!=NULL){
		cout<<t->data<<" ";
		prefix(t->left);
		prefix(t->right);
	}
}
main()
{
	bintree bt;
	TREENODE *t1;
	int ch,ele;
	while(1)
	{
		cout<<"\nMenu\n";
		cout<<"1.Insert node\n";
		cout<<"2.Infix\n";
		cout<<"3.Postfix\n";
		cout<<"4.Prefix\n";
		cout<<"5.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the element to be inserted: ";
					cin>>ele;
					bt.maketree(ele);
					break;
			case 2:	t1=bt.getHead();
					bt.infix(t1);
					break;
			case 3:	t1=bt.getHead();
					bt.postfix(t1);
					break;
			case 4:	t1=bt.getHead();
					bt.prefix(t1);
					break;
			case 5: exit(0);
		}
	}
}
	