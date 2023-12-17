#include "../include/Edge.h"

using namespace std;


/**
 * @brief Construct a new Edge:: Edge object
 */
Edge::Edge(Vertex vi, Vertex vf) {
    this->vi = vi;
    this->vf = vf;
}

/**
 * @brief 
 * This method prints the edge.
 */

void Edge::print() {
    cout << "vi: ";
    this->vi.print();
    cout << ", vf: ";
    this->vf.print();
    cout << endl;
}

/**
 * @brief 
 * This method returns the initial vertex of the edge.
 * @return Vertex 
 */

Vertex Edge::getVi() {
    return this->vi;
}

/**
 * @brief 
 * This method returns the final vertex of the edge.
 * @return Vertex 
 */

Vertex Edge::getVf() {
    return this->vf;
}
