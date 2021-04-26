//#[path="./sample_dir/sample_fn.rs"] mod calltest;
//#[path="./turret/turret.rs"] mod turret;
//#[path="./backjun/dfs_bfs.rs"] mod dfs_bfs;
#[path="./base_algorithm/bfs_dfs.rs"] mod bfs_dfs;

fn main() {
    //다른 디렉토리의 function 읽기
    //calltest::test();
    //turret::turret();
    bfs_dfs::run();
}
