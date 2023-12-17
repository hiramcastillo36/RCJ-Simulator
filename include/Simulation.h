#ifndef SIMULATION_H
#define SIMULATION_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Robot.h"
#include "Ball.h"
#include "Enemy.h"
#include "Animation.h"
#include "Model.h"
#include "OpenGL.h"
#include "Scene.h"
#include "Ply.h"
#include "Obj.h"
#include "Vertex.h"
#include "Message.h"

using namespace std;

/**
 * @brief 
 *  This class is used to generate the simulation
 */

class Simulation
{
public:
    Simulation();
    
    void init(GLuint programID);
    void changeCamera(int camera);
    void setPoint(float x, float y);
    void setPoint2(float x, float y);

    void setCollision(bool collision);
    void setKeyFlag(int key_flag);
    void setPointFlag(int point_flag);
    void setClick(double xpos, double ypos);
    int getPointFlag();
private:
    Robot robot;
    Ball ball;
    Enemy enemy;
    Ball ballPoint;
    Ball ballPoint2;
    Message message;
    Message message2;

    glm::mat4 camera;
    int collision;
    
};

#endif