#ifndef PYRAMIDE_H
#define PYRAMIDE_H
#include <glm/glm.hpp>
#include "Basic_Object.h"

class Pyramide : public Basic_Object
{
protected:
	vec3 a, b, c,  normaalA, normaalB, normaalC;

public:
	Pyramide(void);

	Pyramide(vec3 aa, vec3 bb, vec3 cc, vec3 normA, vec3 normB, vec3 normC);
	bool intersect(vec3 rayorg, vec3 raydirect, float* t = NULL);
	vec3  normaalCalculatie(vec3 p0, int* shininess = NULL, vec3* diffuseKleur = NULL, vec3* specularKleur = NULL);


};

#endif