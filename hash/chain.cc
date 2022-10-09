#include <stdio.h>
#include <stdlib.h>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

#define NUM_BUCKET 10
#define NUM_DATA 100

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

struct NODE {
  int data;
  struct NODE *next;
};

struct NODE *hash_table[NUM_BUCKET];

void initialize(void)
{
  for(int i = 0; i<NUM_BUCKET; i++){
    hash_table[i] = NULL;
  }
}


int hash(int data)
{
  int key = data % NUM_BUCKET;
  return key;
}

void add(struct NODE **head, int data)
{
  struct NODE *new_node;
  struct NODE *node;
  struct NODE *prev;


  new_node = (struct NODE*)malloc(sizeof(struct NODE));

  new_node->data = data;

  node = *head;

  //node = バケットのリストの最後尾, prev = バケットのリストの最後尾のひとつ前
  while (node != NULL){
    prev = node;
    node = node -> next;
  }

  //nodeはNULLを指している。
  if (*head == node){ //バケットのリストに何も入っていない場合
    new_node -> next = *head;
    *head = new_node;
  }else { //バケットのリストに入っている場合
    new_node -> next = node;
    prev -> next = new_node;
  }


}



int search(struct NODE *head, int data)
{
  struct NODE *node;

  node = head;

  while(node != 0){
    if(node -> data == data){
      return 1;
    }
    node = node -> next;
  }
  return 0;
}


int main(void) {
    int i;
    int key;


    int datas[NUM_DATA];

    for (i = 0; i<NUM_DATA; i++){
      datas[i] = random(1, NUM_DATA);
    }

    initialize();

    /* データの格納 */
    for(int i=0;i<NUM_DATA;i++){
      key = hash(datas[i]);
      add(&hash_table[key], datas[i]);
    }

    /* データの探索 */
    for(int i=0;i<NUM_DATA;i++){
      if(search(hash_table[hash(datas[i])], datas[i])){
        printf("%d is found\n", datas[i]);
      }
    }

    return 0;
}
