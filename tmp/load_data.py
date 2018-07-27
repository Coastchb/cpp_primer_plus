import tensorflow as tf
import iris_data

train_dataset_fp = "/Users/coast/.keras/datasets/tmp.csv";



dataset = tf.data.TextLineDataset(train_dataset_fp).skip(1);
print("0");
print(dataset);

CSV_COLUMN_NAMES = ['SepalLength', 'SepalWidth',
                    'PetalLength', 'PetalWidth', 'Species']
CSV_TYPES = [[0.0], [0.0], [0.0], [0.0], [0]]

def _parse_line(line):
    # Decode the line into its fields
    fields = tf.decode_csv(line, record_defaults=CSV_TYPES)

    # Pack the result into a dictionary
    features = dict(zip(CSV_COLUMN_NAMES, fields))

    # Separate the label from the features
    label = features.pop('Species')
    print(features);
    print(label);
    return features, label

dataset = dataset.map(_parse_line);
print("1");
print(dataset);
dataset = dataset.shuffle(1000).repeat().batch(100)
print("2");
print(dataset);

def csv_input_fn(csv_path, batch_size):
    # Create a dataset containing the text lines.
    dataset = tf.data.TextLineDataset(csv_path).skip(1)
    print("csv_input_fn 0:");
    print(dataset);
    # Parse each line.
    dataset = dataset.map(_parse_line)
    print("csv_input_fn 1:");
    print(dataset);
    # Shuffle, repeat, and batch the examples.
    dataset = dataset.shuffle(1000).repeat().batch(batch_size)
    print("csv_input_fn 2:");
    print(dataset);
    # Return the dataset.
    return dataset

dtt = csv_input_fn(train_dataset_fp,100);
print("3")
print(dtt);