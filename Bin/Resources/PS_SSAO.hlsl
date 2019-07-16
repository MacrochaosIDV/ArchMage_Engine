/**
************************
*
*  SSAO
*
************************
*/

sampler NormalSampler;
sampler PositionSampler;

float2 fViewportDimensions;

float SampleRadius;
float Intensity;
float Scale;
float Bias;

float4 ClearColor;

struct PS_INPUT 
{
   float4 Position  : POSITION0;
   float2 TexCoords : TEXCOORD0;
};

struct PS_OUTPUT 
{
   float4 Color : COLOR0;
};

float4 getPosition(in float2 uv)
{
   return tex2D(PositionSampler, uv);
}

float3 getNormal(in float2 uv)
{  
   return normalize(tex2D(NormalSampler, uv).xyz);
}

float2 getRandom(in float2 uv)
{
   float noiseX = (frac(sin(dot(uv, float2(15.8989f, 76.123f)*1.0f))*46336.23745f));
   float noiseY = (frac(sin(dot(uv, float2(11.9899f, 62.233f)*2.0f))*34748.34744f));
   float noiseZ = (frac(sin(dot(uv, float2(13.3238f, 63.122f)*3.0f))*59998.47362f));
   
   return normalize(float3(noiseX, noiseY, noiseZ));
}

float doAmbientOcclusion(in float2 tCoord,in float2 uv, in float3 pos, in float3 cNorm)
{
   float3 diff = getPosition(tCoord + uv) - pos;
   const float3 v = normalize(diff);
   const float d = length(diff) * Scale;
   return max(0.0f, dot(cNorm, v)- Bias) * (1.0f/(1.0f + d)) * Intensity; 
}

PS_OUTPUT ps_main(PS_INPUT Input)
{   
   PS_OUTPUT Output;
   Output.Color = float4(1,0,0,1);
   
   const float2 vec[4] =
   {
      float2(1,0), float2(-1,0), float2(0,1), float2(0,-1)
   };
   
   float4 p = getPosition(Input.TexCoords);
   
   if(p.w != 1)
   {
      Output.Color = ClearColor;
      return Output;
   }
   
   float3 n = getNormal(Input.TexCoords);
   float2 rand = getRandom(Input.TexCoords);
   
   float ao = 0.0f;
   float rad = SampleRadius/p.z;
   int iter = 4;
   
   for(int i = 0; i < iter; ++i)
   {
      float2 coord1 = reflect(vec[i], rand) * rad;
      float2 coord2 = float2(coord1.x * 0.707 - coord1.y * 0.707,
                          coord1.x * 0.707 + coord1.y * 0.707);
                          
      ao += doAmbientOcclusion(Input.TexCoords, coord1 * 0.25, p.xyz, n);
      ao += doAmbientOcclusion(Input.TexCoords, coord2 * 0.5,  p.xyz, n);
      ao += doAmbientOcclusion(Input.TexCoords, coord1 * 0.75, p.xyz, n);
      ao += doAmbientOcclusion(Input.TexCoords, coord2 , p.xyz, n);
   }
   
   ao /= 16;
   
   Output.Color.xyz =  (1.0f - ao.xxx);
   
   return Output;
   
}