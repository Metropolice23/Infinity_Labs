#!/bin/bash
echo "Enter service name"
read fn
systemctl status $fn

echo "---- M E N U ----"
echo "1) Start"
echo "2) Stop"
echo "3) Exit"
echo "Please enter your choice: "
read fp
if [[ $fp -eq 1 ]]
then 
	systemctl start $fn
elif [[ $fp -eq 2 ]]
then
	systemctl stop $fn
elif [[ $fp -eq 3 ]]
then
	echo "exit"
fi
