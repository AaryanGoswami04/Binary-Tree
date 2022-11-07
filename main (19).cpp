#include <iostream>
//Time complezity:O(N), Space complexity:O(N)
   void CreateMapping(vector<int>& inorder, map<int,int>& NodeToIndex,int n){
       for(int i=0; i<n; i++)
           NodeToIndex[inorder[i]]=i;
   }

   TreeNode*solve(vector<int>& preorder,vector<int>& inorder, int &preorderindex, int inorder_start, int inorder_end,int n, map<int,int> NodeToIndex){
       //base case
       if(preorderindex >= n || inorder_start > inorder_end)
          return NULL;

        int element = preorder[preorderindex++];
        TreeNode* root=new TreeNode(element);
        int position= NodeToIndex[element];

        //Recursice calls
        root->left=solve(preorder, inorder, preorderindex, inorder_start, position-1, n,NodeToIndex);
        root->right=solve(preorder, inorder, preorderindex, position+1, inorder_end, n,NodeToIndex);
         
        return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preorderindex=0;
        map<int,int>NodeToIndex;

        CreateMapping(inorder, NodeToIndex, n);

        TreeNode* ans=solve(preorder,inorder,preorderindex,0,n-1,n,NodeToIndex);;
        return ans;
    }
};
int main() {
  std::cout << "Hello World!\n";
}