#!/bin/sh
BASENAME="testMap.dab"
SIZEX=64
SIZEY=64

#if [ $# == 0 ]; then
#    exit 0
#fi
#BASENAME=$1
echo -e -n "[Map\n[Size\nx = $SIZEX\ny = $SIZEY\n]\n{map\n" > $BASENAME
for ((J=0;$J<$SIZEY;$((J+=1))))
do
    STR=""
    for ((I=0;$I<$SIZEX;$((I+=1))))
    do
	VALUE=0
	RAND=$((RANDOM % 100))
	if [ $RAND -lt 15 ]; then
	    VALUE=1
	elif [ $RAND -lt 20 ]; then
	    VALUE=2
	fi
        if [ $I == $((SIZEX - 1)) ] && [ $J == $((SIZEY - 1)) ]; then
	    STR="$STR$VALUE"
	    #echo -n "$VALUE" >> $BASENAME
	else
	    STR="$STR$VALUE,"
	    #echo -n "$VALUE," >> $BASENAME
	fi
    done
    echo -n $STR >> $BASENAME
    echo -e -n "\n" >> $BASENAME
done
echo -e "}\n]" >> $BASENAME
