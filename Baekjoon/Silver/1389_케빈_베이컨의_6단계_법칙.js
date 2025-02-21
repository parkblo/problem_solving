/*
	INPUT
	1. N M
	2~. 간선 정보

	OUTPUT
	각 정점까지의 거리 합이 가장 작은 정점 번호

	PROCESS
	
*/

function solve() {
	let minBacon = Number.MAX_SAFE_INTEGER;
	let answer = 1;
	const [n, m] = input.shift().split(" ").map(Number);
	const g = Array.from({length: 101}, () => []);
	
	for (const line of input) {
		const [a, b] = line.split(" ").map(Number);
		g[a].push(b);
		g[b].push(a);
	}

	// bfs
	function bfs(start) {
		let bacon = 0;
		const vis = {};
		const q = [];

		vis[start] = 1;
		q.push([start,0]);

		while(q.length > 0) {
			const [curr, depth] = q.shift();
			for (const next of g[curr]) {
				if (vis[next]) continue;
				vis[next] = depth+1;
				q.push([next, depth+1]);
			}
		}

		for (const value of Object.values(vis)) {
			bacon += value;
		}

		return bacon-1;
	}

	for (let i=1; i<=n; i++) {
		const bacon = bfs(i);
		if (minBacon > bacon) {
			minBacon = bacon;
			answer = i;
		}
	}

	console.log(answer);
	return;
}

const fs = require("fs");
// const filePath = "./input.txt";
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solve();
