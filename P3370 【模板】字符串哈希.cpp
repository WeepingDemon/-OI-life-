#include<iostream>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
long long h[1000010],N,len,hash,cnt,ans;
long long base = 150;
std::string str;

int main(){
	cin >> N;
	for(int i = 1;i <= N;i++){
		cin >> str;
		hash = 0;
			len = str.length();
		for(int i = 0;i < len;i++){
			hash += str[i] + hash * base;
			hash %= 212370440130137957ll;
			hash += 233317;
		}
		h[++cnt] = hash;
		//cout << hash << std::endl;
	}
	//cout << h[0] << " " << h[1] << " " << h[2] << " " << h[cnt] << std::endl;
	std::sort(h,h+cnt+1);
	//cout << h[0] << " " << h[1] << " " << h[2] << " " << h[cnt] << std::endl;
	for(int i = 1;i <= cnt;i++){
		if(h[i] != h[i+1]) ans++;
	}
	cout << ans;
}
