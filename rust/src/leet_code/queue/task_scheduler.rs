use std::collections::HashMap;
use std::cmp::max;

struct Solution;

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        if n == 0 { return tasks.len() as i32; }
        let mut max_task = 0;
        let m = tasks.len();
        let mut numpeak = 0;
        let mut task = HashMap::new();
        for c in tasks.iter(){
            if task.contains_key(c){
                //println!("{}", task[c]);
                *task.get_mut(c).unwrap() += 1;
            }else{
                task.insert(c, 1);
            }
            max_task = max(max_task,task[c]);
        }
        for c in task.iter(){
            //println!("{:?}", c.1);
            if *c.1 == max_task {
                numpeak += 1;
            }
        }

        max(m as i32, (max_task - 1) * (n + 1) + numpeak)
    }
}

pub fn run(){
    let task : Vec<char> = vec![ 'A', 'A', 'A', 'B', 'B', 'B'];
    println!("{}", Solution::least_interval(task, 2));
}