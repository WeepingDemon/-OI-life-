/*题解：https://www.luogu.org/blog/Mifer/p2602-zjoi2010-shuo-zi-ji-shuo*/
#include<iostream>
using std::cin;using std::cout;using std::endl;
long long a,b;//a,b为左右区间
long long ten[20],f[20];//ten[i]=10^i;ten[i]表示i-1位数第i-1位每个数字出现几次
//f[i]表示i位数的每一个数字总共出现f[i]次
long long cnta[20],cntb[20];

void work(long long x,long long *cnt){
    long long num[20] = {0};//num[i]中i>=1，i表示位数，用来存x
    num[0] = 0;//用来计数(长度length)
    while(x){//将数字x存入数组
        num[++num[0]] = x % 10;
        x /= 10;
    }
    for(int i = num[0];i >= 1;i--){//从大位往小位处理
    //由于i位的数字不见得一样，所以需要通过i位数字与i-1位的出现个数相乘
    //得到，再加上该位置该数字出现的个数，即次位数字个次位数出现的个数，
    //同时对于每一位的数字之前的数字还有一部分零散的num2需要加
        for(int j = 0;j <= 9;j++)
         cnt[j] += f[i-1] * num[i];
        for(int j = 0;j < num[i];j++)
         cnt[j] += ten[i-1];
    //所谓num2，其实是对于形如ABC的数(B为当前处理数字，A为B之前的数字串，C为B之
    //后的数字串)，而num2就是C，所以对num2的操作就是将存入数组的C提取出来，变整型
        long long num2 = 0;
        for(int j = i-1;j >= 1;j--)
         num2 = num2*10 + num[j];
        cnt[num[i]] += num2+1;
    //减去每一个零导数字，为当前位数最高位为0的数字的个数，因此减去ten[i-1]
        cnt[0] -= ten[i-1];
    }
   
}

int main(){
    cin >> a >> b;
    ten[0]=1;
    for(int i = 1;i <= 13;i++){
        f[i] = f[i-1]*10 + ten[i-1];//每一个数字出现的次数等于10倍上一层加上这一位在总数中出现的次数
        ten[i] = 10*ten[i-1];//ten[i]=10^i的计算
    }
    work(a-1,cnta);//求得a左侧的数中i出现多少次[1,a-1]
    work(b,cntb);//求得b左侧的数中i出现了多少次[a,b]
    for(int i = 0;i <= 9;i++)
        cout << cntb[i] - cnta[i] << " ";//将结果做差得到区间内的数中i出现了多少次
    return 0;
}
