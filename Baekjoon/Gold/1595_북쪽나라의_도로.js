// BOJ 1595

/* 
1. 경로상에서 한 도시를 두 번 방문 불가한 전제
2. 모든 도시는 다른 모든 도시에 이동 가능
3. 모든 도로는 양방향

PROCESS (WRONG)
1. DFS를 통해 a->b 진행
2. 각 노드에 도착했을 시 지금까지의 합산 가중치를 기반으로 MAX 갱신

PROCESS
1. 임의의 정점 a에서 가장 먼 정점 b를 찾는다.
2. b에서 가장 먼 정점 c를 찾는다.
3. b와 c의 거리가 정답이다.

INPUT
"도시번호 도시번호 경로길이"의 연속

OUTPUT
거리가 가장 먼 두 도시 사이의 거리

INSIGHT
graph, visited를 object로 선언하기
*/

function solve(input) {
	let maxW = maxV = 0;
	
	// 인접 리스트 생성
	const graph = {};
	
	for (let line of input) {
		const [a, b, w] = line.split(" ").map(Number);
		if (!graph[a]) graph[a] = [];
		if (!graph[b]) graph[b] = [];
		graph[a].push([b,w]);
		graph[b].push([a,w]);
	}

	// DFS
	function dfs(curr, acc) {
		vis[curr] = 1;
		
		// 최대값 갱신
		if (acc > maxW) {
			maxW = acc;
			maxV = curr;
		}

		if (graph[curr]) {
			for (let [next, w] of graph[curr]) {
				if (!vis[next]) {
					vis[next] = 1;
					dfs(next, acc+w);
				}
			}
		}
	}

	// 1차 DFS
	let vis = {};
	dfs(1,0);

	// 2차 DFS
	vis = {};
	dfs(maxV,0);

	console.log(maxW);
	return;
}

const input = [];
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	input.push(line);
});

rl.on("close", () => {
	solve(input);
	process.exit();
});
