// Model.h

#ifndef MODEL_H
#define MODEL_H

#include "Obj.h"
#include "Ply.h" 

/**
 * @brief 
 *  This class is used to create models using Obj and Ply.
 * @tparam T 
 */

template<typename T>

class Model : public T {
public:

    Model(string fileName, float r, float g, float b) : T(fileName, r, g, b) {}
    Model() : T("", 0.0, 0.0, 0.0) {}
};

#endif // MODEL_H