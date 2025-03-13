function solve(input) {
  const N = Number(input.shift());
  const ar = input
    .shift()
    .split(" ")
    .map(Number)
    .sort((a, b) => a - b);
  let ans = 0;

  for (let i = 0; i < N; i++) {
    const target = ar[i];
    let l = 0,
      r = N - 1;
    while (l < r) {
      const sum = ar[l] + ar[r];
      if (sum === target) {
        if (l === i) l++;
        else if (r === i) r--;
        else {
          ans++;
          break;
        }
      } else if (sum < target) {
        l++;
      } else {
        r--;
      }
    }
  }

  console.log(ans);
  return;
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
