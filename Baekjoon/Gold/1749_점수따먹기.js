function solve(input) {
  const [N, M] = input.shift().split(" ").map(Number);
  const board = input.map((v) => v.split(" ").map(Number));
  const d = Array.from({ length: N + 1 }, () => new Array(M + 1).fill(0));
  let answer = Number.MIN_SAFE_INTEGER;

  // 1. 누적합 수열 완성
  // left to right
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= M; j++) {
      d[i][j] = d[i][j - 1] + board[i - 1][j - 1];
    }
  }

  // up to down
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= M; j++) {
      d[i][j] += d[i - 1][j];
    }
  }

  // 2. 최대 부분행렬 구하기
  // (x1, y1) 시작점
  // (x2, y2) 끝점
  const sum = (x1, x2, y1, y2) => {
    return d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
  };

  for (let x1 = 1; x1 <= N; x1++) {
    for (let y1 = 1; y1 <= M; y1++) {
      for (let x2 = x1; x2 <= N; x2++) {
        for (let y2 = y1; y2 <= M; y2++) {
          answer = Math.max(answer, sum(x1, x2, y1, y2));
        }
      }
    }
  }

  console.log(answer);
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
