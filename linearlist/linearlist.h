#include<iostream>
using namespace std;

typedef int ElemType;

class Sqlist{
    private:
        ElemType*data;
        int Maxsize;
        int length;
    public:
    	Sqlist(int max);
    	bool InsertElem(int i,ElemType e); 
    	void printlist();
    	bool DeleteElem(int i,ElemType&e);
    	ElemType GetElem(int i);
    	int LocateElem(ElemType e);
    	~Sqlist();
};





