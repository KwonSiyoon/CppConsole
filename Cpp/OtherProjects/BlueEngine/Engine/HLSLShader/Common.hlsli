// Lambert cosine law.
float CalcLambert(float3 worldNormal, float3 lightDirection)
{
    return saturate(dot(worldNormal, -lightDirection));
}

// Half Lambert.
float CalcHalfLambert(float3 worldNormal, float3 lightDirection, float param = 2.0f)
{
    float nDotL = CalcLambert(worldNormal, lightDirection);
    return pow(nDotL * 0.5f + 0.5f, param);
}

// Phong.
float CalcPhong(float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shineness = 16.0f)
{
    float nDotL = CalcLambert(worldNormal, lightDirection);
    
    float specular = 0;
    if (nDotL)
    {
        float3 reflection = reflect(lightDirection, worldNormal);
        float3 viewDirection = normalize(cameraDirection);
        float rDotV = saturate(dot(reflection, -viewDirection));
        specular = pow(rDotV, shineness);
    }
    
    return specular;
}

// Blinn-Phong.
float CalcBlinnPhong(float3 worldNormal, float3 lightDirection, float3 cameraDirection, float shineness = 32.0f)
{
    //float nDotL = CalcLambert(worldNormal, lightDirection);
    // N dot L
    float NoL = CalcLambert(worldNormal, lightDirection);
    
    float specular = 0;
    if (NoL>0)
    {
        // Half Vector.
        float3 viewDirection = normalize(cameraDirection);
        float3 halfVector = normalize(-lightDirection - viewDirection);
        
        // nDotH.
        // N dot H
        //float nDotH = saturate(dot(worldNormal, halfVector));
        float NoH = saturate(dot(worldNormal, halfVector));
        //specular = pow(nDotH, shineness);
        specular = pow(NoH, shineness);
    }
    return specular;
}