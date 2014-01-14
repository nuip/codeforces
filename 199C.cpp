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

//==============================================================
//下のコードを消す
//桁あふれチェック
//==============================================================

long r,h,ans1,ans2;
double s3=1.7320508075;

int main(){
  cin>>r>>h;

  int i,j;
  i=(2*h-r)/(s3*r)-3;
  while((double)h*2.0-(double)r >= (double)i*s3*r)
    i++;
  //cout<<"i:"<<i<<endl;
  ans1=(i+1)/2;
  ans1*=2;
  ans1+=(i)/2;
  if(i%2==0){
    if((double)h*2.0-(double)r >= (double)(i-1.0)*s3*r+(double)(2.0-s3))
      ans1++;
  }
  
  i=(2*h)/(s3*r)-3;
  while((double)h*2.0 >= (double)i*s3*r)
    i++;
  //cout<<"i:"<<i<<endl;
  ans2=(i)/2;
  ans2*=2;
  ans2+=(i+1)/2;
  if(i%2 && i!=1){
    if((double)h*2.0 >= (double)(i-1.0)*s3*r+(double)(2.0-s3))
      ans2++;
  }

  //cout<<ans1<<","<<ans2<<endl;
  cout<<max(ans1,ans2)<<endl;
  return 0;
}