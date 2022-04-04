fn return_it() -> &'static String {
  let country = String::from("대한민국");
  &country // local 참조변수 이므로  return &String은 불가능
}

pub fn reference() {
  let country = String::from("대한민국");
  let ref_one = &country;
  let ref_two = &country;
  println!("Country is {}", country);
}