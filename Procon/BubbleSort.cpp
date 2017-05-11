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

void bubble_sort(int A[],int N){
  int sw = 0;
  int i =0;
  while(1){
    if(i==N-1){
      break;
    }
    for(int j=N-1; i<j; j--){
      if(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        sw++;
      }
    }
    i++;

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
  bubble_sort(A,n);
  return 0;
}
