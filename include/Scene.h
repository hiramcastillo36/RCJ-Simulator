#ifndef SCENE_H
#define SCENE_H

#pragma once

#include <glm/vec4.hpp>                 // glm::vec4
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "OpenGL.h"
#include "Simulation.h"

/**
 * @brief
 *  This class is used generate the camera views
 */

class Scene
{
public:
    Scene();
    void run();

    static glm::mat4 getCameraPrincipal()
    {
        return glm::perspective(glm::radians(45.0f), (float)1000 / (float)500, 0.1f, 100.0f) *
               glm::lookAt(
                   glm::vec3(6.5, 1.6, 2.6),  // Camera is at (0,0,2), in World Space
                   glm::vec3(-1, 0, 0), // and looks at the oribgin
                   glm::vec3(0, 1, 0)   // Head is up (set to 0,-1,0 to look upside-down)
               );
    }

    static glm::mat4 getCameraZ()
    {
        return glm::perspective(glm::radians(45.0f), (float)1000 / (float)500, 0.1f, 100.0f) *
               glm::lookAt(
                   glm::vec3(0, 0, 6), // Camera is at (0,0,2), in World Space
                   glm::vec3(0, 0, 0), // and looks at the oribgin
                   glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
               );
    }
    static glm::mat4 getCameraY()
    {
        return glm::perspective(glm::radians(45.0f), (float)1000 / (float)500, 0.1f, 100.0f) *
               glm::lookAt(
                   glm::vec3(0, 6, 0), // Camera is at (0,0,2), in World Space
                   glm::vec3(0, 0, 0),    // and looks at the origin
                   glm::vec3(0, 0, -1)    // Head is up (set to 0,-1,0 to look upside-down)
               );
    }

private:
    int key_flag;
    int point_flag;
    int stateSimulation;
    double xMouseClick;
    double yMouseClick;
    bool clickLocked;
};

#endif