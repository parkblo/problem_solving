function solve(input) {
  const [N, K] = input.shift().split(" ").map(Number);
  const numbers = input.shift().split("").map(Number);

  const stack = [];

  let cnt = 0;
  for (let i = 0; i < numbers.length; i++) {
    const val = numbers[i];

    if (cnt >= K) {
      stack.push(val);
      continue;
    }

    while (stack.length > 0 && cnt < K) {
      const top = stack[stack.length - 1];
      if (top < val) {
        stack.pop();
        cnt++;
      } else {
        break;
      }
    }

    stack.push(val);
  }

  while (cnt < K) {
    stack.pop();
    cnt++;
  }

  console.log(stack.join(""));
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
