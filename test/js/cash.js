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

var cents = get_cents();