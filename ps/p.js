function solve(input) {
  let board = input.shift().split("");

  function checkA(board, start) {
    let ans = 0;
    for (let i = start; i < start + 4 && i < board.length; i++) {
      if (board[i] === "X") ans++;
      else return false;
    }

    if (ans < 4) return false;
    return true;
  }

  function checkB(board, start) {
    let ans = 0;
    for (let i = start; i < start + 2 && i < board.length; i++) {
      if (board[i] === "X") ans++;
      else return false;
    }

    if (ans < 2) return false;
    return true;
  }

  for (let i = 0; i < board.length; i++) {
    if (board[i] === "X") {
      if (checkA(board, i)) {
        for (let j = i; j < i + 4; j++) {
          board[j] = "A";
        }
      } else if (checkB(board, i)) {
        for (let j = i; j < i + 2; j++) {
          board[j] = "B";
        }
      }
    }
  }

  if (board.includes("X")) console.log("-1");
  else console.log(board.join(""));
  return;
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
