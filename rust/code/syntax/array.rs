pub fn run(){
    let arr = [0, 1, 2, 3];
    let compare = 1;
    //arg와 배열의 길이를 비교하여 반환
    let n = arr.len().min(compare);
    println!("{}", n);
    let n = arr.len().max(compare);
    println!("{}", n);

    //will task
    //enumerate method 추가
    //scan method 추가
}