use std::borrow::{BorrowMut, Borrow};

struct Solution;

impl Solution {
    pub fn rotate(mut matrix: &mut Vec<Vec<i32>>) {
        let mut v : Vec<Vec<i32>> = matrix.clone();
        let n = matrix.len();

        for i in 0..n{
            for j in 0..n{
                matrix[i][n - 1 - j] = v[j][i];
            }
        }
        println!("{:?}", matrix);
    }
}

pub fn run(){
    let mut matrix = vec![
        vec![5,1,9,11],
        vec![2,4,8,10],
        vec![13,3,6,7],
        vec![15,14,12,16]
    ];
    //let mut matrix = vec![vec![1]];
    Solution::rotate(&mut matrix);
}