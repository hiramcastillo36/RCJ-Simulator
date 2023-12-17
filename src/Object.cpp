//
// Created by Hiram Castillo on 04/09/23.
//

#include "../include/Object.h"

using namespace std;

/**
 * @brief Construct a new Object:: Object object
 * 
 * @param string fileName 
 * @param float r 
 * @param float g 
 * @param float b 
 */


Object::Object(string fileName, float r, float g, float b) {
    this->fileName = fileName;
    this->r = r;
    this->g = g;
    this->b = b;

    this->scale = glm::mat4(1.0f);
    this->rotate = glm::mat4(1.0f);
    this->translate = glm::mat4(1.0f);
    this->transform = glm::mat4(1.0f);
}


/**
 * @brief 
 * This method split a string with a delimiter.
 * @param str 
 * @param delim 
 * @return vector < string > 
 */

vector<string> Object::split(const std::string &str, const std::string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

/**
 * @brief 
 * This method returns the vertices.
 * @return vector < Vertex > 
 */

vector<Vertex> Object::getVertices() {
    return vertices;
}

/**
 * @brief 
 * This method returns the faces.
 * @return vector < Face > 
 */

vector<Face> Object::getFaces() {
    return faces;
}

/**
 * @brief 
 * This method returns the scale matrix.
 * @return glm::mat4 
 */

glm::mat4 Object::getScale() {
    return scale;
}

/**
 * @brief 
 * This method returns the rotation matrix.
 * @return glm::mat4 
 */

glm::mat4 Object::getRotate() {
    return rotate;
}

/**
 * @brief 
 * This method returns the translation matrix.
 * @return glm::mat4 
 */

glm::mat4 Object::getTranslate() {
    return translate;
}

/**
 * @brief 
 * This method returns the transform matrix.
 * @return glm::mat4 
 */

glm::mat4 Object::getTransform() {
    return rotate * translate * scale;
}

/**
 * @brief 
 * This method sets the scale matrix.
 * @param scale 
 */

void Object::setScale(glm::mat4 scale) {
    this->scale = scale;
}

/**
 * @brief 
 * This method sets the rotation matrix.
 * @param rotate 
 */

void Object::setRotate(glm::mat4 rotate) {
    this->rotate = rotate;
}

/**
 * @brief 
 * This method sets the translation matrix.
 * @param translate 
 */

void Object::setTranslate(glm::mat4 translate) {
    this->translate = translate;
}

/**
 * @brief 
 * This method is used to draw the object.
 * @param programID 
 * @param camera 
 */

void Object::draw(GLuint programID, glm::mat4 camera) {
    
    this->transform = camera * getTransform();

    // Enviar al shader
    GLuint MatrixID = glGetUniformLocation(programID, "Transform");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &this->transform[0][0]);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, this->datasize); // Starting from vertex 0; 3 vertices total -> 1 triangle    
    glDisableVertexAttribArray(0);
}

/**
 * @brief 
 * This method is used to set the data of the object.
 */

void Object::set_data() {
    vector <GLfloat> vertex_buffer_data = {};
    vector <GLfloat> color_buffer_data = {};

    for(Face f: this->faces)
    {
        for(Edge e: f.getEdges())
        {
            float x = e.getVi().getX();
            float y = e.getVi().getY();
            float z= e.getVi().getZ();
            vertex_buffer_data.push_back(x);
            vertex_buffer_data.push_back(y);
            vertex_buffer_data.push_back(z);
            color_buffer_data.push_back(this->r);
            color_buffer_data.push_back(this->g);
            color_buffer_data.push_back(this->b);
        }
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenBuffers(1, &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size()*sizeof(GLfloat), &vertex_buffer_data[0], GL_STATIC_DRAW);
    this->datasize = vertex_buffer_data.size();

    glGenBuffers(1, &this->colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, color_buffer_data.size()*sizeof(GLfloat), &color_buffer_data[0], GL_STATIC_DRAW);
}
