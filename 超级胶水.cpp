/*当有2个石头时，ab==ba;
当有3个石头时，ab+c*(a+b)=ab+ac+bc;
3个石头的另一种合并方式：bc+a*(b+c)=ab+bc+ac;
4个石头：ab+(a+b)*c+(a+b+c)*d=ab+ac+ad+bc+bd+cd;
s[0]=a,s[1]=a+b,s[2]=a+b+c,
s[0]*s[1]+s[1]*a[2]+s[2]*a3;因为s[2]-s[1]就是a[2];
所以s[0]*s[1]+s[1]*(s[2]-s[1])+s[2]*(s[3]-s[2]);
所以是s[i]*(s[i+1]-s[i]);
s[n]最坏是10^5个1000相加就是10^8;
int :  -2^31 ---- 2^31-1 2^10~10^3;int 10^9;
res 最大10^16;开long long ;
以此类推，可见无论采用何种方式进行划分；最终的结果是一样的；
计算的时候可以采用前缀和进行计算
假如是10^5个1000相加，就是10^8还要再乘别的数字，需要开long long*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int N=1e5+10;
LL res;
int n;
LL s[N];
int main(){
    scanf("%d",&n);
    s[0]=0;
    
    for(int i=1;i<=n;i++) {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    
    for(int i=1;i<n;i++){
        res+=s[i]*(s[i+1]-s[i]);
    }
    
    cout<<res<<endl;
    return 0;
}