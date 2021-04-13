#include "Raytracer.h"
#include "glm/glm.hpp"
#include "Sphere.h"
#include "Vlak.h"
#include "Pyramide.h"

using namespace glm;

Raytracer::Raytracer(void) {

	
	vec3 rood = vec3(1.00, 0.32, 0.36);
	vec3 geel = vec3(0.90, 0.76, 0.46);
	vec3 blauw = vec3(0.65, 0.77, 0.97);
	vec3 vlakkleur = vec3(0.5, 0.5, 0.5);
	vec3 grijs = vec3(0.5, 0.5, 0.5);
	vec3 kleurtje = vec3(0.67, 0.35, 0.65);
	vec3 paars = vec3(0.8, 1.0, 1.0);

	ObjectVector.push_back(new Vlak(vec3(0, -4, 0), vlakkleur, vec3(0, 1, 0)));
	ObjectVector.push_back(new Sphere(vec3(0, 0, -20), rood, 4));
	ObjectVector.push_back(new Sphere(vec3(-5, -1, -10), geel, 2));
	ObjectVector.push_back(new Sphere(vec3(20, 0, -25), grijs, 3));
	ObjectVector.push_back(new Sphere(vec3(-10, 0, -10), kleurtje, 1));
	ObjectVector.push_back(new Pyramide(vec3(0, 3, -9), vec3(-1.9, 1.2, -5), vec3(1.9, 1.2, -5), 
		vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1)));
	


}

vec3 Raytracer::raytrace(vec3 RayOrgin, vec3 RayDirect, int depth) {

	vec3 finalCOLOR;
	
	float hitRays = 1.0f;
	float t0 = 0.0f;
	float minT = INFINITY;
	int objectHit = -1;

	for (int k = 0; k < ObjectVector.size(); ++k) {

		bool hit = ObjectVector[k]->intersect(RayOrgin, RayDirect, &t0);

		if (hit && t0 < minT) {
			minT = t0;
			objectHit = k;
		}
	}


	if (objectHit != -1) {
		vec3 point0 = RayOrgin + (minT * RayDirect);

		vec3 lpostition = vec3(0, 20, 0);
		vec3 lintensity = vec3(1.0, 1.0, 1.0);
		vec3 dcolor = vec3(0, 0, 0);
		vec3 speccollor = vec3(0, 0, 0);
		int shine = 2;
		vec3 lightray = normalize(lpostition - point0);
		vec3 normal = normalize(ObjectVector[objectHit]->normaalCalculatie(point0, &shine, &dcolor, &speccollor));
		vec3 diffuse = dcolor * lintensity * glm::max(0.0f, dot(lightray, normal));

		vec3 reflectie = normalize(2 * dot(lightray, normal) * normal - lightray);
		float maxCalc = glm::max(0.0f, dot(reflectie, normalize(RayOrgin - point0)));

		float tmp = pow(maxCalc, shine);
		vec3 specular = speccollor * lintensity * tmp;
		finalCOLOR = diffuse + specular;
	}
	else {
		finalCOLOR = vec3(0.1, 0.2, 0.3);
	}

	return finalCOLOR;
}