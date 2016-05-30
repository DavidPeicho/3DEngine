#include "quad.hpp"

namespace Engine
{
  namespace Components
  {
    Quad::Quad()
            : Geometry(initVertices(), initIndices())
    { }

    Quad::VertexList
    Quad::initVertices()
    {
      VertexList vertices;
      GLfloat v_positions[] =
              {
                      1.0f, 1.0f, 0.0f,
                      1.0f, -1.0f, 0.0f,
                      -1.0f, -1.0f, 0.0f,
                      -1.0f, 1.0f, 0.0f,
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

      for (int i = 0; i < 12; i += 3)
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

    Quad::IndexList
    Quad::initIndices()
    {
      GLuint idx[] = {
              0, 1, 3,
              1, 2, 3
      };
      IndexList indices(idx, idx + 6);

      return indices;
    }
  }
}