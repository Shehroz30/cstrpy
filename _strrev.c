#include <Python.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include "impfunctions.h"

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

static PyObject* _startswith(PyObject* self, PyObject *args) {
    char* string;
    char* substring;
    char* s, sb;
    int result;
    if (!PyArg_ParseTuple(args, "ss", &string, &substring)) {
        return NULL;
    }
    
    result = startswith(string, substring);  
    return PyLong_FromLong(result); 
} 

static struct PyMethodDef methods[] = {
    {"reverse", (PyCFunction)_strrev, METH_VARARGS},
    {"startsWith", (PyCFunction)_startswith, METH_VARARGS},
    {NULL, NULL, 0, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, 
    "str",
    NULL, 
    -1, 
    methods
};

PyMODINIT_FUNC PyInit_str(void) {
    return PyModule_Create(&module);
}
