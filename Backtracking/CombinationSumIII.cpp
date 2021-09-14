// https://leetcode.com/problems/combination-sum-iii/
/*
    Time complexity is O(k * 9^k) because you copy k elements for O(9^k) combinations in the final result.
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>temp;
        //1,2,3,4,5,6,7,8,9
        helper(1,k,n,temp);
        return res;
    }
    void helper(int idx,int k,int t,vector<int>temp){
        
        if(t<0){
            return;
        }
        if(t==0 and temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            helper(i+1,k,t-i,temp);
            temp.pop_back();
        }
    }
    
};
