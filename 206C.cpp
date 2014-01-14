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

ll dp[112][112];
int n,lc,rc,ql,qr,w[112];
multiset<int> setlr[2];
multiset<int>::iterator it,ite;

ll extra(int num,int lr){
  ll sum=0;
  int i=0;
  for(it=setlr[lr].begin();it!=setlr[lr].end()&&i<num;it++,i++){
    sum+=(*it);
  }
  return num;
}

int main(){
  int i,j,c;
  ll sum=0,minS=(1<<30),tmp;
  scanf("%d %d %d %d %d",&n,&lc,&rc,&ql,&qr);
  for(i=0;i<n;i++){
    scanf("%d",w+i);
    //if(i)setlr[1].insert(w[i]);//ˆêŒÂ–Ú‚Í‚¾‚ß
    sum+=w[i]*rc;
  }
  int L,R;
  for(c=0;c<=n;c++){
    L=c;
    R=n-c;
    if(L<R){
      //cout<<extra(R-L-1,1)<<"!!"<<endl;
      tmp=extra(R-L-1,1)*qr+sum;
    }else if(L>R){
      //cout<<extra(L-R-1,1)<<"!!"<<endl;
      tmp=extra(L-R-1,0)*ql+sum;
    }else{
      tmp=sum;
    }
    //cout<<c<<":"<<tmp<<endl;
    if(tmp<minS)
      minS=tmp;
    if(c!=n){
  //    if(c!=n-1)setlr[1].erase(setlr[1].find(w[c]));
    //  if(c)setlr[0].insert(w[c]);
      sum+=w[c]*(lc-rc);
    }
  }
  cout<<minS<<endl;
  return 0;
}