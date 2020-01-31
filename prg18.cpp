//binarray
#include<iostream>
#define NUMNODE 100
using namespace std;
struct treearr
{
	int data;
	int flag;
}node[NUMNODE];
class binarray
{
	public: void insert(int num);
			void makenode(int n);
			void display();
			void setleft(int data,int p);
			void setright(int data,int p);
};
void binarray::insert(int num)
{
	int n;
	int p,q;
	cin>>n;
	makenode(n);
	for(int i=1;i<num;i++){
		cin>>n;
		p=0;
		q=0;
		while(q<NUMNODE && node[q].flag==1 && n!=node[p].data){
			p=q;
			if(n<node[p].data)
				q=2*p+1;
			else
				q=2*p+2;
		}
		if(n<node[p].data)
			setleft(n,p);
		else
			setright(n,p);
	}
}
void binarray::setleft(int data,int p)
{
	int q;
	q=2*p+1;
	if(q>=NUMNODE)
		cout<<"Array overflow";
	else if(node[q].flag)
		cout<<"invalid location";
	else{
		node[q].data=data;
		node[q].flag=1;
	}
}
void binarray::setright(int data,int p)
{
	int q;
	q=2*p+2;
	if(q>=NUMNODE)
		cout<<"Array overflow";
	else if(node[q].flag)
		cout<<"invalid location";
	else{
		node[q].data=data;
		node[q].flag=1;
	}
}
void binarray::makenode(int n)
{
	node[0].data=n;
	node[0].flag=1;
	for(int i=1;i<NUMNODE;i++)
		node[i].flag=0;
}
void binarray::display()
{
	if(node[0].flag==0)
		cout<<"No elements";
	else{
		for(int i=0;i<NUMNODE;i++){
			if(node[i].flag)
				cout<<node[i].data<<" ";
			else
				cout<<"0 ";
		}
	}
}
main()
{
	binarray ba;
	int num;
	cout<<"Enter the number of elements to be inserted into the tree: ";
	cin>>num;
	cout<<"Enter n elements:\n";
	ba.insert(num);
	ba.display();
}