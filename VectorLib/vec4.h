#pragma once

#pragma once


struct vec4 {
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
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}
	vec4 operator += (const vec4& b) {
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}
	vec4 operator -= (const vec4& b) {
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}
	vec4 operator * (const vec4& b) {
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}
	vec4 operator *= (const vec4& b) {
		return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);

	}
	vec4 operator * (const float b) {
		return vec4(this->x + b, this->y + b, this->z + b, this->w + b);

	}
	vec4 operator *= (const float b) {
		return vec4(this->x + b, this->y + b, this->z + b, this->w + b);

	}

	bool operator == (const vec4& b) {
		return true;

	}

	bool operator != (const vec4& b) {
		return true;

	}

	float operator [] (const int index) {
		return x;

	}
};

static vec4 operator - (const vec4& b) {
	return vec4(-b.x, -b.y, -b.z, -b.w);

}