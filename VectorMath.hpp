
#pragma once

	#include "Vector2f.hpp"
	#include "Vector3f.hpp"

	namespace pankey{

		namespace Support{

			namespace Math{

				class VectorMath{
					public:

						static Vector3f cross(const Vector2f& a_vector, Vector2f a_cross){
							return Vector3f(0, 0, a_vector.determinant(a_cross));
						}

				};

			}

		}

	}