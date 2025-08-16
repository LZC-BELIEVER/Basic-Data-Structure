#include<iostream>
using namespace std;

void BubbleSort(int*A,int n){
	int i,j,temp;
	for(i=0;i<n-1 ;i++){
		for(j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
			}
		}
	}
}

int main(){
	int array[8]={1,3,5,114514,888,666,520,666};
	BubbleSort(array,8);
	for(int k=0;k<8;k++){
		cout<<array[k]<<endl;
	}
	return 0;
}
