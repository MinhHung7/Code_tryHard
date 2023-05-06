#include<bits/stdc++.h>
using namespace std;
char c;
bool stop = false;
vector<char>vt;
bool check(vector<char>vt){
    bool a = false;
    bool e = false;
    for(int i=0;i<vt.size();++i){
        if(vt[i]=='A') a=true;
        if(vt[i]=='E') e=true;
    }
    if(!a && !e) return false;
    else if(a && !e){
        if(vt[0]!='A' && vt[vt.size()-1]!='A') return false;
        return true;
    }
    else if(e && !a){
        if(vt[0]!='E' && vt[vt.size()-1]!='E') return false;
        return true;
    }
    else{
        if(vt[0]=='A' && vt[1]=='E') return true;
        else if(vt[0]=='E' && vt[1]=='A') return true;
        else if(vt[0]=='E' && vt[vt.size()-1]=='A') return true;
        else if(vt[0]=='A' && vt[vt.size()-1] =='E') return true;
        else if(vt[vt.size()-2]=='A' && vt[vt.size()-1]=='E') return true;
        else if(vt[vt.size()-2]=='E' && vt[vt.size()-1]=='A') return true;
        return false;
    }
}
void sinh(){
    int i=vt.size()-1;
    while(vt[i] < vt[i-1]){
        --i;
        if(i==0) break;
    }
    if(i==0) stop=true;
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
    cin>>c;
    for(char i='A'; i<=c;++i){
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