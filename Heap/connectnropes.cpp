// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

/*
    Use min heap and insert all lengths into the min-heap
    and everytime extract two minimum length add it the cost 
    and push it to the min heap
    
    T.C- O(nlogn)
    S.C- O(1) bcuz of min heap
*/

  long long minCost(long long arr[], long long n) {
        
         long long cost=0;
         
         priority_queue<long long,vector<long long>,greater<long long>>pq(arr,arr+n);
         
        
         while(pq.size()>1){
            long long first=pq.top();
            pq.pop();
            
            long long second=pq.top();
            pq.pop();
            
            cost+=first+second;
            pq.push(first+second);
         }    
         return cost;
    }
