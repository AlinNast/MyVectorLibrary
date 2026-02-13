#pragma once
#include <stdexcept>


class vec3 {
public:
	float x;
	float y;
	float z;

	vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	// done
	vec3 operator + (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);
	}

	// done
	vec3 operator - (const vec3& b) {
		return vec3(this->x - b.x, this->y - b.y, this->z - b.z);
	}

	// should work
	void operator += (const vec3& b) {
		this->x + b.x, this->y + b.y, this->z + b.z;
	}
	void operator -= (const vec3& b) {
		this->x - b.x, this->y - b.y, this->z - b.z;
	}

	// Only scalar, Vector is outside the class as a static function
	vec3 operator * (float b) {
		return vec3(this->x * b, this->y * b, this->z * b);
	}
	void operator *= (float b) {
		this->x *= b;
		this->y *= b;
		this->z *= b;
	}

	// should work but doesent
	bool operator == (const vec3& b) {
		//return (this->x == b.x && this->y == b.y && this->z == b.z) ? true : false;
		return true;
	}

	// should work
	bool operator != (const vec3& b) {
		return (this->x != b.x || this->y != b.y || this->z != b.z) ? true : false;

	}

	// done
	float operator [] (const int index) {
		switch (index) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		default: throw std::out_of_range("Index out of range");
		}
		

	}


};

// should work
static vec3 operator - (const vec3& b) {
	return vec3(-b.x, -b.y, -b.z);

}

//static float length(const vec3& b) {
//	return ((b.x + b.y + b.z) / 3);
//}

// done
float length(vec3& b) {
	return std::sqrt((b.x * b.x + b.y * b.y + b.z * b.z));
}

// done
vec3 normalize (vec3& b) {
	return vec3(b.x/length(b), b.y / length(b), b.z / length(b));
}
 
static vec3 cross(const vec3& b, const vec3& a) {
	return vec3(
		(b.y * a.z) - (b.z * a.y), 
		(b.z * a.x) - (b.x * a.z), 
		(b.x * a.y) - (b.y * a.x)  
	);
}

static float dot(const vec3& b, const vec3& a) {
	return (b.x * a.x) + (b.y * a.y) + (b.z * a.z);
}

