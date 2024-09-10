/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.*/
class Codec {
public:
    string s;
    // Encodes a tree to a single string.
    //TC:O(N); SC:O(N)
    string serialize(TreeNode* root) { //Encode level order traversal into a string, each node separated by ',' and null nodes represented by '#'
        if(!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            auto front = q.front();
            q.pop();

            if(front == NULL) s += "#,";
            else{
                q.push(front->left);
                q.push(front->right);

                s += to_string(front->val) + ",";
            }
        }
        s.pop_back();
    
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data); //Convert string into a stream, with ',' as delimiter
        string node;

        getline(ss, node, ',');
        TreeNode* root = new TreeNode(stoi(node));

        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* front = q.front();
            q.pop();

            getline(ss, node, ',');

            if(node != "#"){
                TreeNode* left = new TreeNode(stoi(node));
                front->left = left;

                q.push(left);
            }

            getline(ss, node, ',');

            if(node != "#"){
                TreeNode* right = new TreeNode(stoi(node));
                front->right = right;

                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
