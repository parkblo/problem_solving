/**
 * FLOW
 * - 시간 제한이 0.5초로 빡빡하다.
 * - 완탐으로 해도 O(n)에 풀릴 것 같은데?
 * - 아니다, 쿼리가 10만이 가능하기 때문에 최대 100억 연산이 뜰 것 같다.
 * - 실수가 일어난 횟수를 누적합으로 기억해두어서 써먹어야겠다 !
 *
 * LOGIC
 * 1. x부터 y까지의 인덱스를 탐색함
 * 2. score[i-1]이 score[i]의 값보다 높다면 ret++함
 * 3. 마지막 인덱스에서는 ret++이 일어나지 않는다.
 */

function solve(input) {
  const score = input[1].split(" ").map(Number);
  const query = input.slice(3);
  const answer = [];

  // 누적합 만들기
  const presum = Array.from({ length: 100001 }, () => 0);

  for (let i = 1; i < score.length; i++) {
    if (score[i] < score[i - 1]) {
      presum[i] = presum[i - 1] + 1;
    } else {
      presum[i] = presum[i - 1];
    }
  }

  // 쿼리 처리하기
  for (let i = 0; i < query.length; i++) {
    const [x, y] = query[i].split(" ").map(Number);

    answer.push(presum[y - 1] - presum[x - 1]);
  }

  console.log(answer.join("\n"));
}

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve(input);
