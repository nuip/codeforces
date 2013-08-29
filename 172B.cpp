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


int main(){
  int n;
  double bb,bs,dMin=1000000,bbmin=-1,bsmin=-1;
  cin>>bs>>bb>>n;
  int i;
  for(i=1;i<=n;i++){
    double bstemp=bs*i/bb;
    double fl=floor(bstemp),ce=ceil(bstemp);
    //cout<<bs/bb-fl/i<<","<<fabs(bs/bb-fl/i)<<endl;
    if(dMin>fabs(bs/bb-fl/i)){
 //     cout<<dMin<<"->";
      dMin=fabs(bs/bb-fl/i);
 //     cout<<dMin<<endl;
      bbmin=i;
      bsmin=fl;
    }
    if(dMin>fabs(bs/bb-ce/i)){
      dMin=fabs(bs/bb-ce/i);
 //     cout<<dMin<<endl;
      bbmin=i;
      bsmin=ce;
    }
  }
  cout<<bsmin<<"/"<<bbmin<<endl;
  return 0;
}