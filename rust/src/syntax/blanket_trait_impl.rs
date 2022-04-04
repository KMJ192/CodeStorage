// implementing a trait for every type that you want to have it

use std::fmt::Debug;

trait Prints: Debug{
  fn prints_something(&self) {
    println!("I am {:?}", self);
  }
}

#[derive(Debug)]
struct Person;
#[derive(Debug)]
struct Building;

impl<T: Debug> Prints for T {}

pub fn blanket_trait_impl() {
  let my_person = Person;
  let my_building = Building;
  my_person.prints_something();
  my_building.prints_something();
}