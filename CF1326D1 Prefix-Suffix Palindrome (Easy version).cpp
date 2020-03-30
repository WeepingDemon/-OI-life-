#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

ll T,n,l,r,jl[55555],jr[55555],al,ar;
string str;
char c[55555];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> T;
    while(T--){
        for(register int i = 0;i <= 5000;++i){
            jl[i] = jr[i] = 0;
            c[i] = ' ';
        }
        al = ar = l = r = 0;
        cin >> str;
        n = str.length();
        for(register int i = 1;i <= n;++i){
            c[i] = str[i-1];
        }
        l = 1,r = n;

        while(c[l] == c[r] && l < r) ++l,--r;

        if(l >= r){
            cout << str << "\n";
            continue;
        }
        
        for(register int i = r;i >= l;--i) if(c[l] == c[i]) jl[++jl[0]] = i;
        for(register int i = l;i <= r;++i) if(c[i] == c[r]) jr[++jr[0]] = i;
        
          //gcout << jl[0] << " " << jr[0] << "\n";

        for(register int i = 1;i < jl[0];++i){
            int L = l, R = jl[i];
            while(c[L] == c[R] && L < R) ++L,--R;
            if(L >= R){
                al = jl[i];
                break;
            }
        }

        for(register int i = 1;i < jr[0];++i){
            int L = jr[i], R = r;
            while(c[L] == c[R] && L < R) ++L,--R;
            if(L >= R){
                ar = jr[i];
                break;
            }
        }


        if(al == 0 && ar == 0){   
            for(register int i = 1;i < l+1;++i) cout << c[i];
            for(register int i = r+1;i <= n;++i) cout << c[i];
            cout << "\n";
            continue;
        }else{
            if(al == 0) r = ar-1;
            else if(ar == 0) l = al+1;
            else if((al-l) < (r-ar)){
                r = ar-1; 
            } else l = al+1;
            for(register int i = 1;i < l;++i) cout << c[i];
            for(register int i = r+1;i <= n;++i) cout << c[i];
            cout << "\n";
            continue;
        }

    }
    

    return 0;
}

/*

abcdfdcecba

*/
