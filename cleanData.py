import os
import csv

def cleanData(inputFolder, outputFilePathPos, outputFilePathNeg):
    inputFiles = os.listdir(inputFolder)
    print(inputFiles)
    
    with open(outputFilePathPos, 'w', newline='') as outputFilePos,open(outputFilePathNeg, 'w', newline='') as outputFileNeg:
        csv_writer_pos = csv.writer(outputFilePos)
        csv_writer_neg = csv.writer(outputFileNeg)
        csv_writer_pos.writerow(['text'])
        csv_writer_neg.writerow(['text'])

        for fileName in inputFiles:
            filePath = os.path.join(inputFolder,fileName)
            
            print(filePath+"\n")
            
            with open(filePath, 'r') as inputFile:
                csv_reader = csv.reader(inputFile)
                
                headers = next(csv_reader)
                text_index = headers.index('text') if 'text' in headers else -1
                label_index = headers.index('label') if 'label' in headers else -1
                
                if text_index == -1 or label_index == -1:
                    print(f"Skipping file '{fileName}' due to missing 'text' or 'label' columns.")
                    continue
                
                for row in csv_reader:
                    text_value = row[text_index].replace('\n', '')
                    label_value = row[label_index]
                    if label_value == '0':
                        csv_writer_neg.writerow([text_value])
                    else:
                        csv_writer_pos.writerow([text_value])

if __name__ == "__main__":
    inputFolder = "rawData"
    outputFilePathNeg = "data/neg_data.csv"
    outputFilePathPos = "data/pos_data.csv"
    cleanData(inputFolder,outputFilePathPos,outputFilePathNeg)