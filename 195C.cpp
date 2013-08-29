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
typedef long long ll;

ll ones[35],oness[35],tmp,ans;
vector<ll> nums[35],outNum;

int fmaxv(ll n){
  if(n==0)return 0;
  int i=0;
  for(i=0;n%2==0;i++,n/=2);
  return i;
}

int main(){
  int i,j,k,maxOs;
  oness[0]=ones[0]=1;
  i=1;
  while(1){
    ans=oness[i]=ones[i]=(ones[i-1]+1)*2-1;
    if(ones[i]>1000000000)break;
    i++;
  }
  maxOs=i;
//cout<<ones[1]<<endl;
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%I64d",&tmp);
    for(j=0;tmp>oness[j];j++){
//      cout<<tmp<<":ones["<<j+1<<"]:"<<ones[j+1]<<endl;
      //if(tmp>ones[j+1])break;
    }
//    cout<<tmp<<"->"<<j<<"("<<ones[j]<<")";
    ones[j]&=tmp;
    nums[j].pb(tmp);
//    cout<<"->"<<j<<"("<<ones[j]<<")"<<endl;
  }

/*  for(i=0;i<10;i++){
    for(j=0;j<nums[i].size();j++){
      cout<<nums[i][j]<<" ";
    }
    cout<<endl;
  }*/

  for(i=maxOs;i>=0;i--){
//    cout<<ans<<":"<<(ans&ones[i])<<":"<<ones[i]<<endl;
    if(fmaxv(ans)<=fmaxv(ans&ones[i])){
      for(j=0;j<nums[i].size();j++){
        outNum.pb(nums[i][j]);
      }
      ans&=ones[i];
    }
  }
cout<<outNum.size()<<endl;
  for(i=0;i<outNum.size();i++){
    printf("%I64d%c",outNum[i],(i==outNum.size()-1)?'\n':' ');
  }
  return 0;
}