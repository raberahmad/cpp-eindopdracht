#ifndef VLAK_H
#define VLAK_H




#include <glm/glm.hpp>
#include "Basic_object.h"
using namespace glm;

class Vlak : public Basic_Object
{
protected:
	vec3 normaalVlak;
public:
	Vlak(void);
	Vlak(vec3 pos, vec3 klr, vec3 norm);
	bool intersect(vec3 rayOrgin, vec3 rayDirection, float* t);
	vec3 getNormaalVlak();
};

#endif