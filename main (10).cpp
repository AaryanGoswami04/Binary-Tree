#include <iostream>
using namespace std;
int main() {
  pair<bool,int> isSumTreeFast(Node*root){
          //base case
        if(root==NULL)
        return {true,0};
        
        if(root->left==NULL && root->right==NULL)//leaf node
        return {true,root->data};
        
        pair<bool,int>leftAns=isSumTreeFast(root->left);
        pair<bool,int>rightAns=isSumTreeFast(root->right);
        
        bool isLeftSumTree=leftAns.first;
        bool isRightSumTree=rightAns.first;
        bool condition= root->data==leftAns.second+rightAns.second;
        
        pair<bool,int>ans;
        
        if(left && right && condition){
            ans.first=true;
            ans.second=2*root->data;
        }
        else
        ans.first=false;
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
}