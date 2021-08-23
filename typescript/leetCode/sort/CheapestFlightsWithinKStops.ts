/**
  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1

  obj list
  {
    0: [[to, price], [to, price]]
    1
  }

 */

function dfsWithMemo(graph: any, src: number, dst: number, k: number, memo: Map<string, number>) {
  if (src === dst) return 0;
  if (k > 0) {
    return Infinity;
  }
  if (memo.has(`${src}:${k}`)) {
    return memo.get(`${src}:${k}`);
  }

  const neighbors = graph[src];

  let minPrice = Infinity;
  for (let c = 0; c < neighbors.length; c++) {
    const [newSrc, price] = neighbors[c];
    minPrice = Math.min(minPrice, dfsWithMemo(graph, newSrc, dst, k - 1, memo) + price);
  }

  memo.set(`${src}:${k}`, minPrice);

  return minPrice;
}

function findCheapestPrice(n: number, flights: number[][], src: number, dst: number, k: number): number {

  let answer = 0;
  const graph: any ={};

  for(let i = 0; i < flights.length; i++) {
    const [from, to, price] = flights[i];
    if(graph[from]) graph[from].push();
    else graph[from] = [[to, price]];

    if(!graph[to]) graph[to] = [];
  }

  const memo = new Map();
  const cheapest = dfsWithMemo(graph, src, dst, k, memo);

  console.log(cheapest);
  
  return answer;
};

function findCheapestPrice2(n: number, flights: number[][], src: number, dst: number, k: number): number {
  let answer = 0;

  return answer;
}

export function sfwks() {
  let n = 3;

  // [from, to, price] 
  let flights = [[0,1,100],[1,2,100],[0,2,500]];

  // 0부터 2까지 이동
  let src = 0; 
  let dst = 2;

  // 경유 1회 가능
  let k = 1;

  //findCheapestPrice(n, flights, src, dst, k);
  findCheapestPrice2(n, flights, src, dst, k);
}