"use strict";
/**
  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1

  obj list
  {
    0: [[to, price], [to, price]]
    1
  }

 */
exports.__esModule = true;
exports.sfwks = void 0;
function dfsWithMemo(graph, src, dst, k, memo) {
    if (src === dst)
        return 0;
    if (k > 0) {
        return Infinity;
    }
    if (memo.has(src + ":" + k)) {
        return memo.get(src + ":" + k);
    }
    var neighbors = graph[src];
    var minPrice = Infinity;
    for (var c = 0; c < neighbors.length; c++) {
        var _a = neighbors[c], newSrc = _a[0], price = _a[1];
        minPrice = Math.min(minPrice, dfsWithMemo(graph, newSrc, dst, k - 1, memo) + price);
    }
    memo.set(src + ":" + k, minPrice);
    return minPrice;
}
function findCheapestPrice(n, flights, src, dst, k) {
    var answer = 0;
    var graph = {};
    for (var i = 0; i < flights.length; i++) {
        var _a = flights[i], from = _a[0], to = _a[1], price = _a[2];
        if (graph[from])
            graph[from].push();
        else
            graph[from] = [[to, price]];
        if (!graph[to])
            graph[to] = [];
    }
    var memo = new Map();
    var cheapest = dfsWithMemo(graph, src, dst, k, memo);
    console.log(cheapest);
    return answer;
}
;
function sfwks() {
    var n = 3;
    // [from, to, price] 
    var flights = [[0, 1, 100], [1, 2, 100], [0, 2, 500]];
    // 0부터 2까지 이동
    var src = 0;
    var dst = 2;
    // 경유 1회 가능
    var k = 1;
    findCheapestPrice(n, flights, src, dst, k);
}
exports.sfwks = sfwks;
