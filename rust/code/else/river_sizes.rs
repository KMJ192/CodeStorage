// you're given a two-dimensional array(a matrix) of potentially unequal height and width containing only 0s and 1s.
// Each 0 represents land, and each 1 represents part of a river.
// A river consists of any number of 1s that are either horizontally or vertically adjacent.
// (but not diagonally adjacent). The number of adjacent 1s forming a river determine its size.
// Not that a river can twist. In other words, it dosen't have to be a straight vertical line or a straight horizontal line;
// it can be L-shaped, for example.
// Write a function that returns an array of the sizes of all rivers represented in the input matrix. the sizes don't need to be in any particular order.

//0, 1로 이루어진 2차원배열
//0땅 1강

// input :
// [
//     [1, 0, 0, 1, 0]
//     [1, 0, 1, 0, 0]
//     [0, 0, 1, 0, 1]
//     [1, 0, 1, 0, 1]
//     [1, 0, 1, 1, 0]
// ]
// output : [1, 2, 2, 2, 5]
// constraint:
// edge case : none array
// algorithm : dfs
// ds :
// code
// time
//  - O(n)
// space
//  - O(n*m)
// c++ int long long long
//

fn dfs(array: &mut Vec<Vec<i32>>, visited: &mut Vec<Vec<i32>>, (pos1, pos2): (usize, usize), mut count: i32) -> i32{
    visited[pos1][pos2] = 2;
    if array[pos1][pos2] == 0 {
        //return;
    }
    // 상
    if pos1 - 1 > 0 && array[pos1-1][pos2] == 1 {
        dfs(array, visited, (pos1-1, pos2), count);
    }
    //하
    if pos1 + 1 < array.len() - 1 && array[pos1+1][pos2] == 1{
        dfs(array, visited, (pos1+1, pos2), count);
    }
    //좌
    if pos2 - 1 > 0 && array[pos1][pos2-1] == 1{
        dfs(array, visited, (pos1, pos2-1), count);
    }
    //우
    if pos2 + 1 < array[pos1].len() - 1{
        dfs(array, visited, (pos1, pos2+1), count);
    }

    0
}

fn solution(array: &mut Vec<Vec<i32>>) -> Vec<i32>{
    let mut result = Vec::new();
    let mut visited = array.clone();
    for i in 0..array.len() {
        if visited[1][0] == 2 { continue; }
        let count = dfs(array, &mut visited, (i, 0), 0);
        result.push(count);
    }

    result
}

pub fn run(){
    let mut array= vec![
        vec![1, 0, 0, 1, 0],
        vec![1, 0, 1, 0, 0],
        vec![0, 0, 1, 0, 1],
        vec![1, 0, 1, 0, 1],
        vec![1, 0, 1, 1, 0]
    ];
    solution(&mut array);
}
