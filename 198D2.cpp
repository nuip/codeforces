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
struct node{
  int val,lnum,rnum,num;
  node *lch,*rch;
};

node *insert(node *p, int x){
  if(p == NULL){
    node *q= new node;
    q->val = x;
    q->lnum = q->rnum = 0;
    q->num = 1;
    q->lch = q->rch = NULL;
    return q;
  }else{
    if(x < p->val){
      p->lch = insert(p->lch,x);
      p->lnum++;
    }else if(x > p->val){
      p->rch = insert(p->rch,x);
      p->rnum++;
    }else{
      p->num++;
    }
    return p;
  }
}

node *find(node *p,int x){
  if(p==NULL)
    return NULL;
    
  if(x == p->val){
    return p;
  }else if(x < p->val){
    return find(p->lch,x);
  }else{
    return find(p->rch,x);
  }
}

int smallerCount(node *p,int x){
  if(p==NULL){
    return 0;
  }else if(p->val == x){
    return p->lnum;
  }else if(x < p->val){
    return smallerCount(p->lch,x);
  }else{
    return smallerCount(p->rch,x) + p->lnum  + p->num;
  }
}

int biggerCount(node *p,int x){
  if(p==NULL){
    return 0;
  }else{
    int xcnt=0;
    node *xnode=find(p,x);
    if( (xnode)!=NULL )
      xcnt=xnode->num;
    return p->num + p->lnum + p->rnum - smallerCount(p,x) -xcnt;
  }
}

int a[100005],cnt[100005],n;

int main(){
  node *lft,*right;
  int i,j,min=1000000;
  lft=right=NULL;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",a+i);
    cnt[i]+=biggerCount(lft,a[i]);
    lft=insert(lft,a[i]);
  }
  for(i=n-1;i>=0;i--){
    cnt[i]+=smallerCount(right,a[i]);
    right=insert(right,a[i]);
    if(cnt[i]<min)min=cnt[i];
  }
  cout<<n-min<<endl;
  return 0;
}