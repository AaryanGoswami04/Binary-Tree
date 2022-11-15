#include <iostream>
public:
//Time complexity:O(N)
   class info{
    public:
    int max; //Stores the max element of  subtree
    int min;  //stores min element of subtree
    bool IsBst; //check if the subtree is BST or not
    int sum;   //stores of sum of all nodes of subtree
};
    
    info solve(TreeNode* root, int &max_sum) {
        //base case
        if(root == NULL)
           return {INT_MIN, INT_MAX, true, 0};

        info left = solve(root->left, max_sum);
        info right = solve(root->right, max_sum);

        info CurrNode;
        CurrNode.sum = left.sum + right.sum + root->val;
        CurrNode.max = max(root->val, right.max);
        CurrNode.min = min(root->val, left.min);

        if(left.IsBst && right.IsBst && (root->val > left.max && root->val < right.min))
            CurrNode.IsBst = true;
        else
            CurrNode.IsBst = false;

        if(CurrNode.IsBst)
            max_sum = max(max_sum, CurrNode.sum);

        return CurrNode;
    }
   
    int maxSumBST(TreeNode* root) {
        if(!root->left && !root->right)
           return root->val;

        int max_sum = 0;
        info temp = solve(root, max_sum);
        return max_sum;
    }
};
int main() {
  std::cout << "Hello World!\n";
}