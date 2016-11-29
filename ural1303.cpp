#include<bits/stdc++.h>
using namespace std;

pair<int, int> p[111111], q[111111];

int main() {
//    freopen("input.txt","r",stdin);
    int m, a, b, n = 0;
    cin>>m;
    while(cin>>a>>b, a!=0 || b!=0){
        if(b > 0 && a <= m){
            p[n] = make_pair(a, b);
            ++n;
        }
    }

    bool ok = 1;

    sort(p,p+n);
    if(n==0 || p[0].first > 0) ok = 0;

    int last = 0, cnt = 0;
    int i=0;
    while(i<n && last<m && ok){
        int u = -1;
        while(i<n && p[i].first <= last){
            if(u == -1 || p[u].second < p[i].second) u = i;
            ++i;
        }
        if(u == -1){
            ok = 0;
            break;
        }
        q[cnt++] = p[u];
        last = p[u].second;
    }

    if(cnt==0 || q[cnt-1].second < m) ok = 0;
    if(!ok) cout<<"No solution\n";
    else {
        cout<<cnt<<endl;
        for(int i = 0; i < cnt; ++i)
            cout<<q[i].first<<' '<<q[i].second<<endl;
    }
}


