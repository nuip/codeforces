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

string str;
int pow2s[303],ans;

void f2ps(){
  int i=0;
  pow2s[0]=1;
  for(i=1;i<=302;i++){
    pow2s[i]=2*pow2s[i-1];
    pow2s[i]%=1000000007;
  }
}

int aa(int num){
  if(num<0)num-=((num/1000000007)-1)*1000000007;
  num%=1000000007;
  return num;
}

int main(){
  f2ps();
  cin>>str;
  int i,k,temp;
  ans=pow2s[str.size()-1];
  ans*=(pow2s[str.size()]-1);
  ans%=1000000007;
  for(i=0,k=str.size()-1;k>=0;i++,k--){
    if(str.at(i)=='0'){
      temp=pow2s[str.size()];
      if(k>=1){
        temp-=pow2s[2*k-1];
        temp=aa(temp);
        temp+=pow2s[k-1];
        temp=aa(temp);
      }
      temp*=pow2s[k];
      temp=aa(temp);
    cout<<temp<<"("<<k<<endl;
    ans-=temp;
    ans=aa(ans);
    }
  }

  cout<<ans<<endl;
      
  return 0;
}