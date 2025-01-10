#include "TextScrollLevel.h"
#include "Actor/TestScrollActor.h"

TextScrollLevel::TextScrollLevel()
{
	AddActor(new TextScrollActor("Welcome to the Console Game Engine class... What the hell.... It`s Friday..... Nice Weekend....."));
}
