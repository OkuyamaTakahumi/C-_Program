#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int main(){
  int R[MAX] , n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> R[i];
  }
  int maxv = -1000000000;
  for(int j=1;j<n;j++){
    for(int i=0;i<j;i++){
      maxv = max(maxv,R[j]-R[i]);
    }
  }
  cout<<maxv<<endl;

  return 0;
}
