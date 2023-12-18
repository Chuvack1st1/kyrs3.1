#pragma once
#include "SFML/Graphics.hpp"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

struct Vertices {
    Vector2 vertices[4];
};
