#include <iostream>
#include <queue>
using namespace std;
void inorder(node *root, int &cnt) {
  if (root == NULL)
    return;
  inorder(root->left, cnt);
  // leaf node
  if (root->left == NULL && root->right == NULL)
    cnt++;
  inorder(root->right, cnt);
}
