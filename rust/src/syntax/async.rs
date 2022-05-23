use tokio;
use std::time;

fn sleep(duration: u64) {
  std::thread::sleep(time::Duration::from_millis(duration));
}

async fn give_data() -> u8 {
  sleep(1000);
  8
}

async fn give_data_again() -> u8 {
  sleep(1000);
  7
}

#[tokio::main]
pub async fn async_fn() {
  let now = time::Instant::now();

  let number_one = give_data().await;
  let number_two = give_data_again().await;

  println!("{:?}", now.elapsed());
}