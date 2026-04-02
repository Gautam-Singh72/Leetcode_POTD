#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    const int NEG_INF=-1e9;
    int solve(int i, int j, int m, int n, int skipCount, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n)    return NEG_INF;
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0){
                if(skipCount<2) return 0;
                return coins[i][j];
            }
            return coins[i][j];
        }
        if(dp[i][j][skipCount] != INT_MIN)   return dp[i][j][skipCount];

        int rightSkip=NEG_INF;
        int downSkip=NEG_INF;
        if(coins[i][j]<0 && skipCount<2){
            rightSkip=solve(i, j+1, m, n, skipCount+1, coins, dp);
            downSkip=solve(i+1, j, m, n, skipCount+1, coins, dp);
        }
        int right=coins[i][j]+solve(i, j+1, m, n, skipCount, coins, dp);
        int down=coins[i][j]+solve(i+1, j, m, n, skipCount, coins, dp);

        return dp[i][j][skipCount]=max({rightSkip, downSkip, right, down});
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        int skipCount=0;

        return solve(0, 0, m, n, skipCount, coins, dp);
    }
};