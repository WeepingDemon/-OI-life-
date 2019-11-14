#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
ll n,N,a[100010],b[100010],p[100010],po[100010][3],node[100010],sum,cnt;

void solve(){
    sum = cnt = N = 0;
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
        node[i] = 0;//初始化
        sum += a[i];
    }
    for(ll i = 1;i <= n;i++){
        cin >> b[i];
        if(b[i] == 0) continue;
        p[++cnt] = b[i];//记录值
        po[cnt][0] = i;//记录位置
        sum -= b[i];
    }
    if(sum != 0){//不是唯一的方案不成立的请情况
        cout << -1 << endl;
        return;
    }
    N = cnt;
    for(ll i = n;i >= 1;i--){
        if(i == n){//边界0处理
            while(a[i] == 0 && i >= 1) i--;
            po[cnt][2] = i;
            }
        p[cnt] -= a[i];
        //cout << "now a[" << i << "] = " << a[i] << " and p[" << cnt << "] = " << p[cnt] << endl; 
        node[i] = cnt;
        if(p[cnt] == 0){
            //cout << "SO jump from " << i << " to ";
            po[cnt--][1] = i--;//记录终点
            while(a[i] == 0 && i >= 0) i--;
            //cout << i << endl;
            po[cnt][2] = i;
            node[i] = cnt;
            i++;
            }
        else if(p[cnt] < 0){
            cout << -1 << endl;
            return;
        }
    }
    /*
    可以知道对应答案po[i][0]的区间为po[i][1]~po[i][2]
    不要忘记减去已经符合的单个区间的操作个数。
    */
//    for(int i = 1;i <= n;i++) cout << node[i] << " ";
//    cout << endl;

   cnt = N;
   for(int i = 1;i <= N;i++){
       if(po[i][1] == po[i][2] && po[i][1] == po[i][0]) cnt--;
        // cout << po[i][1] << " " << po[i][2] << endl;
   }
   cout << cnt << endl;
}

int main(){
    // freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
