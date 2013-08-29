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

int n,m;
vector<int> ngs[1004];

int main(){
  int i,j,conSum=0,temps,tempg;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",&temps,&tempg);
    ngs[temps].pb(tempg);
    ngs[tempg].pb(temps);
  }

  int minNg=10000,minInd;
  for(i=1;i<=n;i++){
    if(minNg>ngs[i].size()){
      minNg=ngs[i].size();
      minInd=i;
    }
  }
  conSum+=n-1-minNg;//’†‰›‚Ì‚É‚Â‚È‚°‚é”
  if(minNg>0){
    conSum*=2;
    conSum+=minNg*(minNg-1)/2;
  }

  for(i=0;i<n;i++){
    if(minInd==i)break;
    for(j=0;j<ngs[minInd].size();j++){
      if(i==
    printf("%d %d\n",minInd,ngs[minInd][i]);
  }
  printf("%d\n",conSum);
  return 0;
}