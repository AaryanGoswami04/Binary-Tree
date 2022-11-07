#include <iostream>
//Time complexity:O(N) Space complexity:O(N)
    void CreateMap(vector<int>& inorder, map<int,int>& NodeToIndex, int n){
        for(int i=0; i<n; i++)
               NodeToIndex[inorder[i]]=i;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postorderindex, int inorder_start, int inorder_end, map<int,int>& NodeToIndex, int n){

           //base case
           if(postorderindex<0 || inorder_start > inorder_end)
               return NULL;
            
            int element = postorder[postorderindex--];
            TreeNode* root = new TreeNode(element);
            int position = NodeToIndex[element];

            //recrusive calls
           root->right = solve(inorder, postorder, postorderindex, position+1, inorder_end,NodeToIndex, n);
        root->left = solve(inorder, postorder, postorderindex, inorder_start, position-1,NodeToIndex, n);

            return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n = inorder.size();
       int postorderindex = n-1;
       map<int,int> NodeToIndex;

        CreateMap(inorder, NodeToIndex, n);
        TreeNode* ans= solve(inorder, postorder, postorderindex, 0, n-1, NodeToIndex, n);
        return ans;
    }
};
int main() {
  std::cout << "Hello World!\n";
}