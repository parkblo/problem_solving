function solve(input) {
  const n = Number(input.shift());
  const devArr = input.shift().split(" ").map(Number);

  let ans = 0;
  let left = 0;
  let right = n - 1;

  while (left < right) {
    const val = (right - left - 1) * Math.min(devArr[left], devArr[right]);

    ans = Math.max(ans, val);
    if (devArr[right] > devArr[left]) {
      left++;
    } else {
      right--;
    }
  }

  console.log(ans);
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
