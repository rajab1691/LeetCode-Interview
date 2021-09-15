// https://leetcode.com/problems/combination-sum-ii/
/*
      The time complexity is O(k * 2^N), where k is the average length of each possible solution. 
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>&a, int t) {
          
        vector<int>temp;
        sort(a.begin(),a.end());
        helper(a,t,0,temp);
        return res;
    }
    
    void helper(vector<int>&a,int t,int idx,vector<int>temp){
        
        if(t<0){
            return;
        }
        if(t==0){
            res.push_back(temp);
            return;
        }
        
        for(int i=idx;i<a.size();i++){
          //this if condition just for handling duplicates
            if(i==idx or a[i]!=a[i-1]){
                  temp.push_back(a[i]);
                   //from i+1 because we can't take same element twice
                   helper(a,t-a[i],i+1,temp);
                   temp.pop_back();
            }
        }
    }
};
