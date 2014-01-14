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

//==============================================================
//下のコードを消す
//桁あふれチェック
//========================================================
ll h[12345],p[12345],n,m;

bool canVisit(ll num){
  int i,j,visited=0;
  ll l,r;
  for(j=i=0;i<n;i++){
    r=l=p[j];
    while(r-l + min(labs(r-h[i]) , labs(l-h[i]))<=num){
      j++;
      visited++;
      if(j>=m)
        return 1;
      r=p[j];
    }
  }
  return visited==m;
}

int main(){
  int i,j;
  scanf("%I64d %I64d",&n,&m);
  for(i=0;i<n;i++)
    scanf("%I64d",h+i);
  for(i=0;i<m;i++)
    scanf("%I64d",p+i);

  ll l=-1,r=100000000000,c;
  while(r-l>1){
    //cout<<l<<"\t"<<r<<endl;
    c=(r+l)/2;
    if(canVisit(c)){
      r=c;
    }else{
      l=c;
    }
  }
  cout<<r<<endl;
  return 0;
}