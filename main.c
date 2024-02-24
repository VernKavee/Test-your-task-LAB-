#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"

int main(int argc , char **argv){
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  //task today.
  int i,x,pay;
  int count = 1;
  for(i = 1; i < argc; i++){
    if(strcmp(argv[i], "x") == 0){
      x = dequeue_struct(&q);
      if(x != 0){
        printf("Customer No: %d\n", count);
        printf("Customer %d have to pay %d Baht.\n", count++, x);

        do{
          printf("Cash: ");
          scanf("%d", &pay);
          x = x - pay;
        }while(x >= 0);
        printf("Thank you");
      }
    }






    else{
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i++]));       
    }



  }

  printf("==================================================");

  if(q.size > 1) printf("There are %d customer left in the queue", q.size);
  else printf("There are %d customers left in the queue", q.size);

  return 0;
}
