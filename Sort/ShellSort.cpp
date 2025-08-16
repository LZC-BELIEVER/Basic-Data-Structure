#include<iostream>
using namespace std;

void ShellSort(int*A,int n){
	int i,j,d;
	for(d=n/2;d>=1;d=d/2){
		for(i=d+1;i<=n;i++){
			if(A[i]<A[i-d]){
				A[0]=A[i];
				for(j=i-d;j>=1&&A[0]<A[j];j=j-d){
					A[j+d]=A[j];
				}
				A[j+d]=A[0];
			}
		}
	}
}

int main(){
	int array[8]={8,7,6,4,5,3,1,2};
	ShellSort(array,8);
	for(int k=0;k<8;k++){
		cout<<array[k]<<endl;
	}
	return 0;
}
