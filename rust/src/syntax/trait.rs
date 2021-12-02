// pub trait Summarizable {
//     fn summary(&self) -> String;
// }

pub trait Summarizable {
    fn author_summary(&self) -> String;

    fn summary(&self) -> String {
        String::from(self.author_summary())
    }
}

pub struct NewsArticle{
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

// impl Summarizable for NewsArticle {
//     fn summary(&self) -> String {
//         format!("{}, by {} ({})", self.headline, self.author, self.location)
//     }
// }

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summarizable for Tweet {
    fn author_summary(&self) -> String {
        format!("@{}", self.content)
    }
}

pub fn notify<T: Summarizable>(item: T) {
    println!("Breaking news! {}", item.summary());
}

use std::cmp::PartialOrd;

fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list.iter() {
        if item > largest {
            largest = &item;
        }
    }

    &largest
}

pub fn run() {
    let numbers = vec![34, 50, 25, 100, 65];

    let result = largest(&numbers);
    println!("The largest number is {}", result);

    let chars = vec!['y', 'm', 'a', 'q'];

    let result = largest(&chars);
    println!("The largest char is {}", result);

    let strs = vec![String::from("test1"), String::from("test2")];

    let result = largest(&strs);
    println!("The largest char is {}", result);

    // let tweet = Tweet {
    //     username: String::from("horse_ebooks"),
    //     content: String::from("of course, as you probably already know, people"),
    //     reply: false,
    //     retweet: false,
    // };
    //
    // // println!("1 new tweet: {}", tweet.summary());
    //
    // notify(tweet);

}