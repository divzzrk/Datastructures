//merge sort
#include<iostream>
using namespace std;
class mergesort{
	public: void msort(int arr[20],int low,int mid,int high);
			void merge(int arr[20],int low,int high);
};
void mergesort::msort(int arr[20],int low,int mid,int high)
{
	int temp[high-low+1];
	int i=low;
	int j,k;
	j=mid+1;
	k=0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
		}
		else{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high){
		temp[k]=arr[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}	
}
void mergesort::merge(int arr[20],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=((low+high)/2);
		merge(arr,low,mid);
		merge(arr,mid+1,high);
		msort(arr,low,mid,high);
	}
}
main()
{
	mergesort m;
	int arr[20];
	int n,i;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements: ";
	for(i=0;i<n;i++)
		cin>>arr[i];
	m.merge(arr,0,n-1);
	cout<<"\nAfter sorting";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}