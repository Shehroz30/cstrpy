from distutils.core import setup, Extension

setup(
        name='strrev_lib',
        version='1',
        ext_modules=[Extension('str', ['_strrev.c', 'impfunctions.c'])],
        )
