/*
  Arc has more overhead
*/
use std::sync::{Mutex, RwLock};

pub fn mutex_with_rwlock() {
  let my_mutex = Mutex::new(5);
  
  let mut mutex_changer = my_mutex.lock().unwrap();

  // mutex_changer가 my_mutex를 lock하고 있고 컴파일 시도 시 time out이 발생한다.
  // try_lock으로 예외 처리할 수 있다.
  // let mut other_mutex_changer = my_mutex.lock().unwrap(); 
  let mut other_mutex_changer = my_mutex.try_lock(); 

  // if let Ok 으로 예외처리 가능
  if let Ok(value) = other_mutex_changer {
    println!("The mutexchanger has: {value}");
  } else {
    println!("Didn't get a lock");
  }

  // *myutex_changer = 6;
  // drop(mutex_changer);
  println!("{my_mutex:?}");

  let my_rwlock = RwLock::new(5);
  let read1 = my_rwlock.read().unwrap(); // read lock, reference와 같은 형태
  let read2 = my_rwlock.read().unwrap();

  println!("{read1:?}, {read2:?}");
}