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

vector<ll> ans;

int main(){
  ll n,b,ue,pow2c,a;
  bool flag=0;

  cin>>n;
  for(b=1;2*n>b*(b-3);b+=2){
    ue=n-b*(b-3)/2;
    if(ue%b!=0)continue;
//    cout<<b<<";"<<ue<<endl;
    pow2c=ue/b;
    a=1;
    flag=0;
    while(pow2c>1){
  ///    cout<<pow2c<<"->";
      if(pow2c%2){
        flag=1;
        break;
      }
      pow2c/=2;
      a*=2;
    }
    if(!flag){
      ans.pb(a*b);
    }
  }

  if(ans.size()){
    sort(ans.begin(),ans.end());
    //ans.unique();
    for(int i=0;i<ans.size();i++){
      if(i>0)if(ans[i]==ans[i-1])continue;
      printf("%d\n",ans.at(i));
    }
  }else{
    printf("-1\n");
  }
  return 0;
}