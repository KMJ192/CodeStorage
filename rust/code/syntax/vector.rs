pub fn run(){
    let mut v: Vec<i32> = vec![1, 2, 3];
    let t = v.get(2);
    match t {
        Some(num) => {
            println!("{}", num);
        },
        _ => {
            println!("None")
        }
    }
}