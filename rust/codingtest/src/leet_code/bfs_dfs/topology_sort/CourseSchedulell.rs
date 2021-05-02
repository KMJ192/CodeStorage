//위상정렬
//1. incoming 없는 node부터 시작
//2 .outgoing node로 이동
//3. outgoing 이동후 해당 node에서 incoming 삭제
//4. 해당 node에서 그 다음 outgoing node로 이동
//5. 2~4반복
//6. outgoing으로 이동한 해당 node의 incoming이 없을 경우 queue에 push
//[[1, 0], [2, 0], [3, 1], [3, 2]]
//    0: {
//        incoming: 0
//        outgoing : [1, 2]
//      }
//    1 : {
//        incoming: 1
//        outgoing : [3]
//      }
//    2 : {
//        incoming: 1
//        outgoing : [3]
//    }
//    3 : {
//        incoming: 2
//        outgoing : []
//    }
//    0 -> 1 -> 3
//      -> 2 -> 3
struct Solution;

impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let mut answer : Vec<i32> = Vec::new();
        //incoming outgoing 저장할 topology Graph
        //incoming count, outcoming node
        let mut v : Vec<(usize, Vec<usize>)> = vec![(0, vec![]); num_courses as usize];

        println!("{:?}", prerequisites);
        //topology Graph 구성
        for p in prerequisites.iter(){
            v[p[0] as usize].0 += 1;
            v[p[1] as usize].1.push(p[0] as usize);
        }
        println!();
        for i in v.iter(){
            println!("{:?}", i);
        }
        println!();

        let mut entry_point: Vec<usize> = Vec::new();
        for (node, i) in (0..).zip(v.iter()) {
            if i.0 == 0 {
                entry_point.push(node);
            }
        }

        //entry_point의 node부터 실행
        while let Some(p) = entry_point.pop(){
            println!("{:?}", p);
            //방문한 노드 push
            answer.push(p as i32);
            for i in v[p].1.clone(){
                //incoming count 감소
                v[i].0 -= 1;
                //incoming node이면 push
                if v[i].0 == 0 {
                    entry_point.push(i as usize);
                }
            }
        }
        println!();
        if answer.len() == num_courses as usize{ answer }
        else { vec![] }
    }
}

pub fn run(){
    let mut perequistes : Vec<Vec<i32>> = Vec::new();
    perequistes.push(vec![1, 0]);
    perequistes.push(vec![2, 0]);
    perequistes.push(vec![3, 1]);
    perequistes.push(vec![3, 2]);

    println!("{:?}", Solution::find_order(4, perequistes));
}