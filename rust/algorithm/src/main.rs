#[path="./sample_dir/sample_fn.rs"] mod calltest;

fn main() {
    //다른 디렉토리의 function 읽기
    calltest::test();
}
