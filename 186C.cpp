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

char num[12],tmp;
int n,m,l,len;

int main(){
  scanf("%s",num);
  n=atoi(num);
  if(n>=0){
    printf("%d\n",n);
  }else{
    len=strlen(num);
    tmp=num[len-1];
    num[len-1]='\0';
    m=atoi(num);
    if(len>1)if(isdigit(num[len-2]))num[len-2]=tmp;
    l=atoi(num);
    printf("%d\n",max(max(n,m),l));
  }
  return 0;
}