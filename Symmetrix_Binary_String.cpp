#include<bits/stdc++.h>
using namespace std;
vector<char>vt;
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
void sinh(){
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
    int n; cin>>n;
    for(int i=0;i<n;++i){
        vt.push_back('0');
    }
    while(!flag){
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