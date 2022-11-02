#include <iostream>
#include <queue>
using namespace std;
class node {
public:
  int data;
  node *left;
  node *right;
  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
node *BuildTree(node *root) {
  cout << "enter data" << endl;
  int data;
  cin >> data;
  root = new node(data);
  if (data == -1)
    return NULL;

  cout << "enter data to be inserted in the left of " << data << endl;
  root->left = BuildTree(root->left);
  cout << "enter data to be inserted in the right of " << data << endl;
  root->right = BuildTree(root->right);
  return root;
}
void levelordertransversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL); // NULL acts as a separator
  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    } else {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}
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
int main() {
  //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  // 1 5 2 -1 -1 6 7 -1 -1 -1 10 15 8 -1 -1 -1 -1
  node *root = NULL;
  root = BuildTree(root);
  cout << isBalanced(root)<< endl;
}