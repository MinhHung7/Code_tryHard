#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>vt;
int a[26];
bool stop = false;
vector<vector<int>>ansV;
int ans=0;
void sinh(){
    int i=k-1;
    while(vt[i] == n){
        --i;
        if(i==-1) break;
    }
    if(i==-1){
        stop = true;
    }
    else{
        ++vt[i];
        for(int j = i+1; j<k;++j){
            vt[j] = 1;
        }
    }
}
int main(){
    char c;
    cin>>c>>k;

    n = c-'A'+1;
    for(int i=0;i<k;++i){
        vt.push_back(1);
    }
    while(!stop){
        for(int i=0;i<k;++i){
            cout<<(char)(vt[i]-1+'A');
        }
        cout<<"\n";
        sinh();
    }
    return 0;
}

