use std::any::{Any, type_name};

/*
  downcasting -> dynamic making concrete
  &dyn any
*/

#[derive(Debug)]
struct MyType;

fn get_type_name<T: Any>(_: T) {
  let typeof_t = type_name::<T>();
  println!("{typeof_t}");
}

fn get_type_name2<T: Any, U: Any>(_: T, _: U) {
  let typeof_t = type_name::<T>();
  let typeof_u = type_name::<U>();
  println!("T: {typeof_t}, U: {typeof_u}");
}

fn do_stuff_depending(input: &dyn Any) { // trait object
  if input.is::<String>() {
    println!("We got a String");
  } else if input.is::<i32>() {
    println!("We have a number");
  } else if input.is::<MyType>() {
    println!("We have a MyType");
  } else {
    println!("Don't know what it is");
  }
}

fn try_do_get_string(input: &dyn Any) { // trait object
  if let Some(a_string) = input.downcast_ref::<String>() {
    println!("We got a String. {a_string}");
  } else if let Some(a_int) = input.downcast_ref::<i32>() {
    println!("We have a number. {a_int}");
  } else if let Some(a_my_type) = input.downcast_ref::<MyType>() {
    println!("We have a MyType. {:?}", a_my_type);
  }
}

pub fn any_trait() {
  // get_type_name(1); // i32
  // get_type_name("1"); // &str
  // get_type_name("1".to_string()); // alloc::string::String
  // get_type_name(vec![1]); // alloc::vec::Vec<i32>
  // get_type_name(MyType); // rust::any_trait::MyType

  // get_type_name2(1, true);
  // get_type_name2(vec!['a'], MyType);

  // type matching
  // do_stuff_depending(&8);
  // do_stuff_depending(&String::from("I am a String"));
  // do_stuff_depending(&MyType);
  // do_stuff_depending(&"1");

  // 맞는 타입에 대한 내용을 얻을 수 있음
  // downcast
  try_do_get_string(&8);
  try_do_get_string(&String::from("I am a String"));
  try_do_get_string(&MyType);
}