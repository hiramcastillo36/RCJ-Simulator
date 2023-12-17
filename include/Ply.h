//
// Created by Hiram Castillo on 31/08/23.
//

#ifndef PLY_H
#define PLY_H

#pragma once

#include "Object.h"

using namespace std;

/**
 * @brief 
 *  This class is used to create objects using the ply file.
 */

class Ply : public Object {
public:
    Ply(string fileName, float r, float g, float b);

    void load();
};


#endif //PLY_H
