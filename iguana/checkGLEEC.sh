#!/bin/bash

# checkGLEEC.sh - Script to verify GLEEC installation

# Define directories
GLEEC_OLD_DIR="$HOME/.komodo/GLEEC_OLD"
GLEEC_DIR="$HOME/.komodo/GLEEC"

# Define block files
OLD_BLOCK_FILE="$GLEEC_OLD_DIR/blocks/blk00000.dat"
GLEEC_BLOCK_FILE="$GLEEC_DIR/blocks/blk00000.dat"

# Expected magic bytes in hexadecimal
OLD_EXPECTED="dd1ac36c"
GLEEC_EXPECTED="dce12147"

# ANSI color codes
LIGHT_GREEN="\e[92m"
LIGHT_RED="\e[91m"
NO_COLOR="\e[0m"

# Function to output error and exit
error_exit() {
    echo -e "${LIGHT_RED}Error: $1${NO_COLOR}"
    exit 1
}

# Check if GLEEC_OLD directory exists
if [ ! -d "$GLEEC_OLD_DIR" ]; then
    error_exit "Directory $GLEEC_OLD_DIR does not exist."
fi

# Check if GLEEC directory exists
if [ ! -d "$GLEEC_DIR" ]; then
    error_exit "Directory $GLEEC_DIR does not exist."
fi

# Check if blk00000.dat exists in GLEEC_OLD
if [ ! -f "$OLD_BLOCK_FILE" ]; then
    error_exit "File $OLD_BLOCK_FILE does not exist."
fi

# Check if blk00000.dat exists in GLEEC
if [ ! -f "$GLEEC_BLOCK_FILE" ]; then
    error_exit "File $GLEEC_BLOCK_FILE does not exist."
fi

# Function to get first 4 bytes as lowercase hex
get_first4bytes_hex() {
    local file="$1"
    xxd -p -l4 "$file" | tr -d '\n' | tr '[:upper:]' '[:lower:]'
}

# Get first 4 bytes of GLEEC_OLD block file
OLD_HEX=$(get_first4bytes_hex "$OLD_BLOCK_FILE")

# Get first 4 bytes of GLEEC block file
GLEEC_HEX=$(get_first4bytes_hex "$GLEEC_BLOCK_FILE")

# Check magic bytes for GLEEC_OLD
if [ "$OLD_HEX" != "$OLD_EXPECTED" ]; then
    error_exit "First 4 bytes of $OLD_BLOCK_FILE are not $OLD_EXPECTED."
fi

# Check magic bytes for GLEEC
if [ "$GLEEC_HEX" != "$GLEEC_EXPECTED" ]; then
    error_exit "First 4 bytes of $GLEEC_BLOCK_FILE are not $GLEEC_EXPECTED."
fi

# If all checks pass, output success message in light green
echo -e "${LIGHT_GREEN}GLEEC install - Ok!${NO_COLOR}"

exit 0
