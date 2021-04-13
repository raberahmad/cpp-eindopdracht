#ifndef SPHERE_H
#define SPHERE_H



#include <glm/glm.hpp>
#include "Basic_object.h"
using namespace glm;

class Sphere : public Basic_Object
{
protected:
	float radius;
public:
	Sphere(void);
	Sphere(vec3 pos, vec3 klr, float radi);

	bool intersect(vec3 rayOrgin, vec3 rayDirection,  float* t = NULL);
	vec3 normaalCalculatie(vec3 p0, int* shininess = NULL, vec3* diffuseKleur = NULL, vec3* specularKleur = NULL);
	vec3 getKleur();

};
#endif
