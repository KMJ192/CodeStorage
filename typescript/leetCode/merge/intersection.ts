export function intersection(nums1: number[], nums2: number[]): number[] {
    let answer : number[];
    let tmp = {};
    nums1.forEach(val1 => {
        nums2.forEach(val2 => {
            if(val1 === val2){
                tmp[val1] = val1;
            }
        });
    });
    console.log(tmp);
    for(let i = 0; i < Object.keys(tmp).length; i++){
        
    }

    return answer;
};