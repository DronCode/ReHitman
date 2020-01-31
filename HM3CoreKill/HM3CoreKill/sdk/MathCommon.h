#pragma once

#include <cstdint>

namespace ioi {
	struct Vector2
	{
		float x, y;
	};

	struct Vector3
	{
		float x, y, z;
	};

	struct Vector4
	{
		float x, y, z, w;
	};

	struct Matrix4x4
	{
		float data[16];
	};
}