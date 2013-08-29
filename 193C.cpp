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



int n,p,k;
ll x[100003],y[100003],miny;
vector<ll> sorty;
multimap<ll,int,greater<ll> > sortx;
multimap<ll,int,greater<ll> >::iterator it,iti;

int main(){
  scanf("%d %d %d",&n,&p,&k);
  int i,j,outCnt=0;
  for(i=0;i<n;i++){
    scanf("%I64d %I64d",x+i,y+i);
    sorty.pb(y[i]);
    sortx.insert(make_pair(x[i],i));
  }
  sort(sorty.begin(),sorty.end());
  if(p==k){
    miny=0;
  }else{
    miny=sorty[p-k-1];
  }
  
  ll maxy=0;

  for(it=sortx.begin();it!=sortx.end();it++){
//      cout<<y[it->Y]<<endl;
    if(y[it->Y]>miny){
      outCnt++;
      printf("%d%c",it->Y+1,(outCnt==p)?'\n':' ');
      if(maxy<y[it->Y])maxy=y[it->Y];
      if(outCnt>=k)break;
    }
  }//cout<<"("<<outCnt<<endl;
  for(i=n-1;i>=0&&outCnt<p;i--){
    if(maxy>sorty[i]){
      outCnt++;
      printf("%d%c",i+1,(outCnt==p)?'\n':' ');
      if(outCnt>=p)break;
    }
  }
  return 0;
}