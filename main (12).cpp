#include <iostream>
using namespace std;
int main() {
  void traverseleft(Node*root, vector<int>&ans){
         //base case
         if((root==NULL)||(root->left==NULL && root->right==NULL))
         return;
         ans.push_back(root->data);
         
         if(root->left)
             traverseleft(root->left,ans);
         else
              traverseleft(root->right,ans);
     }
     
     void traverseleaf(Node*root, vector<int>&ans){
         //base case
         if(root==NULL)
         return;
         if(root->left==NULL && root->right==NULL){
             ans.push_back(root->data);
             return;
         }
         
         traverseleaf(root->left,ans);
         traverseleaf(root->right,ans);
     }
         
       void traverseright(Node*root, vector<int>&ans){
         //base case
         if((root==NULL)||(root->left==NULL && root->right==NULL))
         return;
        
         if(root->right)
             traverseright(root->right,ans);
         else
              traverseright(root->left,ans);
         //push the data in the vector while coming back during recursive call    
        ans.push_back(root->data);
     }
     
    vector <int> boundary(Node *root)
    {
       vector<int>ans;
        if(root==NULL)
        return ans;
        ans.push_back(root->data);
        
        //store left part
        traverseleft(root->left,ans);
        
        //traverse leaf nodes
        //left subtree:
        traverseleaf(root->left,ans);
        //right subtree:
        traverseleaf(root->right,ans);
         
        //traverse right part
        traverseright(root->right,ans);
        
        return ans;
    }
}