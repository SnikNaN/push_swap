#!/bin/bash

NUM100=0
MAX100=0
RES100="OK"
while [ $NUM100 -lt 700 ] && [ $RES100 = "OK" ]
	do
		ARG100=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
		./push_swap $ARG100 > res100
		NUM100=`cat res100 | wc -l`
		echo $NUM100
		if [ $NUM100 -gt $MAX100 ]
		then
			MAX100=$NUM100
			echo $MAX100 > max100
		fi
		RES100=`cat res100 | ./checker_linux $ARG100`
		echo $RES100
	
done
echo $ARG100 > traces/arg100_bad
cp res100 traces/res100_bad
