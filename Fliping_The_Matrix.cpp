#include<bits/stdc++.h>
using namespace std;
int maximum_Upper_left_Quandrant(vector<vector<int, int>>matrix){
    int n = matrix.size()/2;
    int sum=0;
    for(int i=0; i<n/2;++i){
        for(int j=0; j<n/2;++j){
            int r1 = i;
            int r2 = n-i+1;
            int c1 = j;
            int c2 = n-j+1;
            sum+=max(max(matrix[r1][c1], matrix[r1][c2]),max(matrix[r2][c1], matrix[r2][c2]));
        }
    }
    return sum;
}
int main(){
    vector<int>ans;
    cout<<ans.size();
    return 0;
}