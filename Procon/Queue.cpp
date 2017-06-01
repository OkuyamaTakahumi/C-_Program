#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define LEN 100005

//#include<algorithm>

//#include<random>
using namespace std;



struct Queue
{
  char name[10];
  int time;
};
Queue Q[LEN];
int head;
int tail;
int n;

/*
void print(Queue A[],int h, int t){
  for(int val=h;val<t;val++){
    cout<<A[val].name<<" "<<A[val].time<<endl;
  }
}
*/

void enqueue(Queue queue){
  Q[tail] = queue;
  tail = (tail+1)%LEN;
}

Queue dequeue(){
  Queue x = Q[head];
  head = (head+1)%LEN;
  return x;
}
int main(){
  Queue de_q;
  int n, q, c;
  int sum_time=0;

  scanf("%d%d",&n,&q);
  //cin>>n>>q;
  for(int i=0;i<n;i++){
    //cin>>Q[i].name>>Q[i].time;
    scanf("%s", Q[i].name);
    scanf("%d",& Q[i].time);
  }

  head = 0;
  tail = n;

  while(head != tail){
    de_q = dequeue();
    c = min(de_q.time , q);
    sum_time += c;
    de_q.time-=q;
    if(de_q.time > 0){
      enqueue(de_q);
    }
    else{
      //cout<<de_q.name<<" "<<sum_time<<endl;
      printf("%s %d\n", de_q.name, sum_time);
    }
  }
  return 0;
}
