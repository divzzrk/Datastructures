//singly linked list
//queue using linked list
#include<iostream>
using namespace std;
typedef struct listtype{
	int data;
	struct listtype *next;
}NODE;
class list{
	private:NODE *Head;
	public:	list();
			void insertbegin(int ele);
			void insertrear(int ele);
			void insertpos(int ele,int pos);
			int deletefront();
			int deleterear();
			int deletepos(int pos);
			void display();
};
list::list()
{
	Head=NULL;
}
void list::insertpos(int ele,int pos){
	NODE *newnode,*curr,*prev;
	curr=Head;
	int count=0;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=ele;
	newnode->next=NULL;
	while(curr->next!=NULL)
	{
		count++;
		curr=curr->next;
	}
	if(pos>count){
		cout<<"Invalid position!";
		return;
	}
	if(Head==NULL && pos==0){
		Head=newnode;
	}
	else{
		curr=Head;
		for(int i=0;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=newnode;
		newnode->next=curr;
	}
}
void list::insertrear(int ele){
	NODE *newnode,*curr;
	curr=Head;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=ele;
	newnode->next=NULL;
	if(Head==NULL){
		Head=newnode;
	}
	else{
		
			while(curr->next!=NULL){
				curr=curr->next;
			}
			curr->next=newnode;
		
	}
}
void list::insertbegin(int ele){
	NODE *newnode,*curr;
	curr=Head;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=ele;
	newnode->next=NULL;
	if(Head==NULL){
		Head=newnode;
	}
	else{
		newnode->next=Head;
		Head=newnode;
	}
}
int list::deletefront()
{
	int ele;
	NODE *curr;
	if(Head==NULL)
		return -1;
	else{
		curr=Head;
		ele=Head->data;
		Head=Head->next;
		curr->next=NULL;
		free(curr);
		return ele;
	}
}
int list::deleterear()
{
	int ele;
	NODE *curr,*prev;
	if(Head==NULL)
		return -1;
	else{
		if(Head->next==NULL)
		{
			ele=Head->data;
			Head=NULL;
			free(Head);
		}
		else{
			curr=Head;
			while(curr->next!=NULL){
				prev=curr;
				curr=curr->next;
			}
			prev->next=NULL;
			ele=curr->data;
			free(curr);
			return ele;
		}
	}
}
int list::deletepos(int pos){
	NODE *newnode,*curr,*prev;
	curr=Head;
	int count=0,ele;
	if(Head==NULL)
		return -1;
	while(curr->next!=NULL)
	{
		count++;
		curr=curr->next;
	}
	if(pos>count){
		cout<<"Invalid position!";
		return -1;
	}
	else{
		curr=Head;
		for(int i=0;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		ele=curr->data;
		free(curr);
		return ele;
	}
}
void list::display()
{
	if(Head==NULL)
		cout<<"\nThere are no elements in the list!";
	else{
		NODE *curr;
		curr=Head;
		cout<<"\nThe elements are:\n";
		while(curr!=NULL){
			cout<<curr->data<<" ";
			curr=curr->next;
		}
	}
}
main(){
	list l;
	int ch,num,pos;
	while(1)
	{
		cout<<"\nMENU\n";
		cout<<"1.Insert rear\n";
		cout<<"2.Insert Front\n";
		cout<<"3.Insert position\n";
		cout<<"4.Delete Front\n";
		cout<<"5.Delete Rear\n";
		cout<<"6.Delete Position\n";
		cout<<"7.Display\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter a number: ";
					cin>>num;
					l.insertrear(num);
					break;
			case 2: cout<<"Enter a number: ";
					cin>>num;
					l.insertbegin(num);
					break;
			case 3: cout<<"Enter a number: ";
					cin>>num;
					cout<<"Enter the position: ";
					cin>>pos;
					l.insertpos(num,pos);
					break;
					
			case 4: num=l.deletefront();
					if(num==-1)
						cout<<"List is empty";
					else
						cout<<"Deleted node "<<num;
					break;
			case 5:	num=l.deleterear();
					if(num==-1)
						cout<<"List is empty";
					else
						cout<<"Deleted node "<<num;
					break;
			case 6: cout<<"Enter position: ";
					cin>>pos;
					num=l.deletepos(pos);
					if(num==-1)
						cout<<"List is empty";
					else
						cout<<"Deleted node "<<num;
					break;
			case 7:l.display();
					break;
			case 8:exit(0);
		}
	}
}

		
		
