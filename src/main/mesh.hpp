#ifndef _TAYLOR_JOSEPH_MESH_
#define _TAYLOR_JOSEPH_MESH_
#include "math/math.hpp"
#include "math/vector.hpp"
#include <vector>


struct Vertex{
  Vector3 position;
  Vector3 normal;
  Vector2 tex_coord;
};

struct Triangle{
  unsigned int indices[3];
  unsigned int normal_index;
};
typedef std::vector<Vertex> VertexList;
typedef std::vector<Triangle> TriangleList;
typedef std::vector<Vector3> NormalList;
typedef std::vector<int> IndexList;

struct Mesh{
  VertexList vertices;
  TriangleList triangles;
  NormalList normals;
  IndexList indices;

  int num_triangles;
  int num_vertices;
  Vector3 COM;

  char * filename;
  
  Vector3 get_normal(Vector3 a, Vector3 b, Vector3 c);
  bool load(char *filename);
private:
  void calculate_normals();

};

#endif
