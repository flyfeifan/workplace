# threadfun.py

import thread
import time

__metaclass__=type
class Thread:
	def __init__(self):
		self.trun=False
	def run(self):
		while self.trun:
			print 'I am in base run'
			time.sleep(1) 
	
	def start(self):
		self.trun=True
		thread.start_new_thread(self.run, ());
	
	def stop(self):
		self.trun=False

class TestThread(Thread):
	def __init__(self):
		self.name='my name is child thread'
		super(TestThread, self).__init__()
	def run(self):
		while self.trun:
			print 'I am in child run', self.name
			time.sleep(1)

def test():
	th=Thread()
	th.start()
	ch=TestThread()
	ch.start()
	time.sleep(20)
	th.stop()
	ch.stop()

if __name__=='__main__':
	test()

