#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;
using std::deque;

int mod = 1 << 30;
ll x,y,z;
int pos = 0,b1,b2,b3,m,p[100005],l[100005],r[100005];

deque<int> q;
int n,type,a[40000005],pre[40000005];
ll sum[40000005];

void output(__int128 x){
    if(x / 10) output(x/10);
    printf("%d",(int)(x % 10));
}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> type;
    if(!type){
        rep(i,1,n) cin >> a[i];
    } else {
        cin >> x >> y >> z >> b1 >> b2 >> m;
        for(int i = 1; i <= m; i++) scanf("%d%d%d", &p[i], &l[i], &r[i]);
        for(int i = 1, pos = 1; i <= n; i++) {
            if(i > p[pos]) pos++;
            if(i == 1) a[i] = (b1 % (r[pos] - l[pos] + 1)) + l[pos];
            else if(i == 2) a[i] = (b2 % (r[pos] - l[pos] + 1)) + l[pos];
            else {
                b3 = (x * b2 + y * b1 + z) % mod;
                b1 = b2; b2 = b3;
                a[i] = (b3 % (r[pos] - l[pos] + 1)) + l[pos];
            }
        }
    }
    rep(i,1,n) sum[i] = sum[i-1] + a[i];
    q.push_back(0);

    rep(i,1,n){
        while(q.size() >= 2){
            int x,y;
            x = q.front() , q.pop_front();
            y = q.front();
            if(sum[y] - sum[ pre[y] ] > sum[i] - sum[y]){
                q.push_front(x);
                break;
            }
        }
        pre[i] = q.front();
        while(q.size() && (2 * sum[q.back()] - sum[ pre[q.back()] ] >= 2 * sum[i] - sum[ pre[i] ]) ) q.pop_back();
        q.push_back(i);
    }

    __int128 ans = 0;
    for(int i = n;i != 0;i = pre[i]) ans += (__int128)(sum[i] - sum[ pre[i] ]) * (sum[i] - sum[ pre[i] ])   ;
    output(ans);
    cout << "\n";
    return 0;
}
