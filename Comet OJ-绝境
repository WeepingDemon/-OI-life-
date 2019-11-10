/*题面：https://cometoj.com/contest/75/problem/A?problem_id=4138*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
// #include<cmath>
#include<queue>
//int[1e7] ll[5*1e6]
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;

ll up[3],down[3],left[3],right[3];//维护最大&次大
ll x1[222220],x2[222220],y1[222220],y2[222220];

//up ~ y1
//down ~ y2
//left ~ x2
//right ~ x1

void update(int i){
    if(up[2] < y1[i]) up[1] = up[2] , up[2] = y1[i];
    else if(up[1] < y1[i]) up[1] = y1[i];
    if(down[2] > y2[i]) down[1] = down[2] , down[2] = y2[i];
    else if(down[1] > y2[i]) down[1] = y2[i];
    if(left[2] > x2[i]) left[1] = left[2] , left[2] = x2[i];
    else if(left[1] > x2[i]) left[1] = x2[i];
    if(right[2] < x1[i]) right[1] = right[2] , right[2] = x1[i];
    else if(right[1] < x1[i]) right[1] = x1[i];
}

ll SoS(int i){
    ll a,b,c,d;//x1,x2,y1,y2
    if(up[2] == y1[i] && i != 0) c = up[1];
    else c = up[2];
    if(down[2] == y2[i] && i != 0) d = down[1];
    else d = down[2];
    if(left[2] == x2[i] && i != 0) b = left[1];
    else b = left[2];
    if(right[2] == x1[i] && i != 0) a = right[1];
    else a = right[2];
    // printf("While Ask for %d ,a = %d,b = %d,c = %d,d = %d \n",i,a,b,c,d);
    if(b-a+1 <= 0 || d-c+1 <= 0) return 0;
    else return (b-a+1) * (d-c+1);
}

int main(){
    up[2] = right[2] = 0 , down[2] = left[2] = 1e9 ;
    // freopen("in.in", "r", stdin);
    ll n,r;
    cin >> n >> r >> r;
    for(int i = 1;i <= n;i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        update(i);
    }
    ll s = SoS(0);ll ans = s;
    // cout << s << endl;
    for(int i = 1;i <= n;i++){
        ans += (SoS(i) - s);
        // cout << SoS(i) << " " << SoS(i)-s << endl;
    }
    cout << ans;
    return 0;
}
