#!/bin/bash
rm result
if [ -s $1 ]
then
	grep "session is created" $1 > create.tmp
	grep "session destroyed, file" $1 > destroy.tmp
	gawk 'BEGIN{FS="[] /[]"} {print $2,$10}' create.tmp > create2.tmp
	gawk 'BEGIN{FS="[] /[]"} {print $11,$22,$23,$26}' destroy.tmp > destroy2.tmp
	cat create2.tmp | while read line
	do
		c_tm=`echo $line | gawk '{print $1}'`
		c_id=`echo $line | gawk '{print $2}'`
		cat destroy2.tmp | while read line2
		do
			d_id=`echo $line2 | gawk '{print $1}'`
			d_offset=`echo $line2 | gawk '{print $2}'`
			d_range=`echo $line2 | gawk '{print $3}'`
			d_duration=`echo $line2 | gawk '{print $4}'`
			if [ $d_id = $c_id ]
			then
				#echo $c_id,$d_id,$c_tm,$d_offset,$d_range,$d_duration >> result
				echo $c_tm  ${d_offset}${d_range}  $d_duration >> result
				break
			fi
		done
	done
else
	echo "the command is empty"
fi


rm -f *.tmp
