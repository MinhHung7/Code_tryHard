#include<bits/stdc++.h>
using namespace std;
int n;
vector<char>vt;
bool check(vector<char>vt){
    int n = vt.size();
    for(int i=0;i<n/2;++i){
        if(vt[i] != vt[n-i-1]) return false;
    }
    return true;
}
void sinh(){
    int i=vt.size()-1;
    while(vt[i]=='8'){
        --i;
        if(i==-1){
            break;
        }
    }
    if(i==-1){
        vt.resize(vt.size()+2);
        for(int i=0;i<vt.size();++i){
            vt[i] = '6';
        }
    }
    else{
        vt[i] = '8';
        for(int j=i+1; j<vt.size();++j){
            vt[j] = '6';
        }
    }
}
int main(){
    cin>>n;
    vt.push_back('6');
    vt.push_back('6');
    int count=0;
    while(count < n){
        if(check(vt)){
            ++count;
            for(int i=0;i<vt.size();++i){
                cout<<vt[i];
            }
            cout<<" ";
        }
        sinh();
    }
    return 0;
}