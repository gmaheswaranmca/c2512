echo "Enter the file name:"
read file
if [ -f "$file" ]; then
    echo "Lines: $(wc -l < $file)"
    echo "Words: $(wc -w < $file)"
    echo "Characters: $(wc -c < $file)"
else
    echo "File not found."
fi