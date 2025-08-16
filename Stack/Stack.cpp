#include<iostream>
using namespace std;

//typedef int ElemType;

class Box{
	public:
		int i;
		int j;
		int d;
		Box(int a=0,int b=0,int c=0){
			i=a;
			j=b;
			d=c;
		}
};

typedef Box ElemType;

class Stack{
	private:
		int top;
		ElemType*pStack;
		int Maxsize;
	public:
		Stack(int max);
		bool isEmpty();
		bool Push(ElemType x);
		bool Pop(ElemType&x);
		ElemType&GetTop();
		int Length();
		//void PrintStack();
		~Stack();
};

Stack::Stack(int max=100){
	Maxsize=max;
	top=-1;
	pStack=new ElemType[Maxsize];
}

bool Stack::isEmpty(){
	return top==-1;
}

bool Stack::Push(ElemType x){
	if(top==Maxsize-1){
		return false;
	}
	top++;
	pStack[top]=x;
	return true;
}

bool Stack::Pop(ElemType&x){
	if(top==-1){
		return false;
	}
	x=pStack[top];
	top--;
	return true;
}

//使用前判断是否为空栈 
ElemType&Stack::GetTop(){
	return pStack[top];
}

int Stack::Length(){
	return top+1;
}

/*void Stack::PrintStack(){
	for(int i=0;i<=top;i++){
		cout<<pStack[i]<<endl;
	}
}
*/

Stack::~Stack(){
	delete[] pStack;
}

/*
int main(){
	Stack S;
	int x;
	for(int i=0;i<5;i++){
		S.Push(i);
	}
	S.PrintStack();
	x=S.Pop(x);
	cout<<"top"<<S.GetTop()<<endl;
	cout<<"length"<<S.Length()<<endl;
	return 0;
}
*/
/*
int main(){
	Stack s;
	Box b(1,1,1);
	s.Push(b);
	s.Push(b);
	cout<<s.Length();
}*/
