/*-------------------------------------------------------------------------------------------------------------------------------------------
QueueL.cpp
An object-oriented program in cpp to implement a queue using linked list
181713
13-02-19
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
using namespace std;

typedef struct QueType{
	int Num;
	struct QueType *Next;
}QUEUENODE;

class Queue
{
	private:
			QUEUENODE *Head;
	public:
			Queue();
			QUEUENODE *MakeQueNode(int Num);
			void InsertQueNode(int Num);
			int DelQueNode();
			void Display();
};

main()
{
	Queue Q;
	int n,ele,ch;
	cout<<"Program to perform Queue operation using linked list"<<endl;
	while(1){
		cout<<"\nMenu\n";
		cout<<"1.Insert to the queue\n";
		cout<<"2.Delete element from queue\n";
		cout<<"3.Display \n";
		cout<<"4.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element: ";
					cin>>ele;
					Q.InsertQueNode(ele);
					break;
			case 2: ele=Q.DelQueNode();
					if(ele!=-1)
						cout<<"\nThe deleted element is: "<<ele;
					break;
			case 3:	Q.Display();
					break;
			case 4:exit(0);
			default:cout<<"\nSorry! You have entered a wrong choice!!";
		}
	}
					
}

//-------------------------------------------------------Queue()---------------------------------------------------------------------------
Queue::Queue()
{
	Head=NULL;
}
//-------------------------------------------------------MakeQueNode()---------------------------------------------------------------------------
QUEUENODE *Queue::MakeQueNode(int Num)
{
		QUEUENODE *Node;
		Node=(QUEUENODE *)malloc(sizeof(QUEUENODE));
		Node->Num=Num;
		Node->Next=NULL;
		return Node;
}
//-------------------------------------------------------InsertQueNode()---------------------------------------------------------------------------
void Queue::InsertQueNode(int Ele)
{
	QUEUENODE *Curr,*p;
	p=MakeQueNode(Ele);
	Curr=Head;
	if(Head==NULL){
		Head=p;
		return;
	}
	while(Curr->Next!=NULL){
		Curr=Curr->Next;
	}
	Curr->Next=p;
	//cout<<"\nThe element is inserted\n\n";
	return;
}
//-------------------------------------------------------Display()---------------------------------------------------------------------------
void Queue::Display()
{
	QUEUENODE *Curr;
	Curr=Head;
	if(Head==NULL){
		cout<<"Sorry! The queue is empty";
		return;
	}
	cout<<"\nThe elements in the queue are:\n";
	while(Curr->Next!=NULL){
		cout<<Curr->Num<<"\t";
		Curr=Curr->Next;
	}
	cout<<Curr->Num<<"\t";
	return;
}
//-------------------------------------------------------DelQueNode()---------------------------------------------------------------------------
int Queue::DelQueNode(){
	QUEUENODE *Curr;
	Curr=Head;
	int ele;
	if(Head==NULL){
		cout<<"Sorry! The queue is empty";
		return -1;
	}
	if(Curr->Next==NULL){
		Head=NULL;
		ele=Curr->Num;
		free(Curr);
		return ele;
	}
	ele=Curr->Num;
	Head=Curr->Next;
	free(Curr);
	return(ele);
}