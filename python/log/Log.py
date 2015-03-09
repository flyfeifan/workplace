import logging

FORMAT = "%(asctime)s %(message)s"

logging.basicConfig(level=logging.DEBUG, filename = 'mylog.log', format=FORMAT)

logging.info('starting program')

logging.info('trying to divide 1 by 0')
try:
    print 1/0
    logging.info('the division succeeded')
except:
    logging.info('the division failed')

logging.debug('ending program')
