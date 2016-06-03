#include "cube.hpp"

namespace Engine
{
  namespace Components
  {
    Cube::Cube()
            : Geometry(initVertices(), initIndices())
    { }

    Cube::VertexList
    Cube::initVertices()
    {
      VertexList vertices;
      GLfloat v_positions[] =
              {
                      -1.0f, 1.0f, -1.0f,
                      -1.0f, -1.0f, -1.0f,
                      -1.0f, 1.0f, 1.0f,
                      -1.0f, -1.0f, 1.0f,
                      1.0f, 1.0f, 1.0f,
                      1.0f, -1.0f, 1.0f,
                      1.0f, 1.0f, -1.0f,
                      1.0f, -1.0f, -1.0f
              };
      GLfloat normals[] =
              {
                      0.0f, 0.0f, 1.0f,
                      0.0f, 0.0f, 1.0f,
                      0.0f, 0.0f, 1.0f,
                      0.0f, 0.0f, 1.0f,
              };

      GLfloat texcoords[] =
              {
                      // Last index is an offset for the loop below
                      1.0f, 1.0f, 0.0f,
                      1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f
              };

      for (int i = 0; i < 24; i += 3)
      {
        Vertex v;
        v.position = glm::vec3(v_positions[i], v_positions[i + 1],
                               v_positions[i + 2]);
        v.normal = glm::vec3(normals[i], normals[i + 1], normals[i + 2]);
        v.texcoords = glm::vec2(texcoords[i], texcoords[i + 1]);

        vertices.push_back(v);
      }

      return vertices;
    }

    Cube::IndexList
    Cube::initIndices()
    {
      GLuint idx[] = {
              0, 1, 2, 2, 1, 3,
              4, 5, 6, 6, 5, 7,
              3, 1, 5, 5, 1, 7,
              0, 2, 6, 6, 2, 4,
              6, 7, 0, 0, 7, 1,
              2, 3, 4, 4, 3, 5
      };

      return IndexList(idx, idx + 36);
    }
  }
}