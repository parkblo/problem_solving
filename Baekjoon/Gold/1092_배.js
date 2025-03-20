function solve(input) {
  const N = Number(input.shift());
  const limits = input
    .shift()
    .split(" ")
    .map(Number)
    .sort((a, b) => b - a);
  const M = Number(input.shift());
  const weights = input
    .shift()
    .split(" ")
    .map(Number)
    .sort((a, b) => b - a);

  let time = 0;

  while (weights.length > 0) {
    time++;
    let flag = false;

    for (let i = 0; i < limits.length; i++) {
      if (weights.length <= 0) break;

      let removeIndex = null;
      for (let j = 0; j < weights.length; j++) {
        if (weights[j] > limits[i]) continue;

        removeIndex = j;
        break;
      }
      if (removeIndex === null) continue;

      weights.splice(removeIndex, 1);
      flag = true;
    }

    if (flag === false) {
      console.log("-1");
      return;
    }
  }

  console.log(time);
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
