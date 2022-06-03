use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;

#[derive(Debug)]
struct DoublyLinkedListNode  {
	val: i32,
	prev: Option<Rc<RefCell<DoublyLinkedListNode>>>,
	next: Option<Rc<RefCell<DoublyLinkedListNode>>>,
}

impl DoublyLinkedListNode {
	fn new(val: i32) -> Self {
		DoublyLinkedListNode {
			val,
			prev: None,
			next: None,
		}
	}

	fn disconnect(&mut self) {
		if let Some(node) = &self.prev {
			node.borrow_mut().next = self.next.as_ref().map(|r| r.clone());
		}

		if let Some(node) = &self.next {
			node.borrow_mut().prev = self.prev.as_ref().map(|r| r.clone());
		}

		self.prev = None;
		self.next = None;
	}
}

// 빈도 저장 공간
#[derive(Debug)]
struct Frequency {
	val: i32,
	ref_count: i32,
	freq_map: HashMap<i32, Rc<RefCell<DoublyLinkedListNode>>>,
	head: Option<Rc<RefCell<DoublyLinkedListNode>>>,
	tail: Option<Rc<RefCell<DoublyLinkedListNode>>>,
}

impl Frequency {
	fn new(val: i32) -> Self {
		Frequency {
			val,
			ref_count: 0,
			freq_map: HashMap::new(),
			head: None,
			tail: None,
		}
	}

	fn remove_key(&mut self, key: i32) {
		if let Some(old_node) = self.freq_map.get_mut(&key) {
			if self.tail.as_ref().map_or(false, |n| Rc::ptr_eq(&n, old_node)) {
				self.tail = old_node.borrow().prev.as_ref().map(|r| r.clone());
			}
			if self.head.as_ref().map_or(false, |n| Rc::ptr_eq(&n, old_node)) {
				self.head = old_node.borrow().next.as_ref().map(|r| r.clone());
			}
			old_node.borrow_mut().disconnect();
			self.freq_map.remove(&key);
			self.ref_count -= 1;
		}
	}

	fn push_back(&mut self, key: i32) {
		let new_node = Rc::new(RefCell::new(DoublyLinkedListNode::new(key.clone())));
		if let Some(old_node) = &self.tail {
			old_node.clone().borrow_mut().next = Some(new_node.clone());
			new_node.borrow_mut().prev = Some(old_node.clone());
			self.tail = Some(new_node.clone())
		} else {
			self.head = Some(new_node.clone());
			self.tail = Some(new_node.clone());
		}
		self.freq_map.insert(key, new_node);
		self.ref_count += 1;
	}

	fn pop_front(&mut self) {
		let key = self.head.as_ref().unwrap().borrow().val.clone();
		self.remove_key(key);
	}
}

#[derive(Debug)]
struct CacheTable {
	value: i32,
	freq: i32
}

#[derive(Debug)]
struct LFUCache {
	capacity: i32,
	len: i32,
	lowest_freq: i32,
	data_info: HashMap<i32, CacheTable>,
	freq: HashMap<i32, Frequency>
}

impl LFUCache {
	fn new(capacity: i32) -> Self {
			LFUCache {
					capacity,
					len: 0,
					lowest_freq: 0,
					data_info: HashMap::new(),
					freq: HashMap::new(),
			}
	}

	fn get(&mut self, key: i32) -> i32 {
		if let Some(item) = self.data_info.get_mut(&key) {
			let old_freq = self.freq.get_mut(&item.freq).unwrap();
			old_freq.remove_key(key);

			if self.lowest_freq == old_freq.val && old_freq.ref_count == 0 {
					self.lowest_freq += 1;
			}

			item.freq += 1;
			self.freq.entry(item.freq).or_insert(Frequency::new(item.freq)).push_back(key);

			item.value.clone()
		} else {
			-1
		}
}

fn put(&mut self, key: i32, value: i32) {
		if let Some(item) = self.data_info.get_mut(&key) {
			// cache 메모리에 데이터가 있던 경우
			let old_freq = self.freq.get_mut(&item.freq).unwrap();
			old_freq.remove_key(key);
			if self.lowest_freq == old_freq.val && old_freq.ref_count == 0 {
				self.lowest_freq += 1;
			}

			item.freq += 1;
			item.value = value;

			self.freq.entry(item.freq).or_insert(Frequency::new(item.freq)).push_back(key);
		} else {
			// cache 메모리에 데이터가 없음
			if self.capacity > 0 {
				// table 의 길이와 capacity 가 같은 경우 => cache 메모리 공간이 없는 경우 참조 횟수가 가장 적은 페이지 제거
				if self.len == self.capacity {
					let lowest_freq = self.freq.get_mut(&self.lowest_freq).unwrap();
					self.data_info.remove(&lowest_freq.head.as_ref().unwrap().borrow().val);
					lowest_freq.pop_front();
					self.len -= 1;
				}

				self.data_info.insert(key, CacheTable {
					value,
					freq: 1
				});
				self.freq.entry(1).or_insert((Frequency::new(1))).push_back(key);
				self.len += 1;
				self.lowest_freq = 1;
			}
		}
	}
}


pub fn run() {
	let mut lfu_cache = LFUCache::new(2);
	println!("null");

	lfu_cache.put(1, 1);
	println!("null");
	lfu_cache.put(2, 2);
	println!("null");

	println!("{}", lfu_cache.get(1));

	lfu_cache.put(3, 3);
	println!("null");

	println!("{}", lfu_cache.get(2));
	println!("{}", lfu_cache.get(3));

	lfu_cache.put(4, 4);
	println!("null");

	println!("{}", lfu_cache.get(1));
	println!("{}", lfu_cache.get(3));
	println!("{}", lfu_cache.get(4));
}
