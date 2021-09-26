
/*
 Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*>map;
public:
    Node* cloneGraph(Node* node) {
            
        if(!node)return NULL;
        
        Node* copy=new Node(node->val,{});
        map[node]=copy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            
            Node* curr=q.front();
            q.pop();
            for(auto nbr:curr->neighbors){
                if(map.find(nbr)==map.end()){
                    map[nbr]=new Node(nbr->val,{});
                    q.push(nbr);
                }
                map[curr]->neighbors.push_back(map[nbr]);
            }
        }
        return copy;
    }
};
