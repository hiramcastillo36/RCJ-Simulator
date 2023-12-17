#include "../include/Message.h"

/**
 * @brief Construct a new Message:: Message object
 * 
 */

Message::Message()
{
    this->message = Model <Obj> ("models/message.obj", 0.0, 1.0, 1.0);

    message.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.6f)));
    message.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.7f, -1.5f)));
}

/**
 * @brief 
 *  This method draw the collition message.
 * @param programID 
 * @param camera 
 * @param status 
 */
void Message::draw(GLuint programID, glm::mat4 camera, bool status)
{
    if(status)
        this->message.draw(programID, camera);
}

/**
 * @brief 
 * This method rotate the message.
 * @param rotate 
 */
void Message::setRotate(glm::mat4 rotate)
{
    this->message.setRotate(rotate);
}

/**
 * @brief 
 * This method translate the message.
 */
void Message::setTranslate(glm::mat4 translate){
    this->message.setTranslate(translate);
}