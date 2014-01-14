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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;
typedef pair<ll,ll> P;


ll stages[112345][3],n,m,ans[112345];
priority_queue<P> ind;

int solve(ll l,int i){
  cout<<i<<",";
  if(i>=m)
    return 0;
  ll j,r;
  if(stages[i][0]==1){
    r=l+1;
    solve(r,i+1);
    while(!ind.empty() && l<ind.top().X){
      if(ind.top().X != r)
        cout<<"!?!?!???"<<endl;
      ans[ind.top().Y]=stages[i][1];
      printf("%d:a[%d] = %d\n",ind.top().Y,ind.top().X,stages[i][1]);
      ind.pop();
    }
  }else{
    r=l+stages[i][1]*stages[i][2];
    cout<<"("<<r<<")";
    solve(r,i+1);
    while(!ind.empty() && l<ind.top().X){
      ind.push(P((ind.top().X-1 -l)%stages[i][1]+1,ind.top().Y));
      printf("%d:a[%d] -> a[%d]\n",ind.top().Y,ind.top().X,1+(ind.top().X-1 -l)%stages[i][1]);
      ind.pop();
    }
  }
  return 0;
}
int main(){
  ll i,j,tmp;
  scanf("%I64d",&n);
  for(i=0;i<n;i++){
    scanf("%I64d %I64d",&stages[i][0],&stages[i][1]);
    if(stages[i][0]==2)
      scanf("%d",&stages[i][2]);
  }
  scanf("%I64d",&m);
  for(i=0;i<m;i++){
    scanf("%I64d",&tmp);
    ind.push(P(tmp,i));
  }
  solve(0,0);
  for(i=0;i<m;i++){
    printf("%I64d%c",ans[i],(i==m-1)?'\n':' ');
  }
  return 0;
}