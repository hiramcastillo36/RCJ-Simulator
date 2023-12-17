//
// Created by Hiram Castillo on 15/09/23.
//

#include "../include/Animation.h"

/**
 * @brief Construct a new Animation:: Animation object
 * 
 */

Animation::Animation() {}

/**
 * @brief 
 * This method returns the line.
 * @param float dt 
 * @param Vertex v1 
 * @param Vertex v2 
 * @return vector <Vertex> 
 */

vector<Vertex> Animation::line(float dt, Vertex v1, Vertex v2) {
    vector<Vertex> v = {};
    for (float t = 0.0; t <= 1 + dt; t += dt) {
        v.push_back(v1 + ((v2 - v1) * t));
    }

    return v;
}

/**
 * @brief 
 * This method returns the hermite curve.
 * @param  Vertex P1 
 * @param  Vertex P4 
 * @param  Vertex R1 
 * @param  Vertex R4 
 * @param  float dt 
 * @return vector < Vertex > 
 */

vector<Vertex> Animation::hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt) {

    Mat<float> MH{
            {2,  -2, 1,  1},
            {-3, 3,  -2, -1},
            {0,  0,  1,  0},
            {1,  0,  0,  0}
    };

    Mat<float> GH = {};

    GH.insert_rows(0, P1.row());
    GH.insert_rows(1, P4.row());
    GH.insert_rows(2, R1.row());
    GH.insert_rows(3, R4.row());

    Col<float> GHx{1, 5, 3, -1};

    vector<Vertex> v = {};
    // ciclo para calcular las x
    for (float t = 0.0; t <= 1.0; t += dt) {
        Row<float> T{powf(t, 3), powf(t, 2), t, 1};
        Mat<float> Qt = T * MH * GH;

        Vertex tv(Qt(0, 0), Qt(0, 1), Qt(0, 2));
        v.push_back(tv);
    }

    return v;
}

/**
 * @brief 
 * This method returns the bezier curve.
 * @param Vertex P1 
 * @param Vertex P2 
 * @param Vertex P3 
 * @param Vertex P4
 * @param float dt 
 * @return vector < Vertex > 
 */

vector<Vertex> Animation::bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt) {

    Mat<float> MH{
        {-1, 3, -3, 1},
        {3, -6, 3, 0},
        {-3, 3, 0, 0},
        {1, 0, 0, 0}
    };

    Mat<float> GH= {};
    GH.insert_rows(0, P1.row());
    GH.insert_rows(1, P2.row());
    GH.insert_rows(2, P3.row());
    GH.insert_rows(3, P4.row());

    vector<Vertex> v;

    for (float t = 0.0; t <= 1.0 + dt; t += dt) {
        Row<float> T = {powf(t, 3), powf(t, 2),  t, 1};
        
        Mat<float> Qt = T * MH * GH;

        Vertex tv(Qt(0, 0), Qt(0, 1), Qt(0, 2));
        v.push_back(tv);
    }

    return v;
}

/**
 * @brief 
 * This method returns the translation matrix.
 * @param float dx 
 * @param float dy 
 * @param float dz 
 * @return Mat < float > 
 */

Mat<float> Animation::T(float dx, float dy, float dz) {
    Mat<float> T = {
            {1, 0, 0, dx},
            {0, 1, 0, dy},
            {0, 0, 1, dz},
            {0, 0, 0, 1}
    };
    return T;
}

/**
 * @brief 
 * This method returns the scale matrix.
 * @param float sx 
 * @param float sy 
 * @param float sz 
 * @return Mat < float > 
 */

Mat<float> Animation::S(float sx, float sy, float sz) {
    Mat<float> S = {
            {sx, 0,  0,  0},
            {0,  sy, 0,  0},
            {0,  0,  sz, 0},
            {0,  0,  0,  1}
    };
    return S;
}

/**
 * @brief 
 * This method returns the rotation matrix around the x axis.
 * @param float theta 
 * @return Mat < float > 
 */

Mat<float> Animation::Rx(float theta) {
    float theta_eucli = theta * M_PI / 180;
    Mat<float> Rx = {
            {1, 0,                0,                 0},
            {0, cos(theta_eucli), -sin(theta_eucli), 0},
            {0, sin(theta_eucli), cos(theta_eucli),  0},
            {0, 0,                0,                 1}
    };
    return Rx;
}

/**
 * @brief 
 * This method returns the rotation matrix around the y axis.
 * @param float theta 
 * @return Mat < float > 
 */

Mat<float> Animation::Ry(float theta) {
    float theta_eucli = theta * M_PI / 180;
    Mat<float> Ry = {
            {cos(theta_eucli),  0, sin(theta_eucli), 0},
            {0,                 1, 0,                0},
            {-sin(theta_eucli), 0, cos(theta_eucli), 0},
            {0,                 0, 0,                1}
    };
    return Ry;
}

/**
 * @brief 
 * This method returns the rotation matrix around the z axis.
 * @param float theta 
 * @return Mat < float > 
 */

Mat<float> Animation::Rz(float theta) {
    float theta_eucli = theta * M_PI / 180;
    Mat<float> Rz = {
            {cos(theta_eucli), -sin(theta_eucli), 0, 0},
            {sin(theta_eucli), cos(theta_eucli),  0, 0},
            {0,                0,                 1, 0},
            {0,                0,                 0, 1}
    };
    return Rz;
}