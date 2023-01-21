-- Keep a log of any SQL queries you execute as you solve the mystery.

--The CS50 Duck has been stolen! The town of Fiftyville has called upon you to solve the mystery of the stolen duck. Authorities believe that the thief stole the duck and then, shortly afterwards, took a flight out of town with the help of an accomplice. Your goal is to identify:

--Who the thief is,
--What city the thief escaped to, and
--Who the thief’s accomplice is who helped them escape
--All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

--How will you go about solving this mystery? The Fiftyville authorities have taken some of the town’s records from around the time of the theft and prepared a SQLite database for you, fiftyville.db, which contains tables of data from around the town. You can query that table using SQL SELECT queries to access the data of interest to you. Using just the information in the database, your task is to solve the mystery.

select * from crime_scene_reports where day = 28 and month = 7 and year = 2021 and street = "Humphrey Street";

--Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

-- get the transcript to know more about the interview
select * from interviews where transcript like '%bakery%';

--| id  |  name   | year | month | day |   transcript       |

--| 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
--| 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
--| 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

--get some license plate
select * from bakery_security_logs where year = 2021 and month = 7 and day = 28 and hour = 10;

/*+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 258 | 2021 | 7     | 28  | 10   | 8      | entrance | R3G7486       |
| 259 | 2021 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |*/

--whose plate are these?
select * from people where license_plate in
(select license_plate from bakery_security_logs where year = 2021 and month = 7 and day = 28 and hour = 10);
/*+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
| 325548 | Brandon | (771) 555-6667 | 7874488539      | R3G7486       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 652412 | Denise  | (994) 555-3373 | 4001449165      | NRYN856       |
| 660982 | Thomas  | (286) 555-0131 | 6034823042      | WD5M8I6       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
| 745650 | Sophia  | (027) 555-1068 | 3642612721      | 13FNH73       |
| 748674 | Jeremy  | (194) 555-5027 | 1207566299      | V47T75I       |
+--------+---------+----------------+-----------------+---------------+*/

--which of above persons had an atm transaction on july 28, 2021
sqlite> select people.name, people.phone_number, people.passport_number   ...> from people inner join bank_accounts
   ...> on people.id = bank_accounts.person_id
   ...> inner join atm_transactions
   ...> on bank_accounts.account_number = atm_transactions.account_number
   ...> where year = 2021 and day = 28 and month = 7 and name in
   ...> (select name from people where license_plate in
   ...> (select license_plate from bakery_security_logs
   ...> where year = 2021 and month = 7 and day = 28 and hour = 10));
/*+---------+----------------+-----------------+
|  name   |  phone_number  | passport_number |
+---------+----------------+-----------------+
| Bruce   | (367) 555-5533 | 5773159633      |
| Diana   | (770) 555-1861 | 3592750733      |
| Denise  | (994) 555-3373 | 4001449165      |
| Iman    | (829) 555-5269 | 7049073643      |
| Luca    | (389) 555-5198 | 8496433585      |
| Taylor  | (286) 555-6063 | 1988161715      |
| Brandon | (771) 555-6667 | 7874488539      |
| Jeremy  | (194) 555-5027 | 1207566299      |
| Barry   | (301) 555-4174 | 7526138472      |
+---------+----------------+-----------------+*/

sqlite> select * from airports;
/*+----+--------------+-----------------------------------------+---------------+
| id | abbreviation |                full_name                |     city      |
+----+--------------+-----------------------------------------+---------------+
| 1  | ORD          | O'Hare International Airport            | Chicago       |
| 2  | PEK          | Beijing Capital International Airport   | Beijing       |
| 3  | LAX          | Los Angeles International Airport       | Los Angeles   |
| 4  | LGA          | LaGuardia Airport                       | New York City |
| 5  | DFS          | Dallas/Fort Worth International Airport | Dallas        |
| 6  | BOS          | Logan International Airport             | Boston        |
| 7  | DXB          | Dubai International Airport             | Dubai         |
| 8  | CSF          | Fiftyville Regional Airport             | Fiftyville    |
| 9  | HND          | Tokyo International Airport             | Tokyo         |
| 10 | CDG          | Charles de Gaulle Airport               | Paris         |
| 11 | SFO          | San Francisco International Airport     | San Francisco |
| 12 | DEL          | Indira Gandhi International Airport     | Delhi         |
+----+--------------+-----------------------------------------+---------------+*/

--what's the earliest flight out of fiftyville tomorrow morning
sqlite> select * from flights where origin_airport_id = 8 and day = 29 and month = 7 and year = 2021 order by hour asc;
/*+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
+----+-------------------+------------------------+------+-------+-----+------+--------+*/

--these are the people who made phone calls that day, whose also had atm transaction and matched license plate .
select people.name, people.phone_number, people.passport_number
from people inner join bank_accounts
on people.id = bank_accounts.person_id
inner join atm_transactions
on bank_accounts.account_number = atm_transactions.account_number
where year = 2021 and day = 28 and month = 7 and name in
(select name from people where license_plate in
(select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10))
and phone_number in
(select caller from phone_calls where year = 2021 and month = 7 and day = 28);
/*+--------+----------------+-----------------+
|  name  |  phone_number  | passport_number |
+--------+----------------+-----------------+
| Bruce  | (367) 555-5533 | 5773159633      |
| Diana  | (770) 555-1861 | 3592750733      |
| Taylor | (286) 555-6063 | 1988161715      |
| Barry  | (301) 555-4174 | 7526138472      |
+--------+----------------+-----------------+*/

--who are among those 4 are aboard flight 36?
select * from passengers where flight_id = 36 and passport_number IN
(select people.passport_number
from people inner join bank_accounts
on people.id = bank_accounts.person_id
inner join atm_transactions
on bank_accounts.account_number = atm_transactions.account_number
where year = 2021 and day = 28 and month = 7 and name in
(select name from people where license_plate in
(select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10))
and phone_number in
(select caller from phone_calls where year = 2021 and month = 7 and day = 28));

/*+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 5773159633      | 4A   |
| 36        | 1988161715      | 6D   |
+-----------+-----------------+------+*/

--who did bruce and tayler called?
select * from phone_calls where caller in
(select people.phone_number
from people inner join bank_accounts
on people.id = bank_accounts.person_id
inner join atm_transactions
on bank_accounts.account_number = atm_transactions.account_number
where year = 2021 and day = 28 and month = 7 and name in
(select name from people where license_plate in
(select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10))
and phone_number in
(select caller from phone_calls where year = 2021 and month = 7 and day = 28)) and day = 28;

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 230 | (301) 555-4174 | (711) 555-3007 | 2021 | 7     | 28  | 583      |
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 236 | (367) 555-5533 | (344) 555-9601 | 2021 | 7     | 28  | 120      |
| 245 | (367) 555-5533 | (022) 555-4052 | 2021 | 7     | 28  | 241      |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 284 | (286) 555-6063 | (310) 555-8568 | 2021 | 7     | 28  | 235      |
| 285 | (367) 555-5533 | (704) 555-5790 | 2021 | 7     | 28  | 75       |
+-----+----------------+----------------+------+-------+-----+----------+

--whose phone number is in the receiver list?

select * from people where people.passport_number IN
(select passengers.passport_number from passengers where flight_id = 36 and passport_number IN
(select people.passport_number
from people inner join bank_accounts
on people.id = bank_accounts.person_id
inner join atm_transactions
on bank_accounts.account_number = atm_transactions.account_number
where year = 2021 and day = 28 and month = 7 and name in
(select name from people where license_plate in
(select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10))
and phone_number in
(select caller from phone_calls where year = 2021 and month = 7 and day = 28)));

+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+