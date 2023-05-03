#include<bits/stdc++.h>
using namespace std;
string s;
bool stop = false;
vector<int>vt;
void sinh(){
    int x = 0;
    int i =  vt.size()-1;
    while(vt[i] <= vt[i-1]){
        --i;
        if(i==0) break;
    }
    if(i==0){
        stop = true;
    }
    else{
        sort(vt.begin()+i, vt.end());
        for(int j=i; j<vt.size();++j){
            if(vt[j] > vt[i-1]){
                swap(vt[j], vt[i-1]);
                break;
            }
        }
    }
}
int main(){
    int m; cin>>m;
    map<int, int>mp;
    vector<int>arr;
    for(int i=0; i<m;++i){
        int x; cin>>x;
        ++mp[x];
        if(mp[x]==1){
            arr.push_back(x);
        }
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size();++i){
        vt.push_back(arr[i]);
    }
    vector<vector<int>>ans;
    while(!stop){
        ans.push_back(vt);
        sinh();
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

