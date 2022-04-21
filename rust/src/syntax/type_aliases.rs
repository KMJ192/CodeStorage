// type aliases
// alias = different name

use std::iter::Skip;

type SkipAndTake = std::iter::Take<Skip<std::vec::IntoIter<char>>>;

struct SomeType {
  name: String,
  number: u8,
}

fn return_an_iter(input: Vec<char>) -> SkipAndTake {
  input.into_iter().skip(5).take(5)
}

fn some_function(input: SomeType) -> Vec<SomeType> {
  todo!();
}

pub fn type_alias() {
  // let tmp = return_an_iter(vec!['1', '2', '3', '4', '5', '6']);
  // println!("{:?}", tmp);

  some_function(SomeType {
    name: String::from("some"),
    number: 1,
  });

}