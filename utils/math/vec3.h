
namespace math {

	struct vec3 {

		float x;
		float y;
		float z;

		vec3();
		vec3(float x, float y, float z);

		vec3 cross(vec3 vector);
	};

}
