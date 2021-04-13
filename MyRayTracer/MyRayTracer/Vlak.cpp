#include "Vlak.h"
#include <glm/glm.hpp>

using namespace glm;


Vlak::Vlak(void) {
	normaalVlak = vec3(0, 0, 0);
}


Vlak::Vlak(vec3 pos, vec3 klr, vec3 norm) {
	positie = pos;
	kleur = klr;
	normaalVlak = norm;
}

bool Vlak::intersect(vec3 rayOrgin, vec3 rayDirection, float* t) {
	float denominator = dot(rayDirection, normaalVlak); //bereken als eerst de denominator

	if (abs(denominator) > 0.001f) {
		float res = dot((positie - rayOrgin), normaalVlak) / denominator;
		*t = res;

		if (*t > 0) {
			return true;
		}
	}
	return false;
}

vec3 Vlak::getNormaalVlak() {
	return normaalVlak;
}