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

ll n,m;
string x,y;
vector<int> chars[256];

ll Gcd(ll n,ll m){
  if(n<m)swap(n,m);

  if(m==0)return n;
  return Gcd(m,n%m);
}

int main(){
  ll i,j,gcd,lcm,rep,same=0;

  cin>>n>>m;
  cin>>x>>y;
  gcd=Gcd(ll(x.size()),ll(y.size()));
  lcm=x.size()/gcd*y.size();
  rep=n*x.size()/lcm;
  for(i=0;i<y.size();i++){
    chars[y.at(i)].pb(i);
  }
  for(i=0;i<x.size();i++){
    for(j=0;j<chars[x.at(i)].size();j++){
      if((chars[x.at(i)][j]-i)%gcd==0)
        same++;
    }
  }
  cout<<n*x.size()-same*rep<<endl;
  return 0;
}