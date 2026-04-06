#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second; // Simple hash combination
    }
};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char dir='N';
        unordered_set<pair<int ,int>, pair_hash> s;
        for(vector<int> obstacle: obstacles){
            s.insert({obstacle[0], obstacle[1]});
        }
        int x=0, y=0;
        int maxDis=INT_MIN;
        for(int num: commands){
            if(num<0){
                if(dir=='N')    dir=num==-1 ? 'E' : 'W';
                else if(dir=='E')   dir=num==-1 ? 'S' : 'N';
                else if(dir=='S')   dir=num==-1 ? 'W' : 'E';
                else    dir=num==-1 ? 'N' : 'S';
            }else{
                int k=num;
                while(k--){
                    if(dir=='N')    y++;
                    else if(dir=='E')   x++;
                    else if(dir=='S')   y--;
                    else    x--;
                    if(s.find({x, y})!=s.end()){
                        if(dir=='N')    y--;
                        else if(dir=='E')   x--;
                        else if(dir=='S')   y++;
                        else    x++;
                        break;
                    }
                    maxDis=max(maxDis, x*x+y*y);
                }
                maxDis=max(maxDis, x*x+y*y); 
            }
        }
        return maxDis;
    }
};