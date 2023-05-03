#include<bits/stdc++.h>
using namespace std;
vector<int>vt (11, 0);
int n;
bool stop = false;
void sinh(){
    int i = 10;
    while(vt[i]==0){
        --i;
    }
    if(vt[i]==n){
        if(i==1){
            stop = true;
        }
        else{
            ++vt[i-1];
            vt[i] = 0;
        }
    }
    else{
        vt[i+1] = vt[i]+1;
    }
}
int main(){
    cin>>n;
    vt[1]=1;
    while(!stop){
        for(int i=1;i<=n;++i){
            if(vt[i]==0){
                break;
            }
            else{
                cout<<vt[i]<<" ";
            }
        }
        sinh();
        cout<<"\n";
    }
    return 0;
}