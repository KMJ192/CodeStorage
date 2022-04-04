use std::fmt::Debug;

#[derive(Debug)]
struct Book {
  year: i32,
}

fn print_and_give_item<T: Debug>(input: T) -> T {
  println!("{:?}", input); //
  input
}

/*
  제너릭 타입
  generics <-> concrete
  It's a little generic
*/

pub fn generics() {
  let x = print_and_give_item(String::from("Take this thing"));
  let y = print_and_give_item(9);
  let z = print_and_give_item(Book { year: 2022 });
  println!("{} {}", x, y);
}