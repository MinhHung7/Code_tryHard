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
    for(int i=0;i<s.size();++i){
        vt.push_back(s[i]);
    }
    sinh();
    if(stop==true){
        cout<<"NOT EXIST";
    }
    else{
        for(int i=0; i<vt.size();++i){
            cout<<vt[i];
        }
    }
    return 0;
}

