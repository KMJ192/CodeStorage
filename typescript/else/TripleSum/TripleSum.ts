interface Pointer {
  first: number;
  second: number;
  third: number;
}

class Solution {
  private input: number[];
  private target: number;
  private closetValue: number[];
  private closet: number;
  private returnValue: number;
  constructor(input: number[], target: number) {
    this.input = input;
    this.target = target;
    this.closetValue = [0, 0, 0];
    this.closet = 0;
    this.returnValue = -1;
  }

  private renewal(index: Pointer) {
    const { first, second, third } = index;
    this.closetValue[0] = this.input[first];
    this.closetValue[1] = this.input[second];
    this.closetValue[2] = this.input[third];
  }

  private recursion(index: Pointer): void {
    if (this.returnValue === 0) return;
    const { first, second, third } = index;
    if (third > this.input.length - 1) return;
    if (first === second || second === third) return;
    // 상태 갱신
    const hap = this.input[first] + this.input[second] + this.input[third];

    if (hap === this.target) {
      this.renewal(index);
      this.returnValue = 0;
      return;
    } else if (this.closet === 0) {
      this.closet = Math.abs(hap);
      this.renewal(index);
      this.returnValue = Math.abs(hap);
      // 100 - 3 => 97
      // 100 - 2 => 98
    } else if (
      Math.abs(this.target - Math.abs(hap)) <
      Math.abs(this.target - this.closet)
    ) {
      this.closet = Math.abs(hap);
      this.renewal(index);
      this.returnValue = Math.abs(hap);
    }

    // 재귀호출
    if (
      first === this.input.length - 3 &&
      second === this.input.length - 2 &&
      third === this.input.length - 1
    ) {
      return;
    }

    index = {
      ...index,
      third: third + 1,
    };
    this.recursion(index);

    index = {
      ...index,
      second: second + 1,
    };
    this.recursion(index);

    index = {
      ...index,
      first: first + 1,
    };
    this.recursion(index);
  }

  public run() {
    if (this.input.length < 3) return;
    this.recursion({
      first: 0,
      second: 1,
      third: 2,
    });
    console.log(this.closetValue);
    return this.returnValue;
  }
}

function run() {
  const solution = new Solution([-3, -1, 1, 2], 1);
  console.log(solution.run());
}

export default run;
