// n = 2, 2 = 1+1
// n = 3, 3 = 1+1+1 , 1+2,
// n = 4, 4 = 1+1+1+1, 1+3, 2+2,
// n = 5, 5 = 1+1+1+1+1, 1+4 => (1+1+3, 1+2+2), 2+3,
// n = 6, 6 = 1+1+1+1+1+1, 1+5, 2+2+2, 2+4=> 2+(2+2), 3+3,
// n = 7, 7 = 1+1+1+1+1+1+1, 3+4
// n = 8, 8 = 1+1+1+1+1+1+1+1, 2+3+3
// n = 9, 9 = ..., 3+3+3
// n = 10, 10 = ..., 3+3+4
// n = 11, 3+3+3+2
// n = 12, 3+3+3+3
// n = 13, 3+3+3+4
// n = 14, 3+3+3+3+2
// ... => 즉, 3의 개수가 가장 많을때 최대곱이 된다.

function integerBreak(n: number): number {
  if (n < 2) return 0;
  if (n === 2) return 1;
  if (n === 3) return 2;

  const t = Math.floor(n / 3);
  if (n % 3 === 0) {
    return Math.floor(Math.pow(3, t));
  } else if (n % 3 === 2) {
    return Math.floor(Math.pow(3, t)) * 2;
  }
  return Math.floor(Math.pow(3, t - 1)) * 4;
}

function run() {
  console.log(integerBreak(10));
}

export default run;
