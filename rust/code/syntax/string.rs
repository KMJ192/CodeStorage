fn cast(){
    let mut s = String::from("");
    let mut c = 'c';
    s = c.to_string();
    println!("char to string : [{}]", s);

    let mut i = 1;
    s = i.to_string();
    println!("i32 to string : [{}]", s);

    let mut f = 1.0;
    s = f.to_string();
    println!("f64 to string : [{}]", s);

    i = s.parse().unwrap();
    println!("string to i32 : [{}]", i);

    f = s.parse().unwrap();
    println!("string to i64 : [{}]", f);

    c = s.parse().unwrap();
    println!("string to char : [{}]", c);
}

fn string_iterator(){
    let s = String::from("curr_string");
    for c in s.chars(){
        println!("{}", c);
    }
}

fn string_to_vec() {
    let mut s = String::from("curr_string");
    let v : Vec<char> = s.chars().collect();
    println!("{:?}", v);
}

#[derive(Debug)]
struct StringMethod{
    s : String
}

impl StringMethod{
    fn new(input_string: String) -> Self{
        StringMethod{
            s : String::from(input_string)
        }
    }
    fn revers_string(&mut self){
        let rv = self.s.chars().rev().collect::<String>();
        println!("{:?}", rv);
    }
    fn byte_method(&mut self){
        //Bytes type으로 반환
        let mut byte = self.s.bytes();
        println!("{:?}", byte);
        while let Some(b) = byte.next(){
            println!("{}", b);
        }
    }
    fn as_byte_method(&mut self){
        //u8를 참조하는 배열로 반환
        let mut bytes = self.s.as_bytes();
        println!("{:?}", bytes);
    }
}

pub fn string_run(){
    //cast();
    //string_to_vec();

    let s = String::from("CurrentString");
    let mut sm = StringMethod::new(s);
    //sm.revers_string();
    sm.byte_method();
    //sm.as_byte_method();
}