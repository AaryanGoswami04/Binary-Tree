#include <iostream>
//Morris traversal: O(1) Space complexity
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        if(!root)  
            return ans;

        TreeNode* curr=root;
        while( curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;   //Sotres the predecessor i.e the rightmost node of left subtree
                while( pred->right && pred->right != curr)
                    pred = pred->right;
                
                if(pred->right == NULL){  //creation of temporary link
                    pred->right = curr;
                    curr = curr->left;
                }
                else{  //If pred is already linked to curr, it means we have already traversed the left subtree, so remove the link and store curr into ans and then move towards the right subtree
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
int main() {
  std::cout << "Hello World!\n";
}