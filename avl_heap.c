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
int pop(tnode* node)
{
    if (!node->left)
    {
        int result = node->value;
        node->parent->left = NULL;
        free(node->left);
        return result;
    }

    return pop(node->left);
}

//rotate
void ll_rotate(theap* heap)
{

}

void rr_rotate(theap* heap)
{

}

void rl_rotate(theap* heap)
{

}

void lr_rotate(theap* heap)
{

}

int get_height(tnode* node)
{
    if (!node)
        return 0;

    int result = 1;
    if (node->left)
        result = get_height(node->left) + 1;
    if (node->right)
        result = max(result, get_height(node->right) + 1);
    return result;
}

//height-balance property을 업데이트하는 함수
int get_hbp(tnode* node)
{
    //node가 null인 경우
    if (!node)
        return -1;
    
    return get_height(node->left) - get_height(node->right);
}
