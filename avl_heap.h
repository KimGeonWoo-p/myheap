#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node
typedef struct node {
    int value;
    tnode* left;
    tnode* right;
    tnode* parent;
} tnode;

//heap
typedef struct heap {
    int cnt;
    tnode* head;
} theap;

//height-balance property값을 저장
int* dp;

//append
//value에 해당하는 값을 heap에 저장.
//저장 성공시 1을, 실패시 0을 return.
//저장하는 도중 rotate를 실시.
int append(tnode* node, int value);

//pop
//가장 작은 값을 heap에서 제거 후 반환
//제거하는 도중 rotate실시.
int pop(tnode* node);

//rotate
void ll_rotate(theap* heap);
void rr_rotate(theap* heap);
void rl_rotate(theap* heap);
void lr_rotate(theap* heap);

//heap의 높이를 구하는 함수
int get_height(tnode* node);

//height-balance property을 업데이트하는 함수
int get_hbp(tnode* node);

void clear(theap* heap);
