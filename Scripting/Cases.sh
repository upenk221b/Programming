#!/bin/bash
echo -e "Enter a character :\c"
echo $LANG
read choice
case $choice in
	[a-z] ) 
	echo  "$choice is between [a-z] " ;;
	[A-Z] ) 
	echo  "$choice is between [A-Z] " ;;
	[0-9] ) 
	echo  "$choice is between [0-9] " ;;
	? ) 
	echo  "$choice is special character " ;;
	* )
	echo "Unknown input" ;;
esac