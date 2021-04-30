struct Solution;

impl Solution {
    fn dfs(node : usize, is_connected: &Vec<Vec<i32>>, visited: &mut Vec<i32>) {
        visited[node] = 1;
        for i in 0 .. is_connected[node].len(){
            //print!("{}", is_connected[node][i]);
            if is_connected[node][i] == 1 && visited[i] == 0 {
                Self::dfs(i, &is_connected, visited);
            }
        }
    }
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        let mut visited : Vec<i32> = vec![0; is_connected.len()];
        let mut answer : i32 = 0;
        for i in 0 .. is_connected.len(){
            if visited[i] == 0 {
                Self::dfs(i, &is_connected, &mut visited);
                answer += 1;
            }
            //println!();
        }
        answer
    }
}
pub fn run(){
    // let mut is_connected: Vec<Vec<i32>> = Vec::new();
    // is_connected.push(vec![1, 1, 0]);
    // is_connected.push(vec![1, 1, 0]);
    // is_connected.push(vec![0, 0, 1]);

    let is_connected : Vec<Vec<i32>> = vec![
        vec![1,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
        vec![0,1,0,1,0,0,0,0,0,0,0,0,0,1,0],
        vec![0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
        vec![0,1,0,1,0,0,0,1,0,0,0,1,0,0,0],
        vec![0,0,0,0,1,0,0,0,0,0,0,0,1,0,0],
        vec![0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],
        vec![0,0,0,0,0,0,1,0,0,0,0,0,0,0,0],
        vec![0,0,0,1,0,0,0,1,1,0,0,0,0,0,0],
        vec![0,0,0,0,0,0,0,1,1,0,0,0,0,0,0],
        vec![1,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
        vec![0,0,0,0,0,0,0,0,0,0,1,0,0,0,0],
        vec![0,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
        vec![0,0,0,0,1,0,0,0,0,0,0,0,1,0,0],
        vec![0,1,0,0,0,0,0,0,0,0,0,0,0,1,0],
        vec![0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
    ];

    println!("{}", Solution::find_circle_num(is_connected));
}