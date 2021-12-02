#[derive(Debug)]
struct Shoe {
    size: u32,
    style: String,
}

fn my_shoes(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter()
        .filter(|s| s.size == shoe_size)
        .collect()
}

#[derive(Debug)]
struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = u32;
    fn next(&mut self) -> Option<Self::Item> {
        self.count += 1;
        if self.count < 6 {
            Some(self.count)
        } else {
            None
        }
    }
}

fn vec_iterator() {
    let mut count = Counter::new();
    if let Some(N) = count.next() {
        println!("{}", N);
    }
    println!("{:?}", count.next());
    println!("{:?}", count.next());
    println!("{:?}", count.next());
    println!("{:?}", count.next());
    println!("{:?}", count.next());

    let sum: u32 = Counter::new().zip(Counter::new().skip(1))
        .map(|(a, b)| a * b)
        .filter(|x| x % 3 == 0)
        .sum();

    println!("{:#?}", sum);


    // let v1 = vec![1, 2, 3];
    // let mut v1_iter = v1.iter();

    // println!("{:?}", v1_iter);
    // println!("{:?}", v1_iter.next());
    // println!("{:?}", v1_iter.next());
    // println!("{:?}", v1_iter.next());
    // println!("{:?}", v1_iter.next());
    // println!("{:?}", v1_iter);

    // let total: i32 = v1_iter.sum();
    // println!("{}", total);
    // let v2 = v1.iter().map(|x| x + 1);
    // println!("{:?}", v2);
    // let v3: Vec<i32> = v1.iter().map(|x| x + 1).collect();
    // println!("{:?}", v3);

    // let shoes: Vec<Shoe> = vec![
    //     Shoe { size: 240, style: String::from("스니커즈") },
    //     Shoe { size: 255, style: String::from("샌들") },
    //     Shoe { size: 260, style: String::from("디올 B23 하이탑 스니커즈 화이트") },
    //     Shoe { size: 235, style: String::from("단화") },
    //     Shoe { size: 260, style: String::from("발렌시아가 트리플s 트레이너") },
    // ];
    //
    // let mine = my_shoes(shoes, 260);
    //
    // println!("{:?}", mine);
}

pub fn run() {
    vec_iterator();
}
