// #[path="./syntax/async.rs"] mod async_fn;
// #[path="./base_algorithm/page_replacement/lfu_cache.rs"] mod lfu_cache;

pub mod thread;
use thread::thread;

fn main() {
  thread();
}