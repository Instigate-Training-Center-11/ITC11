import argparse
def str2bool(v):
    if isinstance(v, bool):
       return v
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Boolean value expected.')

parser = argparse.ArgumentParser(prog='Argparser for search program')
parser.add_argument('--search', required=True, help='provide string to include for search, required')
parser.add_argument('--include', default='', help='provide regex to include')
parser.add_argument('--exclude', default='', help='provide regex to exclude')
parser.add_argument('--path', default='.', help='provide path to search in')
parser.add_argument('-f', type=str2bool, default=False, const=True, nargs='?', help='search for files')
parser.add_argument('-d', type=str2bool, default=False, const=True, nargs='?', help='search for directories')


args = parser.parse_args()

