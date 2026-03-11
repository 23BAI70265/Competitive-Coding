class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size() ;
        sort(tasks.begin(), tasks.end(), [] (const vector<int> &v1, const vector<int> &v2){
             return (v1[1] - v1[0]) > (v2[1] - v2[0]);
        }) ;
        int total = 0 ;
        for(auto &it : tasks){
            total += it[0] ;
        }
        // for(auto &it : tasks){
        //     cout<<it[0]<<" " <<it[1]<<endl ;
        // }
        // cout<<total<<" " ;
        int ans = total ;
        for(int i = 0; i < n; i++){
            // cout<<ans<<" "<< tasks[i][1]<<endl ;
            if(tasks[i][1] > ans) ans += tasks[i][1] - ans ; 
            ans -= tasks[i][0] ;
        }
        return ans + total  ;
    }
};