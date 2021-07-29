/*
  ~ 11: 08
  input
   - 2d-array
  output
   - square submatrices conut
   - cell이 1인것을 return
  contraint
   - 1 <= arr.length <= 300
   - 1 <= arr[0].length <= 300
   - 0 or 1
 
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]

  [1,0,1],
  [1,1,0],
  [1,1,0]

  힌트 
   - dp

  side 1인 것은 counting
  side 2 

  count = 1
  0,0 => 0
  0,1 => 1 prev 0 왼쪽, 아래쪽 square못만듬 +1
  0,2 => +1
  0,3 => +1
  1,0 => +1
  1 , 1
0,1 | 1,0

*/

//반환 타이밍, 중복계산의 어려움
function countSquares(matrix: number[][]): number {
  let answer = 0;

  return answer;
};

export function secondss(){
  const matrix = [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
  ];
  countSquares(matrix);
}

