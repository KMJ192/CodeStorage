var fourNumberSum = function (array, targetSum) {
  const result = [];
  // array.sort 아스키코드로 정렬
  // 오름차순 정렬
  array.sort((a, b) => a - b);

  let s = new Set();

  for (let i = 0; i < array.length - 3; i++) {
    for (let j = i + 1; j < array.length - 2; j++) {
      // 포인터를 이용해 풀이 진행
      // k는 j 바로 다음 위치, l은 배열의 가장 끝에 위치
      // k는 항상 l보다 작아야 한다.(전제조건) - 포인터

      let k = j++;
      let l = array.length - 1;
      const sum = targetSum - array[i] - array[j];
      while (k < l) {
        // 만약 sum이 target보다 작을 경우, k를 이동시켜서 sum을 키운다.
        // 만약 sum이 target보다 클 경우, l를 이동시켜 sum의 값을 줄인다.
        // const sum = array[i]+array[j]+array[k]+array[l];
        const sum2 = array[k] + array[l];

        if (array[k] + array[l] < sum) {
          k++;
          continue;
        }
        if (array[k] + array[l] > sum) {
          l--;
          continue;
        }
        // // sum === targetSum
        // result.push([array[i], array[j], array[k], array[l]]);
        // // array[k] == array[k+1]과 같을 때 처리
        // while (array[k] === array[k + 1]) k++;
        // // array[l] == array[l-1]과 같을 때 처리
        // while (array[l] === array[l - 1]) l--;
        s.add([array[i], array[j], array[k], array[l]]);
        k++;
        l--;
      }

      /*
      for(let k = j + 1; k<array.length -1; k++){
        for(let l = k + 1; l<array.length; l++){
          const sum = array[i]+array[j]+array[k]+array[l];
          if(sum === targetSum){
            result.push([array[i], array[j], array[k], array[l]]);
          }
          // array[l] == array[l+1]이 같을 때 처리
          while(array[l] === array[l+1]) l++;
        }
        while(array[k] === array[k+1]) k++;
        */
      while (array[j] === array[j + 1]) j++;
    }
    while (array[i] === array[i + 1]) i++;
  }
  console.log(s);
  return result;
};

const array = [7, 6, 4, -1, 1, 2];
const targetSum = 16;
console.log(fourNumberSum(array, targetSum));
