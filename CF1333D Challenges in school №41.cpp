#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int n,k,sum,tt;
char ch[3333];
bool flag;

std::vector< std::vector<int> > v;
std::vector<int> tmp;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);

    cin >> n >> k;
    rep(i,1,n) cin >> ch[i];

    tmp.push_back(0) ,  v.push_back(tmp);

    while(1){
        tmp.clear();
        tmp.push_back(0);
        rep(i,2,n){
            if(ch[i-1] == 'R' && ch[i] == 'L'){
                ch[i-1] = 'L' , ch[i] = 'R' , ++i;
                tmp.push_back(i-2);
                ++tmp[0] , ++sum;
            }
        }
        if(tmp[0] == 0) break;
        v.push_back(tmp);
        ++v[0][0];
    }

    if(sum < k || v[0][0] > k){cout << "-1\n";return 0;}

    rep(i,1,v[0][0]){
        //cout << i << " ::  sum = " << sum << " k = " << k << "\n";
        if(sum == k){
            rep(j,1,v[i][0]) cout << 1 << " " << v[i][j] << "\n";
            sum -= v[i][0] , k -= v[i][0];
        } else {
            if(sum - v[i][0] >= k - 1){
                rep(j,0,v[i][0]) cout << v[i][j] << " ";
                cout << "\n";
                sum -= v[i][0] , --k;
            } else {
                tt = sum - k + 1;
                cout << tt << " ";
                rep(j,1,tt) cout << v[i][j] << " ";
                cout << "\n";
                rep(j,tt + 1,v[i][0]) cout << 1 << " " << v[i][j] << "\n";
                sum -= v[i][0] , k = sum;
            }
        }
    }

    return 0;
}
