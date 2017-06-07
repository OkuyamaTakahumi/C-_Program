#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>

using namespace std;

int binarySearch(int A[], int n ,int key){
  int left = 0;
  int right = n;
  int mid ;

  while(left<right){
    mid = (left+right)/2;

    if(A[mid]==key){
      return 1;
    }
    else if(A[mid]<key){
      left = mid+1;
    }
    else{
      right = mid;
    }
  }
  return 0;
}


int main(){
  int n,q,t;

  scanf("%d",&n);

  int S[n];

  for(int i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int sum = 0;
  for(int i=0;i<q;i++){
    scanf("%d",&t);
    sum+=binarySearch(S,n,t);
  }
  printf("%d",sum);
  printf("\n");
  return 0;
}
