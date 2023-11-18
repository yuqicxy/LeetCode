/*
 * @lc app=leetcode id=19 lang=typescript
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    let slowPtr = head;
    let fastPtr = head;

    for(let i = 0; i < n; ++i) 
        fastPtr = fastPtr.next;

    if(!fastPtr) 
        return head.next;

    while(fastPtr.next){
        slowPtr = slowPtr.next;
        fastPtr = fastPtr.next;
    }

    slowPtr.next = slowPtr.next.next;

    return head;
};
// @lc code=end

