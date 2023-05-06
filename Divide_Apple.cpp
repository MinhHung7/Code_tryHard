#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>vt;
    long long sumleft=0;
    long long sumright=0;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        vt.push_back(x);
        sumright+=x;
    }
    int x = 0 ;
    sort(vt.begin(), vt.end());
    while(x<vt.size() && ((sumright-vt[x] - sumleft-vt[x] < sumright - sumleft) || sumleft==0)){
        sumright-=vt[x];
        sumleft+=vt[x];
        ++x;
    }
    cout<<sumright-sumleft;
    return 0;
}

1 2 3 4 7

1       
