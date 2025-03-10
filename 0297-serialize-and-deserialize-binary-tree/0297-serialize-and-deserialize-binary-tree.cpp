/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curnode=q.front();
            q.pop();
            if(curnode==NULL) s.append("null,");
            else s.append(to_string(curnode->val)+',');
            if(curnode!=NULL)
            {
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="null")
            {
                node->left=NULL;
            }
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="null")
            {
                node->right=NULL;
            }
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));