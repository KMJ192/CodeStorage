// Given two non-empty arrays of integers, write a function that determines whether
// the second array is a subsequence of the first one
//
// A subsequence of an array is a set of numbers that aren't necessarily adjacent in the
// array but that are in the same order as they appear in the array.
// For instance, the numbers[1, 3, 4]  3form a subsequence of the array [1, 2,, 4]
// and so do the numbers [2, 4]. Note that a single numer in an array and the array itself are both valid subsequences of the array

// 비어 있지 않은 두 정수 배열이 주어진 경우, 다음을 결정하는 함수를 작성합니다.
// 두 번째 배열은 첫 번째 배열의 후속 배열입니다.
// 배열의 다음 순서는 반드시 에 인접하지 않은 번호 집합입니다.
// 어레이가 어레이에 표시되는 순서와 동일합니다.
// 예를 들어 숫자[1, 3, 4]는 배열의 연속[1, 2, 3, 4]을 구성합니다.
// 숫자도 마찬가지입니다 [2, 4]. 어레이의 단일 숫자와 어레이 자체는 모두 어레이의 유효한 시퀀스입니다.

// input
//  - 1차원 배열
//  - 1 array = [5, 1, 22, 25, 6, -1, 8, 10]
//  - 2 sequence = [1, 6, -1, 10]
//  array    [1,3,6,2,3,4,5,6,7,8,9,10]
//  sequence [2,3,4,5,6,7,8,9,10]
// output - boolean
// constraint
// - none empty
// edge case
// - array.length < sequence.length - false
// sudo code
// let count = 0
// - for i = 0 to sequence.length{
//     for j = count to array.length{
//         sequence[i] == array[j] count = j;
//     }
// }
// time complexity
//  - O(n)
// space complexity
//  - O(1)

fn solution(array: Vec<i32>, sequence: Vec<i32>) -> bool {
    if array.len() < sequence.len() { return false; }
    let mut count = 0;
    let mut flag = 0;

    for i in 0..sequence.len(){
        for j in count..array.len(){
            if sequence[i] == array[j] {
                count = j;
                flag += 1;
                break;
            }
        }
    }

    if flag != sequence.len() { return false; }
    true
}

pub fn run(){
    let array = vec![5, 1, 22, 25, 6, -1, 8, 10];
    let sequence = vec![1, -1, 6, 10];
    println!("{}", Solution(array, sequence));
}