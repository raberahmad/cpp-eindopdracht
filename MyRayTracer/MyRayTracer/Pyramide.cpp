#include "Pyramide.h"
#include <glm/glm.hpp>

using namespace std;
using namespace glm;
Pyramide::Pyramide(void) {
	a = vec3(0);
	b = vec3(0);
	c = vec3(0);
	normaalA = vec3(0);
	normaalB = vec3(0);
	normaalC = vec3(0);
}

Pyramide::Pyramide(vec3 aa, vec3 bb, vec3 cc, vec3 normA, vec3 normB, vec3 normC) {
	a = aa;
	b = bb;
	c = cc;
	normaalA = normA;
	normaalB = normB;
	normaalC = normC;
}

bool Pyramide::intersect(vec3 rayorg, vec3 raydirect, float* t) {
	vec3 e1 = b - a;
	vec3 e2 = c - a;
	float u = dot((rayorg - a), cross(raydirect, e2)) / dot(e1, (cross(raydirect, e2)));
	float v = dot(raydirect, (cross((rayorg - a), e1)) / dot(e1, cross(raydirect, e2)));
	float w = 1 - u - v;

	float t0 = dot(e2, cross((rayorg - a), e1)) / dot(e1, cross(raydirect, e2));

	if ((u < 0) || (u > 1)) {
		return false;
	}
	else if ((v < 0) || (u + v > 1)) {
		return false;
	}
	else if (t0 <= 0) {
		return false;
	}
	else {
		*t = t0;
		return true;
	}

}


vec3 Pyramide::normaalCalculatie(vec3 p0, int* shininess, vec3* diffuseKleur, vec3* specularKleur) {
	*shininess = 100;
	*diffuseKleur = kleur;
	*specularKleur = vec3(0.7);
	
	float a, b, c = 2.0;
	return (a * normaalA) + (b * normaalB) + (c * normaalC);
}