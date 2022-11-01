#include <iostream>
using namespace std;
 /*Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.*/
pair<bool,int> isSumTreeFast(Node*root){
          //base cases
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
