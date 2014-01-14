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

ll gcds[1000006],cnt[1000006],x[100005],a,b,l,r,maxi,tmp;
long n;

int main(){
  ll i,j,k;
  ll rem;
  scanf("%ld",&n);

  for(i=0;i<n;i++){
    scanf("%I64d",x+i);
  }
  scanf("%I64d %I64d",&a,&b);
//  cout<<"#"<<a<<endl;;
  for(i=0;i<n;i++){
    for(j=(b+x[i]-1)/x[i]; j*x[i]<a; j++){
      if(gcds[j*x[i]-b]<x[i])
        gcds[j*x[i]-b]=x[i];
    }
    
  }
//cout<<"!";
  l=r=b;
  for(i=0; i<=a-b; i++){
    maxi=r+1;
    for(j=l-b; j<=r-b; j++){
      if(gcds[j])
        if((tmp=j+b+gcds[j]-1)>maxi)
          maxi=tmp;
    }
//    cout<<"["<<l<<","<<r<<"]->";
    l=r+1;
    r=maxi;
//    cout<<r<<"\n";
    if(a<=r)
      break;
  }
  cout<<i+1<<endl;
  return 0;
}