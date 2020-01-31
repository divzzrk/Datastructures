/*-------------------------------------------------------------------------------------------------------------------------------------------
Polynomial.cpp
An object-oriented program in cpp to add two polynomial numbers.
181713
13-02-19
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
using namespace std;
typedef struct PolyType{
	int Coef;
	int Pwr;
	struct PolyType *Next;
}POLYNODE;

class Polynomial
{
	private:
			POLYNODE *Head;
	public:
			Polynomial();
			POLYNODE *MakePolyNode(int Coef,int Pwr);
			void InsertPolyNode(int Coef,int Pwr);
			Polynomial AddPoly(Polynomial P,Polynomial Q);
			POLYNODE *getHead();
			void Display();
};

main()
{
	Polynomial P,Q,R,*h1,*h2;
	int n1,n2,coef,pwr,ch,i;
	cout<<"Program to add two polynomial numbers"<<endl;
	cout<<"Enter the number of elements for first polynomial number: ";
	cin>>n1;
	for(i=0;i<n1;i++){
		cout<<"Enter the element and power: ";
		cin>>coef>>pwr;
		P.InsertPolyNode(coef,pwr);
	}
	P.Display();	
	
	cout<<"Enter the number of elements for second polynomial number: ";
	cin>>n2;
	for(i=0;i<n2;i++){
		cout<<"Enter the element and power: ";
		cin>>coef>>pwr;
		Q.InsertPolyNode(coef,pwr);
	}
	Q.Display();
	
	R=P.AddPoly(P,Q);
	cout<<"After adding two polynomial numbers:\n";
	R.Display();
}

//-------------------------------------------------------Polynomial()---------------------------------------------------------------------------
Polynomial::Polynomial()
{
	Head=NULL;
}
//-------------------------------------------------------MakePolyNode()---------------------------------------------------------------------------
POLYNODE *Polynomial::MakePolyNode(int Coef,int Pwr)
{
		POLYNODE *Node;
		Node=(POLYNODE *)malloc(sizeof(POLYNODE));
		Node->Coef=Coef;
		Node->Pwr=Pwr;
		Node->Next=NULL;
		return Node;
}
//-------------------------------------------------------InsertPolyNode()---------------------------------------------------------------------------
void Polynomial::InsertPolyNode(int Coef,int Pwr)
{
	POLYNODE *Curr,*p,*Prev;
	p=MakePolyNode(Coef,Pwr);
	Curr=Head;
	//Case 1: When there is no list 
	if(Head==NULL){
		Head=p;
		return;
	}
	//Case 2: When incoming node has power greater than that of the head of the list
	if(p->Pwr>Head->Pwr){
		p->Next=Head;
		Head=p;
		return;
	}
	//Case 3: Insert data at the middle or at the end of the list
	while(Curr && p->Pwr<=Curr->Pwr){
		Prev=Curr;
		Curr=Curr->Next;
	}
	Prev->Next=p;
	p->Next=Curr;
	//cout<<"\nThe element is inserted\n\n";
	return;
}
//-------------------------------------------------------Display()---------------------------------------------------------------------------
void Polynomial::Display()
{
	POLYNODE *Curr;
	Curr=Head;
	if(Head==NULL){
		cout<<"Sorry! The list is empty";
		return;
	}
	cout<<"\nThe polynomial expression is:\n";
	if(Curr->Pwr==0)
		cout<<Curr->Coef<<"\t";
	else
		cout<<Curr->Coef<<"X^"<<Curr->Pwr;
	Curr=Curr->Next;
	while(Curr->Next!=NULL){
		if(Curr->Coef<0)
			cout<<Curr->Coef<<"X^"<<Curr->Pwr;
		else
			cout<<"+"<<Curr->Coef<<"X^"<<Curr->Pwr;
		Curr=Curr->Next;
	}
	if(Curr->Pwr==0 && Curr->Coef>=0)
		cout<<"+"<<Curr->Coef;
	else if(Curr->Pwr==0 && Curr->Coef<0)
		cout<<Curr->Coef;
	else if(Curr->Coef>=0)
		cout<<"+"<<Curr->Coef<<"X^"<<Curr->Pwr;
	else
		cout<<Curr->Coef<<"X^"<<Curr->Pwr;
	return;
}
POLYNODE *Polynomial::getHead()
{
		return Head;
}
//-------------------------------------------------------AddPoly()---------------------------------------------------------------------------
Polynomial Polynomial::AddPoly(Polynomial P,Polynomial Q)
{
		POLYNODE *Head;
		Polynomial A,B,R;
		int coef,pwr;
		A=P.getHead();
		B=Q.getHead();
		while(A && B){
			if(A->Pwr == B->Pwr){
				coef=A->Coef+B->Coef;
				pwr=A->Pwr;
				R.InsertPolyNode(coef,pwr);
				A=A->Next;
				B=B->Next;
			}
			else if(A->Pwr>B->Pwr){
				coef=A->Coef;
				pwr=A->Pwr;
				R.InsertPolyNode(coef,pwr);
				A=A->Next;
			}
			else{
				coef=B->Coef;
				pwr=B->Pwr;
				R.InsertPolyNode(coef,pwr);
				B=B->Next;
			}
		}
		while(A){
				coef=A->Coef;
				pwr=A->Pwr;
				R.InsertPolyNode(coef,pwr);
				A=A->Next;
		}
		while(B){
			coef=B->Coef;
			pwr=B->Pwr;
			R.InsertPolyNode(coef,pwr);
			B=B->Next;
		}
		return R;
}