#include<bits/stdc++.h>
using namespace std;
int n; 
bool stop = false;
vector<int>vt;
void sinh(){
    int i=n-1;
    while(vt[i]==8){
        --i;
        if(i==-1) break;
    }
    if(i==-1){
        stop = true;
    }
    else{
        vt[i]=8;
        for(int j=i+1; j<n;++j){
            vt[j] = 6;
        }
    }
}
bool check(vector<int>vt){
    if(vt[0]!=8 || vt[n-1]!=6) return false;
    else{
        int i=0;
        while(i<n){
            if(vt[i]==6){
                if(i+3<n && vt[i+1]==6 && vt[i+2]==6 && vt[i+3]==6) return false;
                if(i+3>=n) break;
                else{
                    if(vt[i+1]==8) i=i+1;
                    else if(vt[i+2]==8) i=i+2;
                    else i=i+3;
                }
            }
            else ++i;
        }
        int j=0;
        while(j<n){
            if(vt[j]==8){
                if(j+1 < n && vt[j+1]==8){
                    return false;
                }
                if(j+1 >= n) break;
                else ++j;
            }
            else ++j;
        }
        return true;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        vt.push_back(6);
    }
    while(!stop){
        if(check(vt)){
            for(int i=0;i<n;++i){
                cout<<vt[i];
            }
            cout<<"\n";
        }
        sinh();
    }
    return 0;
}