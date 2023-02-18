var readlineSync = require('readline-sync');

//wait for user's response
var userName = readlineSync.question('May I have your name?');
console.log('Hi ' + userName + '!');

