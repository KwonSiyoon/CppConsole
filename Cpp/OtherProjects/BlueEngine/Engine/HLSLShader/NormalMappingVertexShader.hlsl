struct VertexInput
{
    float3 position : POSITION;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 bitangent : BITANGENT;
};

// ConstantBuffer.
cbuffer Transform : register(b0)
{
    matrix worldMatrix;
};

// Camera Buffer.
// Align byte to 16byte.
// Must make to 16yte in DirectX
cbuffer Camera : register(b1)
{
    matrix view;
    matrix projection;
    float3 cameraPosition;
    float padding; // for Making 16byte.
};

struct VertexOutput
{
    float4 position : SV_Position;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float3 bitangent : BITANGENT;
    float3 cameraDirection : TEXCOORD1;
};

VertexOutput main(VertexInput input)
{
    VertexOutput output;
    //output.position = float4(input.position, 1);
    output.position = mul(float4(input.position, 1), worldMatrix);
    float3 worldPosition = output.position.xyz;
    output.position = mul(output.position, view);
    output.position = mul(output.position, projection);
    output.color = input.color;
    output.texCoord = input.texCoord;
    
    output.normal = normalize(mul(input.normal, (float3x3) worldMatrix));
    output.tangent = normalize(mul(input.tangent, (float3x3) worldMatrix));
    output.bitangent = normalize(mul(input.bitangent, (float3x3) worldMatrix));
    
    output.cameraDirection = normalize(worldPosition - cameraPosition);
    
    return output;
}