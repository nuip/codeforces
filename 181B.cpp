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


int studentN,dataN;
int group[50],students[50],groupCnt=0;
int gMem[30][4];

int main(){
  memset(group,0,sizeof(group));
  memset(gMem,-1,sizeof(gMem));
  memset(students,-1,sizeof(students));
  scanf("%d %d",&studentN,&dataN);
  int i,j,a,b;
  for(i=0;i<dataN;i++){
    scanf("%d %d",&a,&b);
    if(students[a]==-1 && students[b]==-1){
      students[a]=students[b]=groupCnt;
      gMem[groupCnt][0]=a;
      gMem[groupCnt][1]=b;
      group[groupCnt]+=2;
      groupCnt++;
    }else if(students[a]!=students[b]){
      if(students[a]==-1){
        if(group[students[b]]<3){
          students[a]=students[b];
          gMem[students[a]][group[students[a] ] ] =a;
          
          group[students[a]]++;
        }else{
          printf("-1\n");
          return 0;
        }
      }else if(students[b]==-1){
        if(group[students[a] ] <3){
          students[b]=students[a];
          
          gMem[students[a]][group[students[a] ] ] =b;
          group[students[a]]++;
        }else{
          printf("-1\n");
          return 0;
        }
      }else{
        printf("-1\n");
        return 0;
      }
    }
  }
  i=0;
  j=0;
  int amari=1;
  for(i=0;i<groupCnt;i++){
    for(j=0;j<group[i];j++){
      printf("%d ",gMem[i][j]);
    }
    for(;j<3;j++){
      while(students[amari]!=-1)
        amari++;
      printf("%d ",amari);
      students[amari]--;
    }
    printf("\n");
  }
  int ii=0;
  for(;amari<=studentN;amari++){
    if(students[amari]!=-1)
      continue;
    printf("%d ",amari);
    ii++;
    if(ii%3==0)
      printf("\n");
  }
  return 0;
}