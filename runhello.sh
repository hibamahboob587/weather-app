#!/bin/bash


gcc -o hello hello.c alert.c -lcurl -ljansson

# Set the path to your C executable
EXECUTABLE=./hello

# Run the C code to fetch weather data and parse it
$EXECUTABLE

# Sleep for an hour (3600 seconds) before running again
sleep 3600

# Run the script again
exec "$0"
