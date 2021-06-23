// you're given a list of edges representing an un weighted, directed graph with at least one node.
// Write a function that returns a boolean representing whether the given graph contains a cycle
//
// For the purpose of this question, a cycle is defined as any number of vertices. including just one vertex,
// that are connected in a closed chain.
// A cycle can also be defined as a chain of at least one vertex in which the first vertex is the same as the last
//
// The given list is what's called an adjacency list, and it repersents a graph.
// The number of vertices in the graph is equal to the length of edges,
// where each index i in edges contains vertex i's outbound edges, in no particular order.
// Each individual edge is represented by a positive integer that denotes an index(a destination vertex)
// in the list that this vertex is connected to.
// Note that these edges are directed, meaning that you can only travel from a particular vertex to its destination,
// not the other way around(unless then destination vertex itself has an outbound edge to the original vertex).
//
// Also note that graph may contain self-loops. A self-loop is an edge that has the same destination and origin; in other words, its an edge that connects a vertex to itself.
// For the purpose of this question, a self-loop is considered a cycle.
//
// For a more detailed explanation, please refer to the Conceptual Overview section of this question's vedeo explanation

// template
// input: [[1,3], [2, 3, 4], [0], [2, 5], []]
// output: true
// constraint:
// edge case: 배열의 길이가 null인경우

//그래프 내 loop가 존재하면 true, 아니면 false
fn cig(graph: &mut Vec<Vec<i32>>) -> bool{
    if graph.len() == 0 { return true; }
    for i in 0..graph.len(){
        let mut visited: Vec<i32> = vec![0; graph.len()];
        let result = dfs(graph, i, (i, 0), &mut visited);
        if result { return true; }
    }
    false
}

fn dfs(graph: &mut Vec<Vec<i32>>, last: usize, (pos1, pos2): (usize, usize), visited: &mut Vec<i32>) -> bool {
    if graph[pos1].len() == 0 { return false; }
    for i in 0..visited.len(){
        if visited[graph[pos1][pos2] as usize] == 1 { return false; }
    }
    visited[graph[pos1][pos2] as usize] = 1;
    if last == graph[pos1][pos2] as usize {
        println!("{} == {}", last, graph[pos1][pos2]);
        return true;
    }
    let mut result = false;
    for i in 0..graph[graph[pos1][pos2] as usize].len(){
        result = dfs(graph, last, (graph[pos1][pos2] as usize, i), visited);
        if result { return true; }
    }
    result
}


pub fn run(){
    let mut graph = vec![
        vec![1],
        vec![2],
        vec![],
        vec![],
        vec![],
    ];
    let result = cig(&mut graph);
    println!("{}", result);
}
//0 -> 1 3
//1 -> 2 3 4
//2 -> 0
//3
//4 -> 2 5
//5