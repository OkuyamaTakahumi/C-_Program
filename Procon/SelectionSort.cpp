#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100;


void trace(int A[],int N){
  for(int val=0;val<N;val++){
    cout<<A[val];
    if(val!=N-1){
      cout<<" ";
    }
  }
  cout<<endl;
}

void selection_sort(int A[],int N){
  int sw = 0;
  for(int i=0;i<N;i++){
    int min_index=i;
    for (int j=i;j<N;j++){
      if (A[j]<A[min_index]){
        min_index = j;
      }
    }
    if(min_index != i){
      swap(A[i],A[min_index]);
      sw ++;
    }
  }
  trace(A,N);
  cout<<sw<<endl;
}


int main(){
  int A[MAX] , n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  //strace(A,n);
  selection_sort(A,n);
  return 0;
}
