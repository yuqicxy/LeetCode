/*
 * @lc app=leetcode id=120 lang=typescript
 *
 * [120] Triangle
 */

import { match } from "assert";

// @lc code=start

// import console from "console";

// let tri = [[-1],[-2,-3]];

// console.log(minimumTotal(tri));

//version 1
// function minimumTotal(triangle: number[][]): number {
//     let rowNum = triangle.length;
//     let dyArray: Array<number> = [triangle[0][0]];
//     for(let ri = 1; ri < rowNum; ++ri){
//         let elements = triangle[ri];
//         let eleNum = elements.length;
//         let l = dyArray.length;
//         for(let ei = 0; ei < eleNum; ++ei){
//             let i = ei - 1;
//             let min:any = undefined;
//             if(i >= 0 && i < l)
//                 min = dyArray[i] + elements[ei];
//             i = ei;
//             if(i >= 0 && i < l)
//                 min = (min===undefined)?dyArray[i] + elements[ei]:Math.min(min,dyArray[i] + elements[ei]);
//             dyArray.push(min);
//         }
//         dyArray = dyArray.slice(l);
//     }
//     return Math.min(...dyArray);
// }

//version 2
function minimumTotal(triangle: number[][]): number {
    if(triangle.length == 1) return triangle[0][0];

    let height = triangle.length - 2;
    for(let level = height; level >= 0; level--){
        for (let col = 0; col < triangle[level].length; col++){
            let left = triangle[level][col] + triangle[level + 1][col];
            let right = triangle[level][col] + triangle[level + 1][col + 1];
            triangle[level][col] = Math.min(left,right);
        }
    }
    return triangle[0][0];
}

// @lc code=end