#include "../include/Enemy.h"

/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 */

Enemy::Enemy()
{
    this->enemy = Model <Obj> ("models/enemy2.obj", 0.0, 0.0, 1.0);

    srand (time(NULL));
    float random_enemy = (float)(rand() % 2 + 1)/10;

    enemy.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.7f)));
    enemy.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, random_enemy)));
}

/**
 * @brief 
 * This method draws the enemy.
 * @param programID 
 * @param camera 
 */

void Enemy::draw(GLuint programID, glm::mat4 camera)
{
    this->enemy.draw(programID, camera);
}

