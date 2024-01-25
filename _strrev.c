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

static PyObject* _removeDuplicates(PyObject* self, PyObject *args) {
   PyObject* name;
   char* s;
   if (!PyArg_ParseTuple(args, "U", &name)) {
       return NULL; 
   }
   s = PyUnicode_AsUTF8(name);
   removeDuplicates(s); 

   return PyUnicode_FromString(s);
}

static PyObject* _startswith(PyObject* self, PyObject *args) {
    char* string;
    char* substring;
    int result;
    if (!PyArg_ParseTuple(args, "ss", &string, &substring)) {
        return NULL;
    }
    
    result = startswith(string, substring);  
    return PyLong_FromLong(result); 
} 

static PyObject* _containsString(PyObject* self, PyObject *args) {
    char* string;
    char* substring;
    int result;
    if (!PyArg_ParseTuple(args, "ss", &string, &substring)) {
        return NULL;
    }
    
    result = containsString(string, substring);  
    return PyLong_FromLong(result); 
} 

static PyObject* _isRotation(PyObject* self, PyObject *args) {
    char* string;
    char* string2;
    int result;
    if (!PyArg_ParseTuple(args, "ss", &string, &string2)) {
        return NULL;
    }
    
    result = isRotation(string, string2);  
    return PyLong_FromLong(result); 
} 

static PyObject* _isPalindrome(PyObject* self, PyObject *args) {
    char* string;
    int result;
    if (!PyArg_ParseTuple(args, "s", &string)) {
        return NULL;
    }
    
    result = isPalindrome(string);  
    return PyLong_FromLong(result); 
} 


static PyObject* _removeWhitespace(PyObject* self, PyObject *args) {
   PyObject* name;
   char* s;
   if (!PyArg_ParseTuple(args, "U", &name)) {
       return NULL; 
   }
   s = PyUnicode_AsUTF8(name);
   removeWhitespace(s); 

   return PyUnicode_FromString(s);
}

static struct PyMethodDef methods[] = {
    {"reverse", (PyCFunction)_strrev, METH_VARARGS},
    {"startsWith", (PyCFunction)_startswith, METH_VARARGS},
    {"isPalindrome", (PyCFunction)_isPalindrome, METH_VARARGS},
    {"removeDuplicates", (PyCFunction)_removeDuplicates, METH_VARARGS},
    {"containsString", (PyCFunction)_containsString, METH_VARARGS},
    {"isRotation", (PyCFunction)_isRotation, METH_VARARGS},
    {"removeWhitespace", (PyCFunction)_removeWhitespace, METH_VARARGS},
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
