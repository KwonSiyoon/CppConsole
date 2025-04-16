#include "Common.hlsli"

struct PixelInput
{
    float4 position : SV_Position;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 bitangent : BITANGENT;
    float3 cameraDirection : TEXCOORD1;
};

// Texture.
Texture2D diffuseMap : register(t0);
Texture2D normalMap: register(t1);
SamplerState diffuseSampler : register(s0);

float4 main(PixelInput input) : SV_TARGET
{
    // Sampling.
    float4 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord);
    
    // tangent normal.
    float4 tangentNormal = normalMap.Sample(diffuseSampler, input.texCoord);
    tangentNormal = tangentNormal * 2 - 1;
    
    // tangent to world transformation matrix.
    float3x3 tangentToWorld = float3x3(
        normalize(input.tangent),               // T    X
        normalize(input.bitangent),             // B    Y
        normalize(input.normal)                 // N    Z
    );
    
    // Light Direction.
    float3 lightDir = -float3(500.0f, 500.0f, -500.0f);
    lightDir = normalize(lightDir);
    
    // World Normal.
    float3 worldNormal = normalize(mul(tangentNormal.xyz, tangentToWorld));
    
    float nDotHalfL = CalcHalfLambert(worldNormal, lightDir);
    
    float4 ambient = texColor * float4(0.1f, 0.1f, 0.1f, 1);
    float4 diffuse = texColor * nDotHalfL;
    float4 finalColor = ambient + diffuse;
    
    float specular = CalcBlinnPhong(worldNormal, lightDir, input.cameraDirection);
    
    float4 lightColor = float4(0.4f, 0.6f, 0.8f, 1);
    finalColor += lightColor * specular;
    
    return finalColor;
}