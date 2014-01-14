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



long n,a[100005],tmp,temp;
ll res,lcms[100005];
set<int> ver[100002];

ll gcd(ll n,ll m){
  if(n<m)swap(n,m);

  if(m==0)return n;
  return gcd(m,n%m);
}

ll minCommon(ll v1,ll d1,ll v2,ll d2){
 // cout<<v1<<","<<d1<<","<<v2<<","<<d2<<"->";
  ll cnt,tmp=min(v1,v2),lcm=d1*d2/gcd(d1,d2);
  if(d1==d2)
    return (gcd(d1,abs(v1-v2))==d1)?tmp:0;
  if(d1<d2){
    swap(v1,v2);
    swap(d1,d2);
  }
  if(v1<v2){
    if(d2==0)
      return 0;
    v2-=d2*((v2-v1)/d2);
    while(v1<v2)
      v2-=d2;
  }
  cnt=(v1-v2)/(d1-d2);
  v1-=cnt*d1;
  v2-=cnt*d2;
//cout<<"("<<v1<<","<<v2<<")";
  if(tmp-v1>=lcm){
    v1+=(tmp-v1)/lcm*lcm;
  }
//cout<<"("<<v1<<","<<lcm<<","<<tmp<<")";
  return v1;
}

long solve(long num){
  set<int>::iterator it,ite;
  ll sum=0,minv=1000000000000,tmp,gcdv=0,lcm=1,nodev,minC=-10,vvs;
  long i,j;
  if(ver[num].size()==0){
//    cout<<"return"<<endl;
    return a[num];
  }
  gcdv=ver[*(ver[num].begin())].size();
  for(it=ver[num].begin();it!=ver[num].end();it++){
    ver[*it].erase(num);
    vvs=max(ver[*it].size(),(unsigned int)1);
//    cout<<"["<<num<<"] "<<"call "<<(*it)<<"(size:"<<ver[*it].size()<<")"<<endl;
    tmp=solve(*it)*vvs;//lcms[*it];
    if(minC==-10)minC=tmp;
//cout<<"(";
 //   cout<<(vvs)<<":tmp:"<<tmp<<endl;
    minC=minCommon(tmp,lcms[*it],minC,lcm);//cout<<minC<<endl;
    gcdv=gcd(lcms[*it],lcm);
    lcm*=lcms[*it]/gcdv;
//    cout<<")";
    minv=min(tmp,minv);
    sum+=tmp;
  }
  nodev=minC;
  lcms[num]=lcm*ver[num].size();
  res+=sum-nodev*ver[num].size();//minv*ver[num].size();
  //cout<<num<<":"<<nodev<<"*"<<ver[num].size()<<"("<<lcms[num]<<")"<<endl;
  return nodev;
}

int main(){
  set<int>::iterator it,ite;
  long i,j;
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    lcms[i+1]=1;
    scanf("%ld",a+i+1);
  }
  for(i=1;i<n;i++){
    scanf("%ld %ld",&tmp,&temp);
  //  cout<<tmp<<","<<temp<<endl;
    ver[tmp].insert(temp);
    ver[temp].insert(tmp);
  }
  solve(1);
  cout<<res<<endl;
  return 0;
}