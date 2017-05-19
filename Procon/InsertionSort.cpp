#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 1000;


void trace(int A[],int N){
  for(int val=0;val<N;val++){
    cout<<A[val];
    if(val!=N-1){
      cout<<" ";
    }
  }
  cout<<endl;
}

int main(){
  int A[MAX] , n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }

  trace(A,n);

  for(int i=1; i<n; i++){
    int v = A[i];
    int j = i-1;
    while(A[j]>v and 0<=j){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A,n);
  }
  return 0;
}
