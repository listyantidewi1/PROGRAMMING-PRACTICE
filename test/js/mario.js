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
var i = 0;
