#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<list>
#include<stack>

using namespace std;

int n;//運びたい荷物の数
int A[100000];//各荷物の重さ
int k;//用意されたトラックの数

//トラックのキャパがPだといくつの荷物が運べるかをチェックする
int check(int P){
  int i = 0;//積むことのできた荷物の数
  int sum;
  for(int j=0; j<k; j++){//トラックの数だけ繰り返す
    sum = 0;//j台目のトラックに積む荷物の重さの合計
    while(sum+A[i] <= P){//i番目の荷物を積むことができるか
      sum+=A[i];//積んだ
      i++;//次の荷物
      if(i==n){//全部の荷物を積んだか
        return n;
      }
    }
    //j台目のトラックはいっぱいになったので次のトラックへ
  }
  return i;
}

//荷物が全て(n個)運ぶための最低限のトラックのキャパpを見つける
int solve(){

  /* p=0から探索していく方法
  int p = 0;
  while(check(p)<n){
    p++;
  }
  return p;
  */

  //pの最小値=0,pの最大値=10,000x100,000(1台のトラックでw=10,000の荷物を100,000個運ぶ時)
  //の範囲で二分探索
  int left = 0;
  int right = 10000*100000;
  int mid;
  while(left<right){
    mid = (left+right)/2;
    if(check(mid)<n){
      left=mid+1;
    }
    else{
      right=mid;
    }
  }
  return left;
}

int main(){
  cin>>n>>k;
  for(int i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  int ans = solve();
  printf("%d\n",ans);
  return 0;
}
