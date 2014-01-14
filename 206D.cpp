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

char T[30][30];
int dp[30][30],n;

int dpat(int x,int y,int pm){
  int d=0;
  if(T[x][y]=='a')d++;
  if(T[x][y]=='b')d--;
  
  if(x==0){
    return dp[x][y-1]+d;
  }else if(y==0){
    return dp[x-1][y]+d;
  }else{
    int tmp=min(pm*dp[x-1][y],pm*dp[x][y-1]);
    return pm*tmp+d;
  }
}

int main(){
  scanf("%d",&n);
  int i,j,pms[2]={1,-1};

  for(i=0;i<n;i++){
    scanf("%s",T[i]);
  }
  if(T[0][0]=='a')dp[0][0]++;
  if(T[0][0]=='b')dp[0][0]--;

  for(i=0;i<n;i++){
    for(j=0+(i==0);j<n;j++){
      dp[i][j]=dpat(i,j,pms[(i+j)%2]);
    }
  }
  string res;
  if(dp[n-1][n-1]==0){
    res="DRAW";
  }else if(dp[n-1][n-1]>0){
    res="FIRST";
  }else{
    res="SECOND";
  }
  cout<<res<<endl;
  return 0;
}