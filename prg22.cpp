//bubblesort
#include<iostream>
using namespace std;
class bubblesort{
	private:int arr[20],n;
	public: void sort();
};
void bubblesort::sort()
{
	int i,j;
	int temp;
	cout<<"Enter numner of elements: ";
	cin>>n;
	cout<<"Enter n elements:\n";
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	cout<<"\nAfter sorting:\n";
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\n";
}
main()
{
	bubblesort b;
	b.sort();
}