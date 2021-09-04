#[derive(Debug)]
struct ArraySort;

impl ArraySort {
    fn selection_sort(array: &mut Vec<i32>) {
        for i in 0..array.len() {
            let mut min_index = i;
            for j in i + 1..array.len() {
                if array[j] < array[min_index] {
                    min_index = j;
                }
            }
            let curr = array[min_index];
            array[min_index] = array[i];
            array[i] = curr;
        }
        println!("{:?}", array);
    }
}


pub fn selection_sort_run() {
    let mut array = vec![6, 5, 2, 4, 3, 1];
    ArraySort::selection_sort(&mut array);
}
