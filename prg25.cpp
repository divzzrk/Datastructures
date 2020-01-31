//selection sort
#include<iostream>
using namespace std;
class selectionsort
{
	private:int arr[20],n;
	public: void sort();
};
void selectionsort::sort()
{
	int i,max,j,pos;
	cout<<"Enter the number of elements to be sorted: ";
	cin>>n;
	cout<<"Enter n elements:\n";
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=n-1;i>=0;i--){
		max=arr[0];
		pos=0;
		for(j=0;j<=i;j++){
			if(max<arr[j]){
				max=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[i];
		arr[i]=max;
	}
	cout<<"\nElements after sorting:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}
main()
{
	selectionsort s;
	s.sort();
}