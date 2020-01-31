#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct PolyType{
int Coef;
	int Pwr;
	struct PolyType *Next;
}POLYNODE;

class Polynom{
	private:
		POLYNODE *Head;
	public:
		Polynom();
		POLYNODE *MakePolyNode(int Coef,int Pwr);
		void InsertPolyNode(int Coef,int Pwr);		
		void DisplayPolyNode();
		POLYNODE *getHead();
		Polynom AddPoly(Polynom P,Polynom Q);
};

main()
{
	int ele,ch,pwr,n1,n2;
	Polynom p;
	Polynom q;
	Polynom r;
		
	while(1){
		cout<<"\nPOLYNOMIAL NUMBERS MENU\n";
		cout<<"1.Enter"<<endl;
		cout<<"2.Add Polynomial"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch){
			case 1:	cout<<"Enter number of term for first polynomial ";
					cin>>n1;
					for(int i=0;i<n1;i++){
						cout<<"Enter the element: ";
						cin>>ele;
						cout<<"Enter the Power: ";
						cin>>pwr;
						p.InsertPolyNode(ele,pwr);
					}
					cout<<"Enter number of term for second polynomial ";
					cin>>n2;
					for(int i=0;i<n2;i++){
						cout<<"Enter the element: ";
						cin>>ele;
						cout<<"Enter the Power: ";
						cin>>pwr;
						q.InsertPolyNode(ele,pwr);
					}
					break;
					
			case 2:	r=p.AddPoly(p,q);
					break;
			case 3: cout<<"Expresion 1:\n";
					p.DisplayPolyNode();
					cout<<"Expresion 2:\n";
					q.DisplayPolyNode();
					cout<<"Result:\n";
					r.DisplayPolyNode();
					break;
			case 4:	exit(0);
		}
	}		
}
//----------------Polynom()-----------------
Polynom::Polynom()
{
	Head=NULL;
}
//----------------MakePolyNode()-----------------
POLYNODE *Polynom::MakePolyNode(int Coef,int Pwr)
{
	POLYNODE *Node;
	Node=(POLYNODE *)malloc(sizeof(POLYNODE));

	Node->Coef=Coef;
	Node->Pwr=Pwr;
	Node->Next=NULL;
	return Node;
}
//----------------InsertPolyNode()-----------------
void Polynom::InsertPolyNode(int Coef,int Pwr)
{
	POLYNODE *Prev,*Curr,*p;
	p=MakePolyNode(Coef,Pwr);
	Curr=Head;
	if(Head==NULL){
		Head=p;
		return;
	}
	if(p->Pwr > Curr->Pwr){
		p->Next=Curr;
		Head=p;
		return;
	}else{
		while(Curr && p->Pwr < Curr->Pwr){
			Prev=Curr;
			Curr=Curr->Next;
		}
		p->Next=Curr;
		Prev->Next=p;
	}
}
//----------------DisplayPolyNode()-----------------
void Polynom::DisplayPolyNode()
{
	if(Head==NULL){
		cout<<"Expresion is empty";
	}else{
		POLYNODE *Curr;
		Curr=Head;
		
		while(Curr!=NULL){
			if(Curr->Pwr==0){
				cout<<Curr->Coef;
				Curr=Curr->Next;
			}else{
				cout<<Curr->Coef;
				cout<<"X^"<<Curr->Pwr;
				Curr=Curr->Next;
				
				if(Curr==NULL || Curr->Coef<0)
					cout<<"";
				else
					cout<<"+";
					
			}
		}
		cout<<endl;
	}
}

POLYNODE *Polynom::getHead()
{
	return Head;
}

Polynom Polynom::AddPoly(Polynom P,Polynom Q)
{
	POLYNODE *A,*B;
	Polynom R;
	int Coef,Pwr;
	A=P.getHead();
	B=Q.getHead();
	
	while(A&&B){
		if(A->Pwr==B->Pwr){
			Coef=A->Coef + B->Coef;
			Pwr=A->Pwr;
			R.InsertPolyNode(Coef,Pwr);
			A=A->Next;
			B=B->Next;
		}else if(A->Pwr>B->Pwr){
			Coef=A->Coef;
			Pwr=A->Pwr;
			R.InsertPolyNode(Coef,Pwr);
			A=A->Next;
		}else{
			Coef=B->Coef;
			Pwr=B->Pwr;
			R.InsertPolyNode(Coef,Pwr);
			B=B->Next;
		}
	}
	while(A){
		Coef=A->Coef;
		Pwr=A->Pwr;
		R.InsertPolyNode(Coef,Pwr);
		A=A->Next;
	}
	while(B){
		Coef=B->Coef;
		Pwr=B->Pwr;
		R.InsertPolyNode(Coef,Pwr);
		B=B->Next;	
	}
	return R;
}
