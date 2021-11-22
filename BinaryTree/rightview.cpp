// https://leetcode.com/problems/binary-tree-right-side-view/

/*  
    Use BFS/LOT
    Time Complexity: O(n), where n is the number of nodes in the binary tree.
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    
        vector<int>res;
        if(root==NULL){
            return res;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            int size=q.size();
            int count=size;
            while(size--){

                TreeNode* curr=q.front();
                q.pop();

                if(count-1==size){
                    res.push_back(curr->val);
                }

                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }

            }
        }
        return res;
    }
};
