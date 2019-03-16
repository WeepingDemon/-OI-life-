/*题解：https://www.luogu.org/blog/Mifer/post-kmp*/
#include<iostream>
#include<cstring>
char s1[10001],s2[10001];
int i,j,kmp[10001],len1,len2;

int main(){
    std::cin>>s1+1>>s2+1;
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    j=0;
    for(i=2;i<=len2;i++){
        while(j&&s2[i]!=s2[j+1]) j=kmp[j];
        if(s2[i]==s2[j+1]){
            kmp[i]=++j;
        }
    }
    j=0;
    for(i=1;i<=len1;i++){
        while(j&&s1[i]!=s2[j+1]) j=kmp[j];
        if(s2[j+1]==s1[i]) j++;
        //else j=0;
        if(j==len2) std::cout<<i-len2+1<<std::endl;
    }
    for(int i=1;i<=len2;i++){
        std::cout<<kmp[i]<<" ";
    }
}
