// use std::cell::Cell;

// runtime check borrowing rules
use std::{cell::RefCell, borrow::Borrow};

#[derive(Debug)]
struct User {
  id: u32,
  year_registered: u32,
  username: String,
  active: RefCell<bool>
}

pub fn ref_cell() {
  // let my_cell = Cell::new(String::from("I am a String"));
  // my_cell.set(String::from("I am a String?!?!?!?!"));
  // println!("{my_cell:?}"); // Debug x
  // let my_string = my_cell.into_inner();
  // println!("{my_string}");

  let user_1 = User {
    id: 1,
    year_registered: 2022,
    username: "User 1".to_string(),
    active: RefCell::new(true)
  };

  let mut first_reference = user_1.active.borrow_mut();
  // let second_reference = user_1.active.borrow_mut(); // runtime에서 체크하므로 cargo run 이후 panic 발생
  println!("{first_reference}");
  // println!("{second_reference:?}");
  println!("{user_1:?}");
  /*
    first_reference에서 빌려갔으므로 active는 borrowed 상태
    User { 
      id: 1, 
      year_registered: 2022, 
      username: "User 1", 
      active: RefCell { value: <borrowed> },
    }
   */ 

  *first_reference = false;
  println!("{user_1:?}"); // 여전히 빌린 값이므로 active는 borrowed 상태

  drop(first_reference); // 빌림 해제

  println!("{user_1:?}"); // 빌림이 해제되었으므로 active값은 출력됨
}