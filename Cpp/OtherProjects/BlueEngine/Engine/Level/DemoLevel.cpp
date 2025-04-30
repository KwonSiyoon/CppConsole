#include "DemoLevel.h"

#include "Actor/Actor.h"
#include "Actor/QuadActor.h"
#include "Actor/SphereActor.h"
#include "Actor/CameraActor.h"

#include "Render/QuadMesh.h"

#include "Resource/ShaderLoader.h"
#include "Resource/ModelLoader.h"
#include "Resource/TextureLoader.h"

#include "Shader/TextureMappingShader.h"

#include "Component/StaticMeshComponent.h"
#include "Component/CameraComponent.h"

namespace Blue
{
    DemoLevel::DemoLevel()
    {
        // 데모 씬 구성.

        // 액터 생성.
        std::shared_ptr<QuadActor> quadActor = std::make_shared<QuadActor>();
        quadActor->transform.position.x = 0.5f;
        quadActor->transform.scale = Vector3::One * 0.5f;

        std::shared_ptr<QuadActor> quadActor2 = std::make_shared<QuadActor>();
        quadActor2->transform.position.x = 1.5f;
        quadActor2->transform.scale = Vector3::One * 0.5f;

        std::shared_ptr<SphereActor> sphereActor = std::make_shared<SphereActor>();
        sphereActor->transform.position.x = -0.5f;
        sphereActor->transform.scale = Vector3::One * 0.5f;

        //// 스태틱 메시 컴포넌트 생성.
        //std::shared_ptr<StaticMeshComponent> meshComponent = std::make_shared<StaticMeshComponent>();
        //// 액터에 컴포넌트 추가.
        //actor->AddComponent(meshComponent);
        //// 리소스 로드 및 컴포넌트 설정.
        //meshComponent->SetMesh(std::make_shared<QuadMesh>());
        //std::weak_ptr<TextureMappingShader> shader;
        //if (ShaderLoader::Get().Load<TextureMappingShader>(shader, "T_coord.png"))
        //{
        //    meshComponent->AddShader(shader);
        //}
        
        // 카메라 액터 생성.
        //std::shared_ptr<Actor> cameraActor = std::make_shared<Actor>();
        //cameraActor->AddComponent(std::make_shared<CameraComponent>());
        std::shared_ptr<CameraActor> cameraActor = std::make_shared<CameraActor>();
        cameraActor->transform.position.z = -2.0f;


        // 액터를 레벨에 추가.
        AddActor(quadActor);
        AddActor(quadActor2);
        AddActor(sphereActor);
        AddActor(cameraActor);
    }
    DemoLevel::~DemoLevel()
    {
    }
}
