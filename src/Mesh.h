/** \addtogroup resources
Mesh class
*  @{
*/

/*!
\file Mesh.h
*/

#ifndef _MESH_H_
#define _MESH_H_
#include <Material.h>
#include <libheaders.h>
#include <vector>
#include <Shader.h>
#include <memory>

//! Simple data structure that holds vertex data
struct Vertex
{
	glm::vec3 position;
	glm::vec2 uv;
	glm::vec3 normal;
	glm::vec3 tangent;
	glm::vec3 bitangent;
};

//! Typedef for index data
using Index = GLuint;

//! Used to conveniently specify OpenGL's vertex attributes
struct VertexAttribute
{
	//! Number of components
	GLint n;
	//! OpenGL data type. (GL_FLOAT, GL_INT ...)
	GLenum type;
	//! Stride in bytes
	GLsizei stride;
	//! Attribute offset in bytes
	GLintptr offset;
};

/*!
\brief Class that manages geometry data ready to be rendered with OpenGL
*/
class Mesh
{
public:
	//! dtor
	~Mesh();
	//! No copying
	Mesh(const Mesh& other) = delete;
	//! No copying
	Mesh& operator=(const Mesh& other) = delete;
	//! Move ctor
	Mesh(Mesh&& other);
	//! Move assignment operator
	Mesh& operator=(Mesh&& other);
	/**
	\brief Sets the mesh's material uniforms and draws the mesh
	\param shader Shader for which the uniforms shall be set
	*/
	void drawWithMaterial(ShaderProgram* shader);
	/**
	\brief Draws the mesh without setting any material uniforms
	*/
	void draw();

	//! Creates a new mesh from the given vertex and index data and configures the vertex attributes accorting to the last parameter
	static std::unique_ptr<Mesh> createMesh(const std::vector<Vertex>& vd, const std::vector<Index>& id, const std::vector<VertexAttribute>& att);
	//! Creates a new mesh from the given vertex and index data and configures the vertex attributes accorting to the last parameter. Additionally sets a material to be used for renderirng.
	static std::unique_ptr<Mesh> createMesh(const std::vector<Vertex>& vd, const std::vector<Index>& id, const std::vector<VertexAttribute>& att, Material* material);
private:
	Mesh(GLuint _vbo, GLuint _ibo, GLuint _vao, GLsizei _numIndices, Material* _material);
	Material* material;
	GLuint vbo;
	GLuint ibo;
	GLuint vao;
	GLsizei numIndices;
};

#endif
/** @}*/