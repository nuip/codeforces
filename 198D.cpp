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

map<int,int> nums;
map<int,int>::iterator it,iti,minD;

int main(){
  int i,j,cnt,tmp,n;
  scanf("%d",&n);

  for(i=cnt=0;i<n;i++,cnt++){
    scanf("%d",&tmp);
    if(nums.count(tmp)){
      cnt--;
      continue;
    }
    nums[tmp]=cnt;
  }

  int mindd=1000000;

  for(it=nums.begin(),i=0;it!=nums.end();it++,i++){
    if((tmp=abs(i-(it->Y)))<mindd){
      mindd=tmp;
      minD=it;
    }
  }

  int ans=0;
  bool f=0;

  for(it=nums.begin();it!=nums.end();it++){
    if(it==minD){
      f=1;
      continue;
    }
    if(f){
      if( (it->Y)>=(minD->Y) )ans++;
    }else{
      if( (it->Y)<=(minD->Y) )ans++;
    }
  }

  cout<<ans+1<<endl;
  return 0;
}