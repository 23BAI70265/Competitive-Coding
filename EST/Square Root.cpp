class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low = 0 ;
        int high = n ; 
        while(low <= high){
            int mid = low + (high - low)/2 ;
            // 10^4 * 10^4  -> not overflow
            int temp = mid * mid  ;
            if(temp == n) return mid ;
            else if(temp < n) low = mid + 1;
            else high = mid - 1 ;
        }
        return high ;
    }
};