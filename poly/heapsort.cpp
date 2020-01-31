#include<iostream>
using namespace std;
class heapsort
{
	private: 	int i;
	public: 	void HeapSort(int x[],int n);
};
void heapsort::HeapSort(int x[],int n)
{
	int ivalue,ele,s,f;
	for(i=0;i<n;i++){
		ele=x[i];
		s=i;
		f=(s-1)/2;
		while(s>0 && x[f]<ele){
			x[s]=x[f];
			s=f;
			f=(s-1)/2;
		}
		x[s]=ele;
	}
	for(i=n-1;i>0;i--){
		ivalue=x[i];
		x[i]=x[0];
		f=0;
		if(i==1)
			s=-1;
		else
			s=1;
		if(i>2 && x[2]>x[1])
			s=2;
		while(s>=0 && ivalue<x[s]){
			x[f]=x[s];
			f=s;
			s=2*f+1;
			if(s+1<=i-1 && x[s]<x[s+1])
				s=s+1;
			if(s>i-1)
				s=-1;
		}
		x[f]=ivalue;
	}
	
}

main()
{
	int n,i,a[20];
	heapsort h;
	cout<<"Program to perform sort using heap sort"<<endl;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"\nEnter the elements:"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Before sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	h.HeapSort(a,n);
	cout<<"After sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}

}
