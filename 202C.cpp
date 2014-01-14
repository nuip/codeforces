#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;

int a[10009];


int main(){
  ll i,j,tmp,sum=0,ans=0,n,maxa=0;
  scanf("%I64d",&n);
  
  for(i=0;i<n;i++){
    scanf("%I64d",&tmp);
    sum+=tmp;
    maxa=max(tmp,maxa);
  }
  ans=sum/n-10;
  while(ans*n-sum<n)
    ans++;

  cout<<max(ans,maxa)<<endl;
  return 0;
}