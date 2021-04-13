#include <glm/glm.hpp>
#include <vector>
#include "Basic_Object.h"

using namespace glm;
using namespace std;

class Raytracer {
protected:
	vector<Basic_Object*> ObjectVector;
public:

	Raytracer(void);
	vec3 raytrace(vec3 RayOrgin, vec3 RayDirect, int depth);
	
};