#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;

char s[int(1e6+10)];
int n,p,k;

void update(int& ans, int a, int b, int c, int d){
    ans = std::max(b-a-1, ans);
    ans = std::max(c-b-1, ans);
    ans = std::max(d-c-1, ans);
}

void solve(){
    cin >> n >> s;
    p = k = -1;
    rep(i, 0, n-1) if(s[i] == 'p') { p = i; break; }
    per(i, n-1, 0) if(s[i] == 'k') { k = i; break; }
    if (p == -1 || k == -1 || p >= k) { cout << "-1" << endl; return; }
    int ei = 0, flag = 0;
    rep(i, p+1, k-1){
        if (s[i] == 'i') ei = 1;
        if (s[i] == 'n' && ei) {flag = 1; break;}
    }
    if (!flag) { cout << "-1" << endl; return; }

    int ans = 0, p4, p3, p2, p1;
    rep(i, p+1, k-1) if(s[i] == 'i'){ p1=i; break; }
    rep(i, p1+1, k-1) if(s[i] == 'n'){ p2=i; break; }
    update(ans,p,p1,p2,k);
    per(i, k-1, p1+1) if(s[i] == 'n'){ p2=i; break; }
    update(ans,p,p1,p2,k);
    per(i, p2-1, p+1) if(s[i] == 'i'){ p1=i; break; }
    update(ans,p,p1,p2,k);
    cout << ans << endl;
    return;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
