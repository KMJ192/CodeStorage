/*
    11: 20 ~ 11: 50
    Input: 배열
    Output: boolean -> Player1 === win ? true : false
    DS : recursion
    Constraint
        1 <= nums.length <= 20
        0 <= nums[i] <= 10^7
    Edge Case

    Solution
    P1 P2
    P1 첫번째 선택, P2 두번째, 마지막
    P1 마지막 선택, P2 첫번째, len - 2번째
    ...
    P1 win true

    Time :
    Space :

*/

struct Solution;

impl Solution {
    pub fn predict_the_winner(nums: &Vec<i32>) -> bool {
        let mut dp = vec![
            vec![(0, 0); nums.len() + 1]
        ];
        for i in 1..=nums.len() {
            dp.push(vec![]);
            for j in 0..=nums.len() - i {
                let pick_left = dp[i - 1][j + 1];
                let pick_right = dp[i - 1][j];
                dp[i].push(
                if nums[j] + pick_left.1 - pick_right.0 > nums[j + i - 1] + pick_right.1 - pick_right.0 {
                          (nums[j] + pick_left.1, pick_left.0)
                      } else {
                          (nums[j + i - 1] + pick_left.1, pick_left.0)
                      }
                );
            }
        }
        println!("{:?}", dp.last().unwrap()[0]);
        let (p1, p2) = dp.last().unwrap()[0];
        p1 >= p2
    }
}

pub fn run() {
    let mut nums = vec![1,5,2];
    Solution::predict_the_winner(&nums);
}