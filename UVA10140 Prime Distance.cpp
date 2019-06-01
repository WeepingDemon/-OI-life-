#include<iostream>
#include<cstring>
using std::cin;using std::cout;using std::memset;
int pr[46345],cnt,cnt_ans,L,R,pr_ans[1000001];
bool num[1000001];

void prime() {
    memset(num, 1, sizeof(num));
    for (int i = 2; i <= 46345; i++){
        if(num[i]){
       		pr[++cnt] = i;
        for(int j = 2;j <= 46345 / i;j++) num[i * j] = false;
        }
    }    
}

int main(){
    prime();
    while(cin >> L >> R){
    memset(num, 1, sizeof(num));
    if(L==1) num[0] = false;
    cnt_ans = 0;
    for(long long i = 1;i <= cnt;i++){
          for(long long j = L / pr[i];j <= R / pr[i];j++){
            if(j * pr[i] - L < 0 || j <= 1) continue;
            num[j * pr[i] - L] = false;
        }
    }   
        for(long long i = L;i <= R;i++){
        if(num[i - L]) pr_ans[++cnt_ans] = i;
     }
    long long x1,x2,y1,y2,ma=0,mi=2147483647;
    for(int i = 1;i < cnt_ans;i++){
    	long long po = pr_ans[i+1] - pr_ans[i]; 
    	if(po > ma) ma = po , x1 = pr_ans[i] , x2 = pr_ans[i+1];
    	if(po < mi) mi = po , y1 = pr_ans[i] , y2 = pr_ans[i+1];
    }
    if(!ma) cout << "There are no adjacent primes.\n";
    else cout << y1 << ',' << y2 << " are closest, " << x1 << ',' << x2 << " are most distant.\n";
    }
    return 0;
}
