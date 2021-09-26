/*
    소행성 충돌 결과 return
    배열의 원소는 각각의 소행성
    원소가 양수 => 우향
    원소가 음수 => 좌향
    absolute value는 소행성의 크기를 나타냄
    같은 방향으로 이동하는 소행성은 마주치지 않음
    크기가 작은 소행성은 충돌하면 작은 소행성이 소멸
    크기가 같은 소행성끼리 충돌하면 둘다 소멸

    input
     => 1D-array
    output
     => 1D-array

     //충돌 조건
     //이전 원소가 음수이고 현재 원소가 양수이면 만나지 않음
     //이전 원소가 양수이고 현재 원소가 음수이면 만남
*/
use std::borrow::BorrowMut;

struct Solution;
impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        //base case 1
        if asteroids.len() == 2{
            if asteroids[0] + asteroids[1] == 0 { return vec![]; } //둘다 소멸
            if asteroids[0] > 0 && asteroids[1] > 0 { return asteroids; } //만나지 않는 경우1
            if asteroids[0] < 0 && asteroids[1] < 0 { return asteroids; } //만나지 않는 경우2
            if asteroids[0] < asteroids[1] { return vec![asteroids[0]]; } //0번째만 소멸
            if asteroids[0] > asteroids[1] { return vec![asteroids[1]]; } //1번째만 소멸
        }

        let mut pointer = 0;
        let mut prev = 0;
        let mut cur_ast = &asteroids[..];

        //이전 원소가 양수이고 현재 원소가 음수이면 만남
        // while pointer < cur_ast.len(){
        //     if pointer == 0 {
        //         prev = cur_ast[0];
        //     }else{
        //
        //     }
        //     pointer += 1;
        // }

        vec![]
    }
}

pub fn run(){
    //let asteroids = vec![10, 2, -5];
    //let asteroids = vec![-2,-1,1,2];
    //println!("{:?}", Solution::asteroid_collision(asteroids));

    let mut king_tmp = vec![1, 2, 3, 4, 5, 6,7];
    //let tmp1 = &king_tmp.drain(0..2);
    let mut tmp1 = &king_tmp[0..1];
    let mut tmp2 = &king_tmp[2..5];
    let cur_tmp = tmp1.join(tmp2);
    // println!("{:?}", tmp1);
    // println!("{:?}", tmp2);
    println!("{:?}", cur_tmp);

}
