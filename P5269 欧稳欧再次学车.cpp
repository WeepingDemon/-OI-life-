/*题目：https://www.luogu.org/problemnew/show/P5269*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::min;

long long T,N,L,R,X,K,x,y,dis,k,d,v,cnt;

int main(){
    cin >> T >> N >> L >> R >> X >> K;
    v = L;d = 1;
    while(T--){
        cin >> x >> y;
        if(x == 0){
            d++,v = L;
            }
        if(x == 1){
            d--,v = R;
        }
        if(d == N+1) return printf("-1"),0;
        if(d == 0) return printf("-1"),0;
        if(y) v = v+X>R?R:v+X;
        if(v == R) cnt++;else cnt = 0;
        dis += d * v;       
        if(cnt == K) break;
    }
    cout << dis;
    return 0;
}
