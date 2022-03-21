use std::num::ParseIntError;

fn parse_str(input: &str) -> Result<(), ParseIntError> {
  // let parsed_number = input.parse::<i32>();
  // parsed_number

  let parsed_number = input.parse::<i32>()?.to_string().parse::<u32>()?.to_string().parse::<i32>()?;
  println!("It worked! {}", parsed_number);
  Ok(())
}

pub fn optional() {
  for item in vec!["Test", "9", "9.0", "nice", "6666"] {
    parse_str(item);
  }
} 