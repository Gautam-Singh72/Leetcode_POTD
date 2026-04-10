#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minVal=1e9;
        int n=nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it: mp){
            auto &v = it.second;
            if(v.size()<3) continue;
            for(int i=0; i+2<v.size(); i++){
                minVal=min(minVal, 2*(v[i+2]-v[i]));
            }
        }
        return minVal==1e9?-1:minVal;
    }
};