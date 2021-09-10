/*Using Backtracking
    Time Complexity= O(n(2 ^ n)). 
*/
class Solution {
public:
    
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
            
        vector<int>out;
        res.push_back(out);
        helper(0,nums,out);
        return res;
    }
    void helper(int idx,vector<int>&nums,vector<int>&out){
        
        for(int j=idx;j<nums.size();j++){
            out.push_back(nums[j]);  
            res.push_back(out);
            helper(j+1,nums,out);
            out.pop_back();
        }
        
    }
};

/*Using Bit manip
  Time complexity= O(n(2 ^ n)). 
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
         vector<vector<int>>res;
        int n=pow(2,nums.size());
        
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
