use std::cmp::PartialOrd;

trait Summary {
	fn summary(&self) -> String;
}

struct User {
	name: String,
	password: String,
	description: String,
}

impl Summary for User {
	fn summary(&self) -> String {
		format!("{} {} {}", self.name, self.password, self.description)
	}
}

fn notify<T: Summary>(item: T) {
	println!("{}", item.summary());
}

fn largest<T>(list: &[T]) -> T where T: PartialOrd + Copy {
	let mut largest = list[0];

	for &item in list.iter() {
			if item > largest {
					largest = item;
			}
	}

	largest
}

pub fn run() {
	let user = User {
		name: String::from("name"),
		password: String::from("password"),
		description: String::from("test")
	};

	let tmp = user.summary();
	println!("{}", tmp);

	notify(user);

	let numbers = vec![34, 50, 25, 100, 65];
	let result = largest(&numbers);
	println!("The largest number is {}", result);
	let chars = vec!['y', 'm', 'a', 'q'];

	let result = largest(&chars);
	println!("The largest char is {}", result);
}