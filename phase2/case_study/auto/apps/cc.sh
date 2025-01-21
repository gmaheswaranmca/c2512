#!/bin/bash

# Check if a file is provided as an argument
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

# Check if the file exists
if [ ! -f "$1" ]; then
  echo "File not found: $1"
  exit 1
fi

# Copy file content to clipboard
if command -v xclip &> /dev/null; then
  xclip -selection clipboard < "$1"
  echo "Content copied to clipboard using xclip."
elif command -v xsel &> /dev/null; then
  xsel --clipboard < "$1"
  echo "Content copied to clipboard using xsel."
else
  echo "Neither xclip nor xsel is installed. Please install one of them."
  exit 1
fi
