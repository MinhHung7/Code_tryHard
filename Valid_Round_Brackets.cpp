#include<bits/stdc++.h>
using namespace std;
vector<char>vt;
int n;
bool stop = false;
bool check(vector<char>vt){
    stack<char>st;
    for(int i=0 ; i<vt.size();++i){
        if(vt[i]=='('){
            st.push(vt[i]);
        }
        else{
            if(st.size()){
                st.pop();
            }
            else return false;
        }
    }
    if(st.size()) return false;
    return true;
}
void sinh(){
    int i = vt.size()-1;
    while(vt[i]==')'){
        --i;
        if(i==-1) break;
    }
    if(i==-1){
        stop = true;
    }
    else{
        vt[i] = ')';
        for(int j=i+1; j<vt.size();++j){
            vt[j] = '(';
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n;++i){
        vt.push_back('(');
    }
    bool ok = false;
    while(!stop){
        if(check(vt)){
            ok  = true;
            for(int i=0; i<vt.size();++i){
                cout<<vt[i];
            }
            cout<<"\n";
        }
        sinh();
    }
    if(!ok){
        cout<<"NOT EXIST";
    }
    return 0;
}