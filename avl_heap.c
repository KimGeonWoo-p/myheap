#include "avl_heap.h"

//append
//value에 해당하는 값을 heap에 저장.
//저장 성공시 1을, 실패시 0을 return.
//저장하는 도중 rotate를 실시.
int append(tnode* node, int value)
{
    tnode* new_node = (tnode*)malloc(sizeof(tnode));
    if(!new_node)
        return 0;

    if (node->value > value)
    {
        if (node->right)
            return append(node->right, value);
        new_node->parent = node;
        new_node->value = value;
        node->right = new_node;
    }

    else
    {
        if (node->left)
            return append(node->left, value);
        new_node->parent = node;
        new_node->value = value;
        node->left = new_node;
    }
    return 1;
}

//pop
//가장 작은 값을 heap에서 제거 후 반환
//제거하는 도중 rotate실시.
int pop(theap* heap);

//rotate
void ll_rotate(theap* heap);
void rr_rotate(theap* heap);
void rl_rotate(theap* heap);
void lr_rotate(theap* heap);

//height-balance property을 업데이트하는 함수
//메모이제이션을 통한 구현.
void get_hbp(tnode* node);