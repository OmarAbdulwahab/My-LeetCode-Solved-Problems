/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        helper(root);
        return ans;
    }
private:
    vector<int> ans;
    void helper(Node* node){
        if(node == nullptr)
            return;
        
        for(Node* n: node->children)
            helper(n);
            
        ans.push_back(node->val);
    }
};