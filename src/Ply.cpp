//
// Created by Hiram Castillo on 31/08/23.
//

#include "../include/Ply.h"

/**
 * @brief 
 * Construct a new Ply:: Ply object
 * @param  string fileName 
 * @param float r 
 * @param float g 
 * @param float b 
 * @return Ply 
 */

Ply::Ply(string fileName, float r, float g, float b) : Object(fileName, r, g, b) {
    this->load();
    this->set_data();
}

/**
 * @brief 
 * This method is used to load in memory the ply file.
 */

void Ply::load() {    
    string line;
    ifstream PLYfile(fileName);

    vector<string> elems;
    unsigned int prev_vertice;
    int size_vertices;
    int size_faces;

    // leer el header, obtener el numero de vertices y de caras
    while (getline(PLYfile, line) && line != "end_header") {
        elems = split(line, " ");
        if (!elems.empty()) {
            split(line, " ");
            if (elems[0] == "element") {
                if (elems[1] == "vertex") {
                    size_vertices = stoi(elems[2]);
                }
                if (elems[1] == "face") {
                    size_faces = stoi(elems[2]) + 1;
                }
            }
        }
    }

    // leer vertices y caras
    while (getline(PLYfile, line)) {
        if (size_vertices > 0) { // leer vertices
            elems = split(line, " ");
            // elems[0] = x, elems[1] = y, elems[2] = z
            Vertex v(stof(elems[0]), stof(elems[1]), stof(elems[2]));
            this->vertices.push_back(v);
            size_vertices--;
        } else if (size_faces > 0) { // leer caras
            // sacamos primer vertice
            elems = split(line, " ");
            prev_vertice = stoi(split(elems[1], " ")[0]);
            vector<Edge> edges = {};
            vector<string> temp_edges_slides;
            // iterar sobre los n - 1 vertices restantes
            for (int i = 2; i < elems.size(); i++) {
                temp_edges_slides = split(elems[i], " ");
                unsigned int actual_vertice = stoi(temp_edges_slides[0]);
                Edge e(vertices[prev_vertice], vertices[actual_vertice]);
                prev_vertice = actual_vertice;
                edges.push_back(e);
            }
            // cerrar la cara, primer vertice con el ultimo
            Edge e(vertices[prev_vertice], vertices[stoi(split(elems[1], " ")[0])]);
            edges.push_back(e);
            Face face(edges);
            // agregar la cara a la lista de caras
            this->faces.push_back(face);
            size_faces--;
        }
    }
}
