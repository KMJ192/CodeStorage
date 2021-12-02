struct Solution;

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort();
        println!("{:?}", intervals);
        let mut answer : Vec<Vec<i32>> = Vec::new();
        let mut st = Vec::new();
        st.push(intervals[0][0]);
        st.push(intervals[0][1]);
        for i in 1..intervals.len(){
            println!("{} {}", st[1], intervals[i][0]);
            if st[1] >= intervals[i][0] {
                if intervals[i][1] > st[1]{ st[1] = intervals[i][1]; }
            }else{
                answer.push(st.to_owned());
                st.clear();
            }
            println!("{:?}", answer);
            if st.is_empty(){
                st.push(intervals[i][0]);
                st.push(intervals[i][1]);
            }
        }
        answer.push(st.to_owned());
        println!("{:?}", answer);
        answer
    }
}

pub fn run(){
    // let mut intervals = vec![
    //         vec![1,10],
    //         vec![2,3],
    //         vec![4,5],
    //         vec![6,7],
    //         vec![8,9]
    // ];
    // let mut intervals = vec![
    //     vec![1,4],
    //     vec![5,6]
    // ];
    // let intervals = vec![
    //     vec![1,3],
    //     vec![2,6],
    //     vec![8,10],
    //     vec![15,18],
    //     vec![16, 20]
    // ];
    // let intervals = vec![
    //     vec![1, 4],
    //     vec![2, 3],
    //     vec![4, 5]
    // ];
    let intervals = vec![
        vec![1, 4],
        vec![1, 4]
    ];
    Solution::merge(intervals);
}