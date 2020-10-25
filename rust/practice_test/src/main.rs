
fn solution(answers : Vec<i32>) -> Vec<i32>{
    let mut answer :Vec<i32> = Vec::new();
    let mut dapVector : Vec<i32> = Vec::new();
    let mut compare : Vec<i32> = Vec::new();
    let mut dap : i32 = 0;
    let mut s : i32 = 0;
    let mut index : i32 = 0;
   
    //첫번째 계산
    for i in 0 .. answers.len(){
        dap += 1;
        if(dap == answers[i]){
            s += 1;
        }

        if(dap == 5){
            dap = 0;
        }
    }

    compare.push(s);
    s = 0;

    //두번째 계산
    dapVector = [2, 1, 2, 3, 2, 4, 2, 5].to_vec();
    for i in 0 .. answers.len(){
        if dapVector[index] == answer[i]{
            s += 1;
        }
        print!("{}", dap.Vector.len());
        if index == (dapVector.len() - 1) {
            index = 0;
        }else{
            index += 1;
        }
    }
    compare.push(s);
    
    s = 0;
    index = 0;

    //세번째 계산
    dapVector = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5].to_vec();
    for i in 0 .. answers.len(){
        if dapVector[index] == answer[i]{
            s += 1;
        }

        if index == (dapVector.len() - 1) {
            index = 0;
        }else{
            index += 1;
        }
    }
    compare.push(s);

    print!("{}", compare[0]);
    print!("{}", compare[1]);
    print!("{}", compare[2]);

    answer
}

fn main() {
    let mut answers : Vec<i32> = Vec::new();
    answers = [1, 2, 3, 4, 5].to_vec();
    solution(answers);

    // for i in solution(answers){
    //     print!("{}", i);
    // }
}
