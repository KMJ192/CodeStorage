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
  let debug = format!("{:?}", v);
  println!("{}", debug);
  // let s = print_to_string!(v);
}

pub fn run() {
  learn_macro();
}