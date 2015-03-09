# FileLog.py

import logging

FORMAT = '%(asctime)s %(levelname)s %(thread)d %(message)s'

class FileLog:
    def __init__(self, logName, logLevel):
        try:
            logging.basicConfig(level=logLevel, filename=logName, format=FORMAT)
            self.loger = logging.getLogger('FILELOG')
        except:
            assert 0
    def __del__(self):
        logging.shutdown()

    def __call__(self, logLevel, message):
        if(logLevel >= logging.CRITICAL):
            self.loger.critical(message)
        elif (logLevel >= logging.ERROR):
            self.loger.error(message)
        elif (logLevel >= logging.WARNING):
            self.loger.warning(message)
        elif (logLevel >= logging.INFO):
            self.loger.info(message)
        elif (logLevel >= logging.DEBUG):
            self.loger.debug(message)
        else:
            assert 0

def test():
    log = FileLog("testFile.log", logging.DEBUG)
    log(55,"hello,test loger")
    log(45,"hello,test loger")
    log(35,"hello,test loger")
    log(25,"hello,test loger")
    log(15,"hello,test loger")

if __name__ == '__main__':
    print'test class FileLog'
    test()
            
        
        
