#include<bits/stdc++.h>
using namespace std;

vector<int>vt;
bool check(vector<int>vt){
    for(int i=0; i<vt.size()/2;++i){
        if(vt[i]!= vt[vt.size()-i-1]){
            return false;
        }
    }
    return true;
}

void sinh(bool& stop){
    int i = vt.size()-1;
    while(vt[i]==1){
        --i;
        if(i==-1) break;
    }
    if(i==-1) {
        stop = true;
    }
    else{
        vt[i] = 1;
        for(int j=i+1; j<vt.size();++j){
            vt[j] = 0;
        }
    }
}
int main(){
    int m; cin>>m;
    set<vector<int>>ans;
    if(m%2==1){
        --m;
    }
    for(int i=2;i<=m;i+=2){
        bool stop = false;
        vt.resize(i);
        for(int j=0;j<vt.size();++j){
            vt[j] = 0;
        }
        while(!stop){
            if(check(vt)){
                ans.insert(vt);
            }
            sinh(stop);
        }
    }
    for(auto x: ans){
        for(auto y:x){
            cout<<y;
        }
        cout<<"\n";
    }
    return 0;
}
