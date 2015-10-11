# thread_fun.py

import thread
import time
import sys
__metaclass__=type
class Thread:
	def __init__(self):
		self.trun=False
	def run(self):
		while self.trun:
			print 'I am in base run'
			time.sleep(1) 
	
	def start(self):
		try:
			self.trun=True
			thread.start_new_thread(self.run, ());
		except:
			print 'start thread exception'
			sel.trun=False
			sys.exit("thread start got exception")

	def stop(self):
		self.trun=False


#test code

class TestThread(Thread):
	def __init__(self):
		self.name='my name is child thread'
		super(TestThread, self).__init__()
	def doSomeThings(self):
		count=0
		while True:
			count += 1
			if(count < 100):
				print "do my test fun."
			else:
				break
	def run(self):
		while self.trun:
			print 'I am in child run', self.name
			time.sleep(1)
			self.doSomeThings()
def test():
	th=Thread()
	th.start()
	ch=TestThread()
	ch.start()
	time.sleep(2000)
	th.stop()
	ch.stop()

if __name__=='__main__':
	test()

