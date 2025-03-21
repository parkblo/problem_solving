function solve(input) {
  const [n, m] = input.shift().split(" ").map(Number);
  const ar = input.shift().split(" ").map(Number);
  const g = Array.from({ length: n + 1 }, () => -1);
  const score = new Array(n + 1).fill(0);
  const dp = new Array(n + 1).fill(null);

  for (let i = 0; i < n; i++) {
    g[i + 1] = ar[i];
  }

  for (let i = 0; i < m; i++) {
    const [idx, w] = input[i].split(" ").map(Number);
    score[idx] += w;
  }

  function f(n) {
    if (dp[n] !== null) return dp[n];
    if (n === 1) return (dp[n] = 0);

    if (g[n] === 1 || g[n] === -1) {
      return (dp[n] = score[n]);
    }

    return (dp[n] = score[n] + f(g[n]));
  }

  const ans = [];
  for (let i = 1; i <= n; i++) {
    ans.push(f(i));
  }

  console.log(ans.join(" "));
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
