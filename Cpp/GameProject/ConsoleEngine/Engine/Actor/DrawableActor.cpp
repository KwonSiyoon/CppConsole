#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"

DrawableActor::DrawableActor(char image)
	: Actor(), image(image)
{
}

void DrawableActor::Draw()
{
	Super::Draw();			// �θ� Super�� ����Ŵ(����Ƽ���� Base ����)

	// �׸���.
	// 1�ܰ�: �ܼ� ��ǥ �ű��.
	Engine::Get().SetCursorPosition(position);
	// 2�ܰ�: �׸���(�ܼ� ���).
	Log("%c", image);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	// ������ ��ġ�� ���� �����.
	Engine::Get().SetCursorPosition(position);
	Log(" ");

	// ��ġ�� ���� �ű��.
	Super::SetPosition(newPosition);
}
