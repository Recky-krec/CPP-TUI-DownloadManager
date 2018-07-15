#!/bin/bash

mkdir Build; cd Build; cmake ../.; make;

echo "Run the executable?(y/n)";
MY_CHAR=n
read MY_CHAR

if [ $MY_CHAR = "y" ] 
	then ./CPP_TUI_DownloadManager
fi

