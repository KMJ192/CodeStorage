use std::fmt::Display;

#[derive(Debug)]
struct Book<'a> {
  name: &'a str,
}

struct Adventurer<'a> {
  name: &'a str,
  hit_points: u32,
}

impl Adventurer<'_> {
  fn take_damage(&mut self) {
    self.hit_points -= 20;
    println!("{} has {} hit points left!", self.name, self.hit_points);
  }
}

pub fn life_time() {
  let my_book = Book {
    name: "my book"
  };

  println!("{:?}", my_book);
}
