/**
 * IDEA
 * 한 팀만의 조합을 구하고, 없다면 다른 팀에 있다고 가정
 */

function solve(input) {
  const n = Number(input.shift());
  const s = input.map((e) => e.split(" ").map(Number));
  const linkCases = [];
  let answer = Number.MAX_SAFE_INTEGER;

  // 조합 구하기
  function comb(curr, i) {
    if (curr.length > 0) {
      linkCases.push([...curr]);
    } else if (curr.length >= n) return;

    for (let j = i; j <= n; j++) {
      curr.push(j);
      comb(curr, j + 1);
      curr.pop();
    }
  }

  comb([], 1);

  for (let i = 0; i < linkCases.length; i++) {
    let linkScore = (startScore = 0);

    // 팀 구성
    const teamLink = [];
    const teamStart = [];
    for (let j = 1; j <= n; j++) {
      if (linkCases[i].includes(j)) {
        teamLink.push(j);
      } else {
        teamStart.push(j);
      }
    }

    // 팀 내 시너지 합산
    for (let i = 0; i < teamLink.length - 1; i++) {
      for (let j = i + 1; j < teamLink.length; j++) {
        const [a, b] = [teamLink[i] - 1, teamLink[j] - 1];
        linkScore += s[a][b] + s[b][a];
      }
    }

    for (let i = 0; i < teamStart.length - 1; i++) {
      for (let j = i + 1; j < teamStart.length; j++) {
        const [a, b] = [teamStart[i] - 1, teamStart[j] - 1];
        startScore += s[a][b] + s[b][a];
      }
    }

    answer = Math.min(Math.abs(linkScore - startScore), answer);
  }

  console.log(answer);
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
