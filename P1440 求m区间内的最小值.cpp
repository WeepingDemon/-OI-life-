#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int q[2000001][2] , n , m , head = 0 , tail = 0 , x;

int main() {

	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
    cin >> n >> m;
    cout << "0\n";
    cin >> q[tail++][0];
    for(register int i = 1;i < n;i++){
        if(i - q[head][1] > m) head++;
        cout << q[head][0] << "\n";
        cin >> x;
        while(tail > head && x < q[tail - 1][0]) tail--;
        q[tail][0] = x , q[tail++][1] = i;
    }
    return 0;
}
