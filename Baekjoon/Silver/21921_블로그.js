function solve(input) {
  const [n, x] = input.shift().split(" ").map(Number);
  const ar = input.shift().split(" ").map(Number);

  let ans = 0;
  let left = 0;
  let curr = 0;
  let cnt = 0;

  for (let i = 0; i < x; i++) curr += ar[i];

  for (let right = x; right < n; right++, left++) {
    if (curr > ans) {
      ans = curr;
      cnt = 1;
    } else if (curr === ans) {
      cnt++;
    }

    curr -= ar[left];
    curr += ar[right];
  }

  if (curr > ans) {
    ans = curr;
    cnt = 1;
  } else if (curr === ans) {
    cnt++;
  }

  if (ans === 0) console.log("SAD");
  else {
    console.log(ans);
    console.log(cnt);
  }
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
