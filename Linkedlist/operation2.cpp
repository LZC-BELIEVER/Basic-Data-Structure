#include"linkedlist.h"

LList::LList(){
	head=new LNode;
	head->next=NULL;
}

bool LList::isEmpty(){
	if(head->next==NULL){
		return true;
	}
	else{
		return false;
	}
}

LNode* LList::GetElem(int i){
	if(i<0) return NULL;
	LNode*p;
	int j=0;
	p=head;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	return p;
} 

bool LList::InsertNextNode(LNode*p,ElemType e){
	if(p==NULL) return false;
	LNode*s=new LNode;
	if(s==NULL) return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}


bool LList::ListInsert(int i,ElemType e){
	if(i<1) return false;
	LNode*p=GetElem(i-1);
    return InsertNextNode(p,e);
}

bool LList::InsertPriorNode(LNode*p,LNode*s){
	if(p==NULL||s==NULL) return false;
	InsertNextNode(p,s->data);
	ElemType temp=s->data;
	s->data=p->data;
	p->data=temp;
	return true;
}

bool LList::ListDelete(int i,ElemType&e){
	if(i<1) return false;
	LNode*p=GetElem(i-1);
	if(p==NULL||p->next==NULL) return false;
	LNode*q=p->next;
	e=q->data;
	p->next=q->next;
	delete q;
	return true;
}

LNode*LList::GetByValue(ElemType e){
	LNode*p=head->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
}

int LList::Length(){
	int len=0;
	LNode*p=head;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
}

LNode*LList::TailEstab(ElemType*list,int len){
	LNode*end=head;
	LNode*s=NULL;
	for(int i=0;i<len;i++){
		s=new LNode;
		s->data=list[i];
		end->next=s;
		end=s;
	}
	end->next=NULL;
	return head;
}

LNode*LList::HeadEstab(ElemType*list,int len){
	for(int i=0;i<len;i++){
		InsertNextNode(head,list[i]);
	}
	return head;
}

void LList::PrintElem(int i){
	cout<<GetElem(i)->data<<endl;
}

void LList::PrintList(){
	LNode*p=head->next;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}

LList::~LList(){
	LNode*p=head->next;
	LNode*q=NULL;
	while(p!=NULL){
		q=p->next;
    	delete p;
    	p=q;
	}
	delete head;
}

int main(){
	LList L;
	ElemType list[10]={2,3,4,5,114514,666,888,9,0};
    L.HeadEstab(list,10);
    L.PrintList();
    cout<<L.GetByValue(114514)->data;
	return 0;
} 
