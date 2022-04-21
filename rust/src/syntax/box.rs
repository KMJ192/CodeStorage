// owned data on the heap

struct SomeStruct {
  name: String,
  number: u8,
  data: Box<[u8; 10000]>,
}

pub fn _box() {
  let my_struct = SomeStruct {
    name: "Hey there".to_string(),
    number: 0,
    data: Box::new([9; 10000])
  };

  // Box를 이용할 경우 40byte, 아닐 경우 10032bytes
  // println!("The struct is {} bytes", std::mem::size_of_val(&my_struct));
  let my_box = Box::new(9);
  println!("{my_box}");
  println!("{}", *my_box);
}