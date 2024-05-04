import os
import csv
import re

def cleanData(inputFolder, testDataSize, outputFilePathPosTrain, outputFilePathNegTrain, outputFilePathPosTest, outputFilePathNegTest):
    inputFiles = os.listdir(inputFolder)
    print(inputFiles)
    
    # Compile regex pattern to match non-alphanumeric characters
    pattern = re.compile(r'[^a-zA-Z0-9\s]')
    
    testDataValue = 1/testDataSize*100
    
    with open(outputFilePathPosTrain, 'w', newline='') as outputFilePosTrain, open(outputFilePathNegTrain, 'w', newline='') as outputFileNegTrain, open(outputFilePathPosTest, 'w', newline='') as outputFilePosTest, open(outputFilePathNegTest, 'w', newline='') as outputFileNegTest:
        csv_writer_pos_train = csv.writer(outputFilePosTrain)
        csv_writer_neg_train = csv.writer(outputFileNegTrain)
        csv_writer_pos_test = csv.writer(outputFilePosTest)
        csv_writer_neg_test = csv.writer(outputFileNegTest)
        csv_writer_pos_train.writerow(['text'])
        csv_writer_neg_train.writerow(['text'])

        for fileName in inputFiles:
            filePath = os.path.join(inputFolder, fileName)
            
            print(filePath + "\n")
            
            with open(filePath, 'r') as inputFile:
                csv_reader = csv.reader(inputFile)
                
                headers = next(csv_reader)
                text_index = headers.index('text') if 'text' in headers else -1
                label_index = headers.index('label') if 'label' in headers else -1
                
                if text_index == -1 or label_index == -1:
                    print(f"Skipping file '{fileName}' due to missing 'text' or 'label' columns.")
                    continue
                
                n = 0
                for row in csv_reader:
                    text_value = row[text_index].replace('\n', '')
                    label_value = row[label_index]
                    
                    # Use regex to remove non-alphanumeric characters
                    text_value_cleaned = re.sub(pattern, '', text_value)
                    
                    if n%testDataValue == 0:
                        if label_value == '0':
                            csv_writer_neg_test.writerow([text_value_cleaned])
                        else:
                            csv_writer_pos_test.writerow([text_value_cleaned])
                    else:
                        if label_value == '0':
                            csv_writer_neg_train.writerow([text_value_cleaned])
                        else:
                            csv_writer_pos_train.writerow([text_value_cleaned])
                    n+=1

if __name__ == "__main__":
    inputFolder = "rawData"
    outputFilePathNegTrain = "data/neg_data_train.csv"
    outputFilePathPosTrain = "data/pos_data_train.csv"
    outputFilePathNegTest = "data/neg_data_test.csv"
    outputFilePathPosTest = "data/pos_data_test.csv"
    testDataSize = 5 # in percentage
    cleanData(inputFolder, testDataSize, outputFilePathPosTrain, outputFilePathNegTrain, outputFilePathPosTest, outputFilePathNegTest)
