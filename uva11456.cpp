#include<bits/stdc++.h>
using namespace std;

int lis[2001], lds[2001], a[2001];
int main() {
    //freopen("input.txt","r",stdin);
    int T, n, res;
    cin>>T;
    while(T--) {
        res = 0;
        memset(lis, 0, sizeof lis);
        memset(lds, 0, sizeof lds);
        cin>>n;
        for(int i = 0; i < n; ++i)
            cin>>a[i];
        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(a[j] < a[i])
                    lis[i] = max(lis[i], lis[j]);
                if(a[j] > a[i])
                    lds[i] = max(lds[i], lds[j]);
            }
            ++lis[i]; ++lds[i];
            res = max(res, lds[i] + lis[i] - 1);
        }
        cout<<res<<endl;
    }
}
