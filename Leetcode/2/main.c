// https://leetcode.com/problems/add-two-numbers/
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int getDigit(int n){
    int result = 0;
    while (n != 0){
        result ++;
        n /= 10;
    }
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int first = 0;
    int sec = 0;
    int digit= 0;
    int temp = 0;
    
    struct ListNode* lr = 0;
    struct ListNode* lt = 0;
        
    while (l1 != 0){
        first += l1->val * pow(10, digit++);
        l1 = l1->next;
    }
    digit = 0;
    while (l2 != 0){
        sec += l2->val * pow(10, digit++);
        l2 = l2->next;
    }

    int result = first + sec;
    
    if (result == 0){
        lr = (struct ListNode*)malloc(sizeof(struct ListNode));
        lr->next = 0;
        lr->val = 0;
        return lr;
    }
    
    return lr;
}
