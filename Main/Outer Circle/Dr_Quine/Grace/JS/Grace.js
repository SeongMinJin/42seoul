const { Console } = require("console");
const fs = require("fs");
const myLogger = new Console({
	stdout: fs.createWriteStream("./Grace_kid.js"),
});
const backTick = "`";
const s = `const { Console } = require("console");
const fs = require("fs");
const myLogger = new Console({
	stdout: fs.createWriteStream("./Grace_kid.js"),
});
const backTick = "%s";
const s = %s%s%s;
myLogger.log(s, backTick, backTick, s, backTick);`;
myLogger.log(s, backTick, backTick, s, backTick);
