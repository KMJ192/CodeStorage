use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut q : VecDeque<(i32, i32)> = VecDeque::new();
        let mut _loop : i32 = 0;
        //println!("0 번째");
        for i in 0..grid.len(){
            for j in 0..grid[i].len(){
                //print!("{} ", grid[i][j]);
                if grid[i][j] == 2{
                    q.push_back((i as i32, j as i32));
                    _loop += 1;
                }
            }
            //println!();
        }
        let mut min : i32 = 0;
        while !q.is_empty() {
            let mut tmp  = vec![];
            //println!("{} 번째", min + 1);
            while let Some(p) = q.pop_front() {
                let t = [p.0 as usize, p.1 as usize];
                if t[0] > 0 && grid[t[0] - 1][t[1]] == 1{
                    grid[t[0] - 1][t[1]] = 2;
                    tmp.push((p.0 - 1, p.1));
                }
                if t[0] < grid.len() - 1 && grid[t[0] + 1][t[1]] == 1{
                    grid[t[0] + 1][t[1]] = 2;
                    tmp.push((p.0 + 1, p.1));
                }
                if t[1] > 0 && grid[t[0]][t[1] - 1] == 1{
                    grid[t[0]][t[1] - 1] = 2;
                    tmp.push((p.0, p.1 - 1));
                }
                if t[1] < grid[t[0]].len() - 1 && grid[t[0]][t[1] + 1] == 1{
                    grid[t[0]][t[1] + 1] = 2;
                    tmp.push((p.0, p.1 + 1));
                }
            };
            if !tmp.is_empty() {
                min += 1;
                //println!("{:?}", tmp);
                for p in tmp{
                    q.push_back(p)
                }
            }
        }
        for i in 0..grid.len() {
            for j in 0..grid[i].len(){
                if grid[i][j] == 1 {
                    return -1
                }
            }
        }
        min
    }
}
pub fn run(){

    let grid: Vec<Vec<i32>> = vec![
        vec![2, 1, 1],
        vec![1, 1, 0],
        vec![0, 1, 1]
    ];

    println!("{}", Solution::oranges_rotting(grid));
}
