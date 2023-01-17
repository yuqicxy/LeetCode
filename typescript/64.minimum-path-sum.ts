/*
 * @lc app=leetcode id=64 lang=typescript
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

// let grid = [[1,2,3],[4,5,6]]
// grid = [[1,3,1],[1,5,1],[4,2,1]]
// console.log(minPathSum(grid));

function minPathSum(grid: number[][]): number {    
    let m = grid.length;
    let n = grid[0].length;
    const dp: number[][] = Array.from(
        new Array(m),
        () => new Array(n)
    );
    dp[0][0] = grid[0][0];
    for(let r = 0 ; r < m  ; r++){
        for(let c = 0; c < n  ; c++){
            if(r===0 && c===0) continue;
            let fromTop:number = (r != 0) ? grid[r][c] + dp[r-1][c] : Infinity;
            let fromRight:number = (c != 0) ? grid[r][c] + dp[r][c-1] : Infinity;
            dp[r][c] = Math.min(fromTop,fromRight);
        }
    }
    console.log(dp)
    return dp[m-1][n-1];
};
// @lc code=end

