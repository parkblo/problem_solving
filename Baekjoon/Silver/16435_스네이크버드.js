function solve(input) {
	const [N, L] = input[0].split(" ").map(Number);
	const h = input[1].split(" ").map(Number);

	const sortedH = h.sort((a, b) => a - b);
	let currL = L;
	
	for (let i = 0; i < sortedH.length; i++) {
		if (currL >= sortedH[i]) currL++;
	}

	return currL;
}

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
