#test.py
import config
import config.configure

def test():
	conReader = config.configure.ConfigReader("../config/file.cfg")
	greet = conReader.getOption("messages", "greeting")
	print "greet : " + greet
	print "pi : " + conReader.getOption("numbers", "pi")
    	di = conReader.getSection("messages")
    	for l in di.keys():
        	print l + ' : '+ di[l]


if __name__ == '__main__':
    print "test the class ConfigReader"
    test()
