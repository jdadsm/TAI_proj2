g++ src/main.cpp src/MarkovModel.cpp -o run -O3 
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    ./run
else
    echo "Compilation failed."
fi
rm run