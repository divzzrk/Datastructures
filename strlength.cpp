#include<iostream>
using namespace std;
int strlength(char str[20]);
main()
{
	int len;
	char st[20];
	cout<<"Enter a string: ";
	cin>>st;
	len=strlength(st);
	cout<<"The length of the string is: "<<len;
}
int strlength(char str[20])
{
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}