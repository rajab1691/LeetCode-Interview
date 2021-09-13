// https://leetcode.com/problems/subsets-ii/
/*
    same as subset just use sorting and check for duplicates
    Time complexity=  O(N*2^N)   
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>out;
        res.push_back(out);
        helper(0,nums,out);
        return res;
    }
    void helper(int idx,vector<int>&nums,vector<int>&out){
        
        for(int j=idx;j!=nums.size();j++){
            if(j==idx or nums[j]!=nums[j-1]){
                out.push_back(nums[j]);
                res.push_back(out);
                helper(j+1,nums,out);
                out.pop_back();
            }
        }
    }
};
