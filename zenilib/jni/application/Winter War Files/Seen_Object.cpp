#include "Seen_Object.h"

#include <zenilib.h>
#include "Game_Model.h"
#include "World.h"
#include "Tile.h"

using namespace Zeni;

Seen_Object::Seen_Object(const Zeni::Point3f &center_,
              const Zeni::Vector3f &size_,
              const Zeni::Quaternion &theta_ 
			  )	:
center(center_), size(size_), rotation(theta_)
{

}


Seen_Object::~Seen_Object(void)
{
}

void Seen_Object::render(Model *model) const
{
	if (!model)
		throw Error("Trying to render NULL Model!");

	const std::pair<Vector3f, float> rot = rotation.get_rotation();

    model->set_translate(center);
    model->set_scale(size);
    model->set_rotate(rot.second, rot.first);

    model->render();
}

bool Seen_Object::is_on_ground()	{
	//return true if Object is on the ground

	// if my bottom is less than the top of the tile im one
	// MAGIC NUMBER 35.0 here, modify when model fixed.
	// also @ moveable.cpp line 64.
	if(get_bottom_center().z <= Game_Model::get().get_World()->get_tile(center)->get_top_center().z + 10.0f)
		return true;

	return false;
}

bool Seen_Object::is_alive()	{
	return alive;
}

Point3f	Seen_Object::get_bottom_center() const
{
	return Point3f(center.x, center.y, center.z - size.z/2);
}

Point3f	Seen_Object::get_top_center() const
{
	return Point3f(center.x, center.y, center.z + size.z/2);
}