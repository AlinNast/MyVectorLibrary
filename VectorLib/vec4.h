#pragma once
#include <stdexcept>

#pragma once


class vec4 {
public:
	float x;
	float y;
	float z;
	float w;

	vec4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4 operator + (const vec4& b) {
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}

	vec4 operator - (const vec4& b) {
		return vec4(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);

	}
	void operator += (const vec4& b) {
		this->x += b.x;
		this->y += b.y;
		this->z += b.z;
		this->w += b.w;
	}
	void operator -= (const vec4& b) {
		this->x -= b.x;
		this->y -= b.y;
		this->z -= b.z;
		this->w -= b.w;
	}

	
	vec4 operator * (const float b) {
		return vec4(this->x * b, this->y * b, this->z * b, this->w * b);

	}
	void operator *= (const float b) {
		this->x *= b;
		this->y *= b;
		this->z *= b;
		this->w *= b;
	}

	bool operator == (const vec4& b) {
		return ((this->x == b.x && this->y == b.y && this->z == b.z && this->w == b.w) ? true : false);

	}

	bool operator != (const vec4& b) {
		return ((this->x != b.x || this->y != b.y || this->z != b.z || this->w != b.w) ? true : false);

	}

	float operator [] (const int index) {
		switch (index) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		default: throw std::out_of_range("Index out of range");
		}
	}
};

float length(vec4& b) {
	return std::sqrt((b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w));
}


vec4 normalize(vec4& b) {
	return vec4(b.x / length(b), b.y / length(b), b.z / length(b), b.w / length(b));
}

static vec4 operator - (const vec4& b) {
	return vec4(-b.x, -b.y, -b.z, -b.w);

}

static float dot(const vec4& b, const vec4& a) {
	return (b.x * a.x) + (b.y * a.y) + (b.z * a.z) + (b.w * a.w);
}