#include <infra/Api.h>
#include <jobs/Api.h>
#include <type/Api.h>
#include <tree/Api.h>
#include <pool/Api.h>
#include <refl/Api.h>
#include <ecs/Api.h>
#include <srlz/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <noise/Api.h>
#include <wfc/Api.h>
#include <fract/Api.h>
#include <lang/Api.h>
#include <ctx/Api.h>
#include <ui/Api.h>
#include <uio/Api.h>
#include <bgfx/Api.h>
#include <gfx/Api.h>
#include <gfx-pbr/Api.h>
#include <gfx-obj/Api.h>
#include <gltf/Api.h>
#include <gfx-gltf/Api.h>
#include <gfx-ui/Api.h>
#include <gfx-edit/Api.h>
#include <tool/Api.h>
#include <wfc-gfx/Api.h>
#include <frame/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <shell/Api.h>
#include <minimal/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Bullet
	mud::Type* DECL Bullet__type() {
		return &mud::type<Bullet>();
	}
	mud::vec3* DECL Bullet__get_source(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_source, &temp);
	}
	void DECL Bullet__set_source(Bullet* self, mud::vec3* value) {
		self->m_source = *value;
	}
	mud::vec3* DECL Bullet__get_velocity(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_velocity, &temp);
	}
	void DECL Bullet__set_velocity(Bullet* self, mud::vec3* value) {
		self->m_velocity = *value;
	}
	void DECL Bullet__destroy(Bullet* self) {
		delete self;
	}
	// Crate
	mud::Type* DECL Crate__type() {
		return &mud::type<Crate>();
	}
	Crate* DECL Crate_Crate_0() {
		return new Crate();
	}
	Crate* DECL Crate_Crate_3(toy::HSpatial spatial, toy::HMovable movable, const mud::vec3* extents) {
		return new Crate(spatial, movable, *extents);
	}
	mud::vec3* DECL Crate__get_extents(Crate* self) {
		static mud::vec3 temp;
		return (temp = self->m_extents, &temp);
	}
	void DECL Crate__set_extents(Crate* self, mud::vec3* value) {
		self->m_extents = *value;
	}
	void DECL Crate__destroy(Crate* self) {
		delete self;
	}
	// Human
	mud::Type* DECL Human__type() {
		return &mud::type<Human>();
	}
	Human* DECL Human_Human_0() {
		return new Human();
	}
	Human* DECL Human_Human_2(toy::HSpatial spatial, toy::HMovable movable) {
		return new Human(spatial, movable);
	}
	void DECL Human__destroy(Human* self) {
		delete self;
	}
	// Player
	mud::Type* DECL Player__type() {
		return &mud::type<Player>();
	}
	void DECL Player__destroy(Player* self) {
		delete self;
	}
	
}


