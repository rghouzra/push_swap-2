#!/bin/bash

# Generate all possible lists of numbers from 1 to 6 with 6 digits, where each digit is unique
for i in $(seq 1 6); do
  for j in $(seq 1 6); do
    for k in $(seq 1 6); do
      for l in $(seq 1 6); do
        for m in $(seq 1 6); do
          for n in $(seq 1 6); do
            # Skip lists that have duplicate digits
            if [ "$i" != "$j" ] && [ "$i" != "$k" ] && [ "$i" != "$l" ] && [ "$i" != "$m" ] && [ "$i" != "$n" ] && [ "$j" != "$k" ] && [ "$j" != "$l" ] && [ "$j" != "$m" ] && [ "$j" != "$n" ] && [ "$k" != "$l" ] && [ "$k" != "$m" ] && [ "$k" != "$n" ] && [ "$l" != "$m" ] && [ "$l" != "$n" ] && [ "$m" != "$n" ]; then
              # Set the argument to the current list of numbers
              ARG="$i $j $k $l $m $n"

              # Compile the program using the current list of numbers as the argument
              # If the output is "OK", print "OK"
              # If the output is "KO", print "KO"
			  echo $ARG
              ./push_swap $ARG | ./checker_OS $ARG
            fi
          done
        done
      done
    done
  done
done

