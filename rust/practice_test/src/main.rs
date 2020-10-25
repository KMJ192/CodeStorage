
fn solution(answers : Vec<i32>) -> Vec<i32>{
    let mut answer :Vec<i32> = Vec::new();
    let mut dapVector : Vec<i32> = Vec::new();
    let mut compare : Vec<i32> = Vec::new();
    let mut dap : i32 = 0;
    let mut s : i32 = 0;
    let mut index : usize = 0;

    //첫번째 계산
    for i in 0 .. answers.len(){
        dap += 1;
        if dap == answers[i] {
            s += 1;
        }

        if dap == 5 {
            dap = 0;
        }
    }

    compare.push(s);
    s = 0;

    //두번째 계산
    dapVector = [2, 1, 2, 3, 2, 4, 2, 5].to_vec();
    for i in 0 .. answers.len(){

        if dapVector[index] == answers[i] {
            s += 1;
        }

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
        if dapVector[index] == answers[i]{
            s += 1;
        }

        if index == (dapVector.len() - 1) {
            index = 0;
        }else{
            index += 1;
        }
    }
    compare.push(s);

    //1. 첫번째가 가장 큰 경우
    if (compare[0] > compare[1]) && (compare[0] > compare[2]){
        answer.push(1);
    //2. 두번째가 가장 큰경우
    }else if (compare[1] > compare[0]) && (compare[1] > compare[2]){
        answer.push(2);
    //3. 세번째가 가장 큰경우
    }else if (compare[2] > compare[0]) && (compare[2] > compare[1]) {
        answer.push(3);
    //4. 첫번째 두번째 세번째 모두 같은경우
    }else if (compare[0] == compare[1]) && (compare[0] == compare[2]) && (compare[1] == compare[2]){
        answer.push(1);
        answer.push(2);
        answer.push(3);
    }else{
        //5. 첫번째와 두번째가 같은 경우
        if compare[0] == compare[1]{
            answer.push(1);
            answer.push(2);
        //6. 첫번째와 세번째가 같은 경우
        }else if compare[0] == compare[2]{
            answer.push(1);
            answer.push(3);
        //7. 두번째와 세번째가 같은 경우
        }else if compare[1] == compare[2]{
            answer.push(2);
            answer.push(3);
        }
    }
    answer
}

fn main() {
    let mut answers : Vec<i32> = Vec::new();
    let mut result : Vec<i32> = Vec::new();
    
    answers = [1,3,2,4,2].to_vec();

    result = solution(answers);

    for i in 0 .. result.len(){
        print!("{}", result[i]);
    }
}
