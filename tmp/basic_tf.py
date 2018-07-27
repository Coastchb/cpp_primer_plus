from __future__ import absolute_import, print_function, division
import tensorflow as tf
import numpy as np

###
### mark 1: sess.run(arg), arg can be a tf.Tensor, a tuple or a dictionary.
###         run on tf.Tensor to retrieve the value(s)
### mark 2: During a call to tf.Session.run any tf.Tensor only has a single value.
### mark 3: A placeholder is a promise to provide a value later, like a function argument.
### mark 5: To apply a layer to an input, call the layer as if it were a function

a = tf.constant(3.0, dtype=tf.float32);
b = tf.constant(4.0);
total = a + b;
print("====tf.Tensor====");
print(a);
print(b);
print(total);
print()

writer = tf.summary.FileWriter('.');
writer.add_graph(tf.get_default_graph());

sess = tf.Session();

### mark 1
print("====constant====");
print(sess.run(total));
print(sess.run((a,b)));
print(sess.run({'ab':(a,b),'total':total}));
print()

### mark 2
print("====fixed during a run====");
vec = tf.random_uniform(shape=(3,));
out1 = vec + 1;
out2 = vec + 2;
print(vec);
print(sess.run(vec));
print(sess.run(vec));
print(sess.run((out1,out2)));
print()

### mark 3
print("====feed====");
x = tf.placeholder(tf.float32);
y = tf.placeholder(tf.float32);
z = x + y;
print(x);
print(z);
print(sess.run(z, feed_dict={x:1,y:3}));
print(sess.run(z,feed_dict={x:[1,2],y:[3,6]}));
print();

### mark 4
print("====dataset====");
my_data = [
    [0, 1],
    [2, 3],
    [4, 5],
    [6, 7]
];
slices = tf.data.Dataset.from_tensor_slices(my_data);
next_item = slices.make_one_shot_iterator().get_next();
print(slices);
print(next_item);

while True:
    try:
        print(sess.run(next_item));
    except tf.errors.OutOfRangeError:
        break;
print();

### mark 5
print("====layers====");
x = tf.placeholder(tf.float32, shape=[None,3]);
linear_model = tf.layers.Dense(units=1);
y = linear_model(x);

init = tf.global_variables_initializer();
sess.run(init);

print(sess.run(y, {x:[[1,2,3],[4,5,6]]}));
print();

### mark 6
print("====feature column====");
features = {
    'sales': [[5], [10], [8], [9]],
    'department': ['sports', 'sports', 'gardening', 'gardening']
};
department_column = tf.feature_column.categorical_column_with_vocabulary_list('department', ['sports', 'gardening']);
department_column = tf.feature_column.indicator_column(department_column);

columns = [
    tf.feature_column.numeric_column('sales'),
    department_column
]
inputs = tf.feature_column.input_layer(features, columns);

var_init = tf.global_variables_initializer();
table_init = tf.tables_initializer();
sess.run((var_init, table_init));
print(sess.run(inputs));
print();