use std::fmt::Display;

#[derive(Debug)]
struct Book<'a> {
  name: &'a str,
}

fn print_thing<T: Display>(input: T) {
  
}

pub fn life_time() {
  let my_book = Book {
    name: "my book"
  };

  println!("{:?}", my_book);
}
