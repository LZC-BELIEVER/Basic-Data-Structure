#include<iostream>
using namespace std;

typedef int ElemType;

class LNode{
	public:
	    ElemType data;
     	LNode*next;
};

class LList{
	private:
		LNode*head;
	public:
	    LList();
		bool isEmpty(); 
		bool ListInsert(int i, ElemType e);
		bool InsertNextNode(LNode*p,ElemType e);
		bool InsertPriorNode(LNode*p,LNode*s);
		bool ListDelete(int i,ElemType&e);	
		LNode*GetElem(int i); 
		LNode*GetByValue(ElemType e);
		int Length();
		LNode*TailEstab(ElemType*list,int len);
		LNode*HeadEstab(ElemType*list,int len);
		void PrintElem(int i);
		void PrintList();
		~LList();
};
