// https://leetcode.com/problems/palindrome-partitioning/
/*
    Time complexity=O(n*2^n)
    We are basically trying out every possible partition out there. For a string with length n, we will have 2^(n - 1) ways to partition it.
*/

class Solution {
public:
    vector<vector<string>>res;
    //checking palindrome
    bool isPal(string s,int l,int h){
        while(l<=h){
            if(s[l]!=s[h]){
                return false;
            }else{
                l++;
                h--;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        
        helper(s,ans,0);
        return res;
    }
    
    void helper(string s,vector<string>ans,int idx){
        if(idx==s.length()){
            res.push_back(ans);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPal(s,idx,i)){
                ans.push_back(s.substr(idx,i-idx+1));
                helper(s,ans,i+1);
                ans.pop_back();
            }
        }
    }
};
