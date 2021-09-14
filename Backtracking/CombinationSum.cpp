// https://leetcode.com/problems/combination-sum/
/*
    Since the problem is to get all the possible results, not the best or the number of result, 
    thus we don’t need to consider DP(dynamic programming), recursion is needed to handle it.
    
    Time Complexity=O(k*2^n)
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>&a, int t) {
        vector<int>temp;
        helper(a,temp,t,0);
        return res;
    }
    void helper(vector<int>&a, vector<int>temp, int t,int idx){
        //if target becomes negative then just return
        if(t<0){
            return;
        }
        if(t==0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<a.size();i++){
            temp.push_back(a[i]);
            helper(a,temp,t-a[i],i);
            temp.pop_back();
        }
    }
};
