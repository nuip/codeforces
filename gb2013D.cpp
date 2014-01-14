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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

char s0[123],s1[123],fibl[60]="lL",fibr[60]="rR";
ll cnt[60][2],rl[60][4];//rl,rL,Rl,RL

ll gcd(ll a,ll b){
  return b?gcd(b,a%b):a;
}

int main(){
  ll i,j;
  cnt[1][0]=cnt[0][1]=0;
  cnt[0][0]=cnt[1][1]=1;
  for(i=2;i<55;i++){
    cnt[i][0]=cnt[i-1][0]+cnt[i-2][0];
    cnt[i][1]=cnt[i-1][1]+cnt[i-2][1];
    fibl[i]=fibl[i-2];
    fibr[i]=fibr[i-1];
    for(j=0;j<4;j++){
      rl[i][j]=rl[i-1][j]+rl[i-2][j];
    }
    int tmp=(fibr[i-2]=='R')*2 + 1*(fibl[i-1]=='L');
    rl[i][tmp]++;
  }

  ll k,x,n,m,ac=0,nn,mm;
  cin>>k>>x>>n>>m;
  bool f=0;
//  cout<<cnt[k-1][0]<<","<<cnt[k-1][1]<<endl;
  for(s0[0]='C';s0[0]<'E'&&s0[0]>='C';s0[0]++){
    for(s0[n-1]='A';s0[n-1]<'C';s0[n-1]++){
      for(s1[0]='C';s1[0]<'E'&& s1[0]>='C';s1[0]++){
        for(s1[m-1]='A';s1[m-1]<'C';s1[m-1]++){
          ac=x;
      //    cout<<s0[0]<<s0[n-1]<<s1[0]<<s1[m-1];
      //    cout<<m<<  ll(s1[m-1]=='A')<<  ll(s1[0]=='C');
          nn=n-ll(s0[n-1]=='A')-ll(s0[0]=='C');
          mm=m-ll(s1[m-1]=='A')-ll(s1[0]=='C');
     //     printf("(%I64d,%I64d)\n",nn,mm);
          if(s0[n-1]=='A'&&s0[0]=='C'){
            ac-=rl[k-1][0];
          }
          if(s1[n-1]=='A'&&s1[0]=='C'){
            ac-=rl[k-1][3];
          }
          if(s1[n-1]=='A'&&s0[0]=='C'){
            ac-=rl[k-1][2];
          }
          if(s0[n-1]=='A'&&s1[0]=='C'){
            ac-=rl[k-1][1];
          }
          for(i=0;i<=nn/2;i++){
            for(j=0;j<=mm/2;j++){
              if(ac==i*cnt[k-1][0]+j*cnt[k-1][1]){
                f=1;
                i*=2;
                for(int k=(s0[0]=='C');k<n;k++){
                  if(i>0){
                    s0[k]=(i%2)?'C':'A';
                    i--;
                  }else{
                    s0[k]='X';
                  }
                }
                j*=2;
                for(int k=(s1[0]=='C');k<m;k++){
                  if(j>0){
                    s1[k]=(j%2)?'C':'A';
                    j--;
                  }else{
                    s1[k]='X';
                  }
                }
                goto BRK;
              }
            }
          }
        }
        if(m==1)break;
      }
    }
    if(n==1)break;
  }
BRK:
  if(f){
    printf("%s\n%s\n",s0,s1);
  }else{
    printf("Happy new year!\n");
  }
  return 0;
}