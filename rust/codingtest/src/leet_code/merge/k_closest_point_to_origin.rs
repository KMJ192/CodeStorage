struct Solution;

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, mut k: i32) -> Vec<Vec<i32>> {
        let mut answer = Vec::new();
        if k == 0 { return answer; }
        let mut check = Vec::new();

        for i in 0..points.len(){
            let (mut x, mut y) = (0, 0);
            if points[i][0] < 0 { x = -points[i][0]; }
            else { x = points[i][0]; }
            if points[i][1] < 0 { y = -points[i][1]; }
            else { y = points[i][1]; }
            let result = x.pow(2) + y.pow(2);
            check.push((result, vec![points[i][0], points[i][1]]));
        }
        check.sort();
        for i in 0..k{
            answer.push(check[i as usize].1.to_owned());
        }
        println!("{:?}", check);
        println!("{:?}", answer);
        answer
    }
}

pub fn run(){
    // let points = vec![
    //     vec![1, 3],
    //     vec![-2, 2]
    // ];
    let points = vec![
        vec![3, 3],
        vec![5, -1],
        vec![-2, 4]
    ];
    Solution::k_closest(points, 2);
}