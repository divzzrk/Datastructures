/*-------------------------------------------------------------------------------------------------------------------------------------------
PostfixEvaluation.cpp
An object-oriented program in cpp to evaluate a postifx expression
181713
03-04-19
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 30
class stack
{
	public: int S[MAX];
	int N;
	public: stack();
			void push(int Num);
			int pop();
			void displayStack();
			int isStackEmpty();
};
//-----------calc inheriting stack------------------
class calc:public stack
{
	char infix[30];
	char postfix[30];
	public: calc();
			void InputPostfix();
			void InputInfix();
			int EvalPost();
			void InftoPost();
			int Prio(char a);
};
//---------------stack()-----------------------------
stack::stack()
{
	N=-1;
}
//--------------------push()--------------------------
void stack::push(int Num)
{
	if(N==MAX-1)
		return;
		//cout<<"Stack is full";
	else{
		N++;
		S[N]=Num;
	}
}
//----------------pop()---------------------------------
int stack::pop()
{
	int ele;
	if(isStackEmpty()){
		//cout<<"Stack is empty";
		return -1;
	}
	else{
		ele=S[N];
		N--;
		return(ele);
	}
}
//----------------displayStack()--------------------------
void stack::displayStack()
{
	int i;
	for(i=N;i>=0;i--)
			cout<<S[i]<<endl;
}
//------------isEmptyStack()-----------------------------
int stack::isStackEmpty()
{
	if(N==-1)
		return 1;
	else
		return 0;
}
//--------------calc-------------------------------------
calc::calc()
{
	strcpy(postfix," ");
	strcpy(infix," ");
}
void calc::InputPostfix()
{
	N=-1;
	//cin.getline(postfix,30);
	cin>>postfix;
}
void calc::InputInfix()
{
	N=-1;
	//cin.getline(postfix,30);
	cin>>infix;
}
//--------------evalPost---------------------------------
int calc::EvalPost()
{
	int Num,op1,op2,res;
	int i=0;
	char ch; 
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isdigit(ch)){
			Num=ch-'0';
			push(Num);
		}
		else{
			op2=pop();
			op1=pop();
			switch(ch){
				case '^':res=pow(op1,op2);
						push(res);
						break;
				case '/':res=op1/op2;
						push(res);
						break;
				case '*':res=op1*op2;
						push(res);
						break;
				case '-':res=op1-op2;
						push(res);
						break;
				case '+':res=op1+op2;
						push(res);
						break;
			}
			//push(res);
		}
		i++;
	}
	//push(res);
	res=pop();
	return res;
}	
int calc::Prio(char a){
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

void calc::InftoPost(){
	char symb;
	int i=0;	//for infix expression
	int j=-1;	//for postfix
	while(infix[i]!='\0'){
		symb=infix[i];
		if(isalpha(symb)||isdigit(symb)){
			j++;
			postfix[j]=symb;
			
		}
		else{
			if(N==-1){
				N++;
				S[N]=symb;
			}
			else{
				if(symb=='('){
					N++;
					S[N]=symb;
				}
				else if(symb==')'){
						while(S[N]!='('){
							j++;
							postfix[j]=S[N];
							N--;
						}
						N--;
				}
				else if(Prio(symb)>Prio(S[N])){
					N++;
					S[N]=symb;
				}
				
				
				else{
					while(Prio(S[N])>=Prio(symb) && N!=-1)
					{
						j++;
						postfix[j]=S[N];
						N--;
					}
					N++;
					S[N]=symb;
				}
			}
		}
		i++;
	}
	while(N!=-1){
		j++;
		postfix[j]=S[N];
		N--;
	}
	postfix[++j]='\0';
	cout<<postfix;
}
main()
{
	cout<<"c++ program to convert infix expression tp postfix as well as evaluate a postfix expression"<<endl;
	int ch=1;
	while(1){
		cout<<"\n\nMenu"<<endl;
		cout<<"1.To convert infix to postfix"<<endl;
		cout<<"2.To evaluate a postfix expression"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		stack s;
		calc c;
		switch(ch){
			case 1: cout<<"Enter an infix expression: ";
					c.InputInfix();
					cout<<"Postfix is: ";
					c.InftoPost();
					break;
			case 2: cout<<"Enter a postfix expression: ";
					c.InputPostfix();
					cout<<"Result is: "<<c.EvalPost();
					break;
			case 3:exit(0);
			default:cout<<"You have entered a wrong choice";
		}
	}
}