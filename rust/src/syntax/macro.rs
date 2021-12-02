#[macro_export]
macro_rules! vec {
  ($ ($x: expr), *) => {
    {
      let mut temp_vec = Vec::new();
      $(
        temp_vec.push($x);
      )* temp_vec
    }
  };
}

fn learn_macro() {
  let v = vec![1, 2, 3];
  println!("{:?}", v);
}

pub fn run() {
  learn_macro();
}