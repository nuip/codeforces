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

map<int,map<int,int> > table;
set<pair<int,int> > p,n;
set<pair<int,int> >::iterator it,ite;
map<int,map<int,int> >::iterator itm;
map<int,int>::iterator itmm;

void add(int x, int y, int v){
//  cout<<x<<","<<y<<","<<v<<endl;
  table[y][x]+=v;
 /* if(table[y][x]>0){
    p.insert(make_pair(x,y));
  }else if(table[y][x]<0){
    n.insert(make_pair(x,y));
  }else{
    if(v>0){
      n.erase(make_pair(x,y));
    }else{
      p.erase(make_pair(x,y));
    }
  }*/
 // cout<<"finished"<<endl;
}

int main(){
  int N,ax,ay,bx,by;
  bool f=0;

  scanf("%d",&N);
  int i,j;
//  return 0;
  while(N--){
    scanf("%d %d %d %d",&ax,&ay,&bx,&by);
    add(ax,ay,1);
    add(bx,by,1);
    add(ax,by,-1);
    add(bx,ay,-1);
  }



  int cnt=0,ansx[4],ansy[4];
  for(itm=table.begin();itm!=table.end();itm++){
    map<int,int> tempm=(*itm).Y;
    for(itmm=tempm.begin();itmm!=tempm.end();itmm++){
      //cout<<itmm->X<<","<<itm->X<<","<<itmm->second<<endl;
      if(itmm->second){
        if(cnt>=4){
          cnt=10;
          f=0;
          break;
        }
        ansx[cnt]=itmm->X;
        ansy[cnt]=itm->X;
        cnt++;
      }
    }
  }
  if(cnt==4){
    if(ansy[0]==ansy[1] && ansy[2]==ansy[3] && ansx[0]==ansx[2]&& ansx[1]==ansx[3]){
      cout<<ansy[2]-ansy[0] <<","<<ansx[1]-ansx[2] <<endl;
      if(ansy[2]-ansy[0]==ansx[1]-ansx[2])f=1;
    }
  }
  printf((f)?"YES\n":"NO\n");
  return 0;
}