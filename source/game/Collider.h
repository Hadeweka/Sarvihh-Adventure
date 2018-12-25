#pragma once

#include <SFML/Graphics.hpp>
#include "Collision_Shape.h"

namespace Collider {

	template <typename CS1, typename CS2> bool check_shapes_for_collision(CS1& shape_1, CS2& shape_2);

	//! TODO: More collision algorithms
	//! TODO: Ellipse - Ellipse (with rotation)
	//! TODO: Ellipse - AABB
	
	//! TODO: Better structure, maybe separate class for collision shapes

}
