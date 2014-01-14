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

int cnt[4],x,y,n;

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    cnt[2*(x%2)+y%2]++;
  }

  if((cnt[3]*2+cnt[2]+cnt[1])%2!=0){
    cout<<"-1"<<endl;
  }else if((cnt[3]+cnt[2])%2==0 && (cnt[3]+cnt[1])%2==0){
    cout<<"0"<<endl;
  }else if(((cnt[3]+cnt[2])%2!=0 && (cnt[3]+cnt[1])%2!=0)
           &&(cnt[2] || cnt[1])){
    cout<<"1"<<endl;
  }
  return 0;
}