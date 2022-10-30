#include <iostream>
#include <queue>
using namespace std;
int height(node* root){
  //base case
  if(root==NULL)
    return 0;
  int left=height(root->left);
  int right=height(root->right);
  int ans=max(left,right)+1;
  return ans;
}
int diameter(node*root){   //Brute Force Time complexity:O(N^2)
  //base case
  if(root==NULL)
    return 0;
  int op1=diameter(root->left);
  int op2=diameter(root->right);
  int op3=height(root->left)+1+height(root->right);
  int ans=max(op1,max(op2,op3));
  return ans;
}
pair<int,int> fastdiameter(node*root){   //Optimised approach:O(N) Each node is being transversed only once
  //base case
  if(root==NULL)
    return {0,0};     //first,second values of pair store diameter,height respectively
  pair<int,int>left=fastdiameter(root->left);
   pair<int,int>right=fastdiameter(root->right);

  int op1=left.first;   //stores diameter of left subtree
  int op2=right.first; //stores diameter of right subtree
  int op3=left.second+right.second+1; //stores sum of left subtree's height+right subtree's height+1
  
  pair<int,int>ans;
  ans.first=max(op1,max(op2,op3));    //stores diameter of the tree
  ans.second=max(left.second,right.second)+1; //stores height of the tree

  return ans;
  }
