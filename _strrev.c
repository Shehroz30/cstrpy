#include <Python.h>
#include <string.h>
#include <sys/types.h>
void revstr(char *str)  
{
    int i;
	int j;
	unsigned char a;
	unsigned len = strlen((const char *)str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}  

static PyObject* _strrev(PyObject* self, PyObject *args) {
   PyObject* name;
   char* s;
   if (!PyArg_ParseTuple(args, "U", &name)) {
       return NULL; 
   }
   s = PyUnicode_AsUTF8(name);
   revstr(s); 

   return PyUnicode_FromString(s);
}


static struct PyMethodDef methods[] = {
    {"strrev", (PyCFunction)_strrev, METH_VARARGS},
    {NULL, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, 
    "_strrev",
    NULL, 
    -1, 
    methods
};

PyMODINIT_FUNC PyInit__strrev(void) {
    return PyModule_Create(&module);
}
