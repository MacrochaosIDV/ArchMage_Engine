/**
************************
*
*  GBuffer
*
************************
*/
float4x4 matViewProjection;
float4x4 matViewProjectionInverse;
float4x4 matWorld;

float fTime0_2PI;

float fFarClipPlane;
float fNearClipPlane;

struct VS_INPUT 
{
   float4 Position : POSITION0;
   float2 TexCoord : TEXCOORD0;
   float3 Normal   : NORMAL0;
   float3 Tangent  : TANGENT0;
   float3 Binormal : BINORMAL0;
};

struct VS_OUTPUT 
{
   float4 Position : POSITION0;
   float3 WorldPos : TEXCOORD0;
   float2 TexCoord : TEXCOORD1;
   float3x3 TBN    : TEXCOORD2;
   float Depth     : TEXCOORD5;
};

VS_OUTPUT vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output = (VS_OUTPUT)0;
   
   float angle = fTime0_2PI * 5;
   
   float4x4 matRot = { cos(angle),  0, sin(angle), 0,
                       0,           1, 0,          0,
                       -sin(angle), 0, cos(angle), 0,
                       0,           0, 0,          1};
                       
   float4x4 matTransform = mul(matWorld, matRot);
   //matTrans = mul(matTrans, matView);

   float4 tmpPosW = mul(Input.Position, matTransform);
   Output.WorldPos = tmpPosW.xyz;
   Output.Position = mul( tmpPosW, matViewProjection );
   
   Output.TexCoord = float2(Input.TexCoord.x, 1.0f - Input.TexCoord.y);
   
   Output.TBN[0] = normalize(mul(float4(Input.Tangent, 0.0f), matTransform));
   Output.TBN[1] = normalize(mul(float4(-Input.Binormal, 0.0f), matTransform));
   Output.TBN[2] = normalize(mul(float4(Input.Normal, 0.0f), matTransform));
   
   Output.Depth = (1.f - (Output.Position.z - fNearClipPlane) / (fFarClipPlane - fNearClipPlane));
   
   return( Output );
}

/*
float3 PosFromDepth(float depth, float3 TexCoords) {
   float z = (depth * 2.0) - 1.0;

   float4 clipSpacePos = float4((TexCoords * 2.0) - 1.0, z, 1.0, 1.0f);
   float4 SSPos = matViewProjectionInverse * clipSpacePos;

   // Perspective division
   SSPos /= SSPos.w;

   float4 worldSpacePosition = matViewProjectionInverse * SSPos;

   return worldSpacePosition.xyz;
}
*/
