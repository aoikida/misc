#include <stdio.h>
#include <stdlib.h>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());


#define NUM_BUCKET 100
#define NUM_ITEM 50
#define DELTA 1

int array[NUM_BUCKET];

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int hash(int data) {

    return data % NUM_BUCKET;
}

int rehash(int old_hash) {

    return (old_hash + DELTA) % NUM_BUCKET;
}


int add(int data) {

    int i = hash(data);

    /* 空いているバケットを探す */
    while (array[i] != 0) {
        /* 新たなハッシュ値を算出 */
        i = rehash(i);
    }

    /* ハッシュ値の位置のバケットにデータ格納 */
    array[i] = data;

    return i;
}


int search(int data) {

    int i;
    int count = 1;

    /* ハッシュ値の算出 */
    i = hash(data);

    while (array[i] != 0 && count < NUM_BUCKET) {
        if (array[i] == data) {

            /* dataが見つかった */
            return count;
        }

        /* 新たなハッシュ値を算出 */
        i = rehash(i);

        /* 探索回数をカウントアップ */
        count++;
    }

    return 0;
}

int main(void) {

    int i;

    int datas[NUM_ITEM];
    for (i = 0; i<NUM_ITEM; i++){
      datas[i] = random(1, NUM_BUCKET);
    }
    for (i = 0; i<NUM_ITEM; i++){
      array[i] = 0;
    }


    /* データの格納 */
    for (i = 0; i < NUM_ITEM; i++) {
        add(datas[i]);
        }

    /* データの探索 */
    for (i = 0; i < NUM_ITEM; i++) {
        int order = search(datas[i]);
        if (order) {
            printf("%d is FOUND in order %d\n", datas[i], order);
        }
        else {
            printf("%d is not FOUND \n", datas[i]);
        }
    }

    return 0;
}