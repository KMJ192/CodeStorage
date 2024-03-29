use std::thread;
use std::time::Duration;

fn simulated_expensive_calculation(intensity: u32) -> u32 {
  println!("calculating slowly...");
  thread::sleep(Duration::from_secs(2));
  intensity
}

fn generate_workout(intensity: u32, random_number: u32) {
  let expensive_result = simulated_expensive_calculation(intensity);

  let expensive_closure = |num: u32| {
    println!("calculating slowly...");
    thread::sleep(Duration::from_secs(2));
    num
  };

  let mut expensive_result = Cacher::new(|num| {
    println!("calculating slowly...");
    thread::sleep(Duration::from_secs(2));
    num
  });

  if intensity < 25 {
      println!(
          "Today, do {} pushups!",
          expensive_result.value(intensity)
      );
      println!(
          "Next, do {} situps!",
          expensive_result.value(intensity)
      );
  } else {
      if random_number == 3 {
          println!("Take a break today! Remember to stay hydrated!");
      } else {
          println!(
              "Today, run for {} minutes!",
              expensive_result.value(intensity)
          );
      }
  }
}

struct Cacher<T> where T: Fn(u32) -> u32 {
  calculation: T,
  value: Option<u32>,
}

impl<T> Cacher<T> where T: Fn(u32) -> u32 {
  fn new(calculation: T) -> Cacher<T> {
    Cacher { 
      calculation, 
      value: None 
    }
  }

  fn value(&mut self, arg: u32) -> u32 {
    match self.value {
      Some(v) => v,
      None => {
        let v = (self.calculation)(arg);
        self.value = Some(v);
        v
      }
    }
  }
}

fn add(first: i32) -> impl Fn(i32) -> Box<dyn Fn(i32) -> Box<dyn Fn(i32) -> i32>>  {
  return move |second: i32| {
    Box::new(move |third: i32| {
      Box::new(move |forth: i32| {
        first + second + third + forth
      })
    })
  }
}

pub fn closure_run() {
  // let simulated_user_specified_value = 10;
  // let simulated_random_number = 7;

  // generate_workout(
  //   simulated_user_specified_value,
  //   simulated_random_number
  // );
  let add1 = add(1);
  let add2 = add1(2);
  let add3 = add2(3);
  let add4 = add3(4);
  println!("{}", add4);
}