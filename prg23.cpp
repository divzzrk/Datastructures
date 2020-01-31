//insertion 
#include<iostream>
using namespace std;
class insertion{
	private: int arr[20],n;
	public: void sort();
};
void insertion::sort()
{
	int j,i,key;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter n array elements: ";
	for(i=0;i<n;i++)
		cin>>arr[i];
	key=arr[0];
	for(i=1;i<n;i++){
		key=arr[i];
		for(j=i-1;j>=0 && arr[j]>key;j--){
				arr[j+1]=arr[j];
		}
		arr[j+1]=key;
	}
	cout<<"\nAfter sorting:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\n";
}
main()
{
	insertion i;
	i.sort();
}