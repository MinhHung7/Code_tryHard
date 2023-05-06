#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>vt;

int main(){
    cin>>n>>k;
    map<int, int>mp;
    for(int i=0;i<k;++i){
        int x; cin>>x;
        ++mp[x];
        vt.push_back(x);
    }
    int i=k-1;
    while(vt[i]==n-k+i+1){
        --i;
        if(i==-1){
            cout<<k;
            return 0;
        }
    }
    int ans=0;
    ++vt[i];
    ++mp[vt[i]];
    if(mp[vt[i]]==1) ++ans;
    for(int j=i+1; j<k;++j){
        vt[j] = vt[j-1]+1;
        ++mp[vt[j]];
        if(mp[vt[j]]==1) ++ans;
    }
    cout<<ans;
    return 0;
}
// 1 2 3 4 5 6 7 8
// 2 3 7 8
// 2 4 5 6