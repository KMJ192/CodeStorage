struct Solution;



impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        use std::collections::VecDeque;
        let mut q = VecDeque::<(i32, i32)>::new();
        println!("최초 상태");
        for i in 0..grid.len(){
            for j in 0..grid[i].len(){
                print!("{} ", grid[i][j]);
                if grid[i][j] == 2{
                    q.push_back((i as i32, j as i32));
                }
            }
            println!();
        }
        println!("{:?}", q.front());
        //let min : i32 = 0;
        // while !q.is_empty() {
        //     println!("{}번째", min + 1);
        //     let _loop : usize = q.len();
        //     grid = Self::change(&grid, (q.front().0, q.front().1 ));
        // }
        1
    }
    fn change(grid : &mut Vec<Vec<i32>>, pos : (usize, usize)) -> &mut Vec<Vec<i32>> {
        if pos.0 > 0{
            if grid[pos.0 - 1][pos.1] == 1 {
                grid[pos.0 - 1][pos.1] = 2;

            }
        }
        if pos.0 < grid.len() - 1{
            if grid[pos.0 + 1][pos.1] == 1 {
                grid[pos.0 + 1][pos.1] = 2;

            }
        }
        if pos.1 > 0 {
            if grid[pos.0][pos.1 - 1] == 1 {
                grid[pos.0][pos.1 - 1] = 2;

            }
        }
        if pos.1 < grid.len() - 1{
            if grid[pos.0][pos.1 + 1] == 1 {
                grid[pos.0][pos.1 + 1] = 2;

            }
        }
        grid
    }
}
pub fn run(){
    // let tuple_of_tuples = (1u8, 2u16, 2u32);
    // println!("tuple of tuples: {}", tuple_of_tuples.0);

    let grid: Vec<Vec<i32>> = vec![
        vec![2, 1, 1],
        vec![1, 1, 0],
        vec![0, 1, 1]
    ];

    Solution::oranges_rotting(grid);
}