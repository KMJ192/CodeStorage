function sa(array: number[]): number{
    let left = 0;
    let right = array.length - 1;
    let tmp: number[] = [];

    while(left <= right){
        const mid: number = Math.floor(left + ((right - left) / 2));
        if(array[mid] === mid && mid - 1 === array[mid - 1]){
            right = mid - 1;
        }
        if(array[mid] === mid) {
            tmp.push(mid);
        }
        if(array[mid] < mid){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
        console.log(`left : ${left}, right : ${right}, mid : ${mid}`);
    }
    console.log(tmp);
    return -1;
}
//[-5, -3, 2, 3, 4, 5, 9]
//  ^         ^        ^

export function sortedArray(){
    let array: number[] = [-5, -3, 2, 3, 4, 5, 9];
    console.log(sa(array));
}