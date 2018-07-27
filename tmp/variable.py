import tensorflow as tf

v = tf.get_variable("v", shape=(), initializer=tf.zeros_initializer());
w = v + 1;
print(v);
print(w);

def conv_relu(input, kernel_shape, bias_shape):
    weights = tf.get_variable("weights", kernel_shape,
                              initializer=tf.random_normal_initializer());
    bias = tf.get_variable("bias", bias_shape,
                           initializer=tf.constant_initializer(0.0));
    conv = tf.nn.conv2d(input, weights,
                        strides=[1, 1, 1, 1], padding="SAME");
    return tf.nn.relu(conv + bias);

input1 = tf.random_normal([1,10,10,32]);
input2 = tf.random_normal([1,20,20,32]);
x = conv_relu(input1, kernel_shape=[5, 5, 32, 32], bias_shape=[32]);
# y = conv_relu(input2, kernel_shape=[5, 5, 32, 32], bias_shape=[32]);

def my_image_filter(input_images):
    with tf.variable_scope("conv1"):
        relu1 = conv_relu(input_images, [5, 5, 32, 32], [32]);
    with tf.variable_scope("conv2"):
        return conv_relu(relu1, [5, 5, 32, 32], [32]);
