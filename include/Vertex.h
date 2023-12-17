#ifndef VERTEX_H
#define VERTEX_H

#pragma once

#include <iostream>
#include <armadillo>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/glm.hpp>

using namespace std;
using namespace arma;

/**
 * @brief
 * This class is used to create vertices.
 */

class Vertex {
public:
    Vertex(); //constructor default
    Vertex(float vx, float vy, float vz); //constructor
    // ~Vertex(); -> destructor
    void print();

    Vertex operator-(Vertex op2);

    Vertex operator+(Vertex op2);

    Vertex operator*(float op2);

    bool operator==(Vertex op2);
    
    Row<float> row();

    Col<float> homog();

    float getX();

    float getY();

    float getZ();

    vector<float> getXYZ();
    void setX(float vx);
    void setY(float vy);
    void setZ(float vz);
    glm::vec3 getVec3();
private:
    float x, y, z;
};

#endif