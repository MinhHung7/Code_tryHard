#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vt;
bool stop = false;
bool check(vector<int>vt){
    for(int i=0;i<vt.size()-1;++i){
        if(vt[i] == vt[i+1]-1 || vt[i] == vt[i+1]+1) return false;
    }
    return true;
}
void sinh(){
    int i=vt.size()-1;
    while(vt[i] < vt[i-1]){
        --i;
        if(i==0) break;
    }
    if(i==0) stop = true;
    else{
        sort(vt.begin()+i, vt.end());
        for(int j=i;j<vt.size();++j){
            if(vt[j] > vt[i-1]){
                swap(vt[j], vt[i-1]);
                break;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        vt.push_back(i);
    }
    while(!stop){
        if(check(vt)){
            for(int i=0;i<vt.size();++i){
                cout<<vt[i];
            }
            cout<<"\n";
        }
        sinh();
    }
    return 0;
}