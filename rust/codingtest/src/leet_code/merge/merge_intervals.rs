struct Solution;

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        println!("{:?}", intervals);
        intervals.sort();
        println!("{:?}", intervals);
        let mut answer : Vec<Vec<i32>> = Vec::new();
        let (mut x, mut y) = (0, 0);
        let mut visit_end = false;
        x = intervals[0][0];
        y = intervals[0][1];
        //two pointer
        let mut i : usize = 0;
        while !visit_end {
            //이전의 2번째 원소와 다음의 첫번째 원소 비교, 다음의 첫번째 원소가 더 크면 거기까지 짜른다
            if y < intervals[i][0]{
                let v = vec![x, y];
                y = intervals[i][1];
                answer.push(v);
                x = intervals[i][0];
                println!("{:?}", answer);
            }
            y = intervals[i][1];
            if i < intervals.len() - 1{
                i += 1;
            }
            if y == intervals[intervals.len() - 1][1]{
                visit_end = true;
            }
        }
        let v = vec![x, y];
        answer.push(v);

        println!("{:?}", answer);
        answer
    }
}

pub fn run(){
    let mut intervals = vec![
        vec![1,4],
        vec![2,3]
        //vec![5,6]
    ];
    // let intervals = vec![
    //     vec![1,3],
    //     vec![2,6],
    //     vec![8,10],
    //     vec![15,18]
    //     //vec![16, 20]
    // ];
    // let intervals = vec![
    //     vec![1, 4],
    //     vec![2, 3],
    //     vec![4, 5]
    // ];
    Solution::merge(intervals);
}