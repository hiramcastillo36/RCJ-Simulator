#include "../include/Simulation.h"

using namespace std;

/**
 * @brief Construct a new Simulation:: Simulation object
 * 
 */

Simulation::Simulation()
{

    this -> camera = Scene::getCameraY();
    this->collision = -1;
    this->message2.setRotate(glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0,0.0,0.0)));
    this->message2.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.7f)));
    cout<<"Simulation created"<<endl;
}

/**
 * @brief 
 * This method initializes the simulation.
 * @param GLuint programID 

*/

void Simulation::init(GLuint programID)
{
    ball.draw(programID, camera);   
    robot.draw(programID, camera, this->collision);
    enemy.draw(programID, camera);  
    ballPoint.draw(programID, camera);
    ballPoint2.draw(programID, camera);
    message.draw(programID, camera, bool(this->collision != -1)); 
    message2.draw(programID, camera, bool(this->collision != -1));
}

/**
 * @brief 
 * This method changes the camera.
 * @param int camera 
*/

void Simulation::changeCamera(int camera)
{
    if(camera == 1)
    {
        this->camera = Scene::getCameraPrincipal();
    }
    else if(camera == 2)
    {
        this->camera = Scene::getCameraY();
    }
    else if(camera == 3)
    {
        this->camera = Scene::getCameraZ();
    }
}


/**
 * @brief 
 * This method sets the point.
 * @param float x 
 * @param float y 
*/

void Simulation::setPoint(float x, float y)
{
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(x, 0.0f, y));
    ballPoint.setTranslate(translate);
    Vertex P2 = Vertex (x, 0.0, y);
    robot.setP2(P2);
    vector <Vertex> path = robot.getPath();
    int limit = 0;
    for(Vertex v : path)
    {
        if(v.getX() + 0.16 > -0.45 && v.getX() - 0.16 < 0.45 && v.getZ() + 0.16 > -0.45 && v.getZ() - 0.16 < 0.45)
        {
            this->collision = limit;
            return;
        }
        limit++;
    }
    collision = -1;
    
}

/**
 * @brief 
 * This method sets the second point.
 * @param float x 
 * @param float y 
*/

void Simulation::setPoint2(float x, float y)
{
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(x, 0.0, y));
    ballPoint2.setTranslate(translate);
    Vertex P3 = Vertex (x, 0.0, y);
    robot.setP3(P3);
    vector <Vertex> path = robot.getPath();
    int limit = 0;
    for(Vertex v : path)
    {
        if(v.getX() + 0.15 > -0.5 && v.getX() - 0.15 < 0.5
        && v.getZ() + 0.15 > -0.5 && v.getZ() - 0.15 < 0.5)
        {
            
            this->collision = limit;
            return;
        } 
        limit++;
    }
    this->collision = -1;
}

void Simulation::setCollision(bool collision){
    this->collision = collision;
}
