#include <iostream>
//First value of pair stores sum when the current node is included while the second value stores the max sum when current node is excluded
pair<int,int>solve(Node* root){
        //base case
        if(!root)
        return {0,0};
        
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        pair<int,int>res;
        
        res.first = left.second + right.second + root->data;         //Max sum inlcuding current node
        res.second = max(left.first, left.second) + max(right.first, right.second);  //Max sum excluding current node
        return res;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans = solve(root);
        return max(ans.first, ans.second);
    }
