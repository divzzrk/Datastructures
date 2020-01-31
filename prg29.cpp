//radix sort
#include<iostream>
using namespace std;
class radixsort{
	private:	int arr[20],n;
	public:		void sort();
};
void radixsort::sort()
{
	int bucket[10][20],buck_count[10];
	int largest,i,msd=0,lsd,y,k,j,divisor=1,r;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements:\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"The entered digits before sorting are: ";
	for(i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	largest=arr[0];
	for(i=0;i<n;i++)
	{
		if(largest<arr[i])
		{
			largest=arr[i];
		}
	}
	while(largest>0){
		msd++;
		largest/=10;
	}
	cout<<msd;
	for(lsd=0;lsd<msd;lsd++){
		for(k=0;k<10;k++){
			buck_count[k]=0;
		}
		for(i=0;i<n;i++){
			y=arr[i];
			r=(arr[i]/divisor)%10;
			bucket[r][buck_count[r]]=arr[i];
			buck_count[r]++;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<buck_count[k];j++){
				arr[i++]=bucket[k][j];
			}
		}
		divisor*=10;
	}
	cout<<"\nAfter sorting\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	
}
main()
{
	cout<<"Program to perform merge sort\n\n";
	radixsort r;
	r.sort();
}