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
#define MOD 1000000007

using namespace std;
typedef __int64 lonlon;

//==============================================================
//下のコードを消す
//桁あふれチェック
//==============================================================
template <typename tn>void printV(tn v){
  tn::iterator it;
  for( it = v.begin(); it != v.end(); it++ )
    cout << *it << ",";
  cout<<endl;
  return;
}

string toStr(int num){
  ostringstream os;
  os<<num;
  return os.str();
}
string toStr(int chars[]){
  ostringstream os;
  os<<chars;
  return os.str();
}
int a,b;
lonlon n;
long ncr[2][1000008];
void findC(lonlon num){
  memset(ncr,0,sizeof(ncr));
  lonlon i,j;
  ncr[0][0]=ncr[1][0]=1;
  for(i=1;i<=num;i++){
    for(j=1;j<i+1;j++){
      ncr[i%2][j]=ncr[(i-1)%2][j]+ncr[(i-1)%2][j-1];
      ncr[i%2][j]%=MOD;
      //cout<<ncr[i%2][j]<<",";
    }
    cout<<i<<",";
    //cout<<i%2<<endl;
  }
  i=num+1;
  for(j=0;j<i+1;j++){
    ncr[i%2][j]=ncr[(i-1)%2][j];
  }
  ncr[0][0]=ncr[1][0]=1;
  
  return;
}
bool beautiful(lonlon num){
  while(num){
    if(num%10!=a && num%10!=b){
      return 0;
    }
    num/=10;
  }
  return 1;
}
int main(){
  lonlon sum,re=0;
  lonlon i;
  scanf("%d %d %I64d",&a,&b,&n);

  findC(n);
  printf("ddd");
  sum=a*n;
  for(i=0;i<=n;i++){
    if(beautiful(sum)){
      cout<<i<<":"<<sum<<endl;
      re+=ncr[0][i];
      re%=MOD;
    }
    sum-=a;
    sum+=b;
  }
  printf("%I64d\n",re);
  return 0;
}