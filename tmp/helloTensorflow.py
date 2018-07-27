import tensorflow as tf
from optparse import OptionParser as OPT
from tensorflow.examples.tutorials.mnist import input_data
import os

def inference(x):
	with tf.variable_scope("h1"):
        	W1 = tf.Variable(tf.zeros([784,100]), name="W")
        	b1 = tf.Variable(tf.zeros([100]), name="b")
    	with tf.variable_scope('h2'):
		W2 = tf.Variable(tf.zeros([100,10]), name="W")
		b2 = tf.Variable(tf.zeros([10]), name="b")

    	y = tf.nn.softmax(tf.matmul((tf.matmul(x,W1) + b1),W2)+b2);
    	
	return y, [W1, b1, W2, b2]

def train(data,modelDir):
	x = tf.placeholder("float", [None, 784])
	y, variables = inference(x)

	# train
	y_ = tf.placeholder("float", [None, 10])
	cross_entropy = -tf.reduce_sum(y_ * tf.log(y))
	train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)
	correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1))
	accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

	saver = tf.train.Saver(variables)
	init = tf.global_variables_initializer()
	
	with tf.Session() as sess:
   	 	sess.run(init)
    		for i in range(10):
        		batch_xs, batch_ys = data.train.next_batch(100)
        		sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

    		print(sess.run(accuracy, feed_dict={x: data.test.images, y_: data.test.labels}))

		if tf.gfile.Exists(modelDir):
      			tf.gfile.DeleteRecursively(modelDir)
    		tf.gfile.MakeDirs(modelDir)
    		path = saver.save(sess, os.path.join(os.path.dirname(__file__), modelDir,"simple.ckpt"))
    		print("Saved:", path)

def test(data,modelDir):
	if(not tf.gfile.Exists(modelDir)):
      		print('Error:model not exist!');
		exit();
	sess = tf.Session()
	test_feats,test_labels=data.test.next_batch(100);

	###restore the stored parameters as following
	'''
	WW1 = tf.Variable(tf.zeros([784,100]), name="h1/W")  	###nameScope/varName  to get the stored variable
	with tf.variable_scope("h1"):		
    		bb1 = tf.Variable(tf.zeros([100]), name="b")		###or just like this...     To store the variable, there are also such two ways..
	with tf.variable_scope("h2"):
    		WW2 = tf.Variable(tf.zeros([100,10]), name="W")
    		bb2 = tf.Variable(tf.zeros([10]), name="b")
	variables=[WW1,bb1,WW2,bb2];
	saver = tf.train.Saver(variables)
	saver.restore(sess, os.path.join(modelDir,"simple.ckpt"))
	print(sess.run([WW1,bb1,WW2,bb2]));
	'''

	x = tf.placeholder("float", [None, 784]);
	predictions,variables = inference(x);
	sess = tf.Session();
	saver = tf.train.Saver(variables); 
	saver.restore(sess,os.path.join(modelDir,"simple.ckpt"));  ###prefix the model file name with a directory name, even though it is in current directory (add './' in this case)
	print(sess.run(tf.argmax(sess.run(predictions,feed_dict={x: test_feats}),1)));

def main():
	usage = 'python %prog [options]';
	myOpt = OPT(usage);
	myOpt.add_option('--ntr',action='store_true',default=False,help='train or test');
	
	opts,args = myOpt.parse_args();
	ntr = opts.ntr;

	data = input_data.read_data_sets("/tmp/data/", one_hot=True);
	modelDir = 'model';
	if(ntr):
		test(data,modelDir);
	else:
		train(data,modelDir);

main();


