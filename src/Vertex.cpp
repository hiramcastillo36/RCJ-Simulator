#include "../include/Vertex.h"

/**
 * @brief 
 * Construct a new Vertex:: Vertex object
 * @return Vertex 
 */

Vertex::Vertex() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

/**
 * @brief 
 * Construct a new Vertex:: Vertex object
 * @param float vx 
 * @param float vy 
 * @param float vz 
 * @return Vertex 
 */

Vertex::Vertex(float vx, float vy, float vz) {
    this->x = vx;
    this->y = vy;
    this->z = vz;
}

/**
 * @brief 
 * Print the vertex.
 */

void Vertex::print() {
    cout << "(" << this->x << ", " << this->y << ", " << this->z << ")";
}

/**
 * @brief 
 * Overload the - operator.
 * @param Vertex op2 
 * @return Vertex 
 */

Vertex Vertex::operator-(Vertex op2) {
    return Vertex(this->x - op2.x, this->y - op2.y, this->z - op2.z);
}

/**
 * @brief 
 * Overload the + operator.
 * @param Vertex op2 
 * @return Vertex 
 */

Vertex Vertex::operator+(Vertex op2) {
    return Vertex(this->x + op2.x, this->y + op2.y, this->z + op2.z);
}

/**
 * @brief 
 * Overload the * operator.
 * @param float op2 
 * @return Vertex 
 */

Vertex Vertex::operator*(float op2) {
    return Vertex(this->x * op2, this->y * op2, this->z * op2);
}

/**
 * @brief 
 * This method returns the vertex as a row.
 * @return Row < float > 
 */

Row<float> Vertex::row() {
    Row<float> r = {this->x, this->y, this->z};
    return r;
}

/**
 * @brief 
 * This method returns the vertex as a column.
 * @return Col < float > 
 */

Col<float> Vertex::homog() {
    Col<float> h = {this->x, this->y, this->z, 1};
    return h;
}

/**
 * @brief 
 * This method returns the x coordinate of the vertex.
 * @return float 
 */

float Vertex::getX() {
    return this->x;
}

/**
 * @brief 
 * Returns the y coordinate of the vertex.
 * @return float 
 */

float Vertex::getY() {
    return this->y;
}

/**
 * @brief 
 * Returns the z coordinate of the vertex.
 * @return float 
 */

float Vertex::getZ() {
    return this->z;
}

/**
 * @brief 
 * Sets the x coordinate of the vertex.
 * @param float vx 
 */

void Vertex::setX(float vx) {
    this->x = vx;
}

/**
 * @brief 
 * Sets the y coordinate of the vertex.
 * @param float vy 
 */

void Vertex::setY(float vy) {
    this->y = vy;   
}

/**
 * @brief 
 * Sets the z coordinate of the vertex.
 * @param float vz 
 */

void Vertex::setZ(float vz) {
    this->z = vz;
}

/**
 * @brief 
 * Returns the coordinates of the vertex.
 * @return vector < float > 
 */

glm::vec3 Vertex::getVec3() {
    return glm::vec3(this->x, this->y, this->z);
}