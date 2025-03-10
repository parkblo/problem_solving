function solve(input) {
  const N = Number(input.shift());
  const fixAr = [...input].sort((a, b) => a.length - b.length);
  const [a, b] = fixAr.slice(fixAr.length - 2);

  // 후보 생성 (a+b or b+a)
  const first = Array.from({ length: N }, () => null);
  for (let i = 0; i < a.length; i++) {
    first[i] = a[i];
  }
  for (let i = N - b.length, j = 0; i < N; i++, j++) {
    if (first[i]) continue;
    first[i] = b[j];
  }

  const second = Array.from({ length: N }, () => null);
  for (let i = 0; i < b.length; i++) {
    second[i] = b[i];
  }
  for (let i = N - a.length, j = 0; i < N; i++, j++) {
    if (second[i]) continue;
    second[i] = a[j];
  }

  const 후보 = [first, second];

  function isPrefix(target, fix) {
    for (let i = 0; i < fix.length; i++) {
      if (target[i] !== fix[i]) return false;
    }
    return true;
  }

  function isSuffix(target, fix) {
    for (let i = N - fix.length, j = 0; i < N; i++, j++) {
      if (target[i] !== fix[j]) return false;
    }
    return true;
  }

  const prefixSet = new Set();

  for (const S of 후보) {
    let answer = "";
    let flag = true;

    for (const fixString of input) {
      const fix = fixString.split("");

      const isPre = isPrefix(S, fix);
      const isSuf = isSuffix(S, fix);
      const hasSet = prefixSet.has(fixString);

      if (isPre && !isSuf) {
        if (!hasSet) prefixSet.add(fixString);
        answer += "P";
      } else if (isPre && isSuf) {
        if (hasSet) {
          answer += "S";
        } else {
          prefixSet.add(fixString);
          answer += "P";
        }
      } else if (!isPre && isSuf) {
        answer += "S";
      } else {
        flag = false;
        break;
      }
    }

    if (flag) {
      console.log(S.join(""));
      console.log(answer);
      return;
    }
  }

  return;
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
