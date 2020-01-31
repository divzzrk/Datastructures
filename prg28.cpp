//heapsort
#include<iostream>
using namespace std;
class heapsort
{
	private: int arr[20],n;
	public: void sort();
};
void heapsort::sort()
{
	int ivalue,elt,f,s,i;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter the array elements: \n";
	for(i=0;i<n;i++)
			cin>>arr[i];
	
	//preprocessing phase
	//s=0;
	for(i=0;i<n;i++){
		s=i;
		elt=arr[i];
		f=(s-1)/2;
		while(s>0 && arr[f]<elt){
			arr[s]=arr[f];
			s=f;
			f=(s-1)/2;
		}
		arr[s]=elt;
	}
	for(i=n-1;i>0;i--){
		ivalue=arr[i];
		f=0;
		arr[i]=arr[0];
		if(i==1)
			s=-1;
		else
			s=1;
		if(i>2 && arr[2]>arr[1])
			s=2;
		while(s>=0 && arr[s]>ivalue){
			arr[f]=arr[s];
			f=s;
			s=2*f+1;
			if(s+1<=i-1 && arr[s]<arr[s+1])
				s=s+1;
			if(s>i-1)
				s=-1;
		}
		arr[f]=ivalue;
	}	
	cout<<"\nAfter sorting\n";
	for(i=0;i<n;i++)
			cout<<arr[i]<<"\n";	
}
main()
{
	heapsort h;
	int i;
	h.sort();
}