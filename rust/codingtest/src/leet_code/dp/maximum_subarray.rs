struct Solution;

impl Solution {
    pub fn max_sub_array(mut nums: Vec<i32>) -> i32 {
        if nums.len() == 1 { return nums[0]; }
        else if nums.len() == 0 { return 0; }
        let mut max = nums[0];
        for i in 0..nums.len(){
            //정수배열, 배열의 position, 배열 내 원소의 더할갯수, 최대값
            Solution::dfs(&mut nums, i, 1, &mut max);
        }
        max
    }

    fn dfs(nums: &mut Vec<i32>, pos: usize, mut cnt : usize, max: &mut i32){
        //현재 위치값이 주어진 배열의 길이를 초과하면 return
        if cnt > nums.len(){ return; }

        let mut tmp = nums[pos];
        for i in pos+1..cnt {
            tmp += nums[i];
        }

        if tmp > *max { *max = tmp; }

        cnt += 1;
        Solution::dfs(nums, pos, cnt, max);
    }
}

pub fn run(){
    let v = vec![-2,1,-3,4,-1,2,1,-5,4];
    let answer = Solution::max_sub_array(v);
    println!("{}", answer);

    // for i in 0..2{
    //     println!("{}", i);
    // }

}