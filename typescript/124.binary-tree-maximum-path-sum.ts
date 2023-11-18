/*
 * @lc app=leetcode id=124 lang=typescript
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

let gMax = 0;

function maxPathSum(root: TreeNode | null): number {
    gMax = Number.MIN_SAFE_INTEGER;
    let m = maxPath(root);
    return Math.max(m,gMax);
}

function maxPath(root: TreeNode | null): number {
    if(root){
        let leftMax = maxPath(root.left)
        let rightMax = maxPath(root.right)
        let maxP = Math.max(root.val,root.val + leftMax, root.val + rightMax)
        let nodeSelfMax = Math.max(maxP, root.val + leftMax + rightMax);
        gMax = Math.max(gMax,nodeSelfMax);
        return maxP;
    }
    return 0;
};

// @lc code=end

