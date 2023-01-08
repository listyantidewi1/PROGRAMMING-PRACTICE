import csv
import sys
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    dna_database = {}
    with open(argv[1], newline='') as dna_db_file:
        reader = csv.reader(dna_db_file)

        # get the STR sequence from CSV file
        str_sequence = next(reader, None)[1:]  # make a new list without the first data
        for baris in reader:
            dna_database[baris[0]] = baris[1:]

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], "r") as dna_seq_file:
        dna_seq = dna_seq_file.read().rstrip('\n')


    # TODO: Find longest match of each STR in DNA sequence


    # count_AGATC = longest_match(dna_seq, "AGATC")
    # count_ATTTTTTCT= longest_match(dna_seq, "TTTTTTCT")
    # count_AATG= longest_match(dna_seq, "AATG")
    # count_TCTAG= longest_match(dna_seq, "TCTAG")
    # count_GATA= longest_match(dna_seq, "GATA")
    # count_TATC= longest_match(dna_seq, "TATC")
    # count_GAAA= longest_match(dna_seq, "GAAA")
    # count_TCTG= longest_match(dna_seq, "TCTG")

    matches = []

    for STR in str_sequence:
        matches.append(longest_match(dna_seq, STR))

    str_matches = map(str, matches)

    print(str_matches)
    print(dna_database)

    # print(count_AGATC)

    # TODO: Check database for matching profiles



    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
