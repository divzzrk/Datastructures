//quicksort
#include<iostream>
using namespace std;
class quicksort{
	public: void sort(int arr[20],int low,int high);
			int partition(int arr[20],int low,int high);
};
void quicksort::sort(int arr[20],int low,int high)
{
	int keypos;
	if(low<high)
	{
		keypos=partition(arr,low,high);
		sort(arr,low,keypos);
		sort(arr,keypos+1,high);
	}
}
int quicksort::partition(int arr[20],int low,int high)
{
	int i,j,key,temp;
	i=low+1;
	j=high;
	key=arr[low];
	int flag=1;
	while(flag){
		while(key>arr[i] && i<high){
			i++;
		}
		while(key<arr[j])
			j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		else
			flag=0;
	}
	temp=arr[j];
	arr[j]=arr[low];
	arr[low]=temp;
	return j;
}
main()
{
	quicksort q;
	int i,n;
	int arr[20];
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter n array elements:\n";
	for(i=0;i<n;i++)
		cin>>arr[i];
	q.sort(arr,0,n-1);
	cout<<"\nAfter sorting\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}