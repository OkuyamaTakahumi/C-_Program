#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100;

struct Card
{
  char suit;
  int value;
};

void print(Card A[],int N){
  for(int val=0;val<N;val++){
    cout<<A[val].suit<<A[val].value;
    if(val!=N-1){
      cout<<" ";
    }
  }
  cout<<endl;
}

void bubble_sort(Card A[],int N){
  int i =0;
  for(int i=0;i<N;i++){
    for(int j=N-1; i<j; j--){
      if(A[j].value<A[j-1].value){
        //Card t = A[j];
        //A[j] = A[j-1];
        //A[j-1] = t;
        swap(A[j],A[j-1]);
      }
    }
  }
}


void selection_sort(Card A[],int N){
  for(int i=0;i<N;i++){
    int min_index=i;
    for (int j=i;j<N;j++){
      if (A[j].value<A[min_index].value){
        min_index = j;
      }
    }
    if(min_index != i){
      //Card t = A[i];
      //A[i] = A[min_index];
      //A[min_index] = t;
      swap(A[i],A[min_index]);
    }
  }
}

bool isStable(Card A1[],Card A2[],int N){
  for(int i=0;i<N;i++){
    if(A1[i].suit != A2[i].suit){
      return false;
    }
  }
  return true;
}
int main(){
  int n;
  Card C1[100],C2[100];

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> C1[i].suit >>C1[i].value;
  }
  for(int i=0;i<n;i++){
    C2[i] = C1[i];
  }
  bubble_sort(C1, n);
  selection_sort(C2, n);

  print(C1,n);
  cout<<"Stable"<<endl;

  print(C2,n);
  if(isStable(C1,C2,n)){
    cout<<"Stable"<<endl;
  }
  else{
    cout<<"Not stable"<<endl;
  }

  //selection_sort(A,n);


  return 0;
}
