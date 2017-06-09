#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>

using namespace std;
int n;
int A[20];

bool solve(int i,int m){
  if(m == 0){
    return true;
  }
  else if(m<0){
    return false;
  }
  if(i >= n){
    return false;
  }
  return (solve(i+1,m)||solve(i+1,m-A[i]));
}


int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  int q;
  int m;
  cin>>q;
  for(int i=0;i<q;i++){
    scanf("%d",&m);
    if(solve(0, m)){
      printf("yes\n");
    }
    else{
      printf("no\n");
    }
  }
  return 0;
}
