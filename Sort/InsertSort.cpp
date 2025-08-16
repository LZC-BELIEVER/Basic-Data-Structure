#include<iostream>
using namespace std;

void InsertSort(int*A,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if(A[i]<A[i-1]){
			temp=A[i];
			for(j=i-1;j>=0&&A[j]>temp;j--){
				A[j+1]=A[j];
			}
			A[j+1]=temp;
		}
    }
}

/*
int main(){
	int array[10]={3,66,855,9,1,12138,555,666,77,520};
	InsertSort(array,10);
	for(int k=0;k<10;k++){
		cout<<array[k] <<endl;
	}
	return 0;
}
*/
