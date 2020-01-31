//binary search
#include<iostream>
using namespace std;
class binarysearch
{
	public:int search(int arr[20],int n,int ele);
};
int binarysearch::search(int arr[20],int n,int ele)
{
	int low,mid,high;
	low=0;
	high=n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ele==arr[mid])
			return mid;
		else if(ele<arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
main()
{
	binarysearch bs;
	int arr[20],n,ele,flag;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	cout<<"Enter n array elements: \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the search element: ";
	cin>>ele;
	flag=bs.search(arr,n,ele);
	if(flag>=0)
		cout<<"Element found at position: "<<flag;
	else
		cout<<"Search element not found!!";
}