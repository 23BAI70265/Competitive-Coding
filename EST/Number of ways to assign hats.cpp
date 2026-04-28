class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[41][1 << 10];

    int solve(int hat, int mask, vector<vector<int>>& people, int fullMask) {
        if(mask == fullMask) return 1;
        if(hat > 40) return 0;

        if(dp[hat][mask] != -1) return dp[hat][mask];
        long long ans = solve(hat + 1, mask, people, fullMask);

        for(int person : people[hat]) {
            if((mask & (1 << person)) == 0) {
                ans += solve(hat + 1, mask | (1 << person), people, fullMask);
                ans %= MOD;
            }
        }
        return dp[hat][mask] = ans;
    }

    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> people(41);
        for(int person = 0; person < n; person++) {
            for(int hat : hats[person]) {
                people[hat].push_back(person);
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, people, (1 << n) - 1);
    }
};