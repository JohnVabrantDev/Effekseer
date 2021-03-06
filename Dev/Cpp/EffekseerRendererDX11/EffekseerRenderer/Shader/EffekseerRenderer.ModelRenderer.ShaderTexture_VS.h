#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_5_0 /EVS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderTexture_VS.h
//    Shader/model_renderer_texture_VS.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 mCameraProj;              // Offset:    0 Size:    64
//   float4x4 mModel[40];               // Offset:   64 Size:  2560
//   float4 fUV[40];                    // Offset: 2624 Size:   640
//   float4 fAlphaUV[40];               // Offset: 3264 Size:   640
//   float4 fFlipbookParameter;         // Offset: 3904 Size:    16
//   float4 fFlipbookIndexAndNextRate[40];// Offset: 3920 Size:   640
//   float4 fModelAlphaThreshold[40];   // Offset: 4560 Size:   640
//   float4 fModelColor[40];            // Offset: 5200 Size:   640
//   float4 fLightDirection;            // Offset: 5840 Size:    16 [unused]
//   float4 fLightColor;                // Offset: 5856 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset: 5872 Size:    16 [unused]
//   float4 mUVInversed;                // Offset: 5888 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyz         0     NONE  float   xyz 
// NORMAL                   0   xyz         1     NONE  float       
// NORMAL                   1   xyz         2     NONE  float       
// NORMAL                   2   xyz         3     NONE  float       
// TEXCOORD                 0   xy          4     NONE  float   xy  
// NORMAL                   3   xyzw        5     NONE  float   xyzw
// BLENDINDICES             0   xyzw        6     NONE   uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 1     zw        1     NONE  float     zw
// TEXCOORD                 2   x           2     NONE  float   x   
// TEXCOORD                 3    yz         2     NONE  float    yz 
// TEXCOORD                 4      w        2     NONE  float      w
// COLOR                    0   xyzw        3     NONE  float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[369], dynamicIndexed
dcl_input v0.xyz
dcl_input v4.xy
dcl_input v5.xyzw
dcl_input v6.x
dcl_output_siv o0.xyzw, position
dcl_output o1.xy
dcl_output o1.zw
dcl_output o2.x
dcl_output o2.yz
dcl_output o2.w
dcl_output o3.xyzw
dcl_temps 5
ishl r0.x, v6.x, l(2)
mov r0.y, v6.x
mul o3.xyzw, v5.xyzw, cb0[r0.y + 325].xyzw
mul r1.xyzw, v0.yyyy, cb0[r0.x + 5].xyzw
mad r1.xyzw, cb0[r0.x + 4].xyzw, v0.xxxx, r1.xyzw
mad r1.xyzw, cb0[r0.x + 6].xyzw, v0.zzzz, r1.xyzw
add r1.xyzw, r1.xyzw, cb0[r0.x + 7].xyzw
mul r2.xyzw, r1.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, r1.xxxx, r2.xyzw
mad r2.xyzw, cb0[2].xyzw, r1.zzzz, r2.xyzw
mad o0.xyzw, cb0[3].xyzw, r1.wwww, r2.xyzw
mad o1.x, v4.x, cb0[r0.y + 164].z, cb0[r0.y + 164].x
mad r0.x, v4.y, cb0[r0.y + 164].w, cb0[r0.y + 164].y
mad o1.z, v4.x, cb0[r0.y + 204].z, cb0[r0.y + 204].x
mad r0.z, v4.y, cb0[r0.y + 204].w, cb0[r0.y + 204].y
lt r0.w, l(0.000000), cb0[244].x
if_nz r0.w
  frc r1.x, cb0[r0.y + 245].x
  round_ni r0.w, cb0[r0.y + 245].x
  add r0.w, r0.w, l(1.000000)
  eq r2.x, cb0[244].y, l(0.000000)
  if_nz r2.x
    mul r2.x, cb0[244].w, cb0[244].z
    ge r2.x, r0.w, r2.x
    mad r2.y, cb0[244].z, cb0[244].w, l(-1.000000)
    movc r2.x, r2.x, r2.y, r0.w
  else 
    mul r2.y, cb0[244].w, cb0[244].z
    mul r2.z, r0.w, r2.y
    ge r2.z, r2.z, -r2.z
    movc r2.z, r2.z, r2.y, -r2.y
    div r2.w, l(1.000000, 1.000000, 1.000000, 1.000000), r2.z
    mul r2.w, r0.w, r2.w
    frc r2.w, r2.w
    mul r3.x, r2.w, r2.z
    eq r3.yz, cb0[244].yyyy, l(0.000000, 1.000000, 2.000000, 0.000000)
    div r2.y, r0.w, r2.y
    add r3.w, r2.y, r2.y
    ge r3.w, r3.w, -r3.w
    movc r4.xy, r3.wwww, l(2.000000,0.500000,0,0), l(-2.000000,-0.500000,0,0)
    mul r2.y, r2.y, r4.y
    frc r2.y, r2.y
    mul r2.y, r2.y, r4.x
    eq r2.y, r2.y, l(1.000000)
    mad r3.w, cb0[244].z, cb0[244].w, l(-1.000000)
    mad r2.z, -r2.z, r2.w, r3.w
    movc r2.y, r2.y, r2.z, r3.x
    movc r0.w, r3.z, r2.y, r0.w
    movc r2.x, r3.y, r3.x, r0.w
  endif 
  ftoi r0.w, r2.x
  ftoi r2.xy, cb0[244].zwzz
  and r2.z, r0.w, l(0x80000000)
  imax r2.w, r0.w, -r0.w
  imax r3.xy, r2.xyxx, -r2.xyxx
  udiv null, r2.x, r2.w, r3.x
  ineg r3.x, r2.x
  movc r2.x, r2.z, r3.x, r2.x
  itof r4.y, r2.x
  xor r0.w, r0.w, r2.y
  udiv r2.x, null, r2.w, r3.y
  ineg r2.y, r2.x
  and r0.w, r0.w, l(0x80000000)
  movc r0.w, r0.w, r2.y, r2.x
  itof r4.z, r0.w
  div r2.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[244].zwzz
  mul r2.zw, r2.xxxy, r4.yyyz
  mad r1.yz, v4.xxyx, r2.xxyx, r2.zzwz
else 
  mov r1.xyz, l(0,0,0,0)
endif 
mad o1.y, cb0[368].y, r0.x, cb0[368].x
mad o1.w, cb0[368].y, r0.z, cb0[368].x
mov r1.w, cb0[r0.y + 285].x
mov o2.xyzw, r1.xyzw
ret 
// Approximately 76 instruction slots used
#endif

const BYTE g_VS[] =
{
     68,  88,  66,  67, 240, 136, 
    119,  47,  74, 233, 127, 148, 
    181,  45,  84,  16, 231,  26, 
    100,  44,   1,   0,   0,   0, 
     56,  17,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    184,   4,   0,   0, 152,   5, 
      0,   0, 108,   6,   0,   0, 
    156,  16,   0,   0,  82,  68, 
     69,  70, 124,   4,   0,   0, 
      1,   0,   0,   0, 112,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,  16,   1,   0,   0, 
     74,   4,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  86,  83,  95,  67, 
    111, 110, 115, 116,  97, 110, 
    116,  66, 117, 102, 102, 101, 
    114,   0, 171, 171,  92,   0, 
      0,   0,  12,   0,   0,   0, 
    136,   0,   0,   0,  16,  23, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 104,   2, 
      0,   0,   0,   0,   0,   0, 
     64,   0,   0,   0,   2,   0, 
      0,   0, 128,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 164,   2,   0,   0, 
     64,   0,   0,   0,   0,  10, 
      0,   0,   2,   0,   0,   0, 
    172,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    208,   2,   0,   0,  64,  10, 
      0,   0, 128,   2,   0,   0, 
      2,   0,   0,   0, 220,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   0,   3, 
      0,   0, 192,  12,   0,   0, 
    128,   2,   0,   0,   2,   0, 
      0,   0,  12,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  48,   3,   0,   0, 
     64,  15,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     68,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    104,   3,   0,   0,  80,  15, 
      0,   0, 128,   2,   0,   0, 
      2,   0,   0,   0, 132,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 168,   3, 
      0,   0, 208,  17,   0,   0, 
    128,   2,   0,   0,   2,   0, 
      0,   0, 192,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 228,   3,   0,   0, 
     80,  20,   0,   0, 128,   2, 
      0,   0,   2,   0,   0,   0, 
    240,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     20,   4,   0,   0, 208,  22, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,  68,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  36,   4, 
      0,   0, 224,  22,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,  68,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  48,   4,   0,   0, 
    240,  22,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
     68,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     62,   4,   0,   0,   0,  23, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  68,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 109,  67, 
     97, 109, 101, 114,  97,  80, 
    114, 111, 106,   0, 102, 108, 
    111,  97, 116,  52, 120,  52, 
      0, 171, 171, 171,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    116,   2,   0,   0, 109,  77, 
    111, 100, 101, 108,   0, 171, 
      3,   0,   3,   0,   4,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 116,   2,   0,   0, 
    102,  85,  86,   0, 102, 108, 
    111,  97, 116,  52,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
    102,  65, 108, 112, 104,  97, 
     85,  86,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 212,   2, 
      0,   0, 102,  70, 108, 105, 
    112,  98, 111, 111, 107,  73, 
    110, 100, 101, 120,  65, 110, 
    100,  78, 101, 120, 116,  82, 
     97, 116, 101,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
    102,  77, 111, 100, 101, 108, 
     65, 108, 112, 104,  97,  84, 
    104, 114, 101, 115, 104, 111, 
    108, 100,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
    102,  77, 111, 100, 101, 108, 
     67, 111, 108, 111, 114,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  40,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
    102,  76, 105, 103, 104, 116, 
     68, 105, 114, 101,  99, 116, 
    105, 111, 110,   0, 102,  76, 
    105, 103, 104, 116,  67, 111, 
    108, 111, 114,   0, 102,  76, 
    105, 103, 104, 116,  65, 109, 
     98, 105, 101, 110, 116,   0, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171,  73,  83,  71,  78, 
    216,   0,   0,   0,   7,   0, 
      0,   0,   8,   0,   0,   0, 
    176,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
    185,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   0,   0,   0, 
    185,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   0,   0,   0, 
    185,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    192,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   3,   0,   0, 
    185,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,  15,  15,   0,   0, 
    201,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  15,   1,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  78,  79,  82, 
     77,  65,  76,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  66,  76,  69,  78,  68, 
     73,  78,  68,  73,  67,  69, 
     83,   0, 171, 171,  79,  83, 
     71,  78, 204,   0,   0,   0, 
      7,   0,   0,   0,   8,   0, 
      0,   0, 176,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 188,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,  12, 
      0,   0, 188,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  12,   3, 
      0,   0, 188,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   1,  14, 
      0,   0, 188,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   6,   9, 
      0,   0, 188,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   8,   7, 
      0,   0, 197,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     83,  72,  69,  88,  40,  10, 
      0,   0,  80,   0,   1,   0, 
    138,   2,   0,   0, 106,   8, 
      0,   1,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0, 113,   1,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   4,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   5,   0,   0,   0, 
     95,   0,   0,   3,  18,  16, 
     16,   0,   6,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3,  50,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 194,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3,  18,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3,  98,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 130,  32,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      3,   0,   0,   0, 104,   0, 
      0,   2,   5,   0,   0,   0, 
     41,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     16,   0,   6,   0,   0,   0, 
     56,   0,   0,  10, 242,  32, 
     16,   0,   3,   0,   0,   0, 
     70,  30,  16,   0,   5,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,  69,   1, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  86,  21, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   6,  16, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 166,  26, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      7,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 242,  32,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  15, 
     18,  32,  16,   0,   1,   0, 
      0,   0,  10,  16,  16,   0, 
      4,   0,   0,   0,  42, 128, 
     32,   6,   0,   0,   0,   0, 
    164,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   6,   0,   0, 
      0,   0, 164,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  15, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,  16,  16,   0, 
      4,   0,   0,   0,  58, 128, 
     32,   6,   0,   0,   0,   0, 
    164,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   6,   0,   0, 
      0,   0, 164,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  15, 
     66,  32,  16,   0,   1,   0, 
      0,   0,  10,  16,  16,   0, 
      4,   0,   0,   0,  42, 128, 
     32,   6,   0,   0,   0,   0, 
    204,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   6,   0,   0, 
      0,   0, 204,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  15, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  26,  16,  16,   0, 
      4,   0,   0,   0,  58, 128, 
     32,   6,   0,   0,   0,   0, 
    204,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   6,   0,   0, 
      0,   0, 204,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  49,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
    244,   0,   0,   0,  31,   0, 
      4,   3,  58,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   6,   0,   0,   0,   0, 
    245,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     65,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   6,   0,   0, 
      0,   0, 245,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     24,   0,   0,   8,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  29,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  11,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128, 191,  55,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  18,   0,   0,   1, 
     56,   0,   0,   9,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,   8,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     55,   0,   0,  10,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  14,   0, 
      0,  10, 130,   0,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     42,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     24,   0,   0,  11,  98,   0, 
     16,   0,   3,   0,   0,   0, 
     86, 133,  32,   0,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,   0,   0, 
      0,   0,  14,   0,   0,   7, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,   8, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   3,   0,   0,   0, 
     55,   0,   0,  15,  50,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0, 192, 
      0,   0,   0, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      4,   0,   0,   0,  26,   0, 
      0,   5,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  24,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,  11, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,  50,   0, 
      0,  10,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  55,   0,   0,   9, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  55,   0,   0,   9, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     27,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  27,   0,   0,   6, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 230, 138,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,   1,   0,   0,   7, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0, 128, 
     36,   0,   0,   8, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  36,   0,   0,   8, 
     50,   0,  16,   0,   3,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  78,   0, 
      0,   8,   0, 208,   0,   0, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     40,   0,   0,   5,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  43,   0,   0,   5, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  87,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  78,   0,   0,   8, 
     18,   0,  16,   0,   2,   0, 
      0,   0,   0, 208,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  40,   0, 
      0,   5,  34,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
      1,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 128,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  43,   0, 
      0,   5,  66,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     14,   0,   0,  11,  50,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63, 230, 138,  32,   0, 
      0,   0,   0,   0, 244,   0, 
      0,   0,  56,   0,   0,   7, 
    194,   0,  16,   0,   2,   0, 
      0,   0,   6,   4,  16,   0, 
      2,   0,   0,   0,  86,   9, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,   9,  98,   0, 
     16,   0,   1,   0,   0,   0, 
      6,  17,  16,   0,   4,   0, 
      0,   0,   6,   1,  16,   0, 
      2,   0,   0,   0, 166,  11, 
     16,   0,   2,   0,   0,   0, 
     18,   0,   0,   1,  54,   0, 
      0,   8, 114,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     21,   0,   0,   1,  50,   0, 
      0,  11,  34,  32,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
    112,   1,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0, 112,   1,   0,   0, 
     50,   0,   0,  11, 130,  32, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0, 112,   1,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0, 112,   1, 
      0,   0,  54,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  10, 128,  32,   6, 
      0,   0,   0,   0,  29,   1, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     76,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  28,   0, 
      0,   0,   5,   0,   0,   0, 
      5,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
