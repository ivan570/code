#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0;i<n;i++)
using namespace std;

int main() {
    int n,c=0,ans=0,t=0,k;cin>>n;
    vector<int> a(n);
    forn(i,n){
        cin>>a[i];
        if(a[i]%2!=0){
            c++;
            if(t==0){
                k=i;t=1;
            }
            else{
                ans += 2*(i-k);
                t=0;
            }
        }
    }
    if(c%2!=0){
        cout<<"NO";
    }
    else{
        cout<<ans;
    }
    return 0;
}
