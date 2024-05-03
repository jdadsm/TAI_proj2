import os
import csv

def cleanData(inputFolder, outputFilePath):
    inputFiles = os.listdir(inputFolder)
    print(inputFiles)
    
    with open(outputFilePath, 'w', newline='') as outputFile:
        csv_writer = csv.writer(outputFile)
        csv_writer.writerow(['text', 'label'])

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
                    text_value = row[text_index]
                    label_value = row[label_index]
                    csv_writer.writerow([text_value, label_value])

if __name__ == "__main__":
    inputFolder = "rawData"
    outputFilePath = "data/data.csv"
    cleanData(inputFolder,outputFilePath)