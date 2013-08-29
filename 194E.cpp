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

bool used[10];
long nums;
int k;
set<long> ans;

void calc(int n,int sum){
  int i,j;
  if(n){
    for(i=0;i<10;i++){
      if(used[i])continue;
      used[i]=1;
      nums*=10;
      nums+=i;
      calc(n-1,sum+i);
      calc(n-1,sum-i);
      calc(n-1,sum*i);
      used[i]=0;
      nums/=10;
    }
  }else{
    if(sum==k){
      

int main(){
  memset(used,0,sizeof(used));
  return 0;
}