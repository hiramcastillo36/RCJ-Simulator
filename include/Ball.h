#ifndef BALL_H
#define BALL_H

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
 *  This class is used to create and draw the ball
 */

class Ball 
{
public:
    Ball();
    Ball(float x, float y, float z);
    void draw(GLuint programID, glm::mat4 camera);
    void setTranslate(glm::mat4 translate);

private:
    Model <Ply> ball;
};

#endif