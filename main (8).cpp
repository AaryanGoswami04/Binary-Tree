#include <iostream>
reeNode* CreateParentMapping(TreeNode* root, int start,  map<TreeNode*,TreeNode*>& NodeToParent){

        TreeNode* target;
        NodeToParent[root]=NULL;  //Root has no parent
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
               TreeNode* front=q.front();
               q.pop();

               if(front->val == start)   //To find the node whose value is equal to start
                  target=front;

                if(front->left){
                   q.push(front->left);
                   NodeToParent[front->left] = front;  //front->left is mapped to its parent
                }

                if(front->right){
                   q.push(front->right);
                   NodeToParent[front->right] = front;//front->right is mapped to its parent
                }
        }
        return target;
    }

   int infect_tree(TreeNode* root, map<TreeNode*,TreeNode*>& NodeToParent){
       map<TreeNode*,bool> visited;
       queue<TreeNode*>q;

       q.push(root);
       visited[root] = true;

       int ans=0;
       while(!q.empty()){
                bool flag = 0;  //to know if there has been an addition in queue
                int size=q.size();

                for(int i=0; i<size; i++){
                    //process neighbouring nodes
                    TreeNode* front=q.front();
                    q.pop();

                    if(front->left && visited[front->left]==false){  //If left child isn't visited, mark it as visited
                        flag=1;
                        q.push(front->left);
                        visited[front->left]=true;
                    }

                     if(front->right && visited[front->right]==false){
                        flag=1;
                        q.push(front->right);
                        visited[front->right]=true;
                    }
                    
                     if(NodeToParent[front] && visited[NodeToParent[front]]==false){//If parent isn't visited, mark it as visited
                        flag=1;
                        q.push(NodeToParent[front]); //pushes front's parent
                        visited[NodeToParent[front]]=1;
                    }
                }
                if(flag)
                   ans++;
       }
       return ans;
   }
    int amountOfTime(TreeNode* root, int start) {
        //Step 1:Map each node to its parent
        //Step 2: Find the node whose val is equal to start
        //Step 3: Infect the tree using Level order transversal
        map<TreeNode*,TreeNode*> NodeToParent;  //Maps each node to its parent
        TreeNode* target = CreateParentMapping(root, start, NodeToParent);

        int ans=infect_tree(target, NodeToParent);
        return ans;
    }
int main() {
  std::cout << "Hello World!\n";
}