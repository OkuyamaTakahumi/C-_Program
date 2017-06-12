#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<math.h> //

#include<vector>
#include<list>
#include<stack>

using namespace std;

void koch(int d,double p1[],double p2[]){
  if(d == 0){
    return ;
  }
  double tn = M_PI/3; // 度からラジアンへ単位を変換
  double s[2];
  double t[2];
  double u[2];
  s[0] = (2*p1[0]+p2[0])/3;
  s[1] = (2*p1[1]+p2[1])/3;
  //cout<<s[0]<<" "<<s[1]<<endl;
  t[0] = (p1[0]+2*p2[0])/3;
  t[1] = (p1[1]+2*p2[1])/3;
  //cout<<t[0]<<" "<<t[1]<<endl;

  u[0] = (t[0]-s[0])*cos(tn)-(t[1]-s[1])*sin(tn)+s[0];
  u[1] = (t[0]-s[0])*sin(tn)+(t[1]-s[1])*cos(tn)+s[1];
  //cout<<u[0]<<" "<<u[1]<<endl;

  koch(d-1, p1, s);
  printf("%f %f\n",s[0],s[1]);
  koch(d-1, s, u);
  printf("%f %f\n",u[0],u[1]);
  koch(d-1, u, t);
  printf("%f %f\n",t[0],t[1]);
  koch(d-1, t, p2);
}


int main(){
  int n;
  cin>>n;

  double data1[] = {0, 0};//元データ
  double data2[] = {100, 0};//元データ
  printf("%f %f\n",data1[0],data1[1]);
  koch(n, data1, data2);
  printf("%f %f\n",data2[0],data2[1]);

  return 0;
}
