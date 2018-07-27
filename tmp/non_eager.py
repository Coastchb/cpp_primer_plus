import tensorflow as tf

x = [[2.]];
xx1 = tf.matmul(x,x);
print(xx1);

#tf.executing_eagerly();

a = tf.constant([[1,2],
                 [3,4]]);

print(a);

b = tf.add(a,1);
print(b);

print(a*b);

import numpy as np

c = np.multiply(a,b);
print(c);

#print(a.numpy());