#include<bits/stdc++.h>
using namespace std;
bool check(vector<char>vt){
    for(int i=0; i<vt.size()/2;++i){
        if(vt[i]!= vt[vt.size()-i-1]){
            return false;
        }
    }
    return true;
}     // 0 1 2 3 
      // 1 2 3 4
bool flag = false;
void sinh(vector<char>& vt){
    int i = vt.size()-1;
    while(vt[i]=='1'){
        --i;
        if(i==-1) break;
    }
    if(i==-1) {
        flag = true;
    }
    else{
        vt[i] = '1';
        for(int j=i+1; j<vt.size();++j){
            vt[j] = '0';
        }
    }
}
int main(){
    int m; cin>>m;
    vector<vector<char>>ans;
    for(int n=2; n<=m; n+=2){
        flag = false;
        vector<char>vt;
        for(int i=0;i<n;++i){
            vt.push_back('0');
        }
        while(!flag){
            if(check(vt)){
                ans.push_back(vt);
            }
            sinh(vt);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
