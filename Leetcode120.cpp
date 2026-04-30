class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for(int i = 1;i < n;i++){
            for(int j = i;j >= 0;j--){
                if(j == 0) dp[j] = dp[j] + triangle[i][0];
                else if(i == j) dp[j] = dp[j-1] + triangle[i][j];
                else dp[j] = min(dp[j-1],dp[j]) + triangle[i][j];
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};
