#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vt(25, 0);
bool stop=false;
void sinh(){
    int i=24;
    while(vt[i]==1 || vt[i]==0){
        --i;
        if(i==0){
            break;
        }
    }
    if(i==0){
        stop = true;
    }
    else{
        --vt[i];
        int sum=0;
        for(int j=1; j<=i;++j){
            sum+=vt[j];
        }
        sum=n-sum;
        int j=i+1;
        while(sum){
            vt[j] = min(sum, vt[j-1]);
            sum-=vt[j];
            ++j;
        }
        while(j<vt.size()){
            vt[j] = 0;
            ++j;
        }
    }

}
int main(){
    cin>>n;
    vt[1] = n;
    for(int i=2;i<=24;++i){
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