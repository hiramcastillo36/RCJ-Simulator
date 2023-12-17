#include "../include/Face.h"

using namespace std;

/**
 * @brief Construct a new Face:: Face object
 * 
 * @param vector < Edge > 
 */

Face::Face(vector<Edge> edges) {
    this->edges = edges;
    glm::vec3 v1 = edges[0].getVi().getVec3();
    glm::vec3 v2 = edges[1].getVi().getVec3();
    glm::vec3 v3 = edges[2].getVi().getVec3();
    this->normal = 
        glm::normalize(glm::cross(v2-v1, v3-v1));
}

/**
 * @brief 
 * This method prints the face.
 */

void Face::print() {
    int i = 1;
    for (Edge &e: this->edges) {
        cout << "Edge_" << i++ << " = ";
        e.print();
    }
    cout << endl;
}

/**
 * @brief 
 * This method returns the edges of the face.
 * @return vector <Edge> 
 */

vector<Edge> Face::getEdges() {
    return this->edges;
}

/**
 * @brief 
 * This method returns the normal of the face.
 * @return glm::vec3 
 */
glm::vec3 Face::getNormal() {
    return this->normal;
}