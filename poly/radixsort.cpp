#include <iostream>
using namespace std;
class radixsort
{
	private: int i;
	public: int getMax(int arr[], int n);
			void Sort(int arr[], int n, int exp);
			void RadixSort(int arr[], int n);
};

int radixsort::getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
void radixsort::Sort(int arr[], int n, int exp)
{
	  
	int output[n], i, count[10] = {0};
 	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 

void radixsort::RadixSort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);
 	for (exp = 1; m/exp > 0; exp *= 10)
		Sort(arr, n, exp);
}
 
main()
{
	int n,i,a[20];
	radixsort r;
	cout<<"Program to perform sort using radix sort"<<endl;
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
	r.RadixSort(a,n);
	cout<<"After sorting\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}

}


