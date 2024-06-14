#ifndef INPUT_INPUTACTION_H
#define INPUT_INPUTACTION_H

#include <functional>
#include <stdint.h>

using InputKey = uint8_t;
using InputState = uint8_t;
using MouseButton = uint8_t;

using InputAction = std::function<void(uint32_t dt, InputState)>;

struct ButtonAction{
    InputKey key;
    InputAction action;
};

struct MousePosition{
    int32_t xPos, yPos;
};

using MouseMovedAction = std::function<void(const MousePosition& mousePosition)>; // Definicja typu dla akcji ruchu myszy jako funkcji przyjmującej pozycję myszy
using MouseInputAction = std::function<void(InputState state, const MousePosition& position)>; // Definicja typu dla akcji przycisku myszy jako funkcji przyjmującej stan wejściowy i pozycję myszy

struct MouseButtonAction{
    MouseButton mouseButton;
    MouseInputAction mouseInputAction;
};

#endif