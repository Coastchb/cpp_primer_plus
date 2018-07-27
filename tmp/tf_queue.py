import tensorflow as tf

placeholders = [
    tf.placeholder(tf.int32, [None, None], 'inputs'),
    tf.placeholder(tf.int32, [None], 'input_lengths'),
    tf.placeholder(tf.float32, [None, None, 2], 'mel_targets'),
    tf.placeholder(tf.float32, [None, None, 2], 'linear_targets')
]

# Create queue for buffering data:
queue = tf.FIFOQueue(8, [tf.int32, tf.int32, tf.float32, tf.float32], name='input_queue')
enqueue_op = queue.enqueue(placeholders)
inputs, input_lengths, mel_targets, linear_targets = queue.dequeue()

inputs.set_shape(placeholders[0].shape)
input_lengths.set_shape(placeholders[1].shape)
mel_targets.set_shape(placeholders[2].shape)
linear_targets.set_shape(placeholders[3].shape)

