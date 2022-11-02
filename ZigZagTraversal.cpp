#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        bool LeftToRight=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>ans(size);
            
            //process level
            for(int i=0;i<size;i++){
                TreeNode* FrontNode=q.front();
                q.pop();
                
                //normal insert or reverse insert
                int index=LeftToRight?i:size-i-1;
                ans[index]=FrontNode->val;
                
                if(FrontNode->left)
                    q.push(FrontNode->left);
                if(FrontNode->right)
                    q.push(FrontNode->right);
                
            }
            LeftToRight=!LeftToRight;
            res.push_back(ans);
        }
        return res;
}
