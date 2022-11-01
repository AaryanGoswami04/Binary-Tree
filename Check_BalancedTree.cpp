#include <iostream>
#include <queue>
/*A height balanced binary tree is a binary tree in which the height of the left subtree and right subtree of any node does not differ by more than 1 and both the left and right subtree are also height balanced.*/
int height(node *root) {
  // base case
  if (root == NULL)
    return 0;
  int left = height(root->left);
  int right = height(root->right);
  int ans = max(left, right) + 1;
  return ans;
}
 bool isBalanced(node *root)  //Time Complexity:O(N^2)
    {
        //base code
        if(root==NULL)
         return true;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
         
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff)
          return 1;
        else
          return 0;
    }
pair<bool,int> isBalancedFast(node* root){   //Optimised approach:TC->O(N)
   //base case
   if(root==NULL)
     return {true,0};
  
  pair<int,int>left=isBalancedFast(root->left);
  pair<int,int>right=isBalancedFast(root->right);
  
  bool LeftisBalanced=left.first;
  bool RightisBalanced=right.first;
  bool diff=abs(left.second-left.second)<=1;   //difference of their heights
  
  pair<bool,int>ans;
  ans.second=max(left.second,right.second)+1;
  
  if(LeftisBalanced && RightisBalanced && diff)
    ans.first=true;
  else
    ans.first=false;
  return ans;
}
