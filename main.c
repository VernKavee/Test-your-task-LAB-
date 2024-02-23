#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv){
  //For Node Queue.
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;

  enqueue(&headPtr, &tailPtr, 5);
  enqueue(&headPtr, &tailPtr, 9);
  enqueue(&headPtr, &tailPtr, 7);
  enqueue(&headPtr, &tailPtr, 82);
  int a = dequeue(&headPtr, &tailPtr);
  printf("%d\n", a);
  a = dequeue(&headPtr, &tailPtr);
  printf("%d\n", a);
  a = dequeue(&headPtr, &tailPtr);
  printf("%d\n", a);
  a = dequeue(&headPtr, &tailPtr);
  printf("%d\n", a);


  //For struct Queue.
  Queue q;
  q.headPtr=NULL;
  q.tailPtr=NULL;
  q.size=0;

  enqueue_struct(&q, 7);
  int b = dequeue_struct(&q);
  printf("struct %d\n",b);
  enqueue_struct(&q, 14);
  enqueue_struct(&q, 21);
  b = dequeue_struct(&q);
  printf("struct %d\n",b);
  b = dequeue_struct(&q);
  printf("struct %d\n",b);


  //task today.
  int i,x;
  for(i = 1; i < argc; i++){
    if(strcmp(argv[i], "x") == 0){
      x = dequeue_struct(&q);
      if(x != NULL) printf("dequeing %d\n", x);
    }
    else{
      enqueue_struct(&q, atoi(argv[i]));       
    }
  }
  return 0;
}
