//
//  Macro.h
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Macro_h
#define Macro_h

#define PI 3.141592654f

#define TO_ANGLE(rad) (rad) / PI * 180


/**
 generate getter and setter for attribute
 */
#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

/**
 generate getter for attribute
 */
#define SYNTHESIZE_READONLY(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }


#define _TDOGL_PROGRAM_ATTRIB_N_UNIFORM_SETTERS(OGL_TYPE) \
void setAttrib(const GLchar* attribName, OGL_TYPE v0); \
void setAttrib(const GLchar* attribName, OGL_TYPE v0, OGL_TYPE v1); \
void setAttrib(const GLchar* attribName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2); \
void setAttrib(const GLchar* attribName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3); \
\
void setAttrib1v(const GLchar* attribName, const OGL_TYPE* v); \
void setAttrib2v(const GLchar* attribName, const OGL_TYPE* v); \
void setAttrib3v(const GLchar* attribName, const OGL_TYPE* v); \
void setAttrib4v(const GLchar* attribName, const OGL_TYPE* v); \
\
void setUniform(const GLchar* uniformName, OGL_TYPE v0); \
void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1); \
void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2); \
void setUniform(const GLchar* uniformName, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3); \
\
void setUniform1v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
void setUniform2v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
void setUniform3v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \
void setUniform4v(const GLchar* uniformName, const OGL_TYPE* v, GLsizei count=1); \


#define ATTRIB_N_UNIFORM_SETTERS(OGL_TYPE, TYPE_PREFIX, TYPE_SUFFIX) \
\
void Program::setAttrib(const GLchar* name, OGL_TYPE v0) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 1 ## TYPE_SUFFIX (getAttribIndex(name), v0); } \
void Program::setAttrib(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 2 ## TYPE_SUFFIX (getAttribIndex(name), v0, v1); } \
void Program::setAttrib(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 3 ## TYPE_SUFFIX (getAttribIndex(name), v0, v1, v2); } \
void Program::setAttrib(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 4 ## TYPE_SUFFIX (getAttribIndex(name), v0, v1, v2, v3); } \
\
void Program::setAttrib1v(const GLchar* name, const OGL_TYPE* v) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 1 ## TYPE_SUFFIX ## v (getAttribIndex(name), v); } \
void Program::setAttrib2v(const GLchar* name, const OGL_TYPE* v) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 2 ## TYPE_SUFFIX ## v (getAttribIndex(name), v); } \
void Program::setAttrib3v(const GLchar* name, const OGL_TYPE* v) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 3 ## TYPE_SUFFIX ## v (getAttribIndex(name), v); } \
void Program::setAttrib4v(const GLchar* name, const OGL_TYPE* v) \
{ assert(isInUse()); glVertexAttrib ## TYPE_PREFIX ## 4 ## TYPE_SUFFIX ## v (getAttribIndex(name), v); } \
\
void Program::setUniform(const GLchar* name, OGL_TYPE v0) \
{ assert(isInUse()); glUniform1 ## TYPE_SUFFIX (getUniformIndex(name), v0); } \
void Program::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1) \
{ assert(isInUse()); glUniform2 ## TYPE_SUFFIX (getUniformIndex(name), v0, v1); } \
void Program::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ assert(isInUse()); glUniform3 ## TYPE_SUFFIX (getUniformIndex(name), v0, v1, v2); } \
void Program::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ assert(isInUse()); glUniform4 ## TYPE_SUFFIX (getUniformIndex(name), v0, v1, v2, v3); } \
\
void Program::setUniform1v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(isInUse()); glUniform1 ## TYPE_SUFFIX ## v (getUniformIndex(name), count, v); } \
void Program::setUniform2v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(isInUse()); glUniform2 ## TYPE_SUFFIX ## v (getUniformIndex(name), count, v); } \
void Program::setUniform3v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(isInUse()); glUniform3 ## TYPE_SUFFIX ## v (getUniformIndex(name), count, v); } \
void Program::setUniform4v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(isInUse()); glUniform4 ## TYPE_SUFFIX ## v (getUniformIndex(name), count, v); }
#endif /* Macro_h */
