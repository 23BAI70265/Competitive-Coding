class Solution {
public:
    bool check(vector<int> &batteries, int n, long long time){
        int m = batteries.size() ;
        // how to check the validation
        long long sum = 0 ;
        for(int i = 0; i < m; i++){
            sum += min(time, (1ll * batteries[i])) ;
        }
        return sum >= (n * time) ;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size() ;

        long long low = 0 ;
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL)/n ; 
        long long ans = 0 ;
        while(low <= high){
            long long mid = low + (high - low)/2 ;
            if(check(batteries, n, mid)){
                ans = mid ;
                low = mid + 1 ;
            }
            else high = mid - 1 ;
        }
        return ans ;
    }
};