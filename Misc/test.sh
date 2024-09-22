#!/usr/bin/bash
for ((i=0;;i++))
do
python gen.py > case.in
./A < case.in > aout
./B < case.in > bout

if ! (cmp -s aout bout);
then
cat case.in
fi

done
