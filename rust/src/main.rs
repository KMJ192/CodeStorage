// #[path="./syntax/async.rs"] mod async_fn;
#[path="./base_algorithm/page_replacement/lfu_cache.rs"] mod lfu_cache;

fn main() {
  lfu_cache::run();
}