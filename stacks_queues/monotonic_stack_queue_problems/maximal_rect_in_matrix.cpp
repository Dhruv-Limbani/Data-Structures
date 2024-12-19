#include<bits/stdc++.h>
using namespace std;

int largest_rect_in_histogram(vector<int> hist){
    int cols = hist.size();
    int mx = 0;
    vector<int> ls(cols,-1);
    stack<int> st;
    for(int j=0; j<cols; j++){
        while(!st.empty() && hist[st.top()]>hist[j]){
            int h = hist[st.top()], w = j-ls[st.top()]-1;
            mx = max(mx, h*w);
            st.pop();
        }
        if(!st.empty()) ls[j] = st.top();
        st.push(j);
    }
    while(!st.empty()){
        int h = hist[st.top()], w = cols-ls[st.top()]-1;
        mx = max(mx, h*w);
        st.pop();
    }
    return mx;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int mx=0;
    vector<int> hist(cols,0);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            hist[j]=matrix[i][j]=='1'?hist[j]+1:0;
        }
        mx = max(mx, largest_rect_in_histogram(hist));
    } 
    return mx;
}