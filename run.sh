#!/bin/bash

if [ "$1" == "b" ]
then 
   echo ""
   echo "Starting Cleanup"
   echo ""
   make clean
   echo ""
   echo "Building Project"
   echo ""
   make 
   echo ""
   echo "Build Complete"
   echo ""
elif [ "$1" == "c" ]
then
   echo ""
   echo "Starting Cleanup"
   echo ""
   make clean
   echo ""
elif [ "$1" == "run-vm" ]
then
    echo "Running Project: VM"
    echo ""
    make file=$2 run_vm
    echo ""
elif [ "$1" == "run-assembler" ]
then
    echo "Running Project: Assembler"
    echo ""
    make file=$2 run_assembler
    echo ""
else
   echo ""
   echo "Unrecognized Commandline Argument"
   echo ""
fi