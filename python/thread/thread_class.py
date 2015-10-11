# thread_class.py

import threading
import time



class Thread2 (threading.Thread):
	def __init__(self, Tname='my thread2'):
		self.trun=False
		super(Thread2, self).__init__(name=Tname)

	def start(self):
		self.trun=True
		super(Thread2, self).start()
	
	def stop(self):
		self=trun=False

	def run(self):
		count = 0
		while self.trun:
			print "I am base thread thread name is ", self.getName()
			time.sleep(1)
			count += 1
			if (count > 30):
				break


def test():
	th = Thread2("hello")
	th.start()
	th.join()
	th.stop()

if __name__=='__main__':
	test()

	
		
	

