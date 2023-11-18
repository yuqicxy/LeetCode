/*
 * @lc app=leetcode id=148 lang=typescript
 *
 * [148] Sort List
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

// class ListNode {
//     val: number
//     next: ListNode | null
//     constructor(val?: number, next?: ListNode | null) {
//         this.val = (val===undefined ? 0 : val)
//         this.next = (next===undefined ? null : next)
//     }
// }

// testcase()

// function testcase(){
//     let sample = [-1,5,3,4,0];
//     let head = null;
//     let last = null;
//     for(let val in sample){
//         let current = new ListNode(sample[val]);
//         if(last != null){
//             last.next = current;
//             last = current;
//         }else{
//             head = current;
//             last = current;
//         }
//     }
//     let answer = sortList(head);
//     while(answer){
//         console.log(answer.val);
//         answer = answer.next;
//     }
// }


function sortList(head: ListNode | null): ListNode | null {
    return mergeSort(head);
};

function mergeSort(head: ListNode  | null)  : ListNode | null {
    if(head == null) return null;

    let mid = findmid(head);

    let answer:ListNode | null = head;

    if(head && mid){
        let l1 = mergeSort(head);
        let l2 = mergeSort(mid);
        answer = merge(l1,l2);
    }

    return answer;
}

function merge(first : ListNode | null, second: ListNode | null) : ListNode | null {
    let answer: ListNode | null = null;

    if(first == null)
        return second;

    if(second == null)
        return first;

    if(first.val <= second.val){
        answer = first;
        answer.next = merge(first.next,second);
    }else{
        answer = second;
        answer.next = merge(first,second.next);
    }

    return answer;
}

function findmid(head: ListNode | null): ListNode | null{
    if(head == null)
        return null;
    
    let fast : ListNode|null = head;
    let slow : ListNode|null = head;

    while(fast){
        fast = (fast.next && fast.next.next) ? (fast.next.next) : null;
        if(fast)
            slow = (slow?.next) ? (slow?.next) : null;
    }

    let second = null;
    if(slow?.next){
        second = slow.next;
        slow.next = null
    }
    return second;
}
// @lc code=end