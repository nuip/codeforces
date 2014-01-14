#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int i,j;
  cout<<"100000"<<endl;
  for(i=0;i<10000;i++){
    printf("1 %d\n",i+1);
  }
  printf("2 10000 10000\n");
  for(i++;i<100000;i++)
    printf("2 100000 10000\n");
  cout<<"10"<<endl;
  for(i=0;i<10;i++){
    printf("%d\n",1000100+i);
  }
  return 0;
}