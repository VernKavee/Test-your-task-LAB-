#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"

int main(int argc , char **argv){
  queue q;
  q.head = NULL;
  q.tail = NULL;
  q.size = 0;

  //task today.
  int i,x,pay;
  int count = 1;

  for(i = 1; i < argc; i++){
    if(strcmp(argv[i], "x") == 0){
      printf("Customer No: %d\n", count);
      x = dequeue_struct(&q);
      if(x != 0){
        printf("Customer %d have to pay %d Baht.\n", count, x);
        do{
          printf("Cash: ");
          scanf("%d", &pay);
          if(pay < 0){
            printf("Invalid payment amount. Please enter a non-negative amount.\n");\
            continue;
          }
          x = x - pay;
          if(x > 0) printf("Remaining amount to pay: %d Baht\n", x);
          else ("Thank you.\n");
        }while(x >= 0);

        count++;
      }
    }

    else{
      if(atoi(argv[i]) > 0 && atoi(argv[i]) <= 3){
        enqueue_struct(&q, atoi(argv[i]), atoi(argv[i]));
        i++;
      }
      else{
        printf("No food\n");
        i++;
      } 
    }
  }
  

  printf("==================================================\n");

  if(q.size > 1) printf("There are %d customer left in the queue", q.size);
  else printf("There are %d customers left in the queue", q.size);

  return 0;
}
