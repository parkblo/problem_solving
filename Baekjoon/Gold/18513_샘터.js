function solve(input) {
	const [N, K] = input[0].split(" ").map(Number);
	const 샘터위치배열 = input[1].split(" ").map(Number);
	let q = [];
	const occ = new Set();
	let cnt = 0;
	let ans = 0;

	for (const pos of 샘터위치배열) {
		q.push(pos);
		occ.add(pos);
	}

	// while (q.length > 0) {
	// 	if (cnt >= K) break;

	// 	const [currPos, currDis] = q.shift();

	// 	if (occ.has(currPos)) continue;

	// 	occ.add(currPos);
	// 	ans += currDis;
	// 	cnt++;

	// 	if (!occ.has(currPos - 1)) {
	// 		q.push([currPos - 1, currDis + 1]);
	// 	}
	// 	if (!occ.has(currPos + 1)) {
	// 		q.push([currPos + 1, currDis + 1]);
	// 	}
	// }

	let currDis = 0;
	while (q.length > 0) {
		const currQSize = q.length;
		const nextQ = [];
		
		for (let i=0; i<currQSize; i++) {
			if (cnt >= K) return ans;
			const currPos = q[i];
			
			if (!occ.has(currPos)) {
				occ.add(currPos);
				ans += currDis;
				cnt++;
			}
			
			if (!occ.has(currPos - 1)) {
				nextQ.push(currPos - 1);
			}
			if (!occ.has(currPos + 1)) {
				nextQ.push(currPos + 1);
			}
		}

		currDis++;
		q = [...nextQ];
	}

	return ans;
}

// IO
const input = [];
let cnt = 0;
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	input.push(line);
	cnt++;
	if (cnt >= 2) rl.close();
});

rl.on("close", () => {
	console.log(solve(input));
	process.exit();
});
