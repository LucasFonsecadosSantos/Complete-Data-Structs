#!/bin/sh
# BASH SCRIPT TO TESTS EXECUTE
# WROTE BY: LUCAS FONSECA DOS SANTOS

clear;
echo "+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+";
echo "+ |D|A|T|A| |S|T|R|U|C|T|U|R|E|   +";
echo "+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+";
echo "";
echo "+---------------------------------+";
echo "[#] CHOOSE THE OPTION:   ";
echo "				";
echo "[1]Linked Stack		";
echo "[2]Linked Queue		";
echo "[3]Linked List		";
echo "[4]Double Linked List	";
echo "[5]Linked Deque		";
echo "				";
echo "+---------------------------------+";

read OPTION;

if [$OPTION == 1]; then
	echo "hue";
else
	echo "fire";	
