#include <iostream>
using namespace std;
 Node* solve(Node *root, int &k, int node){
    if(!root)
       return NULL;
     
     if(root->data==node)
        return root;
    
    Node* LeftAns=solve(root->left,k,node);
    Node* RightAns=solve(root->right,k,node);
    
    if((!LeftAns && RightAns) || (LeftAns && !RightAns)){
        k--;
        if(k==0)       //Kth ancestor found
            return root;

        if(LeftAns!=NULL)
           return LeftAns;
        else
           return RightAns;
    }
    return NULL;
}
     
    
int kthAncestor(Node *root, int k, int node)
{
      Node*ans=solve(root,k,node);         //Ans stores the kth ancestor(if any)
      if(ans==NULL || ans->data==node)     //Edge case: If node is equal to root's data, return -1 because root has no ancestors
        return -1;
    else
       return ans->data;
}
