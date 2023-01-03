#!/bin/bash
if [ -f "$1" ]
then
	echo "Arguments is afile, displaying its content ..."
	sleep 1
	cat $1

fi
