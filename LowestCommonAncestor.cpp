#include <iostream>
TreeNode* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        //base  case
        if(root==NULL)
           return NULL;
        if(root->val==p->val || root->val==q->val)
           return root;

       Node*LeftAns= lowestCommonAncestor(root->left,p,q);
       Node*RightAns= lowestCommonAncestor(root->right,p,q);
        
         if(LeftAns && RightAns)
            return root;
        else if(!LeftAns && RightAns)
            return RightAns;
         else if(LeftAns && !RightAns)
            return LeftAns;
        else
            return NULL;
    }
