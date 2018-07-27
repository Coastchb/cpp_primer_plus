import tensorflow as tf

c_0 = tf.constant(0, name="c");

#c_0.eval(); ### OK only if a session is active

c_1 = tf.constant(2, name="c");

with tf.name_scope("outer"):
    c_2 = tf.constant(2, name="c");

    with tf.name_scope("inner"):
        c_3 = tf.constant(3, name="c");

    c_4 = tf.constant(4, name="c");

    with tf.name_scope("inner"):
        c_5 = tf.constant(5, name="c");

c_6 = tf.constant(6);
d = tf.add(c_0,c_1);

print(c_0);
print(c_1);
print(c_2);
print(c_3);
print(c_4);
print(c_5);
print(c_6);
print(d);

#writer.add_graph(tf.get_default_graph());

x = tf.constant([[37.0, -23.0], [1.0, 4.0]])
w = tf.Variable(tf.random_uniform([2, 2]))
y = tf.matmul(x, w)
output = tf.nn.softmax(y)
init_op = w.initializer

with tf.Session() as sess:
  # Run the initializer on `w`.
  sess.run(init_op)

  print("output c_1 value by c_1.eval(): %d " % c_1.eval());
  # Evaluate `output`. `sess.run(output)` will return a NumPy array containing
  # the result of the computation.
  print(sess.run(output))

  # Evaluate `y` and `output`. Note that `y` will only be computed once, and its
  # result used both to return `y_val` and as an input to the `tf.nn.softmax()`
  # op. Both `y_val` and `output_val` will be NumPy arrays.
  y_val, output_val = sess.run([y, output])

  print(y_val);
  print(output_val);
  writer = tf.summary.FileWriter(".", graph=sess.graph);

g_1 = tf.Graph();
with g_1.as_default():
    c = tf.constant("constant in g_1");
    sess_1 = tf.Session();
    print(sess_1.run(c));
    print(tf.rank(c));
    print(c.shape);
    print(c.dtype);

g_2 = tf.Graph();
with g_2.as_default():
    d = tf.constant("constant in g_2");
sess_2 = tf.Session(graph=g_2);

assert c.graph is g_1;
assert sess_1.graph is g_1;

assert d.graph is g_2;
assert sess_2.graph is g_2;

#print(tf.get_default_graph().get_operations());

rank_three_tensor = tf.ones((3,4,5));
matrix = tf.reshape(rank_three_tensor, shape=(5,-1));
print(matrix);
#matrixB = rank_three_tensor.reshape((3,4,-1)); # Tensor has no attribure "reshape"
#print(matrixB);

sess = tf.Session();
t = tf.constant(1);
#tf.Print(t,[t]);
t = tf.Print(t,[t]);
result = t + 1;
print(result.eval(session=sess));
print("output result value by run:");
print(sess.run(result));