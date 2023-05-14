from distutils.core import setup, Extension

setup(
        name='strrev_lib',
        version='1',
        ext_modules=[Extension('_strrev', ['_strrev.c'])],
        )
