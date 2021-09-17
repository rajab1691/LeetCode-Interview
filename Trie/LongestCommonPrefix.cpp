// https://leetcode.com/problems/longest-common-prefix/
/*
    Implement trie and Do till we find a leaf node or node has more than 1 children
    
    Time complexity : preprocessing O(S), where S is the number of all characters in the array, LCP query O(m).
                        Trie build has O(S) time complexity. To find the common prefix of q in the Trie takes in the worst case O(m).

    Space complexity : O(S). We only used additional S extra space for the Trie.
*/

class Node{
public:
    char data;
    unordered_map<char,Node*>children;
    bool isEnd=false;
    
    Node(){};
    Node(char d){
        data=d;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
  //get Trie
    Node* getTrie(){
        return root;
    }
  //Insert a word in trie
    void insert(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node(ch);
                temp=temp->children[ch];
            }else{
                temp=temp->children[ch];
            }
        }
        temp->isEnd=true;
    }
};
class Solution {
public:
    
    string longestCommonPrefix(vector<string>& v) {
        
        Trie *t=new Trie();
        
        for(int i=0;i<v.size();i++){
            t->insert(v[i]);
        }
        Node *temp=t->getTrie();
         string final="";  
        // Do till we find a leaf node or node has more than 1 children
        while(temp and !temp->isEnd and temp->children.size()==1){
            auto it=temp->children.begin();
            final+=it->first;
            temp=it->second;
        }
        return final;
    }
};
