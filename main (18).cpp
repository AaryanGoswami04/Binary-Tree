#include <iostream>
pair<int,int>solve(Node* root){
        //base case
        if(!root)
        return {0,0};
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        pair<int,int>res;
        
        res.first=left.second+right.second+root->data;
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans=solve(root);
        return max(ans.first,ans.second);
    }
int main() {
  std::cout << "Hello World!\n";
}