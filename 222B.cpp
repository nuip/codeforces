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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;
typedef pair<int,int> P;

map<int,vector<int> > bugs;
map<int,vector<int> >::reverse_iterator rit,rite;
vector<P> abil;
int costs[12345],re[12345];
int n,m,s;

bool check(int n){
//  cout<<"try "<<n<<":";
  priority_queue<P,vector<P>,greater<P> > pque;
  int cost,cnt=0,i,j,sum=0,abii=abil.size()-1,peri=0;
  for(rit=bugs.rbegin();rit!=bugs.rend();rit++){
    cost=rit->X;
    cnt+=rit->Y.size();
    for(;abii>=0;abii--){
      if(abil[abii].X<cost)break;
      pque.push(P(costs[abil[abii].Y],abil[abii].Y));
    }
    for(;peri<(cnt+n-1)/n;peri++){
      if(pque.empty()){
  //      cout<<"person"<<endl;
        return 0;
      }
      sum+=pque.top().X;
      pque.pop();
    }
    if(sum>s){
    //  cout<<"cost"<<endl;
      return 0;
    }
  }
//  cout<<"ok"<<endl;
  return 1;
}

int printRes(int n){
  priority_queue<P,vector<P>,greater<P> > pque;
  queue<int> bugque,perque;
  int cost,cnt=0,i,j,sum=0,abii=abil.size()-1,peri=0,rem=0;
  for(rit=bugs.rbegin();rit!=bugs.rend();rit++){
    cost=rit->X;
    cnt+=rit->Y.size();
    vector<int> vtmp=rit->Y;
    for(i=0;i<vtmp.size();i++){
      bugque.push(vtmp[i]);
    }
    for(;abii>=0;abii--){
      if(abil[abii].X<cost)break;
      pque.push(P(costs[abil[abii].Y],abil[abii].Y));
    }
    for(;peri<(cnt+n-1)/n;peri++){
      if(pque.empty()){
   //     cout<<"person"<<endl;
        return 0;
      }
      sum+=pque.top().X;
      for(i=0;i<n;i++){
        perque.push(pque.top().Y);
      }
      pque.pop();
    }
    if(sum>s){
   //   cout<<"cost"<<endl;
      return 0;
    }
  }
  while(!(perque.empty()||bugque.empty())){
    re[bugque.front()]=perque.front();
    bugque.pop(),perque.pop();
  }

  for(i=0;i<m;i++){
    printf("%d%c",re[i]+1,(i==m-1)?'\n':' ');
  }
//  cout<<"ok"<<endl;
  return 1;
}

int main(){
  int i,j,tmp;
  scanf("%d %d %d",&n,&m,&s);
  for(i=0;i<m;i++){
    scanf("%d",&tmp);
    bugs[tmp].pb(i);
  }
  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    abil.pb(P(tmp,i));
  }
  sort(abil.begin(),abil.end());
  for(i=0;i<n;i++){
    scanf("%d",costs+i);
  }

/*  for(it=bugs.begin();it!=bugs.end();it++){
    vector<int> vtmp=it->Y;
    for(i=0;i<vtmp.size();i++)
      cout<<vtmp[i]<<" ";
    cout<<endl;
  }
  for(i=0;i<abil.size();i++){
    printf("(%d,%d)",abil[i].X,abil[i].Y);
  }cout<<endl;*/

  int l=0,r=1e8,m;//[l,r)
  while(r-l>1){
    m=(r+l)/2;
    if(check(m)){
      r=m;
    }else{
      l=m;
    }
   // printf("[%d,%d)\n",l,r);
  }
  if(check(r)){
    cout<<"YES"<<endl;
    printRes(r);
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}