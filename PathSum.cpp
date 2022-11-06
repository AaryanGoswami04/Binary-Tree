#include <iostream>
using namespace std;
/*Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.*/
 //Time complexity:O(N^2) , Space complexity:O(N)
    void solve(TreeNode* root, int targetSum,int &ans, vector<int>&path){
        //base case
        if(!root)
           return;

        path.push_back(root->val);
        solve(root->left, targetSum, ans, path);
        solve(root->right, targetSum, ans, path);

        long long int PathSum=0;  
        for(int i=path.size()-1; i>=0; i--){
             PathSum += path[i];
             if(PathSum == targetSum)
              ans++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int ans=0;
        solve(root,targetSum,ans,path);
        return ans;
    }
};
