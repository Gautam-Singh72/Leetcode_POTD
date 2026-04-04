#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    static bool comparator(pair<int, int> x, pair<int, int> y){
        if(x.second< y.second)  return true;
        return false;
    }

    int countWall(int l, int r, vector<int>& walls){
        int n=walls.size();
        int leftIdx=lower_bound(begin(walls), end(walls), l)-begin(walls);
        int rightIdx=upper_bound(begin(walls), end(walls), r)-begin(walls);
        int wallCount=rightIdx-leftIdx;
        return wallCount;
    }

    int solve(int i, int prevDir, vector<pair<int, int>>& roboDis, vector<int>& walls){
        int n=roboDis.size();
        if(i==n)    return 0;
        if(dp[i][prevDir]!=-1)  return dp[i][prevDir];

        //prevDir=0 left fire prevDir=1 right fire
        int leftRange=(i-1>=0) ? max(roboDis[i].second-roboDis[i].first, roboDis[i-1].second+1) : roboDis[i].second-roboDis[i].first;
        //if prevrobo fire R and curr robo fire left then walls may be counted repeated
        if(prevDir==1){ //to resolve repeated walls count
            leftRange=max(leftRange, roboDis[i-1].second+roboDis[i-1].first+1);
        }
        int leftWallCount=countWall(leftRange, roboDis[i].second, walls)+solve(i+1, 0, roboDis, walls);

        int rightRange=i+1<n ? min(roboDis[i].second+roboDis[i].first, roboDis[i+1].second-1) : roboDis[i].second+roboDis[i].first;

        int rightWallCount=countWall(roboDis[i].second, rightRange, walls)+solve(i+1, 1, roboDis, walls);

        return dp[i][prevDir]=max(leftWallCount, rightWallCount);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int roboLen=robots.size();
        vector<pair<int, int>> roboDis;
        for(int i=0; i<roboLen; i++){
            roboDis.push_back({distance[i], robots[i]});
        }
        sort(roboDis.begin(), roboDis.end(), comparator);
        sort(walls.begin(), walls.end());
        dp.assign(roboLen+1, vector<int>(2, -1));

        return solve(0, 0, roboDis, walls);
    }
};