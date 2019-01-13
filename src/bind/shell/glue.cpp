#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
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
#include <emscripten.h>


extern "C" {
	
	// Not using size_t for array indices as the values used by the javascript code are signed.
	void array_bounds_check(const int array_size, const int array_idx) {
		  if (array_idx < 0 || array_idx >= array_size) {
			    EM_ASM({
				      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
				    }, array_idx, array_size);
			  }
	}
	// Game
	User EMSCRIPTEN_KEEPALIVE Game_get_user(toy::Game* self) {
		return self->m_user;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_user(toy::Game* self, User user) {
		self->m_user = user;
	}
	GameMode EMSCRIPTEN_KEEPALIVE Game_get_mode(toy::Game* self) {
		return self->m_mode;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_mode(toy::Game* self, GameMode mode) {
		self->m_mode = mode;
	}
	GameShell EMSCRIPTEN_KEEPALIVE Game_get_shell(toy::Game* self) {
		return self->m_shell;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_shell(toy::Game* self, GameShell shell) {
		self->m_shell = shell;
	}
	GameModule EMSCRIPTEN_KEEPALIVE Game_get_module(toy::Game* self) {
		return self->m_module;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_module(toy::Game* self, GameModule module) {
		self->m_module = module;
	}
	Ref EMSCRIPTEN_KEEPALIVE Game_get_player(toy::Game* self) {
		return self->m_player;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_player(toy::Game* self, Ref player) {
		self->m_player = player;
	}
	World EMSCRIPTEN_KEEPALIVE Game_get_world(toy::Game* self) {
		return self->m_world;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_world(toy::Game* self, World world) {
		self->m_world = world;
	}
	Widget EMSCRIPTEN_KEEPALIVE Game_get_screen(toy::Game* self) {
		return self->m_screen;
	}
	void EMSCRIPTEN_KEEPALIVE Game_set_screen(toy::Game* self, Widget screen) {
		self->m_screen = screen;
	}
	void EMSCRIPTEN_KEEPALIVE Game___destroy__(toy::Game* self) {
		delete self;
	}
	// GameModule
	void EMSCRIPTEN_KEEPALIVE GameModule_init_2(toy::GameModule* self, GameShell shell, Game game) {
		self->init(*shell, *game);
	}
	void EMSCRIPTEN_KEEPALIVE GameModule_start_2(toy::GameModule* self, GameShell shell, Game game) {
		self->start(*shell, *game);
	}
	void EMSCRIPTEN_KEEPALIVE GameModule_pump_3(toy::GameModule* self, GameShell shell, Game game, Widget ui) {
		self->pump(*shell, *game, *ui);
	}
	void EMSCRIPTEN_KEEPALIVE GameModule_scene_2(toy::GameModule* self, GameShell shell, GameScene scene) {
		self->scene(*shell, *scene);
	}
	void EMSCRIPTEN_KEEPALIVE GameModule_paint_3(toy::GameModule* self, GameShell shell, GameScene scene, Gnode graph) {
		self->paint(*shell, *scene, *graph);
	}
	void EMSCRIPTEN_KEEPALIVE GameModule___destroy__(toy::GameModule* self) {
		delete self;
	}
	// GameShell
	void EMSCRIPTEN_KEEPALIVE GameShell_init_0(toy::GameShell* self) {
		self->init();
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_load_1(toy::GameShell* self, GameModule module) {
		self->load(*module);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_load_path_1(toy::GameShell* self, const std::string module_path) {
		self->load_path(*module_path);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_0(toy::GameShell* self) {
		self->run(iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_1(toy::GameShell* self, size_t iterations) {
		self->run(iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_game_1(toy::GameShell* self, GameModule module) {
		self->run_game(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_game_2(toy::GameShell* self, GameModule module, size_t iterations) {
		self->run_game(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_editor_1(toy::GameShell* self, GameModule module) {
		self->run_editor(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_editor_2(toy::GameShell* self, GameModule module, size_t iterations) {
		self->run_editor(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_game_path_1(toy::GameShell* self, const std::string module_path) {
		self->run_game_path(*module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_game_path_2(toy::GameShell* self, const std::string module_path, size_t iterations) {
		self->run_game_path(*module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_editor_path_1(toy::GameShell* self, const std::string module_path) {
		self->run_editor_path(*module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_run_editor_path_2(toy::GameShell* self, const std::string module_path, size_t iterations) {
		self->run_editor_path(*module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_launch_0(toy::GameShell* self) {
		self->launch();
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_save_0(toy::GameShell* self) {
		self->save();
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_reload_0(toy::GameShell* self) {
		self->reload();
	}
	bool EMSCRIPTEN_KEEPALIVE GameShell_pump_0(toy::GameShell* self) {
		return self->pump();
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_cleanup_0(toy::GameShell* self) {
		self->cleanup();
	}
	GameScene EMSCRIPTEN_KEEPALIVE GameShell_add_scene_0(toy::GameShell* self) {
		return self->add_scene();
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_remove_scene_1(toy::GameShell* self, GameScene scene) {
		self->remove_scene(*scene);
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_clear_scenes_0(toy::GameShell* self) {
		self->clear_scenes();
	}
	Core EMSCRIPTEN_KEEPALIVE GameShell_get_core(toy::GameShell* self) {
		return self->core;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_core(toy::GameShell* self, Core core) {
		self->core = core;
	}
	LuaInterpreter EMSCRIPTEN_KEEPALIVE GameShell_get_lua(toy::GameShell* self) {
		return self->lua;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_lua(toy::GameShell* self, LuaInterpreter lua) {
		self->lua = lua;
	}
	WrenInterpreter EMSCRIPTEN_KEEPALIVE GameShell_get_wren(toy::GameShell* self) {
		return self->wren;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_wren(toy::GameShell* self, WrenInterpreter wren) {
		self->wren = wren;
	}
	GfxSystem EMSCRIPTEN_KEEPALIVE GameShell_get_gfx(toy::GameShell* self) {
		return self->gfx;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_gfx(toy::GameShell* self, GfxSystem gfx) {
		self->gfx = gfx;
	}
	Context EMSCRIPTEN_KEEPALIVE GameShell_get_context(toy::GameShell* self) {
		return self->context;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_context(toy::GameShell* self, Context context) {
		self->context = context;
	}
	Vg EMSCRIPTEN_KEEPALIVE GameShell_get_vg(toy::GameShell* self) {
		return self->vg;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_vg(toy::GameShell* self, Vg vg) {
		self->vg = vg;
	}
	UiWindow EMSCRIPTEN_KEEPALIVE GameShell_get_ui_window(toy::GameShell* self) {
		return self->ui_window;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_ui_window(toy::GameShell* self, UiWindow ui_window) {
		self->ui_window = ui_window;
	}
	Editor EMSCRIPTEN_KEEPALIVE GameShell_get_editor(toy::GameShell* self) {
		return self->m_editor;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_editor(toy::GameShell* self, Editor editor) {
		self->m_editor = editor;
	}
	Ui EMSCRIPTEN_KEEPALIVE GameShell_get_ui(toy::GameShell* self) {
		return self->m_ui;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell_set_ui(toy::GameShell* self, Ui ui) {
		self->m_ui = ui;
	}
	void EMSCRIPTEN_KEEPALIVE GameShell___destroy__(toy::GameShell* self) {
		delete self;
	}
	// GameModuleBind
	toy::GameModuleBind* EMSCRIPTEN_KEEPALIVE GameModuleBind_GameModuleBind_2(Module module, const mud::VirtualMethod call) {
		return new toy::GameModuleBind(*module, *call);
	}
	void EMSCRIPTEN_KEEPALIVE GameModuleBind___destroy__(toy::GameModuleBind* self) {
		delete self;
	}
	// GameScene
	void EMSCRIPTEN_KEEPALIVE GameScene___destroy__(toy::GameScene* self) {
		delete self;
	}
	
}


