const { Console } = require("console");
const { exec } = require("child_process");
const fs = require("fs");
const path = require("path");
const backTick = "`";
const dollar = "$";
const s = `const { Console } = require("console");
const { exec } = require("child_process");
const fs = require("fs");
const path = require("path");
const backTick = "%s";
const dollar = "%s";
const s = %s%s%s;
const main = async () => {
	
	let i = %i
	
	if (i < 1) return;

	if (path.basename(__filename) !== "Sully.js") --i;
	
	const myLogger = new Console({
		stdout: fs.createWriteStream(%s./Sully_%s{i}.js%s),
	});

	myLogger.log(s, backTick, dollar, backTick, s, backTick, i, backTick, dollar, backTick, backTick, dollar, backTick);
	if (i > 0) {
		await exec(%snode ./Sully_%s{i}%s);
	}
}
main();`;
const main = async () => {
	
	let i = 5;

	if (i < 1) return;

	if (path.basename(__filename) !== "Sully.js") --i;
	const myLogger = new Console({
		stdout: fs.createWriteStream(`./Sully_${i}.js`),
	});

	myLogger.log(s, backTick, dollar, backTick, s, backTick, i, backTick, dollar, backTick, backTick, dollar, backTick);
	if (i > 0) {
		await exec(`node ./Sully_${i}`);
	}
}
main();