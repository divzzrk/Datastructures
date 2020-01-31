//queue using linked list
#include<iostream>
using namespace std;
typedef struct quetype{
	int data;
	struct quetype *next;
}NODE;
class queue{
	private:NODE *Head;
	public:	queue();
			void insertrear(int ele);
			int deletefront();
			void display();
};
queue::queue()
{
	Head=NULL;
}
void queue::insertrear(int ele){
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
int queue::deletefront()
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
void queue::display()
{
	if(Head==NULL)
		cout<<"\nThere are no elements in the queue!";
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
	queue q;
	int ch,num;
	while(1)
	{
		cout<<"\nMENU\n";
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter a number: ";
					
					cin>>num;
					q.insertrear(num);
					break;
			case 2:
					num=q.deletefront();
					if(num==-1)
						cout<<"List is empty";
					else
						cout<<"Deleted node "<<num;
					break;
			case 3:q.display();
					break;
			case 4:exit(0);
		}
	}
}

		
		
