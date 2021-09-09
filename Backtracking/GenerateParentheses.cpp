/*Every backtracking problem consists of three steps
  1)choose
  2)explore
  3)unchoose
  
 always use helper function in backtracking problem
 
 -givenFxn(){
      
      return res;
 }
 helper(){
    //base case
    
    //recursive
 }
 
 Generating all combinations of well formed paranthesis is a typical example of catalan numbers
 The complexity of this code is O(n * Cat(n)) where Cat(n) is the nth Catalan number
*/

class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        if(n==0)return {};
        
        string ans="";
        
        helper(n,ans,0,0);
        
        return res;
    }
    
    void helper(int n,string ans,int open,int close){
        
        if(ans.size()==2*n){
            res.push_back(ans);
            return;
        }
        
        if(open<n){
            ans.push_back('(');
            helper(n,ans,open+1,close);
            ans.pop_back();
        }
        if(close<open){
             ans.push_back(')');
            helper(n,ans,open,close+1);
            ans.pop_back();
        }
    }
};
