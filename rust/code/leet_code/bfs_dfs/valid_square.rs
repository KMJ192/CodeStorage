
struct Solution;
// impl Solution {
//     pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
//         let mut map: HashMap<i32, usize> = HashMap::new();
//         let rs = |point1: &Vec<i32>, point2: &Vec<i32>| -> i32{
//             let x = point2[0] - point1[0];
//             let y = point2[1] - point1[1];
//             (x * x) + (y * y)
//         };
//         [
//             rs(&p1, &p2),
//             rs(&p1, &p3),
//             rs(&p1, &p4),
//             rs(&p2, &p3),
//             rs(&p2, &p4),
//             rs(&p3, &p4)
//         ].iter().for_each(|&d| *map.entry((d)).or_insert(0) += 1);
//
//         let  values: Vec<usize> = map.iter().map(|(_, &v)| v).collect();
//         values == vec![2, 4] || values == vec![4, 2]
//     }
// }

impl Solution {
    pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
        let two_po = |point1: &Vec<i32>, point2: &Vec<i32>| -> i32 {
            let mut x = 0;
            let mut y = 0;
            if point1[0] > point2[0]{
                x = (point1[0] - point2[0]).pow(2);
            }else{
                x = (point2[0] - point1[0]).pow(2);
            }
            if point1[1] > point2[1]{
                y = (point1[1] - point2[1]).pow(2);
            }else{
                y = (point2[1] - point1[1]).pow(2);
            }
            x + y
        };

        // if two_po(&p1, &p2) == two_po(&p1, &p3){
        //
        // }else if two_po(&p2, &p3) == two_po(&p2, &p4){
        //
        // }else if two_po(&p3, &p4) == two_po(&p3, &p1) {
        //
        // }else if two_po(&p4, &p1) == two_po(&p4, &p2){
        //
        // }

        // println!("{} {}", two_po(&p1, &p2), two_po(&p2, &p4));
        // println!("{} {}", two_po(&p2, &p4), two_po(&p3, &p4));
        // println!("{} {}", two_po(&p3, &p4), two_po(&p1, &p3));
        // println!("{} {}", two_po(&p1, &p4), two_po(&p2, &p3));

        two_po(&p1, &p2) == two_po(&p2, &p4) &&
        two_po(&p2, &p4) == two_po(&p3, &p4) &&
        two_po(&p3, &p4) == two_po(&p1, &p3) &&
        two_po(&p1, &p4) == two_po(&p2, &p3)
    }
}

pub fn run(){
    let p1 = vec![0,0];
    let p2 = vec![1,1];
    let p3 = vec![1,0];
    let p4 = vec![0,1];
    println!("{}", Solution::valid_square(p1, p2, p3, p4));
    // println!("{}", sqrtf32(5.0));
    // println!("{}", 5_i32.pow(2));
}

