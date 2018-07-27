from __future__ import absolute_import, division, print_function
import tensorflow as tf
tf.enable_eager_execution();
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

print(a.numpy());

def fizzbuzz(max_num):
  counter = tf.constant(0)
  for num in range(max_num):
    num = tf.constant(num)
    if int(num % 3) == 0 and int(num % 5) == 0:
      print('FizzBuzz')
    elif int(num % 3) == 0:
      print('Fizz')
    elif int(num % 5) == 0:
      print('Buzz')
    else:
      print(num)
    counter += 1
  return counter

fizzbuzz(20);