echo "Enter the file name:"
read file
if [ -f "$file" ]; then
    echo "File exists."
else
    echo "File not found."
fi