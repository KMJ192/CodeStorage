use std::cmp::max;

#[derive(Debug)]
struct KnapsackProblem {
  capacity: i32,
  items: Vec<Vec<i32>>,
  dp_table: Vec<Vec<i32>>,
}

impl KnapsackProblem {
  pub fn new(capacity: i32, items: Vec<Vec<i32>>) -> Self {
    let item_cnt = items.len();
    KnapsackProblem {
      capacity,
      items,
      dp_table: vec![vec![0; capacity as usize + 1]; item_cnt + 1]
    }
  }

  fn back_tracking(&mut self) {
    let mut cur_capacity = self.capacity;
    let cnt = self.dp_table.len();
    
    let mut item = vec![];
    for i in (0..cnt).rev() {
      let mut weight= 0;
      let (mut now_dp_weight, mut prev_dp_weight) = (0, 0);
      if i != 0 {
        weight = self.items[i as usize - 1][1];
        now_dp_weight = self.dp_table[i][cur_capacity as usize];
        prev_dp_weight = self.dp_table[i - 1][cur_capacity as usize]
      }
      if now_dp_weight == prev_dp_weight {
        continue;
      }
      item.push(i - 1);
      cur_capacity = cur_capacity - weight;
      if cur_capacity < 0 { 
        break;
      }
    }
    item.reverse();
    println!("{:?}", item);
  }

/*
   v,  w   0  1   2   3   4   5
  [0,  0] [0, 0,  0,  0,  0,  0 ]
> [30, 1] [0, 30, 30, 30, 30, 30]
  [20, 2] [0, 30, 30, 50, 50, 50]
> [40, 3] [0, 30, 30, 50, 70, 70]
  [10, 4] [0, 30, 30, 50, 70, 70]
  [70, [30, 40]]
  // 위로 올라갔을 때 기존과 동일하면 그건 안쓴거
  // 썼을때는 capacity - item의 weight

   v, w    0  1  2  3  4  5
  [0, 0]  [0, 0, 0, 0, 0, 0]
> [3, 2]  [0, 0, 3, 3, 3, 3]
> [4, 3]  [0, 0, 3, 4, 4, 7]
  [5, 4]  [0, 0, 3, 4, 5, 7]
  [6, 5]  [0, 0, 3, 4, 5, 7]
  [7, [3, 4]]
*/

  fn make_table(&mut self) {
    for i in 1..self.dp_table.len() {
      let ele_len = self.dp_table[i].len();
      for cur_capacity in 1..ele_len {
        // self.item 0(i - 1)부터 확인
        let (value, weight) = (self.items[i - 1][0], self.items[i - 1][1]);
        let prev_value = self.dp_table[i - 1][cur_capacity];
        
        // 현재 value(dp_table에 넣을)에 cur_capacity >= item의 weight이면,
        // 현재 value를 item의 value + dp_table의 이전row, cur_capacity - weight의 value를 넣음
        let mut now_value = 0;
        if cur_capacity as i32 >= weight {
          now_value = value + self.dp_table[i - 1][cur_capacity - weight as usize];
        }

        // dp_table[i][cur_capacity] 에 이전 row의 value와 현재 row의 value 중 큰 값으로 갱신
        self.dp_table[i][cur_capacity] = max(prev_value, now_value);
      }
    }
  }

  pub fn algorithm_run (&mut self) {
    self.make_table();
    self.back_tracking();
    println!("{}", self.dp_table[self.dp_table.len() - 1][self.capacity as usize]);
  }
}

pub fn knapsack() {
  let capacity = 200;
  let items = vec![
    vec![465, 100],
    vec![400, 85],
    vec![255, 55],
    vec![350, 45],
    vec![650, 130],
    vec![1000, 190],
    vec![455, 100],
    vec![100, 25],
    vec![1200, 190],
    vec![320, 65],
    vec![750, 100],
    vec![50, 45],
    vec![550, 65],
    vec![100, 50],
    vec![600, 70],
    vec![255, 40]
  ];

  // let capacity = 5;
  // let items = vec![
  //   vec![3, 2],
  //   vec![4, 3],
  //   vec![5, 4],
  //   vec![6, 5],
  // ];

  // let items = vec! [
  //   vec![30, 1],
  //   vec![20, 2],
  //   vec![40, 3],
  //   vec![10, 4],
  // ];
  let mut knapsack_problem = KnapsackProblem::new(capacity, items);
  knapsack_problem.algorithm_run();
  
  // println!("{:?}", knapsack_problem);
}