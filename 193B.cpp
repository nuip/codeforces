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
//==============================================================

ll nums[200004],sum;
multimap<ll,int,greater<ll> > sums;
multimap<ll,int,greater<ll> >::iterator it,iti;
int n,k;

int main(){
  int i,j,minInd,maxInd;
  ll maxAbs=0;

  scanf("%d %d",&n,&k);
  for(i=0,sum=0;i<k;i++){
    scanf("%I64d",nums+i);
    sum+=nums[i];
  }
  sums.insert(make_pair(sum,0));
  for(j=1;i<n;i++,j++){
    scanf("%I64d",nums+i);
    sum+=-nums[j-1]+nums[i];
    sums.insert(make_pair(sum,j));
  }

  it=sums.begin();
  minInd=maxInd=(it->Y);
  for(it++;it!=sums.end();it++){
    cout<<minInd<<","<<maxInd<<":"<<it->Y<<endl;
    if(abs((it->Y)-minInd)>=k || abs(maxInd-(it->Y))>=k){
      for(iti=sums.begin();iti!=it;iti++){
        if(abs( (iti->Y)-(it->Y) )>=k){
          maxAbs=iti->X + it->X;
          printf("%d %d\n",min(iti->Y,it->Y)+1,max(iti->Y,it->Y)+1);
          break;
        }
      }
      break;
    }else{
      if(minInd>(it->Y))minInd=it->Y;
      if(maxInd<(it->Y))maxInd=it->Y;
    }
  }
  printf("%I64d\n",maxAbs);
  return 0;
}