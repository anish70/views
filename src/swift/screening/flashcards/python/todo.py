
# Undo decorator use; make simpler tmpname; use this instead of previous s() method
@contextmanager
def replacefile(name):
    tmpname = '%s.tmp-%s' % (name, binascii.hexlify(os.urandom(10)).decode('ascii'))
    try:
        with open(tmpname, 'w+') as f:
            yield f
        os.rename(tmpname, name)
    finally:
        try:
            os.unlink(tmpname)
        except OSError:
            pass
