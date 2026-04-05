#include<iostream>
using namespace std;
class Solution {
public:
    //T.C->O(N) AND S.C->O(1)
    bool judgeCircle(string moves) {
        int leftMove=0;
        int upMove=0;
        for(char ch : moves){
            if(ch=='L') leftMove++;
            else if(ch=='R')    leftMove--;
            else if(ch=='U')    upMove++;
            else    upMove--;
        }
        return leftMove==0 && upMove==0;
    }
};