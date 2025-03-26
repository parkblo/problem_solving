function solve(input) {
  const [n, m] = input.shift().split(" ").map(Number);
  const title = [];
  const ans = [];

  for (let i = 0; i < n; i++) {
    const [name, val] = input[i].split(" ");
    title.push({ name, val: Number(val) });
  }

  for (let i = n; i < n + m; i++) {
    const power = Number(input[i]);
    const idx = lowerBound(power);
    const name = title[idx].name;
    ans.push(name);
  }

  function lowerBound(power) {
    let lo = 0;
    let hi = n - 1;
    let mid;

    while (lo <= hi) {
      mid = Math.floor((lo + hi) / 2);

      if (title[mid].val >= power) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return lo;
  }

  console.log(ans.join("\n"));
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
