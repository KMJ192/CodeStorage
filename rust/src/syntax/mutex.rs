/*
 Mutex
 Mutual Exclusion

 Arc
 Atomic Reference Counter
*/

// use std::cell::RefCell;
use std::thread;
use std::sync::{Mutex, Arc};


trait CoolTrait {
  fn cool_function(&self);
}

#[derive(Debug)]
struct OurStruct {
  // data: RefCell<u8>,
  // thread safe
  data: Arc<Mutex<u8>>,
}

impl CoolTrait for OurStruct {
  fn cool_function(&self) {
    // *self.data.borrow_mut() += 1;
    let lock = self.data.lock().unwrap();
    drop(lock);
    *self.data.lock().unwrap() += 1;
  }
}

pub fn mutex() {
  let our_struct = OurStruct {
    // data: RefCell::new(0)
    data: Arc::new(Mutex::new(0)),
  };

  let mut join_vec = vec![];
  for _ in 0..10 {
    let clone = Arc::clone(&our_struct.data);
    // life time issue가 있으므로 Arc로 clone
    let join_handle = thread::spawn(move || { //// 클로저가 가능한 레퍼런스를 사용하도록 함, take by value,
      // *our_struct.data.borrow_mut() += 1;
      // *our_struct.data.lock().unwrap() += 1;
      *clone.lock().unwrap() += 1;
      println!("{}", Arc::strong_count(&clone));
    });
    join_vec.push(join_handle);
  }

  for handle in join_vec {
    handle.join().unwrap();
  }

  println!("{our_struct:?}"); // -> OurStruct { data: Mutex { data: 10, poisoned: false, .. } }
  // poisoned => mutex에서 오염이 발생한 경우
}