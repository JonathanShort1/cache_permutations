#!/usr/bin/bash

out_dir="/tmp/js321/uras"

echo "clearing $out_dir"
rm -rf $out_dir/*

for i in {12..28}
do
    n=$((2**$i))
    name=$((n*4))
    out="$out_dir/random-$name.bin"
    echo $n $out
    ./generate_data $n $out
done
