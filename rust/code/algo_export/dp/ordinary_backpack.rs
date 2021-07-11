/*
    input
     - 2차원 배열이 주어진다
     - 배열의 각 원소의 첫번째 원소는 value, 두번째 원소는 weight
    output
     - 1번째 원소에 총중량을, 2번째 원소에 더한값의 index 를 넣는다.

    solution
     - dp solution
    // dp_table
    // horizontal : max capacity
    // vertical : items count
    // weight < capacity 일때 value 를 배열에 담는다.
    // [i-1]의 value + [i]의 value 를 담는다.

    // [value, weight]
    items
             0  1  2  3  4  5  6  7  8  9  10 => capacity
    [1,2] : [0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    [4,3] : [0, 0, 1, 4, 4, 5, 5, 5, 5, 5, 5]
    [5,6] : [0, 0, 1, 4, 4, 5, 5, 5, 6, 9, 9]
    [6,7] : [0, 0, 1, 4, 4, 5, 5, 6, 6, 9, 10]

    back tracking
    1. dp[i][j], dp[i-1][j]비교 같은지(items[i]를 사용하지 않음) 다른지(items[i]를 사용)
    // step1 사용한 인덱스 => 3, 1
    // step2
        -> case1 items[i]를 사용한 인덱스 였다. j - items[i][1]
        -> case2 items[i]를 사용안했다. j
    back tracking sudo
      index배열
      i = items.length - 1
      j = capacity
      prev = dp[i][j]
      for i..0 {
        if i == 0 && dp[i][j] != 0{
            index.push(i);
            continue;
        }
        if prev != dp[i-1][j] {
           index.push(i)
           //case1
           j = j - items[i][1]
        }else{
            //case2
            //j 그대로
        }
      }

    memorization // dp table

    패턴이 작동하는 방식 => dp[i][j]의 의미
    items를 0 ~ i 까지 가지고 있다.
    capacity 는 j
    같은 로직으로 다른 조건(i, j)을 모두 구할 수 있는 패턴 => dynamic programing

    // i => items의 index, j = capacity
    // i가 1일때 items[i][0]을 넣어주는 패턴이 => 넣는지 않넣는지 (value가 더 크게 나올것)
    //   => 넣을때 4 + 0 =>
    // Math.max(dp[i-1][j], dp[i-1][j - items[i][1]] + items[i][0])

    //base case
    //1. dp 테이블을 만든다, i가 0일때는 items[i][1] <= j dp[i][j] = items[i][0]
    //2. if j >= items[i][1] { dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j - items[i][1]] + items[i][0]) }
         else { dp[i][j] = dp[i-1][j]; }
    //3. 1, 2으로 dp테이블이 완성
    //4. back tracking => items의 i를 사용했다는것을 체크 index값을 알수있다.
*/
use std::cmp;

#[derive(Debug)]
struct ResultType {
    weight: i32,
    index: Vec<i32>
}

fn solution(items: Vec<Vec<i32>>, capacity: i32) -> ResultType{
    let mut ret_val = ResultType {
        weight: 0,
        index: vec![]
    };
    if items.len() == 0 { return ret_val; }

    let mut dp = vec![vec![0; capacity as usize + 1]; items.len()];

    for i in 0..items.len(){
        for j in 0..capacity as usize + 1{
            //1.
            if i == 0 {
                if items[i][1] <= j as i32 {
                    dp[i][j] = items[i][0];
                }
            } else {
                //2.
                if j >= items[i][1] as usize {
                    dp[i][j] = cmp::max(dp[i-1][j], dp[i-1][j - items[i][1] as usize] + items[i][0]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    for i in 0..dp.len(){
        println!("{:?}", dp[i]);
    }

    //ret_val.index 배열
    let mut j = capacity as usize;
    for i in (0..items.len()).rev(){
        if i == 0 {
            if dp[i][j] != 0 {
                ret_val.index.push(i as i32);
            }
            break;
        }
        if dp[i][j] != dp[i -1][j] {
            ret_val.index.push(i as i32);
            j = j - items[i][1] as usize;
        }
    }

    ret_val.weight = dp[items.len() - 1][capacity as usize];
    ret_val.index.reverse();
    ret_val
}

pub fn ordinary_backpack(){
    let items = vec![
        vec![1, 2],
        vec![4, 3],
        vec![5, 6],
        vec![6, 7]
    ];
    //solution(items, 10);
    println!("{:#?}", solution(items, 10));

    //println!("{}", cmp::max(4,2));
}