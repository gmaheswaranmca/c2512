#!/bin/bash

# Directory variables
DirApp="./App"
DirLibSun="./LibSun"
DirLibSunTest="./LibSunTest"

# Function to print usage 
printUsage() { 
	printf "Usage:\n"
	printf "\t$0 build all\n"
	printf "\t$0 build app\n"
	printf "\t$0 build lsun\n"
	printf "\t$0 build lsuntest\n"
	echo 
	printf "\t$0 clean all\n"
	printf "\t$0 clean app\n"
	printf "\t$0 clean lsun\n"
	printf "\t$0 clean lsuntest\n"
	echo 
	printf "\t$0 print all\n"
	printf "\t$0 print app\n"
	printf "\t$0 print lsun\n"
	printf "\t$0 print lsuntest\n"
}

# Function to build using make
makeBuild() {	
	Arg=$1
	if [ $Arg == "build" ]; then
		Arg=""
	fi;
	case $2 in
		all) 
			make -C $DirLibSun $Arg
			make -C $DirApp $Arg
			make -C $DirLibSunTest $Arg
			;;
		app) 
			make -C $DirApp $Arg
			;;
		lsun) 
			make -C $DirLibSun $Arg
			;;
		lsuntest) 
			make -C $DirLibSunTest $Arg
			;;
		*) 
			printUsage
			exit 1
			;;
	esac
}

# Check for required arguments
if [ $# -eq 1 ]; then 
	case $1 in 
		run) 
			make -C $DirApp "run"
			;;
		testsun)
			make -C $DirLibSunTest "test"
			;;
	esac
	exit 0
elif [ $# -lt 2 ] || [ -z "$1" ]; then
	printUsage
	exit 1
fi

# Execute the function with the passed arguments
makeBuild $1 $2
