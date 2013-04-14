#pragma once
//This class represents our standard gameplay. Everything neccessary will be in here
//If we want to add more modes later, then those classes can inherit from this one


#include <zenilib.h>
//This class basically replaces bootstrap (except for Instruction state stuff)
//I did not modify the relevant code, and I copy and pasted it here, but essentially 
//the play_state in bootstrap is disconnected

class Controls;
class Team;


using namespace std;
using namespace Zeni;



class Play_State_Base : public Gamestate_Base		{
  Play_State_Base(const Play_State_Base &);
  Play_State_Base operator=(const Play_State_Base &);
 
public:
	Play_State_Base(const vector<String> &genders_, const vector<int> &colors_, const vector<int> &controls_, const vector<int> &sensitivities_, bool isLocalGame_ = true, bool isServer_ = false);
	~Play_State_Base();



private:

	bool isServer;
	bool isLocal;

	vector<Controls*> controllers;
	vector<int> teams;
	vector<Zeni::String> genders;

	Color m_prev_clear_color;

	void on_joy_axis(const SDL_JoyAxisEvent &event);
	void on_joy_hat(const SDL_JoyHatEvent &event);
	void on_joy_button(const SDL_JoyButtonEvent &event);
	
	void on_key(const SDL_KeyboardEvent &event);
 	void on_mouse_motion(const SDL_MouseMotionEvent &event);

	void on_push();
	void on_pop();

	void perform_logic();

	void render();

};



