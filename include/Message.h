#ifndef MESSAGE_H
#define MESSAGE_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Model.h"

/**
 * @brief 
 * This class is used to create and draw collition message
 */

class Message
{
public:
    Message();
    void draw(GLuint programID, glm::mat4 camera, bool status);
    void setRotate(glm::mat4 rotate);
    void setTranslate(glm::mat4 translate);
private:
    Model <Obj> message;
};

#endif