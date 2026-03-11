class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int m = growTime.size() ;
        vector<pair<int, int>> grow(m) ;
        for(int i = 0; i < m; i++){
            grow[i] = {growTime[i], i} ;
        }
        sort(grow.begin(), grow.end(),[] ( const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.first > p2.first ; 
        }) ;
        int days = 0 ;

        for(auto &it : grow){
            days += plantTime[it.second] ;
        }
        int daysPassed = 0 ;
        for(int i = 0; i < m; i++){
            auto it = grow[i] ;
            daysPassed += plantTime[it.second] ;
            if(it.first - (days - daysPassed) > 0) days += it.first - (days - daysPassed) ;
            
        }
        return days;
    }
};