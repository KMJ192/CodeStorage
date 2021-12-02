use std::collections::HashSet;

struct Solution;
impl Solution {
    pub fn intersection(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> Vec<i32> {
        let mut answer = Vec::new();
        for n1 in nums1.iter(){
            for n2 in nums2.iter(){
                if n1 == n2 { answer.push(*n1) };
            }
        }
        Self::remove_duplicates(&mut answer);
        answer
    }
    fn remove_duplicates(input : &mut Vec<i32>){
        let set : HashSet<i32> = input.drain(..).collect();
        input.extend(set.into_iter());
    }
}

pub fn run(){
    let nums1 = vec![1,2,2,1];
    let nums2 = vec![2,2];

    println!("{:?}", Solution::intersection(nums1, nums2));
}