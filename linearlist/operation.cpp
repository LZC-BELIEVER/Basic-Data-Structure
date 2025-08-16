#include"linearlist.h"
#include<iostream>
using namespace std;


Sqlist::Sqlist(int maxsize){
	Maxsize=maxsize;
    data=new ElemType[Maxsize];
    length=0;
}

bool Sqlist::InsertElem(int i,ElemType e){
	if(i<1||i>length+1) return false;
	length=length+1;
	if(length>Maxsize) return false;
	for(int j=length;j>=i;j--){
		data[j]=data[j-1];
	}
	data[i-1]=e;
	return true;
} 

void Sqlist::printlist(){
	for(int i=0;i<length;i++){
		cout<<data[i]<<endl;
	}
}

bool Sqlist::DeleteElem(int i,ElemType&e){
	if(i<1||i>length) return false;
	e=data[i-1];
	for(int j=i;j<length;j++){
		data[j-1]=data[j];
	}
	length--;
	if(length<0) return false;
	return true;
}

ElemType Sqlist::GetElem(int i){
	return data[i-1];
}

int Sqlist::LocateElem(ElemType e){
	for(int i=0;i<length;i++){
		if(data[i]==e){
			return i+1;
		}
	}
}

Sqlist::~Sqlist(){
	delete[] data;
}

int main(){
	Sqlist L(100);
	int a=0;
	if(L.InsertElem(1,20)){
		L.InsertElem(2,500);
		L.InsertElem(3,50);
		L.InsertElem(4,666);
		L.DeleteElem(2,a);
		L.printlist();
		cout<<L.GetElem(2)<<endl;
		cout<<L.LocateElem(666)<<endl;
	}
	else{
		cout<<"fail"<<endl;
	}
}


