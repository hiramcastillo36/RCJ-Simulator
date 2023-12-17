#include "../include/Scene.h"

/**
 * @brief Construct a new Scene:: Scene object
 *
 */

Scene::Scene()
{
    this->key_flag = 0;
    this->point_flag = 0;
    this->stateSimulation = 1;
    this->clickLocked = false;
}

/**
 * @brief 
 * This method runs the simulation.
 * 
 */

void Scene::run()
{
    OpenGL gl = OpenGL();

    GLFWwindow *window = gl.createWindow(1000, 500, "Simulation");
    if (window == NULL)
        return;

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    Simulation simulation;

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {
            simulation.changeCamera(1);
            stateSimulation = 0;
        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {
            simulation.changeCamera(2);
            stateSimulation = 1;
        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        {
            simulation.changeCamera(3);
            stateSimulation = 0;
        }

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            if (!clickLocked)
            {
                glfwGetCursorPos(window, &xMouseClick, &yMouseClick);
                yMouseClick = 250 - yMouseClick;
                xMouseClick -= 500;
                point_flag++;

                clickLocked = true;
                glfwSetTime(0.0);
            }
        }

        if (glfwGetTime() > 0.5)
        {
            clickLocked = false;
        }

        if (stateSimulation == 1)
        {
            if (point_flag == 1)
            {
                simulation.setPoint(xMouseClick / 100, -1 * (yMouseClick / 100));
                point_flag++;
            }
            if (point_flag == 3)
            {
                simulation.setPoint2(xMouseClick / 100, -1 * (yMouseClick / 100));
                point_flag = 0;
            }
        }

        if (point_flag > 3)
        {
            cout << "Error: Presionar tecla numero 2 para cambiar posicion de puntos" << endl;
            point_flag = 0;
        }

        simulation.init(gl.getProgramID());

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
            
    glfwTerminate();
    return;
}