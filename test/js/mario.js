var readlineSync = require('readline-sync');

//wait for user's response
// var userName = readlineSync.question('May I have your name?');
// console.log('Hi ' + userName + '!');

var height;
while((height <= 0) || (height > 8))
{
    height = readlineSync.question("Height: ");
}

//loop for the number of rows
for (let i = 0; i < height; i++)
{
    for (let k = height; k > i+1; k--)
    {
        console.log(" ");
    }

    for (let j = 0; j <= i; j++)
    {
        console.log("#");
    }

    console.log(" ");

    for (j = 0; j <= i; j++)
    {
        console.log("#");
    }

    console.log("\n");
}