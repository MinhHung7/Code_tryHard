#include<bits/stdc++.h>
using namespace std;
vector<char>kiTu;
vector<int>so;
vector<string>ansKiTu;
vector<string>ansSo;
int n;
bool stop = false;
void sinh1(){
    int i =  kiTu.size()-1;
    while(kiTu[i] < kiTu[i-1] ){
        --i;
        if(i==0){
            break;
        }
    }
    if(i==0){
        stop = true;
    }
    else{
        sort(kiTu.begin()+i, kiTu.end());
        for(int j=i; j<kiTu.size();++j){
            if(kiTu[j] > kiTu[i-1]){
                swap(kiTu[j],kiTu[i-1]);
                break;
            }
        }
    }
}
void sinh2(){
    int i =  so.size()-1;
    while(so[i]==n){
        --i;
        if(i==-1){
            break;
        }
    }
    if(i==-1){
        stop = true;
    }
    else{
        ++so[i];
        for(int j=i+1; j<so.size();++j){
            so[j] = 1;
        }
    }
}
int main(){
    cin>>n;
    string xau="";
    for(int i=0;i<n;++i){
        kiTu.push_back((char)(i+'A'));
    }
    for(int i=0;i<n;++i){
        so.push_back(1);
    }
    while(!stop){
        for(int i=0; i<kiTu.size();++i){
            xau+=kiTu[i];
        }
        ansKiTu.push_back(xau);
        xau="";
        sinh1();
    }
    stop = false;
    while(!stop){
        for(int i=0; i<so.size();++i){
            xau+=to_string(so[i]);
        }
        ansSo.push_back(xau);
        xau="";
        sinh2();
    }
    
    for(int i=0;i<ansKiTu.size();++i){
        for(int j=0;j<ansSo.size();++j){
            cout<<ansKiTu[i]<<ansSo[j]<<"\n";
        }
    }
    return 0;
}

// 111
// 112
// 113
// 121
// 122
// 123
// 131
// 132
// 133
// 211
// 212
// 213
// 221
// 222
// 223
// 231
// 232
// 233



// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1