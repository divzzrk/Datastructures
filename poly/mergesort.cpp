#include <iostream>
using namespace std;
class mergesort
{
	private: 	int i,j,k;
	public: 	void Merge(int a[], int low, int high, int mid);
				void MergeSort(int a[], int low, int high);
};
void mergesort::Merge(int a[], int low, int high, int mid)
{
	int temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 	while (i <= mid && j <= high)
	{
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}else{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void mergesort::MergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
main()
{
	int n,i,a[20];
	mergesort m;
	cout<<"Program to perform sort using merge sort"<<endl;
	cout<<"Enter the value of n:";
	cin>>n;
	cout<<"\nEnter the elements:"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Before sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	m.MergeSort(a,0,n-1);
	cout<<"After sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}

}
