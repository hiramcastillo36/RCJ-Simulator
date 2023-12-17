//
// Created by Hiram Castillo on 04/09/23.
//

#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/scalar_constants.hpp> // glm::pi

using namespace std;

/**
 * @brief 
 *  This class is used to create objects using vertices and faces.
 */

class Object {
public:
    Object(string fileName, float r, float g, float b);
    vector<Vertex> getVertices();
    vector<Face> getFaces();
    virtual void load() = 0;
    void draw(GLuint programID, glm::mat4 transform);
    
    void setScale(glm::mat4 scale);
    void setRotate(glm::mat4 rotate);
    void setTranslate(glm::mat4 translate);

    glm::mat4 getScale();
    glm::mat4 getRotate();
    glm::mat4 getTranslate();
    glm::mat4 getTransform();
    
protected:
    string fileName;
    vector<Vertex> vertices = {};
    vector<Face> faces = {};
    float r, g, b;
    
    vector<string> split(const string &str, const string &delim);

    GLuint colorbuffer;
    GLuint datasize;
    GLuint MatrixID;
    GLuint vertexbuffer;
    
    glm::mat4 scale;
    glm::mat4 transform;
    glm::mat4 rotate;
    glm::mat4 translate;

    void set_data();

};


#endif
