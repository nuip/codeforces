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

map<ll,short> a;
ll an,bn,k;

int main(){
  ll i,j,temp;
  scanf("%I64d %I64d %I64d",&an,&bn,&k);
  cout<<an<<bn<<k<<endl<<a[0]<<endl;
  for(i=0;i<an;i++){
    scanf("%I64d",&temp);
    a[temp]++;
  }
  for(i=0;i<bn;i++){
    scanf("%I64d",&temp);
    a[temp]--;
  }
  map<ll,short>::iterator it;
  bool flag=1;
  while(flag){
    flag=0;
    it=a.begin();
    for(;it!=a.end();it++){
      cout<<(*it).first<<","<<(*it).second<<"/";
    }
    it=a.begin();
    for(it++;it!=a.end();it++){
      cout<<((*(--it)).second)<<"_"<<(*(++it)).second<<endl;
      if((*it).second==0){
        a.erase(it++);
        flag=1;
        if(it==a.end())
          break;
      }else if(((*(--it)).second)*((*(++it)).second)>0){
        (*(--it++)).second+=(*it).second;
        flag=1;
      }else{
        it--;
        if( (*(it)).second>0){
          it++;
          if((*(it)).second<0){
            (*(--it++)).second+=(*it).second;
            flag=1;
          }
        }else{
          it++;
        }
      }
    }
  }
  return 0;
}