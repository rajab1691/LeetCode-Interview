/*
      Class Node is = for every character we are storing  
      root->a->p->p->l->e
      here every (a,p,p,l,e,root)-> is a Node
      therefore it has data,and map for storing the address of childs   
      
      //isTerminal tells us whether it is last node or not
*/

class Node{
public:
    char data;
    unordered_map<char,Node*>children;
    bool isTerminal=false;

    Node(){}
        
    Node(char d){
        data=d;
    }
};
class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
            
        Node* temp=root;    
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node(ch);
                temp=temp->children[ch];
            }else{
                temp=temp->children[ch];
            }
        }
        temp->isTerminal=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->children.count(ch)==0)
                return false;
            temp=temp->children[ch];
        }
        return temp->isTerminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            if(temp->children.count(ch)==0)return false;
            temp=temp->children[ch];
        }
        return true;
    }
};
