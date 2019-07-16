/**
************************
*
*  Generic Vertex Shader
*
************************
*/
sampler InputSampler;
struct VS_INPUT 
{
   float2 TexCoords : TEXCOORD0; 
};

float4 vs_main( VS_INPUT Input ) : COLOR0
{
   float4 Color = tex2D(InputSampler, Input.TexCoords);
   return Color;
}