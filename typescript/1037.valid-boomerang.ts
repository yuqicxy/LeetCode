/*
 * @lc app=leetcode id=1037 lang=typescript
 *
 * [1037] Valid Boomerang
 */

// @lc code=start

function isBoomerang(points: number[][]): boolean {
    return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) != (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
};
// @lc code=end

