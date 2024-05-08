# How to run

- Run download.sh or download2.sh(bigger dataset)

- Then run cleanData.py (for download.sh) or cleanData2.py (for download2.sh)

- Finally run run.sh to train and test the model with default parameters
- Alternatively compile with g++ src/MarkovModel.cpp src/HashTable.cpp src/MainClass.cpp src/Metrics.cpp src/main.cpp src/*.hpp -o run -O3
- ./run (parametros)

- To get a predict to a single text file run run_label.sh with fixed text file
- Alternatively compile with g++ src/MarkovModel.cpp src/HashTable.cpp src/MainClass.cpp src/Metrics.cpp src/label_text.cpp src/*.hpp -o label -O3
- run with ./label path_to_text_file
