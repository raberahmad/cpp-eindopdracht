#include "Basic_Object.h"
#include <glm/glm.hpp>

using namespace glm;


Basic_Object::Basic_Object(void) {
	positie = vec3(0, 0, 0);
	kleur = vec3(0, 0, 0);


}


Basic_Object::Basic_Object(vec3 pos, vec3 klr) {
	positie = pos;
	kleur = klr;
}

bool Basic_Object::intersect(vec3 rayOrgin, vec3 rayDirection, float* t) {
	return false;
}

vec3 Basic_Object::normaalCalculatie(vec3 p0, int* shininess, vec3* diffuseKleur, vec3* specularKleur) {
	return normaal;
}


vec3 Basic_Object::getPositie() {
	return positie;
}

vec3 Basic_Object::getKleur() {
	return kleur;
}

