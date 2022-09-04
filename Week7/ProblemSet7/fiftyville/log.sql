-- Keep a log of any SQL queries you execute as you solve the mystery.

-- SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time –
-- each of their interview transcripts mentions the bakery.

------------------------------------------------------------------------------------------------

-- SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- First, 10 minutes within the theft, theif got in a car and run away
-- Second, after leaving the bakery, they planned to take the earliest flight out of Fiftyville tomorrow.
-- And they told to purchase Flight Ticket
-- Third, that morning they were withdrawing some money from ATM in legget street.

------------------------------------------------------------------------------------------------

-- SELECT activity, license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 18 AND 25;

-- FROM security log, I got license_plate of 8 cars exiting.

-- SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- FROM atm, I got 8 bankaccount transactions

-- SELECT name, phone_number, passport_number
-- FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
-- WHERE year = 2021 AND month = 7 AND day = 28
-- AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit'

-- I got 8 names of license_plates

-- SELECT name FROM people
-- JOIN bank_accounts ON people.id = bank_accounts.person_id
-- JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
-- WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- I got 4 suspects

-- SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND duration < 60; -- this is Bruce
-- SELECT receiver FROM phone_calls WHERE caller = '(770) 555-1861' AND duration < 60; -- this is Diana

-- SELECT flight_id FROM passengers where passport_number = '3592750733';
-- flight id = 36 (Bruce)
-- flight id = 18, 24, 54 (Diana)

-- SELECT year, month, day, hour, minute FROM flights where ID = 36;
-- Victim is Bruce.

-- SELECT origin_airport_id, destination_airport_id FROM flights where ID = 36;

-- destination = 4, origin = 8

-- SELECT abbreviation, full_name, city FROM airports WHERE id = 4;

-- Thief will leave New York

-- SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND duration < 60 AND year = 2021 AND day = 28 AND month = 7;

-- receiver number is (375) 555-8161

SELECT name FROM people WHERE phone_number ='(375) 555-8161';