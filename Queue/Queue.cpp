#include<iostream>
using namespace std;

typedef int ElemType;

class Queue{
	private:
		int front;
		int rear;
		ElemType*pQueue;
		int Maxsize;
	public:
		Queue(int max);
		bool isEmpty();
		bool isFull();
		ElemType GetHead();
		bool EnQueue(ElemType x);
		bool DeQueue(ElemType&x);
		int Length();
		void PrintQueue();
		~Queue();
};

Queue::Queue(int max=100){
	Maxsize=max;
	front=rear=0;
	pQueue=new ElemType[Maxsize];
}

bool Queue::isEmpty(){
	if(rear==front){
		return true;
	}
	else return false;
}

bool Queue::isFull(){
	if((rear+1)%Maxsize==front){
		return true;
	}
	else return false;
}

bool Queue::EnQueue(ElemType x){
	 if(isFull()) return false;
	 pQueue[rear]=x;
	 rear=(rear+1)%Maxsize;
	 return true;
}

bool Queue::DeQueue(ElemType&x){
	if(isEmpty()) return false;
	x=pQueue[front];
	front=(front+1)%Maxsize;
	return true;
}

//使用前判断是否为空队 
ElemType Queue::GetHead(){
	return pQueue[front];
}

int Queue::Length(){
	if(isEmpty()){
		return 0;
	}
	else if(rear>front){
		return rear-front;
	}
	else{
		return rear+Maxsize-front;
	}
}

void Queue::PrintQueue(){
	if(isEmpty()){
		cout<<"Empty"<<endl;
	}
	else if(rear>front){
		for(int i=front;i<rear;i++){
			cout<<pQueue[i]<<endl;
		}
	}
	else{
		for(int j=front;j<Maxsize;j++){
			cout<<pQueue[j]<<endl;
		}
		for(int k=0;k<rear;k++){
			cout<<pQueue[k]<<endl;
		}
	}
}

Queue::~Queue(){
	delete[] pQueue;
}

/*
int main(){
	int temp;
	Queue Q(10);
	cout<<"Empty? "<<Q.isEmpty()<<endl;
	for(int i=0;i<10;i++){
		Q.EnQueue(i);
	}
	Q.PrintQueue();
	Q.DeQueue(temp); 
	Q.PrintQueue();
}
*/
