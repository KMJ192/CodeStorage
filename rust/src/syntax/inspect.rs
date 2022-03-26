/*
  inspect - Iterator trait에 소속
  passing the value on -> iterater에서 각 요소를 넘겨준다
  클로저를 param으로 넘겨준다
*/

pub fn inspect() {
  let new_vec = [8, 9, 10];
  let double_vec 
    = new_vec
      .iter()
      .inspect(|first_item| { 
        println!("{}", first_item);
      })
      .map(|x| x * 2)
      .inspect(|next_item| {
         dbg!(next_item);
      })
      .filter(|num| *num > 17)
      .inspect(|filtered_item| {
        println!("filtered {}", filtered_item);
      })
      .collect::<Vec<_>>();
}