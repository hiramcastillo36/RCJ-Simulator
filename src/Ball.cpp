#include "../include/Ball.h"

/**
 * @brief Construct a new Ball:: Ball object
 * 
 */

Ball::Ball(){
    srand (time(NULL));
    float r = (float)(rand() % 10 + 1)/10;
    float g = (float)(rand() % 10 + 1)/10;
    float b = (float)(rand() % 10 + 1)/10;
    this->ball = Model <Ply> ("models/rock.ply", r, g, b);
    ball.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.2f)));
    ball.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(4.0f, 0.0f, 0.0f)));
}

/**
 * @brief 
 *  Construct a new Ball:: Ball object
 */

Ball::Ball(float x, float y, float z){
    this->ball = Model <Ply> ("models/rock.ply", x, y, z);
    ball.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.1f)));
    ball.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z)));
}

/**
 * @brief 
 * This method draws the ball.
 * @param programID 
 * @param camera 
 */

void Ball::draw(GLuint programID, glm::mat4 camera)
{
    this->ball.draw(programID, camera);
}

/**
 * @brief 
 *  This method sets the translate.
 * @param translate
 */

void Ball::setTranslate(glm::mat4 translate){
    this->ball.setTranslate(translate);
}