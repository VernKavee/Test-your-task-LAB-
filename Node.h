//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2566 BE.
//
#ifndef Node_h
#define Node_h

struct order{
  struct order* next;
  int order_number;
  int qty;
};

typedef struct order Node;
typedef struct order* NodePtr;

typedef struct {
  NodePtr head, tail;
  int size;
}queue;

void enqueue_struct(queue* q, int x, int y){
  Node *new_node = (Node*) malloc(sizeof(Node));
  if(new_node){ 
    new_node->order_number = x;
    new_node->qty = y;
    new_node->next = NULL;

    if(q->size == 0 ) q->head = new_node;
    else q->tail->next = new_node;

    q->tail = new_node;
    q->size++;
  }
}


int dequeue_struct(queue *q){
  NodePtr t = q->head;

  if(t){
    int value;
    q->head = t->next;

    switch(t->order_number){
      case 1://Ramen 100 Baht.
        value = 100*(t->qty);
        if(t->qty > 1 ) printf("%d Bowl of Ramen\n", t->qty);
        else printf("%d Bowls of Ramen\n", t->qty);
        break;

      case 2://Somtum 20 Baht.
        value = 20*(t->qty);
        if(t->qty > 1 ) printf("%d Dish of Somtum\n", t->qty);
        else printf("%d Dishes of Somtum\n", t->qty);
        break;

      case 3://Fried chicken 50 Baht.
        value = 50*(t->qty);
        if(t->qty > 1 ) printf ("%d Bucket of Fried chicken\n", t->qty);
        else printf ("%d Buckets of Fried chicken\n", t->qty);
        break;

      default:
        printf("ERROR ON DAFAULT CASE!!!\n");
        break;
    }

    if(q->size == 1) q->tail = NULL;//if it's the last queue.
    q->size--;
    free(t);
    return value;
  }

  printf("The Queue is Empty.\n");
  return 0;
}

#endif
