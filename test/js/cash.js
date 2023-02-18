var readlineSync = require('readline-sync');

get_cents = () => {
    var cents = -1;
    while (cents < 0) {
        cents = readlineSync.question("Change owed: ");
    }
    return cents;
}

calculate_quarters = (cents) => {
    var quarters = cents / 25;
    return quarters;
}

calculate_dimes = (cents) => {
    var dimes = cents / 10;
    return dimes;
}

calculate_nickels = (cents) => {
    var nickels = cents / 5;
    return nickels;
}

calculate_pennies = (cents) => {
    return cents;
}

var cents = get_cents();

var quarters = calculate_quarters(cents);
cents = cents - quarters * 25;

var dimes = calculate_dimes(cents);
cents = cents - dimes * 10;

var nickels = calculate_nickels(cents);
cents = cents - nickels * 5;

var pennies = calculate_pennies(cents);
cents = cents - pennies * 1;

var coins = quarters + dimes + nickels + pennies;

console.log(coins);