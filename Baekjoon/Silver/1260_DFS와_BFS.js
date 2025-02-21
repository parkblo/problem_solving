function solve(N, M, V, input) {
	const graph = Array.from({ length: N + 1 }, () => []);
	const dfsvis = Array.from({ length: N + 1 }, () => 0);
	const bfsvis = Array.from({ length: N + 1 }, () => 0);

	// 인접 그래프 생성
	for (const [a, b] of input) {
		graph[a].push(b);
		graph[b].push(a);
	}

	// 정점 번호 오름차순 정렬
	for (let i = 0; i < graph.length; i++) {
		graph[i].sort((a, b) => a - b);
	}

	// DFS
	const dfsRet = [];
	
	function dfs(v) {
		if (dfsRet.length >= N) return;
		dfsvis[v] = 1;
		dfsRet.push(v);
		for (const next of graph[v]) {
			if (!dfsvis[next]) {
				dfsvis[next] = 1;
				dfs(next);
			}
		}
	}
	
	dfs(V);

	// BFS
	const bfsRet = [];
	const q = [];
	
	function bfs() {
		bfsvis[V] = 1;
		q.push(V);
		while (q.length > 0) {
			const front = q.shift();
			bfsRet.push(front);
			for (const next of graph[front]) {
				if (!bfsvis[next]) {
					bfsvis[next] = 1;
					q.push(next);
				}
			}
		}
	}
	
	bfs();

	console.log(dfsRet.join(" "));
	console.log(bfsRet.join(" "));
	return;
}

const input = [];
let cnt = (N = M = V = 0);
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	if (cnt === 0) {
		[N, M, V] = line.split(" ").map(Number);
	} else {
		input.push(line.split(" ").map(Number));
	}

	cnt++;
	if (cnt > M) rl.close();
});

rl.on("close", () => {
	solve(N, M, V, input);
	process.exit();
});
