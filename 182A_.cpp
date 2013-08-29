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
long b[200004],l,r;

int main(){
  b[0]=0;
  long n,m;
  scanf("%ld %ld",&n,&m);
  long i,j,sum=0,temp;
  for(i=1;i<=n;i++){
    scanf("%ld",&temp);
    sum+=temp;
    cout<<sum<<",";
    b[i]=sum;
  }
  for(i=0;i<m;i++){
    scanf("%ld %ld",&l,&r);
    printf("%d\n",(b[r]-b[l-1]==0));
  }
  return 0;
}