//shell sort
#include<iostream>
using namespace std;
class shellsort
{
	private: int arr[20],n,incr[5],m;
	public: void sort();
};
void shellsort::sort()
{
	int i,span,j,y,k;
	cout<<"Enter the number of array elements: ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the number of increment elements: ";
	cin>>m;
	for(i=0;i<m;i++)
		cin>>incr[i];
	for(i=0;i<m;i++){
		span=incr[i];
		for(j=span;j<n;j++)
		{
			y=arr[j];
			for(k=j-span;arr[k]>y;k=k-span){
				arr[k+span]=arr[k];
			}
			arr[k+span]=y;
		}
	}
	cout<<"\nAfter sort:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}
main()
{
	shellsort s;
	s.sort();
}