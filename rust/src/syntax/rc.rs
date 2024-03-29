/*
  Rc - Reference Couter
  소유권의 숫자를 가지고 있음.
  
  Python과 같은 언어에서의 GC는 Rust의 Rc<dyn Any>와 같은 형태

  Rc<RefCell> // 
  Arc<Mutex> // thread가 여러 개 있고 이를 카운팅 하는 형태, Atomic Reference Coutner
*/
use std::rc::Rc;

struct MyStruct {

}


impl MyStruct {
  fn new_uninit(&self) {

  }
}

fn takes_a_string(input: Rc<String>) {
  println!("{input}");
}

fn also_takes_a_string(input: Rc<String>) {
  println!("{input}");
}

struct City {
  name: String,
  population: u32,
  history: Rc<String>,
}

#[derive(Debug)]
struct CityData {
  names: Vec<String>,
  histories: Vec<Rc<String>>
}

pub fn rc() {
  // let my_string = "Hello there".to_string();
  // takes_a_string(my_string.clone());
  // also_takes_a_string(my_string);

  let my_string = Rc::new("Hello there".to_string());
  takes_a_string(my_string.clone()); // Rc의 clone으로 동작을 하지만 코드를 보기가 어려울 수 있다.
  takes_a_string(Rc::clone(&my_string)); // Associated function syntax, rc rust fully qualified
  also_takes_a_string(Rc::clone(&my_string));

  let calgary = City {
    name: "Calgary".to_string(),
    population: 1_336_000,
    history: Rc::new("history".to_string()),
  };

  let canada_cities =CityData {
    names: vec![calgary.name],
    histories: vec![Rc::clone(&calgary.history)]
  };

  println!("Calgary's history is: {}", calgary.history);

  // strong_count
  // 소유권자가 하나라도 있다면 Rc drop을 할 수 없도록 함.
  println!("Data has {} owners", Rc::strong_count(&calgary.history));

  // weak_count
  // 소유권자가 있더라고 Rc drop을 할 수 있도록 함.
  println!("Data has {} owners", Rc::weak_count(&calgary.history));
}