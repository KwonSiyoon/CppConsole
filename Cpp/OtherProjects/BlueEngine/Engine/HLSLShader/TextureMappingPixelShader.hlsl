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
SamplerState diffuseSampler : register(s0);

float4 main(PixelInput input) : SV_TARGET
{
    // Sampling.
    float4 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord);
    
    // Light Direction.
    float3 lightDir = -float3(500.0f, 500.0f, -500.0f);
    lightDir = normalize(lightDir);
    
    // World Normal.
    float3 worldNormal = normalize(input.normal);
    
    // Dot (Lambert).
    //float nDotL = saturate(dot(worldNormal, -lightDir));
    //float nDotL = CalcLambert(worldNormal, lightDir);
    
    // Half Lambert.
    //nDotL = pow((nDotL * 0.5f) + (1.0f - 0.5f), 3.0f);
    float nDotHalfL = CalcHalfLambert(worldNormal, lightDir);
    
    
    //float4 finalColor = texColor * nDotHalfL;
    float4 ambient = texColor * float4(0.1f, 0.1f, 0.1f, 1);
    float4 diffuse = texColor * nDotHalfL;
    float4 finalColor = ambient + diffuse;
    
    // Phong (specular).
    //float specular = 0;
    //if (nDotHalfL)
    //{
    //    float3 reflection = reflect(lightDir, worldNormal);
    //    float3 viewDirection = normalize(input.cameraDirection);
    //    float rDotV = saturate(dot(reflection, -viewDirection));
    //    float shineness = 16.0f;
    //    specular = pow(rDotV, shineness);
    //}
    //float specular = CalcPhong(worldNormal, lightDir, input.cameraDirection);
    
    // Blinn-Phong (specular).
    //float specular = 0;
    //if (nDotHalfL)
    //{
    //    // Half Vector.
    //    float3 viewDirection = normalize(input.cameraDirection);
    //    float3 halfVector = normalize(-lightDir - viewDirection);
        
    //    // nDotH.
    //    float nDotH = saturate(dot(worldNormal, halfVector));
    //    float shineness = 32.0f;
    //    specular = pow(nDotH, shineness);
    //}
    float specular = CalcBlinnPhong(worldNormal, lightDir, input.cameraDirection);
    
    
    float4 lightColor = float4(0.4f, 0.6f, 0.8f, 1);
    finalColor += lightColor * specular;
    
	//return float4(1.0f, 0.5f, 0.0f, 1.0f);
    //return float4(input.color, 1.0f);
    //return float4(input.texCoord, 0.0f, 1.0f);
    //return float4(lightIntensity, lightIntensity, lightIntensity, 1);
    return finalColor;
}