use std::borrow::Cow;

/*
Cow -> Clone On Write
빌려진 값 또는 소유된 값을 표현할 수 있는 enum, 변경이 있을때만 복사와 소유가 일어나는 스마트 포인터
~일수도 있고 ~가 아닐 수도 있음
어떤 타입일수도 있고, 어떤 타입이 아닐수도 있음
Borrowed type, Owned type 2가지를 가진다.
Cow는 reference와 value 2개를 encapsulate 하므로, 어떤 함수가 reference와 value 모두 받고 싶다면 유용하게 사용할 수 있음
pub enum Cow<'a, B: ?Sized + 'a> where B: ToOwned {
  /// Borrowed data.
  #[stable(feature = "rust1", since = "1.0.0")]
  Borrowed(#[stable(feature = "rust1", since = "1.0.0")] &'a B),
  /// Owned data.
  #[stable(feature = "rust1", since = "1.0.0")]
  Owned(#[stable(feature = "rust1", since = "1.0.0")] <B as ToOwned>::Owned),
}
*/

fn modulo_3(input: u8) -> Cow<'static, str> {
  match input % 3 {
    0 => "0".into(),
    1 => "1".into(),
    remainder => format!("{remainder}").into(),
  }
}

pub fn cow() {
  for number in 1..=6 {
    print!("{} % 3 : ", number);
    match modulo_3(number) {
      Cow::Borrowed(message) => println!("The Cow is borrowed {message}"),
      Cow::Owned(message) => println!("The Cow is owned with {message}")
    }
  }
}