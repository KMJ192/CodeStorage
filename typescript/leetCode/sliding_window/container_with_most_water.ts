//input : integer type array
//output : number(size)
//constraint 
// - n === height.length
// - 2 <= n <= 10^5
// - 0 <= height[i] <= 10^4
//Edge Case
//DS

interface Pointer{
    front: number;
    back: number;
}

function maxArea(height: number[]): number{
    let maxSize = 0;
    let pointer: Pointer = {
        front: 0,
        back: 1
    };
    

    return maxSize;
}

// 시간 초과
// function maxArea_fail(height: number[]){
//     let maxSize = 0;
//     for(let i = 0; i < height.length; i++){
//         for(let j = i; j < height.length; j++){
//             const len = j - i;
//             if(height[i] > height[j]){
//                 if(maxSize < height[j] * len){
//                     maxSize = height[j] * len;
//                 }
//             }else{
//                 if(maxSize < height[i] * len){
//                     maxSize = height[i] * len;
//                 }
//             }
//         }
//     }
//     return maxSize;
// }

export function run(){
    //let height: number[] = [1, 8, 6, 2, 5, 4, 8, 3, 7];
    //let height: number[] = [1, 2, 6, 2, 5, 4, 1, 3, 1];
    //let height: number[] = [1, 2]; // => 1
    //let height: number[] = [2, 1]; // => 1
    //let height: number[] = [0, 2]; // => 0
    let height: number[] = [1, 2, 4, 3]; // => 4
    
    console.log(maxArea(height));
}
//    f                    b
//[1, 8, 6, 2, 5, 4, 8, 3, 7]
// 0  8  0  2  15 16 40 18 49

// f  b
//[1, 8, 6, 2, 5, 4, 8, 3, 7]
//if(front < back) 둘다이동?
    
//     |
//     | |
//   | | |
// | | | | => 4

//   |
// | | |   => 2

//   |
// | |     => 1

// |  
// | |     => 1

//   |
//   |     => 0