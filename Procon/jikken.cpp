#include<iostream>
#include<algorithm>

#include<random>

using namespace std;
static const int MAX = 200000;

int main(){
  std::random_device rd;

  bool flag=1;

  for(int i=0; flag; i++){
    flag=0;
    int r = rd()%10;
    //cout<<r<<endl;
    if(r==9){
      flag=1;
    }
  }

  int A[]={1,2,3,4,5};
  int B[]={7,7,7,7,7};
  swap(A[2],B[3]);
  for(int i=2;i<5;i+=4){
    cout<<A[i]<<endl;
  }
  return 0;
}
