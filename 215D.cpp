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

multiset<int> cur,hoge;
multiset<int>::iterator it,ite;
set<int> ans;
queue<int> str;

int main(){
  int n,m,p,a[212345],tmp,cnt;
  scanf("%d %d %d",&n,&m,&p);
  int i,j;
  for(i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(i=0;i<m;i++){
    scanf("%d",&tmp);
    hoge.insert(tmp);
  }

  for(int s=0;s<p;s++){
    cur=hoge;
    cnt=0;
    for(i=s;i<n;i+=p){
      if( (it=cur.find(a[i]))==cur.end() ){
        if(cnt){
          cur.insert(str.front());
          str.pop();
          cnt--;
          i-=p;
        }
      }else{
        cur.erase(it);
        str.push(a[i]);
        cnt++;
        if(cnt==m){
          ans.insert(i-p*(m-1));
          cur.insert(str.front());
          str.pop();
          cnt--;
        }
      }
  //    cout<<cnt<<" ";
    }
  }
    set<int>::iterator sit,f;
    printf("%d\n",ans.size());
    for(f=sit=ans.begin();sit!=ans.end();sit++){
      f++;
      printf("%d%c",*sit+1,(f==ans.end()?'\n':' '));
    }
  return 0;
}