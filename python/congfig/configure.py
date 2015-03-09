# configure.py

from ConfigParser import ConfigParser

class ConfigReader:
    def __init__(self, fileName):
        self.config = ConfigParser()
        self.config.read(fileName)

    def getSection(self, sectionName):
        try:
            sectionList = self.config.items(sectionName)
            d = dict(sectionList)
            return d
        except:
            print "get section %s error" % sectionName

    def getOption(self, sectionName,optionName):
        try:
            return self.config.get(sectionName, optionName)
        except:
            print "get section %s option %s error" % (sectionName, optionName)


def test():
    conReader = ConfigReader("file.cfg")
    greet = conReader.getOption("messages", "greeting")
    print "greet : " + greet
    print "pi : " + conReader.getOption("numbers", "pi")
    di = conReader.getSection("messages")    
    for l in di.keys():
        print l + ' : '+ di[l]


if __name__ == '__main__':
    print "test the class ConfigReader"
    test()
    
