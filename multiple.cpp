#include<bits/stdc++.h>
using namespace std;
vector<int>vt;
map<int, long long>mp;
bool check(vector<int>vt){
    bool khong=false, tam=false;
    for(int i=0;i<vt.size();++i){
        if(vt[i]==0) khong =true;
        else tam=true;
    }
    return (tam && khong);
}
long long tong(vector<int>vt){
    long long number=0;
    for(int i=0;i<vt.size();++i){
        number = number*10 + vt[i];
    }
    return number;
}
void sinh(bool& stop){
    int i = vt.size()-1;
    while(vt[i]==8){
        --i;
        if(i==-1) break;
    }
    if(i==-1) stop = true;
    else{
        vt[i] = 8;
        for(int j=i+1; j<vt.size();++j){
            vt[j]=0;
        }
    }
}
void khoitao(){
    for(int i=1;i<=19;++i){
        vt.resize(i);
        vt[0] = 8;
        for(int j=1;j<vt.size();++j){
            vt[j] = 0;
        }
        bool stop = false;
        while(!stop){
            if(check(vt)){
                long long tongSo = tong(vt);
                for(long long k=1;k<=min((long long)300, tongSo);++k){
                    if(tongSo%k==0 && mp[k]==0){
                        mp[k] = tongSo;
                    }
                }
            }
            sinh(stop);
        }
    }
}
int main(){
    int t; cin>>t;
    khoitao();
    while(t--){
        int n;cin>>n;
        cout<<mp[n]<<"\n";
    }
    return 0;
}