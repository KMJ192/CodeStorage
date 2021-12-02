fn solution(array: &mut Vec<i32>) -> Vec<i32>{
    let mut result: Vec<i32> = Vec::new();
    result.push(array[0]);
    result.push(array[1]);
    result.push(array[2]);
    result.sort();

    for i in 3..array.len(){
        if array[i] > result[0] {
            result[0] = array[i];
            result.sort();
        }
    }
    result
}

pub fn run(){
    let mut array = vec![1411, 31, 17, 27, -17, -27,  18, 541, 8, 7, 7];
    println!("{:?}", solution(&mut array));
}