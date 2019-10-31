#!/usr/bin/bash

in_dir="/tmp/js321/uras"

for f in `ls -rS $in_dir/*.bin`
do
    ./check $f
done
