// You are given an m*n binary matrix grid. An island is a group of 1's (representing land) connected
// 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// An island is considered to be the same as another if and only if one island can be translated(and not rotated or reflected) to equal te other.
//
// Return te number of distinct islands

// m*n 이진 행렬 그리드가 제공됩니다. 섬은 연결된 1의 그룹입니다(땅)의 그룹입니다.
// 4방향(수평 또는 수직) 그리드의 네 모서리가 모두 물로 둘러싸여 있다고 가정할 수 있습니다.
//
// 한 섬을 서로 동일하게 변환(회전 또는 반사되지 않음)할 수 있는 경우에만 섬이 다른 섬과 동일한 것으로 간주됩니다.
//
// 고유 섬 개수 반환

/*
    1. recursion으로 2D Array를 순회한다.
    2. 시작점(0,0) 부터 1이 연결되어 있는 모든곳을 탐색한다.
    3. 탐색 순서
     - 상, 하, 좌, 우
     - 0, 1, 2, 3
    4. 탐색하며 탐색했던 정보를 담는다.
     - Hashmap의 배열에 담는다.
     - 한번 방문한 노드는 0으로 바꾼다.
    5. 2d array탐색을 마칠때 까지 반복한다.
    6. 탐색 정보를 비교한다.
*/

use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn number_of_distinct_island(grid: &mut Vec<Vec<i32>>) {
        let mut path: Vec<HashMap<(usize, usize), usize>>;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == 1 {
                    Solution::recursion(&mut path, (i, j), true);
                }
            }
        }
    }

    fn recursion(path: &mut Vec<HashMap<(usize, usize), usize>>, (x, y): (usize, usize), new_flag: bool) {
        println!("{} {} ", x, y);
    }
}

pub fn run() {
    let mut grid = vec![
        vec![1,1,0,0,0],
        vec![1,1,0,0,0],
        vec![0,0,0,1,1],
        vec![0,0,0,1,1],
    ];

    // let grid = vec![
    //     vec![1,1,0,1,1],
    //     vec![1,0,0,0,0],
    //     vec![0,0,0,0,1],
    //     vec![1,1,0,1,1],
    // ];

    Solution::number_of_distinct_island(&mut grid);
}
