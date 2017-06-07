#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>

using namespace std;

int linerSearch(int A[], int n, int key){
  A[n] = key;
  int i =0;
  while(A[i]!=key){
    i++;
  }
  return i!=n;
}


int main(){
  int n,q,t;

  scanf("%d",&n);

  int S[n+1];

  for(int i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int sum = 0;
  for(int i=0;i<q;i++){
    scanf("%d",&t);
    sum+=linerSearch(S,n,t);
  }
  printf("%d",sum);
  printf("\n");
  return 0;
}
