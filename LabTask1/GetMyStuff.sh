#!/bin/bash

echo "File Name (MyStuff.txt):"
read filename
while read line;
do echo -e "$line";
done < $filename
