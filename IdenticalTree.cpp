#include <iostream>
#include <queue>
using namespace std;
 bool isSameTree(node* p,node* q) {
        //base case
        if(p==NULL && q==NULL)
           return true;
       if((p!=NULL && q==NULL)||(p==NULL && q!=NULL))
            return false;
        
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool isequal=p->val==q->val;
        
        if(left && right && isequal)
            return 1;
        else
            return 0;  
 }
