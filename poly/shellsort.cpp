#include<iostream>
using namespace std;
class shellsort
{
	private: 	int incr,j,k,span,y;
	public: 	void ShellSort(int a[],int n,int increment[],int numincr);
};
void shellsort::ShellSort(int a[],int n,int increment[],int numincr)
{
	for(incr=0;incr<numincr;incr++){
		span=increment[incr];
		for(j=span;j<n;j++){
			y=a[j];
			for(k=j-span;k>=0 && y<a[k];k=k-span){
				a[k+span]=a[k];
			}
			a[k+span]=y;
		}
	}
}
main()
{
	int a[30],increment[10],y,numincr,i,n;
	shellsort s;
	cout<<"Program to perform sort using shell sort"<<endl;
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"\nEnter the elements:"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"\nEnter number of increments:";
	cin>>numincr;
	cout<<"Enter the increments:"<<endl;
	
	for(i=0;i<numincr;i++){
		cin>>increment[i];
	}
	s.ShellSort(a,n,increment,numincr);
	cout<<"Before sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	cout<<"\nAfter sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
}
