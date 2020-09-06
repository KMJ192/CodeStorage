function substr(str) {
    let slen = 0;
    const arr = [];
    for (let i = 1; i <= str.length; i++) {
      arr[slen] = str.slice(slen, i);
      slen++;
    }
    return arr;
  }
  //================string 자르는 function
  
  function solution(skill, skill_trees) {
    var answer = 0;
  
    let compareArr = [];
    //let totallen = fac(skill); // factorial 길이
    let strArr = substr(skill);
  
    for (let i = 0; i < skill_trees.length; i++) {
      let test = false;
      var position = 0;
      var compare = 0;
      compareArr = [];
      for (let j = 1; j < skill_trees[i].length + 1; j++) {
        const sStr = skill_trees[i].slice(position, j);
        if (sStr === strArr[compare]) {
          compareArr[compare] = sStr;
          compare++;
        }
        position += 1;
      }
  
      for (let j = 0; j < skill.length; j++) {
        if (compareArr[j] === strArr[j]) {
          test = true;
        } else {
          test = false;
          break;
        }
      }
      if (test === true) {
        answer++;
      }
    }
    return answer;
  }