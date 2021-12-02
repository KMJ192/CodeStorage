/*
    bubble sort
    i번째 index와 i + n번째 index와 비교하여 정렬
*/
fn bubble_sort(array: &mut Vec<i32>) {
    for i in (0..array.len()).rev() {
        for j in 0..i {
            if array[j] > array[j + 1] {
                let curr = array[j];
                array[j] = array[j + 1];
                array[j + 1] = curr;
            }
        }
    }
    println!("{:?}", array);
}

pub fn bubble_sort_run() {
    let mut array = vec![6, 1, 3, 5, 2, 4];
    bubble_sort(&mut array);
}