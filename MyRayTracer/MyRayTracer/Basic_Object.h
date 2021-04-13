#ifndef BASIC_OBJECT_H
#define BASIC_OBJECT_H



#include <glm/glm.hpp>

using namespace glm;

class Basic_Object
{
protected:
	vec3 positie;
	vec3 kleur;
	vec3 normaal;
public:
	Basic_Object(void);
	Basic_Object(vec3 pos, vec3 klr);
	virtual bool intersect(vec3 rayOrgin, vec3 rayDirection, float* t);
	virtual vec3 normaalCalculatie(vec3 p0, int* shininess = NULL, vec3* diffuseKleur = NULL, vec3* specularKleur = NULL);
	vec3 getPositie();
	vec3 getKleur();

};

#endif 