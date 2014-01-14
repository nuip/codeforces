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

int n,heap[110];
vector<int> nums[105];
multimap<int,int> nms;
multimap<int,int>::iterator it;

int main(){
  scanf("%d",&n);
  int tmp,i,j,h[2];
  for(i=0;i<n*2;i++){
    scanf("%d",&tmp);
    nums[tmp].pb(i);
  }

  for(i=10;i<=99;i++){
    if(nums[i].size()==0)continue;
    nms.insert(make_pair(nums[i].size(),i));
  }

  int cnt=0,sizes[2]={0,0};
  h[0]=h[1]=0;
  for(it=nms.begin(),i=0;it!=nms.end();it++,i++){
    h[i%2]++;
    sizes[i%2]+=nums[it->Y].size()/2;
    if(nums[it->Y].size()>1)
      h[(i+1)%2]++;
    sizes[(i+1)%2]+=nums[it->Y].size()/2;
    for(j=0;j<nums[it->Y].size();j++){
      heap[nums[it->Y][j]]=cnt%2+1;
      cnt++;
    }
  }
  /*for(i=0;i<oe[0].size();i++){
    h[0]++;
    h[1]++;
    sizes[0]+=nums[oe[0][i]].size()/2;
    sizes[1]+=nums[oe[0][i]].size()/2;
    for(j=0;j<nums[oe[0][i]].size();j++){
      heap[nums[oe[0][i]][j]]=cnt%2+1;
      cnt++;
    }
  }*/

  printf("%d\n",h[0]*h[1]);
  for(i=0;i<2*n;i++){
    printf("%d%c",heap[i],(i-1==2*n?'\n':' '));
  }
  return 0;
}