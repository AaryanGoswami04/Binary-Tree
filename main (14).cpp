#include <iostream>
public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
     vector<int>ans;
     if(!root)
        return ans;
     
     map<int,int>TopNode;
     queue<pair<Node*,int>>q;
     q.push({root,0});
     
     while(!q.empty()){
         pair<Node*,int>temp=q.front();
         q.pop();
         
         Node*frontnode=temp.first;
         int hd=temp.second;
         
         //If a value is already present for hd, then do nothing
         if(TopNode.find(hd)==TopNode.end())
             TopNode[hd]=frontnode->data;
             
         if(frontnode->left)
             q.push({frontnode->left,hd-1});
             
         if(frontnode->right)
             q.push({frontnode->right,hd+1});
     }
     for(auto i:TopNode)
     ans.push_back(i.second);
     return ans;
int main() {
  
}