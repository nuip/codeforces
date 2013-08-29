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

int n,nn,temp;

int main(){
  long sum=0,posi=0,nega=0,min=10000;
  scanf("%d",&n);
  nn=n*2-1;
  int i;
  for(i=0;i<nn;i++){
    scanf("%d",&temp);
    if(temp<0){
      nega++;
      temp*=-1;
    }else if(temp!=0){
      posi++;
    }
    if(min>temp)
      min=temp;
    sum+=temp;
  }
  if(posi%2==0 && nega%2==1)
    sum-=min*2;
  printf("%ld\n",sum);
  return 0;
}