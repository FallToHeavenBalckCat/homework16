/*根据给定的数据范围，算法的时间复杂度应该在O(NlogN内)；所以可以枚举一重循环，
另一重循环需要优化；可以采用哈希表的方式，加入第一个枚举的是ai,那么他有Ki位，而
另一冲循环为aj*10^ki，加入由ai,aj组成的数字能够整出K ,那么就是
(aj*10^ki+ai)%m==0;则有aj*10^ki%m=-ai%m;
预处理：枚举每一个ai,同时将ai*10^0到ai*10^10%m的结果分别加入到ki(0,10]的哈希表中，
主函数：枚举每一个aj,同时记录aj的位数len,到对应位数len的哈希表中去查找对应的结果，
如果在对应的表中找到的结果是-ai%m，则将结果+1*/


/*首先要明确各个变量的含义，就是这个题如果要用哈希表来做的话,实际上是开11个哈希表
（11个哈希表表示可能出现的所有位数）；
对于每个哈希表来说，就是我将a[i]乘一个10^k(0<=k<=10),然后将这个结果对m取模之后的
出现次数进行计数，也就是说是将所有对应位数可能的结果都罗列出来，然后再枚举a[i]，
看a[i]对m取的摸和在它对应的len的取模的结果当中和他对m取模的结果相同的次数，放入到
答案中，如果a[i]自己*10^len(len是a[i]的长度)对m的取模的结果是相等的，说明两个集合
中取用了相同的数字，应该把结果-1*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;

int a[N];
typedef long long LL ;
int s[11][N];
int n,m;
LL res;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++){
        LL t=a[i]%m;
        for(int j=0;j<11;j++){
            s[j][t]++;
            t=t*10%m;
        }
    }
    
    for(int i=0;i<n;i++){
        LL t=a[i]%m;
        int len=to_string(a[i]).size();
        res+=s[len][(m-t)%m];
        
        //去重；
        LL r=t;
        while(len--) r=r*10%m;
        if(r==(m-t)%m)  res--;
    }

    cout<<res<<endl;
    return 0;
    
}