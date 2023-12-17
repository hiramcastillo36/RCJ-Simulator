#ifndef ROBOT_H
#define ROBOT_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Animation.h"
#include "Model.h"

using namespace std;

/**
 * @brief 
 *  This class is used to create and draw the robot
 */

class Robot {
public:
    Robot();
    void draw(GLuint programID, glm::mat4 camera, int collision);

    void setP2(Vertex P2);
    void setP3(Vertex P3);
    void setP4(Vertex P4);

    Vertex getCurrentPos();
    vector <Vertex> getPath();

private:
    Model <Ply> robot;
    unsigned int pathIndex = 0;
    vector <Vertex> path;

    Vertex P1;
    Vertex P2;
    Vertex P3;
    Vertex P4;

    float t;
};

#endif