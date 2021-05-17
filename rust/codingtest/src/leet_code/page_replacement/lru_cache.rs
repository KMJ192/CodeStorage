struct LRUCache {

}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    fn new(capacity: i32) -> Self {

    }

    fn get(&self, key: i32) -> i32 {
        1
    }

    fn put(&self, key: i32, value: i32) {

    }
}

pub fn run(){
    let obj = LRUCache::new(capacity);
    let ret_1: i32 = obj.get(key);
    obj.put(key, value);
}