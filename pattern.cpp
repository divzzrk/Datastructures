#include<iostream>
using namespace std;
main()
{
	int count = 1,spcount = 0;
	int k;
	for(int i=0; i<5; i++){
		for(int j=0;j<(int)9/2 - i;j++)
			cout<<" ";
		for(k=0; k<count; k++)
			cout<<"*";
		cout<<"\n";
		count += 2;
	}
	count -= 2;
	for(int i=0; i<5; i++){
		for(int j=0; j<spcount; j++)
			cout<<" ";
		for(int k=0; k<count; k++)
			cout<<"*";
		cout<<"\n";
		count -= 2;
		spcount += 1;
	}
}