use std::io;
use std::collections::BinaryHeap;

struct Dijkstra {
    inf: u32,
    path: Vec<Vec<(u32, u32)>>,
    v: usize,
    e: u32,
    start: usize,
    table: Vec<u32>
}

impl Dijkstra {
    fn new() -> Self {
        Dijkstra {
            inf: 987654321,
            path: vec![vec![]; 20001],
            v: 0,
            e: 0,
            start: 0,
            table: vec![]
        }
    }

    fn dijkstra(&mut self) {
        let mut pq = BinaryHeap::new();
        self.table[self.start] = 0;
        pq.push((0, self.start));

        while let Some(unit) = pq.pop() {
            let cur = unit.1;
            let weight = -unit.0 as i32;

            if (self.table[cur] as i32) < weight {
                continue;
            }

            for i in 0..self.path[cur].len() {
                let connect = self.path[cur][i].0;
                let con_dist = weight + (self.path[cur][i].1 as i32);

                if self.table[connect as usize] > con_dist as u32 {
                    self.table[connect as usize] = con_dist as u32;
                    pq.push((-con_dist, connect as usize))
                }
            }
        }
    }

    fn input(&mut self) {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("failure");

        let tmp: Vec<&str> = input.split_whitespace().collect();
        self.v = tmp[0].parse::<usize>().unwrap();
        self.e = tmp[1].parse::<u32>().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("failure");
        let tmp: Vec<&str> = input.split_whitespace().collect();
        self.start = tmp[0].parse::<usize>().unwrap();

        for i in 0..self.e {
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("failure");
            let tmp: Vec<&str> = input.split_whitespace().collect();
            let u = tmp[0].parse::<usize>().unwrap();
            let v = tmp[1].parse::<u32>().unwrap();
            let w = tmp[2].parse::<u32>().unwrap();
            self.path[u].push((v, w));
        }
        self.v += 1;

        self.table = vec![self.inf; self.v];
    }

    fn display(&self) {
        for i in 1..self.v {
            if self.table[i] == self.inf {
                println!("INF\n");
            }else{
                println!("{}", self.table[i]);
            }
        }
    }
}

pub fn dijkstra_build() {
  let mut dk = Dijkstra::new();
  dk.input();
  dk.dijkstra();
  dk.display();
}