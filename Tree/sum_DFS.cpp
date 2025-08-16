#include<iostream>
#include"Treenode.cpp"
using namespace std;


int rage_sum(Treenode*root,int low,int high){
	if(root==NULL){
		return 0;
	}
	if(root->val>high){
		return rage_sum(root->left,low,high);
	}
	if(root->val<low){
		return rage_sum(root->right,low,high);	
	}
	return root->val+rage_sum(root->left,low,high)+rage_sum(root->right,low,high);
} 

