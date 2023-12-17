#ifndef FACE_H
#define FACE_H

#pragma once

#include "Edge.h"
#include "iostream"
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/glm.hpp> 

using namespace std;

/**
 * @brief 
 *  This class is used to create faces using edges.
 */

class Face {
private:
    vector<Edge> edges;
    glm::vec3 normal;

public:
    Face(vector<Edge> edges);
    void print();

    vector<Edge> getEdges();
    glm::vec3 getNormal();
};


#endif