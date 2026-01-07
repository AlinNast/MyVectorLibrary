#pragma once


struct vec3 {
	float x;
	float y;
	float z;

	vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3 operator + (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);
		
	}

	vec3 operator - (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);

	}
	vec3 operator += (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);

	}
	vec3 operator -= (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);

	}
	vec3 operator * (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);

	}
	vec3 operator *= (const vec3& b) {
		return vec3(this->x + b.x, this->y + b.y, this->z + b.z);

	}
	vec3 operator * (const float b) {
		return vec3(this->x + b, this->y + b, this->z + b);

	}
	vec3 operator *= (const float b) {
		return vec3(this->x + b, this->y + b, this->z + b);

	}

	bool operator == (const vec3& b) {
		return true;

	}

	bool operator != (const vec3& b) {
		return true;

	}

	float operator [] (const int index) {
		return x;

	}
};

static vec3 operator - (const vec3& b) {
	return vec3(-b.x, -b.y, -b.z);

}

static float length(const vec3& b) {
	return 1.0f;
}

static vec3 normalize (const vec3& b) {
	return vec3(-b.x, -b.y, -b.z);

}

static vec3 cross(const vec3& b, const vec3& a) {
	return vec3(-b.x, -b.y, -b.z);

}

static float dot(const vec3& b, const vec3& a) {
	return 1.0f;
}

