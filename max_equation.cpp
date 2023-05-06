#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans1 = a+b+c+d;
    int ans2 = a+b+c-d;
    int ans3 = a+b-c+d;
    int ans4 = a+b-c-d;
    int ans5 = a-b+c+d;
    int ans6 = a-b+c-d;
    int ans7 = a-b-c+d;
    int ans8 = a-b-c-d;
    cout<<max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, max(ans6, max(ans7, ans8)))))));
    return 0;
}