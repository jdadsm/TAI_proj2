g++ src/MarkovModel.cpp src/HashTable.cpp src/MainClass.cpp src/Metrics.cpp src/label_text.cpp src/*.hpp -o label -O3 
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    ./label data/ai_sentence.txt
else
    echo "Compilation failed."
fi
rm label