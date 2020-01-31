/*-------------------------------------------------------------------------------------------------------------------------------------------
Arrayop.cpp
An object-oriented program in cpp to create an array object with respect to method
181713
06-02-19
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<math.h>
using namespace std;
class Arrayop
{
	private:
			int N,A[30];
	public:
			Arrayop(int Num);
			void InputArray();
			void PrintArray();
			void BubbleSort();
			int MaxArray();
			float StdDev();
};

main()
{
	Arrayop X(5);
	int Max; 
	
	cout<<"C++ program to create an array object with respect to method\n\n";
	X.InputArray();
	X.PrintArray();
	X.BubbleSort();
	cout<<"\nAfter sorting";
	X.PrintArray();
	Max=X.MaxArray();
	cout<<"The maximum element in the array is: "<<Max;
	cout<<"\nThe standard deviation is: "<<X.StdDev();
}

//---------------------------------------------------------Array()-------------------------------------------------------------------------
Arrayop::Arrayop(int Num)
{
	N=Num;
}
//---------------------------------------------------------InputArray()----------------------------------------------------------------------
void Arrayop::InputArray()
{
	int i;
	cout<<"Enter the array elements:\n";
	for(i=1;i<=N;i++){
		cin>>A[i];
	}
}
//---------------------------------------------------------PrintArray()----------------------------------------------------------------------
void Arrayop::PrintArray()
{
	int i;
	cout<<"\nThe elements in the array are: "<<endl;
	for(i=1;i<=N;i++){
		cout<<A[i]<<endl;
	}
}
//---------------------------------------------------------BubbleSort()----------------------------------------------------------------------
void Arrayop::BubbleSort()
{
	int i,j,temp;
	for(i=1;i<=N;i++){
		for(j=1;j<=N-i;j++){
			if(A[j]>=A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
//---------------------------------------------------------MaxArray()----------------------------------------------------------------------
int Arrayop::MaxArray()
{
	int Max,i;
	Max=A[1];
	for(i=2;i<=N;i++){
		if(Max<A[i]){
			Max=A[i];
		}
	}
	return Max;
}
//---------------------------------------------------------StdDev()----------------------------------------------------------------------
float Arrayop::StdDev()
{
	int SumX=0,SumXSqr=0,i;
	float Avg,T1,T2,Variance,SDev;
	
	for(i=1;i<=N;i++){
		SumX=SumX+A[i];
		SumXSqr=SumXSqr+(A[i]*A[i]);
	}
	
	Avg=SumX/N;
	T2=Avg*Avg;
	T1=SumXSqr/N;
	Variance=T1-T2;
	SDev=sqrt(Variance);
	return SDev;
}