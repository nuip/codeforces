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

char grid[44][44];
int cnt[44][44],lt[44][44],rb[44][44];
int n,m;

bool count(){
  int i,j;
  for(i=0;i<=n;i++){
    for(j=0;j<m;j++){
      if(grid[i][j]=='1')
        cnt[i+1][j+1]++;
      cnt[i+1][j+2]+=cnt[i+1][j+1];
    }
  }
  for(j=0;j<=m;j++){
    for(i=0;i<n;i++){
      cnt[i+2][j+1]+=cnt[i+1][j+1];
    }
  }
}

int main(){
  int q,i,j,x,X,y,Y;
  scanf("%d %d %d",&n,&m,&q);
  for(i=0;i<n;i++)
    scanf("%s",grid[i]);
  count();
  for(y=0;y<n;y++){
    for(Y=y+1;Y<n;Y++){
      for(x=0;x<m;x++){
        for(X=x+1;X<m;X++){
          if(cnt[Y][X]+cnt[y][x]-cnt[y][X]-cnt[Y][x]==0){
            if(x==1&&y==1)printf("(%d,%d|%d,%d)",x,y,X,Y);
            lt[0][x+1]--;
            lt[y+1][0]--;
            lt[y+1][x+1]++;
            rb[Y][X]++;
          }
        }
      }
    }
  }
  for(i=0;i<=n;i++){
    for(j=0;j<m;j++){
      lt[i][j+1]+=lt[i][j];
      rb[i][j+1]+=rb[i][j];
    }
  }
  for(j=0;j<=m;j++)
    for(i=0;i<n;i++){
      lt[i+1][j]+=lt[i][j];
      rb[i+1][j]+=rb[i][j];
    }cout<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)
      cout<<lt[i][j]<<" ";
    cout<<endl;
  }cout<<"---"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)
      cout<<rb[i][j]<<" ";
    cout<<endl;
  }
  for(i=0;i<q;i++){
    scanf("%d %d %d %d",&y,&x,&Y,&X);
    printf("%d\n",rb[Y][X]+lt[y-1][x-1]);
  }
  return 0;
}