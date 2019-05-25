#include<iostream>
#include<cstring>
using std::cin;using std::cout;using std::memset;
long long pr[46345],cnt,cnt_ans,L,R,po[1000001],pr_ans[1000001];
bool num[1000001],num_ans[1000001];

void prime() {
    memset(num, 1, sizeof(num));//格式化整数表，不过由于这个表只要筛一次，所以如果num[]申请在main函数外的话可以不用写
    num[0] = false;//1既不是合数也不是素数
    for (int i = 2; i <= 46345; i++){//从2开始，1既不是合数也不是素数
        if(num[i]){//判断i是否是素数，如果是合数的话之前会被筛掉
        pr[++cnt] = i;//按照字典序存入素数表
        for(int j = 2;j * i <= 46345;j++) num[i * j] = 0;//利用该素数筛掉之后的合数，线性筛核心
        }
    }    
}

void solve1(){
    cnt_ans = 0;
    memset(pr_ans,0,sizeof(pr_ans));//由于需要多组数据处理所以要memset
    memset(po,0,sizeof(po));
    memset(num_ans,1,sizeof(num_ans));
    for(int i = 1;i <= cnt;i++){//i用来表示字典序素数表的下表
          for(int j = L / pr[i];j * pr[i] <= R;j++){//j用来表示筛的数为pr[i]的j倍
            if(j * pr[i] < L || j == 1) continue;//防爆，j=1时就是素数自己不用筛掉
            num_ans[j * pr[i]] = false;//筛掉符合条件的合数
        }
    }   
        for(int i = L;i <= R;i++){
        if(num_ans[i] == 0) continue;
            pr_ans[++cnt_ans] = i;
     }
}

void solve2(){
    if(cnt_ans < 2){//如果cnt小于2则输出There are no adjacent primes.
            cout << "There are no adjacent primes.\n";
            return;
        }
    for(int i = 1;i < cnt_ans;i++){//将差储存下来
            po[i] = pr_ans[i+1] - pr_ans[i];
        }
    int MAX = cnt_ans,MIN = 0;//最大值和最小值的申请
    po[0] = 2147483647;po[cnt_ans] = 0;//借用位置存储一下
    for(int i = 1;i < cnt_ans;i++){//开始暴力
            MAX = po[MAX] >= po[i] ? MAX : i;
                MIN = po[MIN] <= po[i]? MIN : i;
    }
    cout << pr_ans[MIN] << ',' << pr_ans[MIN + 1] << " are closest, " << pr_ans[MAX] << ',' << pr_ans[MAX + 1] << " are most distant.\n";
}

int main(){
    prime();
    while(cin >> L >> R){
     solve1();
     solve2();

     cout << cnt_ans << " " << std::endl; 
    }
}
