#!/bin/tcsh

echo -n "Enter a number: "
set number = $<

if ($number =~ "") then
    echo "ERROR... nothing entered"
    exit
endif

set v = `df | grep sda1 | awk '{print $5}' | cut -c 1-2`

echo $v%

if ($v > $number) then
    echo The percentage is bigger than your number
else if ($v < $number) then
    echo The percentage is smaller than your number
else
    echo The percentage is equal to your number
endif
