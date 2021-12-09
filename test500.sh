#!/bin/bash

NUM500=0
MAX500=0
RES500="OK"
while [ $NUM500 -lt 5500 ] && [ $RES500 = "OK" ]
	do
		ARG500=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
		./push_swap $ARG500 > res500
		NUM500=`cat res500 | wc -l`
		echo $NUM500
		if [ $NUM500 -gt $MAX500 ]
		then
			MAX500=$NUM500
			echo $MAX500 > max500
		fi
		RES500=`cat res500 | ./checker_linux $ARG500`
		echo $RES500
	
done
echo $ARG500 > traces/arg500_bad
cp res500 traces/res500_bad
