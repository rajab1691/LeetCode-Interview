/*Every backtracking problem consists of three steps
  1)choose
  2)explore
  3)unchoose
  
 always use helper function in backtracking problem
 
 Time complexity = O(4^n).
 because- Each digit can be replaced by at most 4 letters, so the total number of combinations is 4^N.
*/


class Solution {
public:
  
    vector<string>mappings={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
    //we are going to  return this 
    vector<string>res;
  
    vector<string> letterCombinations(string digits) {
        
        if(digits == "") return {};  
            
        string ans="";
        helper(digits,0,ans);
        return res;
    }
    
    void helper(string digits,int idx,string ans){
        
        if(idx==digits.length()){
            res.push_back(ans);
            return;
        }   
        
        for(auto &x:mappings[digits[idx]-'2']){
            //choose
            ans.push_back(x);
            
            //exploring
            helper(digits,idx+1,ans);
            
            //unchoose
            ans.pop_back();
            
        }
    }
};
