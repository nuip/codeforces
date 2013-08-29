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

int main(){
  long n,a,b,c,cnt=0,i;
  cin>>n;
  for(a=1;a<=n;a++){
    for(b=a;b<=n;b++){
      c=(long)sqrt(a*a+b*b);
      for(i=-1;i<=1;i++){
        if(a*a+b*b==(c+i)*(c+i)&& c<=n){
          cnt++;
          //cout<<a<<","<<b<<","<<c<<endl;
        }
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}