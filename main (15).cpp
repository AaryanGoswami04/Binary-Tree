#include <iostream>
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base  case
        if(root==NULL)
           return NULL;
        if(root->val==p->val || root->val==q->val)
           return root;

        TreeNode*LeftAns= lowestCommonAncestor(root->left,p,q);
        TreeNode*RightAns= lowestCommonAncestor(root->right,p,q);
        
         if(LeftAns && RightAns)
            return root;
        else if(!LeftAns && RightAns)
            return RightAns;
         else if(LeftAns && !RightAns)
            return LeftAns;
        else
            return NULL;
    }
int main() {
  std::cout << "Hello World!\n";
}