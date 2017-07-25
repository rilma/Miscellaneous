import argparse, logging

parser = argparse.ArgumentParser(description='Set some log manager.')

parser.add_argument('--log', default='DEBUG', dest='loglevel',
    help='logging level. By default is debug.',
    required=False, type=str)

args = parser.parse_args()

numeric_level = getattr(logging, args.loglevel.upper(), None)

if not isinstance(numeric_level, int):
    raise ValueError('Invalid log level: %s' % numeric_level)

logging.basicConfig(filename='example.log', filemode='w', level=numeric_level)
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')
