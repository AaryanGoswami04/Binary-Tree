#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
      int data;
      node*left;
      node*right;
      node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
      }
};
node* BuildTree(node*root){
  cout<<"enter data"<<endl;
  int data;
  cin>>data;
  root=new node(data);
  if(data==-1)
    return NULL;

  cout<<"enter data to be inserted in the left of "<<data<<endl;
  root->left=BuildTree(root->left);
  cout<<"enter data to be inserted in the right of "<<data<<endl;
  root->right=BuildTree(root->right);
  return root;
}
void levelordertransversal(node*root){
  queue<node*>q;
  q.push(root);
  q.push(NULL);  //NULL acts as a separator
  while(!q.empty()){
    node*temp=q.front();
    q.pop();

    if(temp==NULL){
      cout<<endl;
      if(!q.empty())
        q.push(NULL);
    }
    else{
     cout<<temp->data<<" ";
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
    }
   }
}
int main() {
   //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node*root=NULL;
    root=BuildTree(root);
    levelordertransversal(root);
}