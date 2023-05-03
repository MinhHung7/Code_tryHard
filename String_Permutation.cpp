#include<bits/stdc++.h>
using namespace std;
string s;
bool stop = false;
vector<char>vt;
void sinh(){
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
    string s;
    cin>>s;
    map<char, int>mp;
    for(int i=0;i<s.size();++i){
        ++mp[s[i]];
        if(mp[s[i]]==1) vt.push_back(s[i]);
    }
    sort(vt.begin(), vt.end());
    while(!stop){
        for(int i=0;i<vt.size();++i){
            cout<<vt[i];
        }
        cout<<"\n";
        sinh();
    }
    return 0;
}

// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
