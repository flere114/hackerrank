#!/bin/bash

read x

tmp=`echo ${x} | bc -l`

printf "%.3f\n" $tmp
