#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static const int MAX = 1000000;
long long cnt;
vector<int> A(MAX);
int n;
vector<int> G;


void trace(vector<int>, int N){
  for(int val=0;val<N;val++){
    cout<<A[val];
    if(val!=N-1){
      cout<<" ";
    }
  }
  cout<<endl;
}

void trace2(vector<int>, int N){
  for(int val=0;val<N;val++){
    cout<<A[val];
    cout<<endl;
  }
}

void insertion_sort(vector<int>, int N, int g){
  //cout<<g<<endl;
  for(int i=g; i<N; i++){
    int v = A[i];
    int j = i-g;
    while(A[j] > v and j>=0){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
  //trace(A);
}

void shell_sort(vector<int>, int N){
  int h = 1;
  cnt = 0;
  while(h<=N){
    G.push_back(h);
    h = 3*h + 1;
  }
  for(int i=G.size()-1; 0<=i; i--){
    insertion_sort(A, N, G[i]);
  }
}

int main(){
  int a;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  shell_sort(A, n);
  cout<<G.size()<<endl;
  for(int val=G.size()-1 ; 0<=val; val--){
    cout<<G[val];
    if(val!=0){
      cout<<" ";
    }
  }
  cout<<endl;
  cout<<cnt<<endl;
  trace2(A, n);
  return 0;
}
