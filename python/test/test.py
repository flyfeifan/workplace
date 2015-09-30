#test.py
import config
import config.configure

def test():
	print "hello PI: " + str(config.configure.PI)
	print "hello PI: " , config.configure.PI
	conReader = config.configure.ConfigReader("file.cfg")
	greet = conReader.getOption("messages", "greeting")
	print "greet : " + greet
	print "pi : " + conReader.getOption("numbers", "pi")
	print "time: " + conReader.getOption("numbers", "time")
    	di = conReader.getSection("messages")
    	for l in di.keys():
        	print l + ' : '+ di[l]


if __name__ == '__main__':
    print "test the class ConfigReader"
    test()
