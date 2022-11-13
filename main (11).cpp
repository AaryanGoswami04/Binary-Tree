#include <iostream>
//Iterative approach: Space complexity:O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* temp = root;
    while(temp != NULL){
        if(temp->val < p->val && temp->val < q->val)
              temp = temp->right;

        else if(temp->val > p->val && temp->val > q->val)
               temp = temp->left;
        else 
           return temp;
    }
    return temp;
    }
};
int main() {
  std::cout << "Hello World!\n";
}