function solve(input) {
  const N = Number(input.shift());
  const events = input.map((e) => e.split(" ").map(Number));
  let answer = 0;

  const cal = new Array(366).fill(0);
  for (const [s, e] of events) {
    for (let i = s; i <= e; i++) {
      cal[i]++;
    }
  }

  let w = (h = 0);
  for (let i = 1; i <= 365; i++) {
    if (cal[i] > 0) {
      w++;
      h = Math.max(h, cal[i]);
    } else {
      answer += w * h;
      w = h = 0;
    }
  }

  if (w > 0) {
    answer += w * h;
  }

  console.log(answer);
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
