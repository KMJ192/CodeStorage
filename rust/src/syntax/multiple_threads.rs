use std::thread;

pub fn multiple_threads() {
  // https://doc.rust-lang.org/stable/std/thread/struct.JoinHandle.html
  let join_handle = thread::spawn(|| {
    println!("thread");
  });

  // thread wait
  join_handle.join().unwrap();

  let mut join_vec = vec![];
  for _ in 0..10 {
    let handle = thread::spawn(|| {
      println!("printing somthing");
    });
    join_vec.push(handle);
  }
  join_vec.into_iter().for_each(|handle| handle.join().unwrap());
}