//polynode
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct polynome
{
	int data;
	int pwr;
	struct polynome *next;
}POLYNODE;
class polynom
{
	private: POLYNODE *Head;
	public: polynom();
			void insertpoly(int data,int pwr);
			polynom addpoly(polynom p1,polynom q1);
			POLYNODE *getHead();
			void display();
};
polynom::polynom()
{
	Head=NULL;
}
void polynom::insertpoly(int data,int pwr)
{
	POLYNODE *newnode,*curr,*prev;
	newnode=(POLYNODE *)malloc(sizeof(POLYNODE));
	newnode->data=data;
	newnode->pwr=pwr;
	newnode->next=NULL;
	if(Head==NULL)
		Head=newnode;
	else if(newnode->pwr>Head->pwr){
		newnode->next=Head;
		Head=newnode;
	}
	else{
		curr=Head;
		while(curr && newnode->pwr<curr->pwr){
			prev=curr;
			curr=curr->next;
		}
		prev->next=newnode;
		newnode->next=curr;
	}
}
void polynom::display()
{
	POLYNODE *curr;
	if(Head==NULL)
		cout<<"Polynome is empty!!";
	else{
		curr=Head;
		while(curr!=NULL){
			if(curr->pwr==0){
				cout<<curr->data;
				curr=curr->next;
			}
			else{
				cout<<curr->data;
				cout<<"X^"<<curr->pwr;
				curr=curr->next;
				if(curr!=NULL)
					cout<<" + ";
			}
		}
	}
}
polynom polynom::addpoly(polynom p1,polynom q1)
{
	polynom r;
	POLYNODE *a,*b;
	a=p1.getHead();
	b=q1.getHead();
	int d,p;
	while(a&&b)
	{
		if(a->pwr==b->pwr)
		{
			d=a->data+b->data;
			p=a->pwr;
			r.insertpoly(d,p);
			a=a->next;
			b=b->next;
		}
		else if(a->pwr>b->pwr)
		{
			d=a->data;
			p=a->pwr;
			r.insertpoly(d,p);
			a=a->next;
		}
		else{
			d=b->data;
			p=b->pwr;
			r.insertpoly(d,p);
			b=b->next;
		}
	}
	while(a)
	{
		d=a->data;
		p=a->pwr;
		r.insertpoly(d,p);
		a=a->next;
	}
	while(b)
	{
		d=b->data;
		p=b->pwr;
		r.insertpoly(d,p);
		b=b->next;
	}
	return r;
}
POLYNODE *polynom::getHead()
{
	return Head;
}
main()
{
	cout<<"Program to add two polynomial numbers\n";
	int ch,n,i,num,pwr,m;
	polynom p,q,r;
	int flag=0;
	while(1)
	{
		cout<<"\n\nMENU\n";
		cout<<endl<<"1.Insert polynomial";
		cout<<endl<<"2.Add 2 polynomial";
		cout<<endl<<"3.Display polynomial";
		cout<<endl<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter the number of elements for first polynomial: ";
					cin>>n;
					cout<<"\nEnter "<<n<<" elements:\n";
					for(i=0;i<n;i++){
						cout<<"Enter number: ";
						cin>>num;
						cout<<"Enter power: ";
						cin>>pwr;
						p.insertpoly(num,pwr);
					}
					cout<<"\nEnter the number of elements for second polynomial: ";
					cin>>m;
					cout<<"\nEnter "<<m<<" elements:\n";
					for(i=0;i<m;i++){
						cout<<"Enter number: ";
						cin>>num;
						cout<<"Enter power: ";
						cin>>pwr;
						q.insertpoly(num,pwr);
					}
					break;
			case 2: r=p.addpoly(p,q);
					flag=1;
					break;
			case 3: cout<<"\nFirst polynomial:\n";
					p.display();
					cout<<"\nSecond polynomial:\n";
					q.display();
					if(flag){
						cout<<"\nAfter adding:\n";
						r.display();
					}
					break;
			case 4:exit(0);
		}
	}
}