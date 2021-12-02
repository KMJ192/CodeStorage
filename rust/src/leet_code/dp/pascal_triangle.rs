/*
    input: 5
    output: [
                [1],
               [1,1],
              [1,2,1],
             [1,3,3,1],
            [1,4,6,4,1]
          ]

  n번째 배열은 n+1의 길이를 가진다.
  0번째와 n번째는 항상 1
  이전 배열의 정보를 가지고 배열을 조립
   -> 현재 배열의 0
*/

struct Solution;
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        if num_rows == 1 { return vec![vec![1]]; }

        let mut ret_val: Vec<Vec<i32>> = vec![];

        for i in 0..num_rows {
            let mut cur_arr: Vec<i32> = vec![1; (i+1) as usize];
            ret_val.push(cur_arr);
            if i == 0 || i == 1 { continue; }

            for j in 0..ret_val[i as usize].len() as i32 {
                if j == 0 || j == (ret_val[i as usize].len() - 1) as i32 { continue; }
                //ret_val[i-1]에서 데이터를 가져온다.
                //1번째는 0, 1
                //2번째는 1, 2
                //3번째는 2, 3
                ret_val[i as usize][j as usize] = ret_val[(i - 1) as usize][(j - 1) as usize] + ret_val[(i - 1) as usize][j as usize];
            }
        }
        ret_val
    }
}

pub fn run(){

    //Solution::generate(5);
    println!("{:?}", Solution::generate(5));
}
