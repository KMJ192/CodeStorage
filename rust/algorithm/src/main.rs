//#[path="./sample_dir/sample_fn.rs"] mod calltest;
#[path="./turret/turret.rs"] mod turret;


fn main() {
    //다른 디렉토리의 function 읽기
    //calltest::test();
    turret::turret();
}
