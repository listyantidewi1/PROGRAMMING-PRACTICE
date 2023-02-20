var readlineSync = require('readline-sync');

//wait for user's response
// var userName = readlineSync.question('May I have your name?');
// console.log('Hi ' + userName + '!');

var height = 0;
while ((height <= 0) || (height > 8) || (isNaN(height))) {
    height = readlineSync.question("Height: ");
}

//loop for the number of rows
for (let i = 0; i < height; i++) {
    for (let k = height; k > i + 1; k--) {
        process.stdout.write(" ");
    }

    for (let j = 0; j <= i; j++) {
        process.stdout.write("#");
    }

    process.stdout.write("  ");

    for (j = 0; j <= i; j++) {
        process.stdout.write("#");
    }

    process.stdout.write("\n");
}