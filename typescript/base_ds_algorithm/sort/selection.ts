export function selectionSort(){
    let array = [6, 5, 2, 4, 3, 1];
    for(let i = 0; i < array.length; i++){
        let minIndex = i;
        for(let j = i + 1; j < array.length; j++){
            if(array[j] < array[minIndex]) minIndex = j;
        }
        const curr = array[minIndex];
        array[minIndex] = array[i];
        array[i] = curr;
    }
    console.log(array);
}