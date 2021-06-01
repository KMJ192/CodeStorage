//위상정렬
//1. incoming 없는 node부터 시작
//2. outgoing node로 이동
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
    pub fn topology_sort(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let mut answer : Vec<i32> = Vec::new();
        //incoming outgoing 저장할 topology Graph
        //incoming count, outgoing node
        let mut v : Vec<(usize, Vec<usize>)> = vec![(0, vec![]); graph.len()];

        println!("그래프 : {:?}", graph);
        //topology Graph 구성
        for p in graph.iter(){
            v[p[1] as usize].0 += 1;
            v[p[0] as usize].1.push(p[1] as usize);
        }
        println!();
        for i in 0..v.len(){
            println!("노드 {} {:?}", i, v[i]);
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
        answer
    }
}

pub fn run(){
    let mut graph: Vec<Vec<i32>> = Vec::new();
    graph.push(vec![0, 1]);
    graph.push(vec![0, 2]);
    graph.push(vec![1, 3]);
    graph.push(vec![2, 3]);
    graph.push(vec![3, 5]);
    graph.push(vec![4, 5]);

    println!("정렬\n{:?}", Solution::topology_sort(graph));
}