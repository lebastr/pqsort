#!/usr/bin/env python3

import sys
import random
import string

MAX_KEY_VALUE = 123123

def generate_random_value():
    return "".join( [ random.choice( string.ascii_lowercase ) for _ in range( 1, MAX_VALUE_LEN ) ] )

def main():
    if len(sys.argv) < 4:
        print("Usage: {} <output dir> <test len> <tests count>".format(sys.argv[0]))
        sys.exit(1)

    output_dir = sys.argv[1]
    test_len = int(sys.argv[2])
    tests_cnt = int(sys.argv[3])

    for num in range(1, tests_cnt+1):
        values = list()
        output_filename_pattern = "{}/{:02d}".format(output_dir, num)
        output_filename = "{}.t".format(output_filename_pattern)

        with open( output_filename, 'w') as foutput:
            for _ in range( 0, test_len ):
                key = random.randint(0, MAX_KEY_VALUE)
                values.append(key)
                foutput.write("{}\n".format(key))

        answer_filename = "{}.a".format(output_filename_pattern)
        with open(answer_filename, 'w') as fans:
            values = sorted(values)
            for value in values:
                fans.write("{}\n".format(value))

if __name__ == "__main__":
    main()


