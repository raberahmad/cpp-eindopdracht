#include "Sphere.h"
#include <glm/glm.hpp>

using namespace glm;


Sphere::Sphere(void) {
	radius = 0;
}


Sphere::Sphere(vec3 pos, vec3 klr, float radi) {
	positie = pos;
	kleur = klr;
	radius = radi;
}

bool Sphere::intersect(vec3 rayOrgin, vec3 rayDirection,float* t) {
	vec3 L = positie - rayOrgin;
	float tca = dot(L, rayDirection);

	if (tca < 0) {
		return false;
	}

	float s2 = (dot(L, L)) - (tca * tca);
	float s = sqrt(s2);

	if (s > radius) {
		return false;
	}

	float thc = sqrt((radius * radius) - s2);
	*t = tca - thc;

	return true;
}


vec3 Sphere::normaalCalculatie(vec3 p0, int* shininess, vec3* diffuseKleur, vec3* specularKleur) {
	*shininess = 20;
	*diffuseKleur = kleur * vec3(0.7);
	*specularKleur = vec3(1.0);
	return p0 - positie;
}

vec3 Sphere::getKleur() {
	return kleur;
}
