class Solution {
public:
    bool check(vector<int> &nums, int value, int maxOperations){
        int n = nums.size() ;
        long long count = 0 ;
        for(int i = 0; i < n; i++){
            if(nums[i] <= value) continue ;
            int temp = nums[i] ;
            if(temp % value != 0) count++ ; 
            count +=  temp/value - 1 ;   
            if(count > maxOperations) return false ;
        }
        // cout<<count<<" "<<value<<'\n' ;
        return count <= maxOperations ;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size() ;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end()) ;
        int ans = 1 ;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            if(check(nums, mid, maxOperations)){
                ans = mid ;
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        return ans ;
    }
};