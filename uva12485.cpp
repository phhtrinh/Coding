#include<bits/stdc++.h>
using namespace std;

int a[10001];
int main() {
    //freopen("input.txt","r",stdin);
    int n, res, avg;
    while(cin>>n) {
        avg = res = 0;
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
            avg += a[i];
        }
        if(avg%n==0) {
            avg/=n;
            for(int i = 0; i < n; ++i) {
                if(a[i]>=avg) break;
                res+=avg - a[i];
            }
        }
        else res = -2;
        cout<<res+1<<endl;
    }
}

