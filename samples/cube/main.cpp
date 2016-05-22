#include "engine.hpp"
#include "components/transform.hpp"

#include <GLFW/glfw3.h>

using namespace Engine;
using namespace Engine::Scene;

static void error_callback(int error, const char* description)
{
  std::cerr << "Error " << error << ": " << description;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    throw 1;

  GLFWwindow* window = glfwCreateWindow(640, 480, "Cube Sample", NULL, NULL);

  glfwSetKeyCallback(window, key_callback);

  if (!window)
  {
    glfwTerminate();
    throw 1;
  }

  Node::NodePtr root = Node::create("root");
  Node::NodePtr camera = Node::create("camera");
  Node::NodePtr cube = Node::create("cube");
  //cube->add_component(std::shared_ptr<Transform>());

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    // Refreshes screen
    // Draws
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
