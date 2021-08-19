function duplicateZeros(arr: number[]): void {
  for (let i = 0; i < arr.length; i++) {
    let end = arr.length - 1;
    if (arr[i] === 0) {
      while (end > i + 1) {
        arr[end] = arr[end - 1];
        end--;
      }
      if (i + 1 < arr.length) arr[i + 1] = 0;
      i++;
    }
  }
  console.log(arr);
};

export function dupZeros() {
  let arr = [1, 0, 2, 3, 0, 4, 5, 0];
  duplicateZeros(arr);
}