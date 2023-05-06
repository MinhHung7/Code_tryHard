#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>>vt;
int n, l;
int maxV=0;
void eat(map<int, int>visited, int i, int w, int ansV){
    visited[i]=1;
    ansV+=vt[i].second;
    w-=vt[i].first;
    maxV = max(maxV, ansV);
    for(int i=0;i<vt.size();++i){
        if(w-vt[i].first >= 0 && visited[i] == 0){
            eat(visited, i, w, ansV);
        }
    }
    visited[i]=0;
}
int main(){
    cin>>n>>l;
    vector<int>w;
    vector<int>v;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        w.push_back(x);
    }
    for(int i=0;i<n;++i){
        int x; cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;++i){
        vt.push_back({w[i], v[i]});
    }
    map<int,int>visited;
    int ansV = 0;
    for(int i=0;i<vt.size();++i){
        if(visited[i]==0) eat(visited, i, l, ansV);
    }
    cout<<maxV;
    return 0;
}