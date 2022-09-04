import csv
import sys


def main():

    # TODO: Check for command-line usage

    # Ensure correct usage

    if(len(sys.argv) != 3):
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    database = sys.argv[1]

    with open(database) as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames[1:]
        strs_count = {}

    # TODO: Read DNA sequence file into a variable

        dna_file = open(sys.argv[2]).read()

    # TODO: Find longest match of each STR in DNA sequence

        for STR in strs:
            strs_count[STR] = longest_match(dna_file, STR)

    # TODO: Check database for matching profiles

        for person in reader:
            name = person['name']
            is_found = True

            for STR in strs:
                if int (person[STR]) != strs_count[STR]:
                    is_found = False
                    break

                if is_found:
                    print(name)
                    sys.exit(0)

        print('No Match')

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
