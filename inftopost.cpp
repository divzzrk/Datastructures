#include<iostream>
#include<string.h>
using namespace std;

class inftopost
{
private:
		char infix[30];
		char postfix[30];
		char opstk[30];
		int top;
	public:
		inftopost();
		void convert(char s[]);
		int prec(char a);
};

inftopost::inftopost(){					//constructor to initialise top
	top=-1;
}

int inftopost::prec(char a){				//function to check precedence of symbol
	switch(a)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':
		case '$':return 3;
		default: return -1;
	}
}

void inftopost::convert(char s[20])			//function to convert infix to postifix
{
	strcpy(infix,s);
	char symb;
	int i=0;						//for infix expression
	int j=-1;					//for postfix
	while(infix[i]!='\0'){
		symb=infix[i];
		if(isalpha(symb)){
			j++;
			postfix[j]=symb;
		}
		else{
			if(top==-1){
				top++;
				opstk[top]=symb;
			}
			else{
				if(symb=='('){
					top++;
					opstk[top]=symb;
				}
				else if(symb==')'){
						while(opstk[top]!='('){
							j++;
							postfix[j]=opstk[top];
							top--;
						}
						top--;
				}
				else if(prec(symb)>prec(opstk[top])){
					top++;
					opstk[top]=symb;
				}
				else{
					while(prec(opstk[top])>=prec(symb) && top!=-1)
					{
						j++;
						postfix[j]=opstk[top];
						top--;
					}
					top++;
					opstk[top]=symb;
				}
			}
		}
		i++;
}
	while(top!=-1){
		j++;
		postfix[j]=opstk[top];
		top--;
	}
	postfix[++j]='\0';
	cout<<postfix;
}	

//main method definition
main()
{
	cout<<"Program to convert infix expression to postfix expression"<<endl;
	inftopost ip;
	char inf[30];
	cout<<"Enter the infix expression: ";
	cin>>inf;
	cout<<"The postfix expression is: ";
	ip.convert(inf);
}
