import tensorflow as tf
from optparse import OptionParser as OPT

def trainVar():

	######
	a=tf.Variable(1.0);
	newA=tf.add(a,2.0);
	update=tf.assign(a,newA);
	sess=tf.Session();
	sess.run(tf.global_variables_initializer());
	for i in range(10):
		sess.run(update);
		print(sess.run(a)); ###same as :  print(a.eval(sess));
	print('\n')
	sess.close();

	######
	b=tf.Variable(0.0);
	b=tf.add(b,2.0);
	sess=tf.Session();
	sess.run(tf.global_variables_initializer());
	for i in range(10):
		print(sess.run(b));  ###print b 10 times	
	print('\n');
	sess.close();

	######
	with tf.name_scope('n1'):
		c=tf.Variable(0.0,name='c');
		newC=tf.add(c,2.0);
		c=newC;
		sess=tf.Session();
		sess.run(tf.global_variables_initializer());
		for i in range(10):
			sess.run(newC);  ###print b 10 times  
			print(sess.run(c));      
	print('\n');
	sess.close();



	#simulate the BP process
	###inference step: d is the weights, e is the output of the NN
	def f():
		d=tf.Variable(0.0,name='d');
		e=tf.add(d,2);
		return d,e;

	###optimizer:  reset the weights according to the output value
	def changeD(dd,ee):
		newD=tf.add(dd,ee/2);
		#print(sess.run(newD));
		return tf.assign(dd,newD);

	D,E=f();
	change=changeD(D,E);
	sess=tf.Session();
	sess.run(tf.global_variables_initializer());
	for i in range(10):
		sess.run(change);  ###print b 10 times  
		print(sess.run(D));
	print('\n');
	print(D.name);
	print(sess.run(D));
	print('\n');
	print([o.name for o in tf.global_variables()]);
	print([o.name for o in tf.local_variables()]);

	saver=tf.train.Saver([D]);
	saver.save(sess,'model');
	sess.close();


	###print the global variables name and value (initial)
	sess=tf.Session();
	sess.run(tf.global_variables_initializer());
	print([o.name for o in tf.global_variables()]);
	print([sess.run(o) for o in tf.global_variables()]);
	sess.close();

def getVar():
	sess=tf.Session();
	f=tf.Variable(0.0,name='d');
	saver1=tf.train.Saver([f]);
	saver1.restore(sess,'./model');
	print(sess.run(f));


def main():
	usage='python %prog [--ntr]';
 	myOpt = OPT(usage);
	myOpt.add_option('--ntr', action = 'store_false', default = True, help = 'to train or get vars');
	
	opts, args = myOpt.parse_args();
	if(opts.ntr):
		trainVar();
	else:
		getVar();
main();


