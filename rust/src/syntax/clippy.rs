// clippy 문법을 더 나은 방법으로 작성할 수 있도록 도와줌
fn print_vec_ref(input: &Vec<i32>) {
  // if input.len() == 0 {
  if input.is_empty() {
    println!("Vec is empty");
  } else {
    // for num in input {
    //   println!("{num}");
    // }
    input.iter().for_each(|num| println!("{num}") );
  }
}

pub fn clippy() {
  let my_vec = vec![3, 4, 5];
  print_vec_ref(&my_vec);

  let mut done = false;
  let mut counter = 0;

  // while done == false {
  while !done {
    counter += 1;
    if counter > 10 {
      done = true;
    }
  }

  let some_variable = Some(9);
  // match some_variable {
  //   Some(number) => println!("We got a {number}"),
  //   _ => {}
  // }
  if let Some(number) = some_variable {
    println!("We got a {number}");
  }
}