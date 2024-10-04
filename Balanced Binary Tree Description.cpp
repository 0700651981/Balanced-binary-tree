#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
//definition of a binary tree node
struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//function to check the height of a tree
int height(TreeNode*root){
	if(root==NULL){
		return 0;
	}
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	return max(leftHeight,rightHeight)+1;
}
//function to check if it is balanced
bool isBalanced(TreeNode*root){
	if(root==NULL){
		return true;
	}
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	//explicitly call std::abs to avoid ambiguity
	if (std::abs(leftHeight-rightHeight)>1){
		return false;
	}
	//check if the current node is balanced
	if(abs(leftHeight-rightHeight)>1){
	return false;
	};
	//recursive check if the left and rigth 
	return isBalanced(root->left)&&isBalanced(root->right);
}
int main(){
	//example usage
	TreeNode*root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->right=new TreeNode(6);
	if (isBalanced(root)){
		cout<<"The tree height-balanced."<<endl;
	}
	else{
		cout<<"The tree is not height-balanced."<<endl;
	}
	return 0;
}
