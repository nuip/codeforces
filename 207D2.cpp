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
map<int,int> charsX[256],charsY[256];
map<int,int>::iterator it;

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
  for(i=0;i<x.size();i++){
    charsX[x.at(i)][i%gcd]++;
  }
  for(i=0;i<y.size();i++){
    charsY[y.at(i)][i%gcd]++;
  }
  for(char c='a';c<='z';c++){
    for(it=charsX[c].begin();it!=charsX[c].end();it++){
      same+=charsY[c][it->X]*it->Y;
    }
  }
  cout<<n*x.size()-same*rep<<endl;
  return 0;
}