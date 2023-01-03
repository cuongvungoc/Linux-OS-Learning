#!/bin/bash
PS3="Your choice:"
select ITEM in "Add User" "List All Process" "Kill Process" "Install Program" "Quit"
do
if [[ $REPLY -eq 1 ]]
then
	read -p "Enter the username:" username
	output="$grep -w $username /etc/passwd)"
	if [[ -n "$output" ]]
	then
		echo "The username $username already exixt."
	else
		sudo useradd -m -d /bin/bash "$username"
ifZZZZZ
