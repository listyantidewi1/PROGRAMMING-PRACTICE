var readlineSync = require('readline-sync');

var text = readlineSync.question("Text: ");

//remove space and any symbols
const lettersOnly = text.replace(/[^a-z]/gi, '');

//count the number of letters
const num_letters = lettersOnly.length;

//console.log(num_letters);

//count the number of words
const words = text.split(" ");
const num_words = words.length - 1;
//console.log(num_words);

//count the number of sentences
const sentences = text.split(/[.!?]+/);
const num_sentences = sentences.length;
//console.log(num_sentences);

//calculate index
var l = num_letters / num_words * 100;
var s = num_sentences / num_words * 100;
var index = Math.floor(0.0588 * l - 0.296 * s - 15.8);

// console.log("l: ", l);
// console.log("s: ", s);
// console.log("index: ", index);

if (index < 1) {
    console.log("Before Grade 1");
} else if (index > 16) {
    console.log("Grade 16+");
} else {
    console.log("Grade " + index);
}