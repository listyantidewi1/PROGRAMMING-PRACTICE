var readlineSync = require('readline-sync');

var text = readlineSync.question("Text: ");

//remove space and any symbols
const lettersOnly = text.replace(/[^a-z]/gi, '');

//count the number of letters
const num_letters = lettersOnly.length;

//console.log(num_letters);

