//
//  Macro.h
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Macro_h
#define Macro_h

#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

#define SYNTHESIZE_READONLY(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }



#endif /* Macro_h */
