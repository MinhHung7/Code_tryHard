#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vt(25, 0);
bool stop=false;
void sinh(){
    if(vt[1]==1){
        stop = true;
        return ;
    }
    else{
        if(vt[2]==1){
            --vt[1];
            int sum = n-vt[1];
            int j=2;
            while(sum>0){
                vt[j] = min(vt[j-1], sum);
                sum-=vt[j];
                ++j;
            }
            while(j<=n){
                vt[j] = 0;
                ++j;
            }
        }
        else{
            int i=n;
            while(vt[i]==0 || vt[i]==1){
                --i;
            }
            if(vt[i]-1 >= vt[i+1]+1){
                --vt[i];
                ++vt[i+1];
            }
            else{
                --vt[i];
                for(int j=i+1; j<=n;++j){
                    if(vt[j]==0){
                        vt[j]=1;
                        break;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n;
    vt[1] = n;
    for(int i=2;i<=21;++i){
        vt[i] = 0;
    }
    vector<vector<int>>ansV;
    int ans=0;
    while(!stop){
        ansV.push_back(vt);
        ++ans;
        sinh();
    }
    cout<<ans<<"\n";
    for(int i=0; i<ansV.size();++i){
        int j;
        for(j=1; j<ansV[i].size()-1;++j){
            if(ansV[i][j+1]==0){
                break;
            }
            cout<<ansV[i][j]<<"+";
        }
        cout<<ansV[i][j]<<"\n";
    }
    // for(int i=1;i<ansV[1].size();++i){
    //     cout<<ansV[1][i]<<" ";
    // }
    return 0;
}