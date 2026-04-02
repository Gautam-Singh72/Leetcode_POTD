#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
//T.C->O(N*longn) s.c-O(N) stack space
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        unordered_map<int, int> position;
        //maping robot to their position
        for(int i=0; i<n; i++){
            position[positions[i]]=i;
        }
        //sort the positions to process robot which comes first on number line
        sort(positions.begin(), positions.end());
        stack<int> st;
        for(int i=0; i<n; i++){
            int pos=positions[i];
            int robot=position[pos];
            char direc=directions[robot];
            bool flag=true;
            while(!st.empty() && directions[st.top()]=='R' && direc=='L'){
                int h1=healths[st.top()];
                int h2=healths[robot];
                if(h1<h2){
                    healths[st.top()]=-1;
                    st.pop();
                    healths[robot]-=1;
                }else if(h1>h2){
                    healths[st.top()]-=1;
                    healths[robot]=-1;
                    flag=false;
                    break;
                }else{
                    healths[st.top()]=-1;
                    healths[robot]=-1;
                    st.pop();
                    flag=false;
                    break;
                }
            }
            if(flag)
                st.push(robot);
        }
        vector<int> ans; // to find the health of robot who survives in edn 
        for(int i=0; i<n; i++){
            if(healths[i]!=-1){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};