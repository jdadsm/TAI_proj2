import csv
import os

csv.field_size_limit(10 * 1024 * 1024)

def calculate_file_size(file_path):
    # Calculate the size of a file in bytes
    return os.path.getsize(file_path)

def reduce_csv_file_size(input_file_path, output_file_path, target_size_mb):
    target_size_bytes = target_size_mb * 1024 * 1024  # Convert MB to bytes
    current_size_bytes = calculate_file_size(input_file_path)

    with open(input_file_path, 'r', newline='', encoding='utf-8') as input_file:
        csv_reader = csv.reader(input_file)
        header = next(csv_reader)  # Read the header (first row)

        # Initialize variables for writing trimmed content to output file
        with open(output_file_path, 'w', newline='', encoding='utf-8') as output_file:
            csv_writer = csv.writer(output_file)
            csv_writer.writerow(header)  # Write the header to the output file

            # Calculate and remove lines until file size meets the target
            for row in csv_reader:
                row_size_bytes = len(','.join(row).encode('utf-8')) + len(os.linesep.encode('utf-8'))
                if current_size_bytes > target_size_bytes:
                    current_size_bytes -= row_size_bytes
                else:
                    csv_writer.writerow(row)

    print(f"Reduced '{input_file_path}' to '{output_file_path}' with target size of {target_size_mb} MB")

if __name__ == "__main__":
    input_file_path = 'data/neg_data_train.csv'  # Path to the input CSV file
    output_file_path = 'data/neg_data_train2.csv'  # Path to the output trimmed CSV file
    target_size_mb = 110  # Target size in MB

    reduce_csv_file_size(input_file_path, output_file_path, target_size_mb)
    
    input_file_path = 'data/neg_data_test.csv'  # Path to the input CSV file
    output_file_path = 'data/neg_data_test2.csv'  # Path to the output trimmed CSV file
    target_size_mb = 2.8  # Target size in MB

    reduce_csv_file_size(input_file_path, output_file_path, target_size_mb)
