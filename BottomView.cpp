/*Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.*/
/*        20
        /    \
      8       22
    /   \     /   \
  5      3   4     25
         /    \      
       10      14

For the above tree, the output should be 5 10 4 14 25.*/
//TC: O(N log N); SC:O(N)
//Print all nodes present at each x coordinate and are at max height from left to right 
    vector <int> bottomView(Node *root) {
        vector <int>ans;
        map<int, pair<int, Node*>> mp; //Stores {x, {y,Node}} 
        queue<pair<Node*, vector<int>>> q;  //Stores {Node, {x,y}} 
        
        q.push({root, {0,0}}); //root is at (0,0) (Reference)
        mp[0] = {0,root}; 
        
        while(q.size()){
            Node* front = q.front().first;
            int x = q.front().second[0], height = q.front().second[1];
            q.pop();
            
            //Hash x coordinate to correspondind {y,Node}
            if(front->left){
                q.push({front->left, {x-1, height+1}});
                mp[x-1] = {height+1, front->left};
            }
            if(front->right){
                q.push({front->right, {x+1, height+1}});
                mp[x+1] = {height+1, front->right};
            }
        }
        
        for(auto itr:mp){
             ans.push_back(itr.second.second->data);
        }
        
        return ans;
    }
