use std::borrow::Cow;

struct User<'a> {
  name: Cow<'a, str>,
}

// cow
pub fn cow2() {

  // string을 만드는 방법
  // let string_1 = String::from("Hello"); // From trait
  // let string_2 = "Hello".to_string(); // Display trait
  // let string_3: String = "Hello".into(); // From
  // let string_4 = "Hello".to_owned(); // ToOwned trait : str -> String

  // println!("{} {} {} {}", string_1, string_2, string_3, string_4);

  let name_1 = "User1";
  let name_2 = "User2";

  let user_1 = User {
    name: name_1.into()
  };

  let user_2 = User {
    name: name_2.into()
  };

}