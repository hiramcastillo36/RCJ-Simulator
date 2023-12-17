#ifndef EDGE_H
#define EDGE_H

#pragma once

#include "Vertex.h"

/**
 * @brief 
 * This class is used to create edges using vertices.
 */

class Edge {
private:
    Vertex vi, vf;

public:
    Edge(Vertex vi, Vertex vf); //constructor
    // ~Edge(); -> destructor
    void print();

    Vertex getVi();

    Vertex getVf();
};

#endif