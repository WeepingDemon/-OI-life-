#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

        int n,flag[95001],k[901];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(flag,0,sizeof(flag));
        memset(k,0,sizeof(k));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>k[i];
            flag[k[i]]=2;
        }
        sort(k+1,k+n+1);
        for(int i=1;i<=k[n];i++){
            //cout<<"flag["<<i<<"]="<<flag[i]<<endl;
            if(flag[i]!=0){
                for(int j=1;j<=n;j++){
                    //cout<<"用"<<i<<"和"<<k[j]<<"凑"<<endl; 
                    if (i+flag[j]<=k[n]){
                        flag[i+k[j]]=1;
                        //cout<<"flag["<<i+k[j]<<"]become"<<1<<endl;
                    }
                    else break; 
                }
            }
        }
        int ans=0;
        for(int i=1;i<=25001;i++){
            if(flag[i]==2){
            ans++;
            //cout<<"答案中包含"<<i<<endl;
            }
        }
        cout<<ans<<endl;
    }
}
