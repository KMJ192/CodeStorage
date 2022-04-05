/*
  zero cost abstraction
  비용이 들지 않는 추상화

  제네릭, 컬렉션 등 고급 프로그래밍 개념을 추가한것을 의미하며, 
  런타임 비용은 발생하지 않고
  단지 컴파일러 시간 비용만 발생
*/

pub fn zero_cost_abstractions() {

  let my_vec = vec![8, 9, 10];

  // 인덱스 범위를 넘어선 경우 예외처리
  let fourth = my_vec.get(3).unwrap_or_else(|| {
    // 0번째 인덱스가 있을 경우 else &0 return
    if my_vec.get(0).is_some() {
      &my_vec[0]
    } else {
      &0
    }
  });

  println!("{fourth}");

  // let my_number = 9;
  // let anoymouse_function = || println!("");
  // let closure = || println!("{my_number}");

  // .iter().map().filter().inspect().collect()
}