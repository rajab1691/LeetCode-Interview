// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

/*
    Use Sorting
    ->sort both arrival and dep time, then count the maximum platform
    
    T.C- O(nlogn) bcuz of Sorting
    S.C- O(1)
*/

   int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int i=0,j=0;
        int res=0;
        int platNeed=0;
        while(i<n and j<n){
            
            if(arr[i]<=dep[j]){
                platNeed++;
                i++;
            }else{
                platNeed--;
                j++;
            }
            res=max(res,platNeed);
        }
        return res;
    }
