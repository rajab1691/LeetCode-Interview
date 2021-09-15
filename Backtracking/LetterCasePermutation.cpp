/*
    why recursion,backtracking because we have to return **all possible** strings
    Time Complexity: O(2^n*n).
    Space Complexity: O(2^n*n).
*/

class Solution {
public:
    
    vector<string>res;
    vector<string> letterCasePermutation(string s) {
        string ans="";
        helper(0,ans,s);
        return res;
    }
    void helper(int idx,string ans,string s){
        
        if(ans.size()==s.size()){
            res.push_back(ans);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
          //if it is a letter then
            if(isalpha(s[i])){
                ans.push_back(tolower(s[i]));
                helper(i+1,ans,s);
                ans.pop_back();
                
                ans.push_back(toupper(s[i]));
                helper(i+1,ans,s);
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
                helper(i+1,ans,s);
                ans.pop_back();
            }
        }
        
    }
};
