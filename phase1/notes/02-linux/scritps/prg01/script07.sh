if [ $# -lt 2 ]; then
    echo "Usage: $0 arg1 arg2"
else
    echo "First argument: $1"
    echo "Second argument: $2"
    echo $(($1 + $2))
fi