#pragma once

#include <string>

#include "Engine\Button.h"
#include "Movie.h"
#include "Engine\SDL_ptr.h"
#include "Engine\Sprite.h"

//CurrentScene is static.
//Use to reference class functions.

class Scene
{
public:
	~Scene();
	Scene();
	void SetHeader(std::string name, std::string sceneFile);
	Sprite_ptr bk;
	SDL_Texture_ptr bkFMV;
	std::vector<Sprite_ptr> ovls;
	std::vector<Button_ptr> hots;
	std::vector<Movie_ptr> fmvs;
	std::string sceneFile;
	std::string sceneName;

	void Draw();
	void Run();
	void EventProc(SDL_Event event);
	void setBkg(std::string fileName);
	void AddSprite(Sprite_ptr sprite);
	void AddHotzone(Button_ptr hot);
	void AddMovie(Movie_ptr fmv);
	void AddMusic(std::string sound, int channel, int loop, int chan1, int chan2);
	void AddSound(std::string sound, int channel, int loop, int chan1, int chan2);
	static void AddSound(std::string sound, int channel, int loop, int chan1, int chan2, int scene);
	static void AddSound(std::string sound, int channel, int loop, int chan1, int chan2, std::string scene);

protected:
};
using Scene_ptr = std::shared_ptr<Scene>;

extern Scene_ptr currentScene;
extern Scene_ptr nextScene;
extern bool sceneChangeFlag;
extern bool sceneReloadFlag;
extern std::string sceneChangeName;
extern std::string prevScene;
extern bool flags[];

//For internal use. Call Loader::loadScene instead
void _ChangeScene(std::string sceneName);
//For internal use. Call Loader::loadScene instead
void _LoadScene(std::string sceneName);
void ReloadScene();