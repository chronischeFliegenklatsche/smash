// For all platforms
#include "smash/BehaviourScript.hpp"
#include "smash/Color.hpp"
#include "smash/Component.hpp"
#include "smash/ComponentsContainer.hpp"
#include "smash/Containers.hpp"
#include "smash/Diagnostics.hpp"
#include "smash/GameObject.hpp"
#include "smash/InputAPI.hpp"
#include "smash/InputDetection.hpp"
#include "smash/InputSystem.hpp"
#include "smash/Integers.hpp"
#include "smash/KeyCodes.hpp"
#include "smash/Math.hpp"
#include "smash/Renderer.hpp"
#include "smash/RenderingAPI.hpp"
#include "smash/Runtime.hpp"
#include "smash/Scene.hpp"
#include "smash/SceneManagement.hpp"
#include "smash/SmartPointers.hpp"
#include "smash/String.hpp"
#include "smash/TestComponent.hpp"
#include "smash/TextDisplay.hpp"
#include "smash/TimedTone.hpp"
#include "smash/Time.hpp"
#include "smash/Tone.hpp"
#include "smash/TypeNameProvider.hpp"
#include "smash/Vector2.hpp"
#include "smash/Transform.hpp"
#include "smash/RectangleRenderer.hpp"
#include "smash/EngineLoop.hpp"

// For embedded platforms such as Arduino and ESP32
#ifdef ARDUINO
#include "smash/ArduinoSpeakerTone.hpp"
#include "smash/ArduinoInputDevice.hpp"
#include "smash/ArduinoInputAPI.hpp"
#include "smash/RgbMatrixRenderingAPI.hpp"
#include "smash/ArduinoSpeaker.hpp"
#include "smash/ArduinoButton.hpp"
#endif

// For windows platform
#ifdef _WIN32
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "smash/GLBaseAPI.hpp"
#include "smash/GLInputAPI.hpp"
#include "smash/GLRenderingAPI.hpp"
#endif
