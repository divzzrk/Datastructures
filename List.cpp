/*-------------------------------------------------------------------------------------------------------------------------------------------
List.cpp
An object-oriented program in cpp to implement an ordered list.
181713
13-02-19
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
using namespace std;

typedef struct ListType{
	int Num;
	struct ListType *Next;
}LISTNODE;

class List
{
	private:
			LISTNODE *Head;
	public:
			List();
			LISTNODE *MakeListNode(int Num);
			void InsertListNode(int Num);
			int DeleteFirstNode();
			void DeleteListNode(int Num);
			void Display();
};

main()
{
	List L;
	int n,ele,ch;
	cout<<"Program to perform List operations"<<endl;
	while(1){
		cout<<"\nMenu\n";
		cout<<"1.Insert list element\n";
		cout<<"2.Delete first element from list\n";
		cout<<"3.Delete a specified item from list\n";
		cout<<"4.Display \n";
		cout<<"5.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element: ";
					cin>>ele;
					L.InsertListNode(ele);
					break;
			case 2: ele=L.DeleteFirstNode();
					if(ele!=-1)
						cout<<"\nThe deleted element is: "<<ele;
					break;
			case 3: cout<<"Enter the element to be deleted: ";
					cin>>ele;
					L.DeleteListNode(ele);
					break;		
			case 4:	L.Display();
					break;
			case 5:exit(0);
			default:cout<<"\nSorry! You have entered a wrong choice!!";
		}
	}
					
}

//-------------------------------------------------------List()---------------------------------------------------------------------------
List::List()
{
	Head=NULL;
}
//-------------------------------------------------------MakeListNode()---------------------------------------------------------------------------
LISTNODE *List::MakeListNode(int Num)
{
		LISTNODE *Node;
		Node=(LISTNODE *)malloc(sizeof(LISTNODE));
		Node->Num=Num;
		Node->Next=NULL;
		return Node;
}
//-------------------------------------------------------InsertListNode()---------------------------------------------------------------------------
void List::InsertListNode(int Ele)
{
	LISTNODE *Curr,*p,*Prev;
	p=MakeListNode(Ele);
	Curr=Head;
	//Case 1: When there is no list 
	if(Head==NULL){
		Head=p;
		return;
	}
	//Case 2: When incoming node has data less than that of the head of the list
	if(p->Num<Head->Num){
		p->Next=Head;
		Head=p;
		return;
	}
	//Case 3: Insert data at the middle or at the end of the list
	while(Curr && p->Num>Curr->Num){
		Prev=Curr;
		Curr=Curr->Next;
	}
	Prev->Next=p;
	p->Next=Curr;
	//cout<<"\nThe element is inserted\n\n";
	return;
}
//-------------------------------------------------------Display()---------------------------------------------------------------------------
void List::Display()
{
	LISTNODE *Curr;
	Curr=Head;
	if(Head==NULL){
		cout<<"Sorry! The list is empty";
		return;
	}
	cout<<"\nThe elements in the list are:\n";
	while(Curr->Next!=NULL){
		cout<<Curr->Num<<"\t";
		Curr=Curr->Next;
	}
	cout<<Curr->Num<<"\t";
	return;
}
//-------------------------------------------------------DeleteFirstNode()---------------------------------------------------------------------------
int List::DeleteFirstNode(){
	LISTNODE *Curr;
	Curr=Head;
	int ele;
	if(Head==NULL){
		cout<<"Sorry! The list is empty";
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
//-------------------------------------------------------DeleteListNode()---------------------------------------------------------------------------
void List::DeleteListNode(int Num){
	LISTNODE *Curr,*Prev;
	Prev=Curr=Head;
	if(Head==NULL){
		cout<<"Sorry! The list is empty";
		return;
	}
	else if(Num==Head->Num){
		Head=Curr->Next;
		free(Curr);
		cout<<"Element is deleted!";
		return;
	}
	else{
		while(Curr->Next!=NULL){
			Prev=Curr;
			Curr=Curr->Next;
			if(Curr->Num==Num){
				Prev->Next=Curr->Next;
				free(Curr);
				cout<<"The number is deleted";
				return;
			}
		}
		if(Curr->Num==Num)
		{
				Prev->Next=Curr->Next;
				free(Curr);
				cout<<"The number is deleted";
				return;
		}
		cout<<"Sorry! The entered element is not found in the list!!";
	}
}