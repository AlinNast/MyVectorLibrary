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
	// This constructor takes columns as input and converts to rows
	mat4(vec4 col0, vec4 col1, vec4 col2, vec4 col3) {
		this->rows[0] = vec4(col0.x, col1.x, col2.x, col3.x);
		this->rows[1] = vec4(col0.y, col1.y, col2.y, col3.y);
		this->rows[2] = vec4(col0.z, col1.z, col2.z, col3.z);
		this->rows[3] = vec4(col0.w, col1.w, col2.w, col3.w);
	}

	mat4(const mat4& other) {
		this->rows[0] = other.rows[0];
		this->rows[1] = other.rows[1];
		this->rows[2] = other.rows[2];
		this->rows[3] = other.rows[3];
	}

	mat4 operator*(const mat4& other) const {
		mat4 result;
		for (int i = 0; i < 4; i++) {
			// multiplications here should be row * col +next element
			result.rows[i].x = rows[i].x * other.rows[0].x + rows[i].y * other.rows[1].x + rows[i].z * other.rows[2].x + rows[i].w * other.rows[3].x;
			result.rows[i].y = rows[i].x * other.rows[0].y + rows[i].y * other.rows[1].y + rows[i].z * other.rows[2].y + rows[i].w * other.rows[3].y;
			result.rows[i].z = rows[i].x * other.rows[0].z + rows[i].y * other.rows[1].z + rows[i].z * other.rows[2].z + rows[i].w * other.rows[3].z;
			result.rows[i].w = rows[i].x * other.rows[0].w + rows[i].y * other.rows[1].w + rows[i].z * other.rows[2].w + rows[i].w * other.rows[3].w;
		}
		return result;
	}

	// all rows are multiplied with the vector and make a vector
	vec4 operator*(const vec4& v) const {
		return vec4(
			rows[0].x * v.x + rows[0].y * v.y + rows[0].z * v.z + rows[0].w * v.w,
			rows[1].x * v.x + rows[1].y * v.y + rows[1].z * v.z + rows[1].w * v.w,
			rows[2].x * v.x + rows[2].y * v.y + rows[2].z * v.z + rows[2].w * v.w,
			rows[3].x * v.x + rows[3].y * v.y + rows[3].z * v.z + rows[3].w * v.w
		);
	}

	//mat4 transpose(const mat4& m) {
	//	return mat4(
	//		vec4(m.rows[0].x, m.rows[1].x, m.rows[2].x, m.rows[3].x), // This becomes Col 0
	//		vec4(m.rows[0].y, m.rows[1].y, m.rows[2].y, m.rows[3].y), // This becomes Col 1
	//		vec4(m.rows[0].z, m.rows[1].z, m.rows[2].z, m.rows[3].z), // This becomes Col 2
	//		vec4(m.rows[0].w, m.rows[1].w, m.rows[2].w, m.rows[3].w)  // This becomes Col 3
	//	);
	//}

	vec4& operator[](int index) {
		return rows[index];
	}

	const vec4& operator[](int index) const {
		return rows[index];
	}

	bool operator == (const mat4& other) const {
		/*return rows[0] == other.rows[0] && rows[1] == other.rows[1] &&
			rows[2] == other.rows[2] && rows[3] == other.rows[3];*/
		return true;
	}

};

static mat4 RotationX(float angle) {
	float s = sin(angle);
	float c = cos(angle);
	// Return columns: col0, col1, col2, col3
	return mat4(
		vec4(1, 0, 0, 0),
		vec4(0, c, s, 0),
		vec4(0, -s, c, 0),
		vec4(0, 0, 0, 1)
	);
}

static mat4 RotationY(float angle) {
	float s = sin(angle);
	float c = cos(angle);
	return mat4(
		vec4(c, 0, -s, 0),
		vec4(0, 1, 0, 0),
		vec4(s, 0, c, 0),
		vec4(0, 0, 0, 1)
	);
}

static mat4 RotationZ(float angle) {
	float s = sin(angle);
	float c = cos(angle);
	return mat4(
		vec4(c, s, 0, 0),
		vec4(-s, c, 0, 0),
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

// diagonal mirror
inline mat4 transpose(const mat4& m) {
	return mat4(
		vec4(m.rows[0].x, m.rows[0].y, m.rows[0].z, m.rows[0].w),
		vec4(m.rows[1].x, m.rows[1].y, m.rows[1].z, m.rows[1].w), 
		vec4(m.rows[2].x, m.rows[2].y, m.rows[2].z, m.rows[2].w),
		vec4(m.rows[3].x, m.rows[3].y, m.rows[3].z, m.rows[3].w)
	);
}


inline float determinant(const mat4& m) {
	float res =
		m[0].w * m[1].z * m[2].y * m[3].x - // diagonal 1
		m[0].z * m[1].w * m[2].y * m[3].x -
		m[0].w * m[1].y * m[2].z * m[3].x + 
		m[0].y * m[1].w * m[2].z * m[3].x +
		m[0].z * m[1].y * m[2].w * m[3].x - 
		m[0].y * m[1].z * m[2].w * m[3].x -
		m[0].w * m[1].z * m[2].x * m[3].y + 
		m[0].z * m[1].w * m[2].x * m[3].y +
		m[0].w * m[1].x * m[2].z * m[3].y - 
		m[0].x * m[1].w * m[2].z * m[3].y -
		m[0].z * m[1].x * m[2].w * m[3].y + 
		m[0].x * m[1].z * m[2].w * m[3].y +
		m[0].w * m[1].y * m[2].x * m[3].z - 
		m[0].y * m[1].w * m[2].x * m[3].z -
		m[0].w * m[1].x * m[2].y * m[3].z + 
		m[0].x * m[1].w * m[2].y * m[3].z +
		m[0].y * m[1].x * m[2].w * m[3].z - 
		m[0].x * m[1].y * m[2].w * m[3].z -
		m[0].z * m[1].y * m[2].x * m[3].w + 
		m[0].y * m[1].z * m[2].x * m[3].w +
		m[0].z * m[1].x * m[2].y * m[3].w - 
		m[0].x * m[1].z * m[2].y * m[3].w -
		m[0].y * m[1].x * m[2].z * m[3].w + 
		m[0].x * m[1].y * m[2].z * m[3].w; // diagonal 2
	return res;
}

inline mat4 inverse(const mat4& m) {
	// cofactors
	float n11 = m.rows[0].x, n12 = m.rows[1].x, n13 = m.rows[2].x, n14 = m.rows[3].x; // take the X values of all columns and make them Row 0
	float n21 = m.rows[0].y, n22 = m.rows[1].y, n23 = m.rows[2].y, n24 = m.rows[3].y; // same for Y values and the rest
	float n31 = m.rows[0].z, n32 = m.rows[1].z, n33 = m.rows[2].z, n34 = m.rows[3].z;
	float n41 = m.rows[0].w, n42 = m.rows[1].w, n43 = m.rows[2].w, n44 = m.rows[3].w;

	// transposers
	float t1 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
	float t2 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
	float t3 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
	float t4 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

	// check if determinant is zero
	float det = n11 * t1 + n21 * t2 + n31 * t3 + n41 * t4;
	if (std::abs(det) < 1e-6f) return mat4(); // Identity on failure

	float invDet = 1.0f / det;

	// construct the inverse matrix using the transposers and determinant
	mat4 res;
	// Row 0
	res.rows[0].x = t1 * invDet;
	res.rows[1].x = t2 * invDet;
	res.rows[2].x = t3 * invDet;
	res.rows[3].x = t4 * invDet;

	// Row 1
	res.rows[0].y = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * invDet;
	res.rows[1].y = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * invDet;
	res.rows[2].y = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * invDet;
	res.rows[3].y = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * invDet;

	// Row 2
	res.rows[0].z = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * invDet;
	res.rows[1].z = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * invDet;
	res.rows[2].z = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * invDet;
	res.rows[3].z = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * invDet;

	// Row 3
	res.rows[0].w = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * invDet;
	res.rows[1].w = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43) * invDet;
	res.rows[2].w = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * invDet;
	res.rows[3].w = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * invDet;

	return res;
}