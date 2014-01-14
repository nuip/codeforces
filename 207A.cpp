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

int sum[112],m,x,y;

int main(){
  int i,tmp;

  scanf("%d",&m);
  for(i=1;i<=m;i++){
    scanf("%d",&tmp);
    sum[i+1]=sum[i]+tmp;
  }
  scanf("%d %d",&x,&y);
  int ans=0;
  for(i=1;i<=m;i++){
    if(x<=sum[i] && sum[i]<=y){
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}