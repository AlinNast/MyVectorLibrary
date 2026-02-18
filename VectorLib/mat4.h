#pragma once
#include <stdexcept>
#include "vec4.h"
#include <cmath> 


class mat4
{
public:
	vec4 rows[4];

	mat4() {
		this->rows[0] = vec4(1.0f, 0.0f, 0.0f, 0.0f);
		this->rows[1] = vec4(0.0f, 1.0f, 0.0f, 0.0f);
		this->rows[2] = vec4(0.0f, 0.0f, 1.0f, 0.0f);
		this->rows[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	mat4(vec4 row0, vec4 row1, vec4 row2, vec4 row3) {
		this->rows[0] = row0;
		this->rows[1] = row1;
		this->rows[2] = row2;
		this->rows[3] = row3;
	}

	mat4(const mat4& other) {
		this->rows[0] = other.rows[0];
		this->rows[1] = other.rows[1];
		this->rows[2] = other.rows[2];
		this->rows[3] = other.rows[3];
	}

	// Cekc this 
	mat4 operator*(const mat4& other) const {
		mat4 result;
		for (int i = 0; i < 4; i++) {
			float rx = rows[i].x * other.rows[0].x + rows[i].y * other.rows[1].x + rows[i].z * other.rows[2].x + rows[i].w * other.rows[3].x;
			float ry = rows[i].x * other.rows[0].y + rows[i].y * other.rows[1].y + rows[i].z * other.rows[2].y + rows[i].w * other.rows[3].y;
			float rz = rows[i].x * other.rows[0].z + rows[i].y * other.rows[1].z + rows[i].z * other.rows[2].z + rows[i].w * other.rows[3].z;
			float rw = rows[i].x * other.rows[0].w + rows[i].y * other.rows[1].w + rows[i].z * other.rows[2].w + rows[i].w * other.rows[3].w;
			result.rows[i] = vec4(rx, ry, rz, rw);
		}
		return result;
	}

	vec4 operator*(const vec4& v) const {
		return vec4(
			rows[0].x * v.x + rows[0].y * v.y + rows[0].z * v.z + rows[0].w * v.w,
			rows[1].x * v.x + rows[1].y * v.y + rows[1].z * v.z + rows[1].w * v.w,
			rows[2].x * v.x + rows[2].y * v.y + rows[2].z * v.z + rows[2].w * v.w,
			rows[3].x * v.x + rows[3].y * v.y + rows[3].z * v.z + rows[3].w * v.w
		);
	}

	mat4 transpose() const {
		return mat4(
			vec4(rows[0].x, rows[1].x, rows[2].x, rows[3].x),
			vec4(rows[0].y, rows[1].y, rows[2].y, rows[3].y),
			vec4(rows[0].z, rows[1].z, rows[2].z, rows[3].z),
			vec4(rows[0].w, rows[1].w, rows[2].w, rows[3].w)
		);
	}

	vec4& operator[](int index) {
		return rows[index];
	}

	const vec4& operator[](int index) const {
		return rows[index];
	}

	bool operator == (const mat4& other) const {
	/*	return rows[0] == other.rows[0] && rows[1] == other.rows[1] &&
			rows[2] == other.rows[2] && rows[3] == other.rows[3];*/
		return true;
	}

};

static mat4 RotationX(float angleRad) {
	float c = cos(angleRad);
	float s = sin(angleRad);
	return mat4(
		vec4(1, 0, 0, 0),
		vec4(0, c, -s, 0),
		vec4(0, s, c, 0),
		vec4(0, 0, 0, 1)
	);
}

static mat4 RotationY(float angleRad) {
	float c = cos(angleRad);
	float s = sin(angleRad);
	return mat4(
		vec4(c, 0, s, 0),
		vec4(0, 1, 0, 0),
		vec4(-s, 0, c, 0),
		vec4(0, 0, 0, 1)
	);
}

static mat4 RotationZ(float angleRad) {
	float c = cos(angleRad);
	float s = sin(angleRad);
	return mat4(
		vec4(c, -s, 0, 0),
		vec4(s, c, 0, 0),
		vec4(0, 0, 1, 0),
		vec4(0, 0, 0, 1)
	);
}

static mat4 RotationAxis(vec4 axis, float angleRad) {
	float c = cos(angleRad);
	float s = sin(angleRad);
	float t = 1.0f - c;
	// Normalize axis 
	float len = sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	float x = axis.x / len, y = axis.y / len, z = axis.z / len;

	return mat4(
		vec4(t * x * x + c, t * x * y - s * z, t * x * z + s * y, 0),
		vec4(t * x * y + s * z, t * y * y + c, t * y * z - s * x, 0),
		vec4(t * x * z - s * y, t * y * z + s * x, t * z * z + c, 0),
		vec4(0, 0, 0, 1)
	);
}

inline mat4 transpose(const mat4& m) {
	return mat4(
		vec4(m[0].x, m[1].x, m[2].x, m[3].x),
		vec4(m[0].y, m[1].y, m[2].y, m[3].y),
		vec4(m[0].z, m[1].z, m[2].z, m[3].z),
		vec4(m[0].w, m[1].w, m[2].w, m[3].w)
	);
}

//inline bool matnearequal(const mat4& a, const mat4& b, float epsilon = 0.0001f) {
//	for (int i = 0; i < 4; i++) {
//		if (!n_fequal(a[i].x, b[i].x, epsilon)) return false;
//		if (!n_fequal(a[i].y, b[i].y, epsilon)) return false;
//		if (!n_fequal(a[i].z, b[i].z, epsilon)) return false;
//		if (!n_fequal(a[i].w, b[i].w, epsilon)) return false;
//	}
//	return true;
//}

inline float determinant(const mat4& m) {
	float res =
		m[0].w * m[1].z * m[2].y * m[3].x - m[0].z * m[1].w * m[2].y * m[3].x -
		m[0].w * m[1].y * m[2].z * m[3].x + m[0].y * m[1].w * m[2].z * m[3].x +
		m[0].z * m[1].y * m[2].w * m[3].x - m[0].y * m[1].z * m[2].w * m[3].x -
		m[0].w * m[1].z * m[2].x * m[3].y + m[0].z * m[1].w * m[2].x * m[3].y +
		m[0].w * m[1].x * m[2].z * m[3].y - m[0].x * m[1].w * m[2].z * m[3].y -
		m[0].z * m[1].x * m[2].w * m[3].y + m[0].x * m[1].z * m[2].w * m[3].y +
		m[0].w * m[1].y * m[2].x * m[3].z - m[0].y * m[1].w * m[2].x * m[3].z -
		m[0].w * m[1].x * m[2].y * m[3].z + m[0].x * m[1].w * m[2].y * m[3].z +
		m[0].y * m[1].x * m[2].w * m[3].z - m[0].x * m[1].y * m[2].w * m[3].z -
		m[0].z * m[1].y * m[2].x * m[3].w + m[0].y * m[1].z * m[2].x * m[3].w +
		m[0].z * m[1].x * m[2].y * m[3].w - m[0].x * m[1].z * m[2].y * m[3].w -
		m[0].y * m[1].x * m[2].z * m[3].w + m[0].x * m[1].y * m[2].z * m[3].w;
	return res;
}

inline mat4 inverse(const mat4& m) {
	float det = determinant(m);
	if (std::abs(det) < 1e-6f) return mat4(); // Return identity if not invertible

	float invDet = 1.0f / det;
	mat4 res;
	
	return res;
}