#pragma once

#pragma warning(push)
#pragma warning(disable: 4267 4838)

#include "SADXModLoader.h"

NJS_MATERIAL material_8D9A3AD72768CB60585[] = {
	{ { 0xFF565353 }, { 0xFFFFFFFF }, 11, 8, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 5, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 7, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 6, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 6, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_8D9A3AD72768CB69B79[] = {
	0x8000u | 5, 8, 22, 13, 0, 12,
	4, 1, 21, 0, 22,
	0x8000u | 5, 18, 1, 17, 21, 11
};

Sint16 poly_8D9A3AD72768CB652DD[] = {
	0x8000u | 7, 19, 20, 2, 3, 4, 5, 6
};

Sint16 poly_8D9A3AD72768CB6EAB5[] = {
	6, 14, 9, 15, 7, 16, 10,
	4, 13, 8, 14, 9,
	4, 3, 17, 20, 18,
	4, 2, 19, 13, 12,
	4, 10, 11, 16, 17
};

Sint16 poly_8D9A3AD72768CB6533D[] = {
	3, 13, 14, 2,
	0x8000u | 9, 2, 4, 14, 6, 15, 5, 16, 3, 17
};

Sint16 poly_8D9A3AD72768CB61ADE[] = {
	0x8000u | 8, 7, 10, 9, 11, 8, 18, 12, 19,
	3, 19, 20, 18
};

NJS_TEX uv_8D9A3AD72768CB6FAB8[] = {
	{ 113, 148 },
	{ 1, 147 },
	{ 244, 148 },
	{ 1, 253 },
	{ 245, 253 },
	{ 58, 254 },
	{ 59, 147 },
	{ 137, 255 },
	{ 138, 147 },
	{ 245, 253 },
	{ 1, 253 },
	{ 244, 148 },
	{ 1, 147 },
	{ 113, 148 }
};

NJS_TEX uv_8D9A3AD72768CB690C5[] = {
	{ 2, 251 },
	{ 242, 251 },
	{ 3, 149 },
	{ 240, 147 },
	{ 18, 47 },
	{ 225, 46 },
	{ 122, 10 }
};

NJS_TEX uv_8D9A3AD72768CB622C8[] = {
	{ 121, 61 },
	{ 45, 225 },
	{ 238, 50 },
	{ 235, 245 },
	{ 121, 61 },
	{ 45, 225 },
	{ 202, 245 },
	{ 205, 49 },
	{ 45, 225 },
	{ 27, 69 },
	{ 226, 245 },
	{ 226, 39 },
	{ 45, 225 },
	{ 121, 61 },
	{ 224, 246 },
	{ 45, 225 },
	{ 224, 51 },
	{ 121, 61 },
	{ 45, 225 },
	{ 224, 240 },
	{ 104, 53 },
	{ 223, 23 }
};

NJS_TEX uv_8D9A3AD72768CB653EF[] = {
	{ 244, 5 },
	{ 61, 6 },
	{ 243, 250 },
	{ 243, 250 },
	{ 63, 250 },
	{ 61, 6 },
	{ 243, 250 },
	{ 244, 5 },
	{ 63, 250 },
	{ 61, 6 },
	{ 243, 250 },
	{ 244, 5 }
};

NJS_TEX uv_8D9A3AD72768CB64381[] = {
	{ 123, 38 },
	{ 8, 16 },
	{ 234, 15 },
	{ 9, 104 },
	{ 236, 102 },
	{ 8, 212 },
	{ 237, 212 },
	{ 238, 253 },
	{ 238, 253 },
	{ 8, 254 },
	{ 8, 212 }
};

NJS_MESHSET_SADX mesh_8D9A3AD72768CB6C966[] = {
	{ NJD_MESHSET_TRIMESH | 0, 3, poly_8D9A3AD72768CB69B79, NULL, NULL, NULL, uv_8D9A3AD72768CB6FAB8, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 1, poly_8D9A3AD72768CB652DD, NULL, NULL, NULL, uv_8D9A3AD72768CB690C5, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 5, poly_8D9A3AD72768CB6EAB5, NULL, NULL, NULL, uv_8D9A3AD72768CB622C8, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 2, poly_8D9A3AD72768CB6533D, NULL, NULL, NULL, uv_8D9A3AD72768CB653EF, NULL },
	{ NJD_MESHSET_TRIMESH | 4, 2, poly_8D9A3AD72768CB61ADE, NULL, NULL, NULL, uv_8D9A3AD72768CB64381, NULL }
};

NJS_VECTOR vertex_8D9A3AD72768CB6AD6D[] = {
	{ 0.161837f, -0.883218f, -0.426639f },
	{ 0.162454f, -0.883209f, 0.620228f },
	{ 1.51789f, 0.564792f, -0.863793f },
	{ 1.518863f, 0.5648389f, 0.86378f },
	{ 1.517501f, 1.242311f, -0.658317f },
	{ 1.518104f, 1.24232f, 0.71699f },
	{ 1.299455f, 1.474194f, -0.007752f },
	{ 0.172482f, 0.955776f, 0.007173f },
	{ 0.478153f, 0.47672f, -0.71896f },
	{ 0.289545f, 0.783242f, -0.557673f },
	{ 0.290132f, 0.783251f, 0.618576f },
	{ 0.478925f, 0.476748f, 0.76053f },
	{ 0.8965009f, 0.133745f, -0.80528f },
	{ 0.647691f, 0.547958f, -0.90455f },
	{ 0.454601f, 1.24143f, -0.6818309f },
	{ 0.347232f, 1.469275f, -0.000344f },
	{ 0.455196f, 1.241441f, 0.749438f },
	{ 0.648563f, 0.5480019f, 0.9292769f },
	{ 0.897284f, 0.133765f, 0.865052f },
	{ 1.291539f, 0.220497f, -0.855159f },
	{ 1.292512f, 0.220537f, 0.855153f },
	{ 0.041273f, -0.135344f, 0.609117f },
	{ 0.040679f, -0.135353f, -0.402004f }
};

NJS_VECTOR normal_8D9A3AD72768CB66877[] = {
	{ -0.927996f, -0.126617f, -0.350416f },
	{ -0.8949119f, -0.16686f, 0.413872f },
	{ 0.722167f, -0.137194f, -0.677976f },
	{ 0.7364669f, -0.13043f, 0.663781f },
	{ 0.626685f, 0.5609789f, -0.540896f },
	{ 0.620719f, 0.561025f, 0.547686f },
	{ 0.310346f, 0.950525f, -0.013673f },
	{ -0.9975989f, -0.06906199f, -0.005191f },
	{ -0.755634f, -0.309206f, -0.5774159f },
	{ -0.924414f, -0.136693f, -0.356054f },
	{ -0.911409f, -0.13823f, 0.387589f },
	{ -0.657674f, -0.371396f, 0.655385f },
	{ -0.291542f, -0.619233f, -0.729077f },
	{ -0.312436f, 0.075494f, -0.946934f },
	{ -0.468627f, 0.57888f, -0.667298f },
	{ -0.575205f, 0.817876f, -0.01476f },
	{ -0.450591f, 0.581487f, 0.677378f },
	{ -0.201638f, 0.049448f, 0.978211f },
	{ -0.172148f, -0.591763f, 0.787516f },
	{ 0.447371f, -0.66695f, -0.59585f },
	{ 0.462223f, -0.656224f, 0.596423f },
	{ -0.662645f, -0.146192f, 0.734527f },
	{ -0.8047439f, -0.09067f, -0.586657f }
};

NJS_MODEL_SADX attach_02707284 = { vertex_8D9A3AD72768CB6AD6D, normal_8D9A3AD72768CB66877, LengthOfArray<Sint32>(vertex_8D9A3AD72768CB6AD6D), mesh_8D9A3AD72768CB6C966, material_8D9A3AD72768CB60585, LengthOfArray<Uint16>(mesh_8D9A3AD72768CB6C966), LengthOfArray<Uint16>(material_8D9A3AD72768CB60585), { 0.779771f, 0.295488f, 0.012364f }, 1.493344f, NULL };

NJS_OBJECT object_027072B0 = { NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_02707284, 0, 0, -0.960205f, 0, 0, 0xFFFFC001, 1, 1, 1, NULL, NULL };

NJS_MATERIAL material_8D9A3AD59B801E09402[] = {
	{ { 0xFF565353 }, { 0xFFFFFFFF }, 11, 8, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 5, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 7, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 6, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 6, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_8D9A3AD59B801E0B1EF[] = {
	0x8000u | 5, 0, 22, 12, 8, 13,
	4, 0, 22, 1, 21,
	0x8000u | 5, 21, 1, 11, 18, 17
};

Sint16 poly_8D9A3AD59B801E0AE61[] = {
	0x8000u | 7, 20, 19, 3, 2, 5, 4, 6
};

Sint16 poly_8D9A3AD59B801E0EA76[] = {
	6, 9, 14, 7, 15, 10, 16,
	4, 14, 9, 13, 8,
	4, 20, 18, 3, 17,
	4, 13, 12, 2, 19,
	4, 16, 17, 10, 11
};

Sint16 poly_8D9A3AD59B801E0F1AD[] = {
	3, 2, 4, 13,
	0x8000u | 9, 13, 14, 4, 15, 6, 16, 5, 17, 3
};

Sint16 poly_8D9A3AD59B801E0BD0E[] = {
	0x8000u | 8, 7, 9, 10, 8, 11, 12, 18, 20,
	3, 20, 19, 12
};

NJS_TEX uv_8D9A3AD59B801E0A1AA[] = {
	{ 1, 253 },
	{ 1, 147 },
	{ 245, 253 },
	{ 113, 148 },
	{ 244, 148 },
	{ 137, 255 },
	{ 138, 147 },
	{ 58, 254 },
	{ 59, 147 },
	{ 1, 147 },
	{ 1, 253 },
	{ 113, 148 },
	{ 245, 253 },
	{ 244, 148 }
};

NJS_TEX uv_8D9A3AD59B801E0A2D8[] = {
	{ 242, 251 },
	{ 2, 251 },
	{ 240, 147 },
	{ 3, 149 },
	{ 225, 46 },
	{ 18, 47 },
	{ 122, 10 }
};

NJS_TEX uv_8D9A3AD59B801E09BF8[] = {
	{ 45, 225 },
	{ 121, 61 },
	{ 235, 245 },
	{ 238, 50 },
	{ 45, 225 },
	{ 121, 61 },
	{ 45, 225 },
	{ 27, 69 },
	{ 202, 245 },
	{ 205, 49 },
	{ 45, 225 },
	{ 121, 61 },
	{ 226, 245 },
	{ 226, 39 },
	{ 224, 51 },
	{ 121, 61 },
	{ 224, 246 },
	{ 45, 225 },
	{ 104, 53 },
	{ 223, 23 },
	{ 45, 225 },
	{ 224, 240 }
};

NJS_TEX uv_8D9A3AD59B801E0BD7F[] = {
	{ 243, 250 },
	{ 63, 250 },
	{ 244, 5 },
	{ 244, 5 },
	{ 61, 6 },
	{ 63, 250 },
	{ 244, 5 },
	{ 243, 250 },
	{ 61, 6 },
	{ 63, 250 },
	{ 244, 5 },
	{ 243, 250 }
};

NJS_TEX uv_8D9A3AD59B801E01F4F[] = {
	{ 123, 38 },
	{ 234, 15 },
	{ 8, 16 },
	{ 236, 102 },
	{ 9, 104 },
	{ 237, 212 },
	{ 8, 212 },
	{ 8, 254 },
	{ 8, 254 },
	{ 238, 253 },
	{ 237, 212 }
};

NJS_MESHSET_SADX mesh_8D9A3AD59B801E057A5[] = {
	{ NJD_MESHSET_TRIMESH | 0, 3, poly_8D9A3AD59B801E0B1EF, NULL, NULL, NULL, uv_8D9A3AD59B801E0A1AA, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 1, poly_8D9A3AD59B801E0AE61, NULL, NULL, NULL, uv_8D9A3AD59B801E0A2D8, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 5, poly_8D9A3AD59B801E0EA76, NULL, NULL, NULL, uv_8D9A3AD59B801E09BF8, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 2, poly_8D9A3AD59B801E0F1AD, NULL, NULL, NULL, uv_8D9A3AD59B801E0BD7F, NULL },
	{ NJD_MESHSET_TRIMESH | 4, 2, poly_8D9A3AD59B801E0BD0E, NULL, NULL, NULL, uv_8D9A3AD59B801E01F4F, NULL }
};

NJS_VECTOR vertex_8D9A3AD59B801E087B6[] = {
	{ 0.161837f, -0.883218f, 0.426639f },
	{ 0.162454f, -0.883209f, -0.620228f },
	{ 1.51789f, 0.564792f, 0.863793f },
	{ 1.518863f, 0.5648389f, -0.86378f },
	{ 1.517501f, 1.242311f, 0.658317f },
	{ 1.518104f, 1.24232f, -0.71699f },
	{ 1.299455f, 1.474194f, 0.007752f },
	{ 0.172482f, 0.955776f, -0.007173f },
	{ 0.478153f, 0.47672f, 0.71896f },
	{ 0.289545f, 0.783242f, 0.557673f },
	{ 0.290132f, 0.783251f, -0.618576f },
	{ 0.478925f, 0.476748f, -0.76053f },
	{ 0.8965009f, 0.133745f, 0.80528f },
	{ 0.647691f, 0.547958f, 0.90455f },
	{ 0.454601f, 1.24143f, 0.6818309f },
	{ 0.347232f, 1.469275f, 0.000344f },
	{ 0.455196f, 1.241441f, -0.749438f },
	{ 0.648563f, 0.5480019f, -0.9292769f },
	{ 0.897284f, 0.133765f, -0.865052f },
	{ 1.291539f, 0.220497f, 0.855159f },
	{ 1.292512f, 0.220537f, -0.855153f },
	{ 0.041273f, -0.135344f, -0.609117f },
	{ 0.040679f, -0.135353f, 0.402004f }
};

NJS_VECTOR normal_8D9A3AD59B801E05874[] = {
	{ -0.927996f, -0.126617f, 0.350416f },
	{ -0.8949119f, -0.16686f, -0.413872f },
	{ 0.722167f, -0.137194f, 0.677976f },
	{ 0.7364669f, -0.13043f, -0.663781f },
	{ 0.626685f, 0.5609789f, 0.540896f },
	{ 0.620719f, 0.561025f, -0.547686f },
	{ 0.310346f, 0.950525f, 0.013673f },
	{ -0.9975989f, -0.06906199f, 0.005191f },
	{ -0.755634f, -0.309206f, 0.5774159f },
	{ -0.924414f, -0.136693f, 0.356054f },
	{ -0.911409f, -0.13823f, -0.387589f },
	{ -0.657674f, -0.371396f, -0.655385f },
	{ -0.291542f, -0.619233f, 0.729077f },
	{ -0.312436f, 0.075494f, 0.946934f },
	{ -0.468627f, 0.57888f, 0.667298f },
	{ -0.575205f, 0.817876f, 0.01476f },
	{ -0.450591f, 0.581487f, -0.677378f },
	{ -0.201638f, 0.049448f, -0.978211f },
	{ -0.172148f, -0.591763f, -0.787516f },
	{ 0.447371f, -0.66695f, 0.59585f },
	{ 0.462223f, -0.656224f, -0.596423f },
	{ -0.662645f, -0.146192f, -0.734527f },
	{ -0.8047439f, -0.09067f, 0.586657f }
};

NJS_MODEL_SADX attach_02707A14 = { vertex_8D9A3AD59B801E087B6, normal_8D9A3AD59B801E05874, LengthOfArray<Sint32>(vertex_8D9A3AD59B801E087B6), mesh_8D9A3AD59B801E057A5, material_8D9A3AD59B801E09402, LengthOfArray<Uint16>(mesh_8D9A3AD59B801E057A5), LengthOfArray<Uint16>(material_8D9A3AD59B801E09402), { 0.779771f, 0.295488f, -0.012364f }, 1.493344f, NULL };

NJS_OBJECT object_02707A40 = { NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_02707A14, 0, 0, 0.960205f, 0, 0, 0xFFFFC001, 1, 1, 1, NULL, &object_027072B0 };

NJS_OBJECT object_02707A74 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_HIDE, NULL, 0, 0, 0, 0, 0, 0, 1, 1, 1, &object_02707A40, NULL };

NJS_MATERIAL material_8D99B0A9D9D47993DDE[] = {
	{ { 0xFFB2B2B2 }, { 0x00FFFFFF }, 11, 4, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0x00FFFFFF }, 11, 5, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 17, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 16, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 26, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 15, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 25, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 27, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFF8000FF }, { 0xFFFFFFFF }, 11, 23, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_FLAG_USE_ENV | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 11, 24, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFF400080 }, { 0xFFFFFFFF }, 11, 22, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_FLAG_USE_ENV | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 30, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 31, NJD_D_200 | NJD_FLAG_USE_ANISOTROPIC | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_8D99B0A9D9D47990F02[] = {
	6, 35, 20, 25, 17, 11, 22,
	4, 17, 30, 22, 32,
	0x8000u | 5, 38, 40, 26, 31, 19,
	0x8000u | 8, 33, 23, 30, 12, 16, 54, 60, 58,
	0x8000u | 6, 34, 20, 24, 18, 10, 53,
	0x8000u | 6, 41, 43, 36, 19, 7, 69,
	0x8000u | 5, 43, 42, 19, 39, 8,
	0x8000u | 5, 40, 37, 31, 27, 9,
	0x8000u | 6, 31, 9, 18, 52, 61, 56,
	0x8000u | 8, 48, 45, 29, 21, 13, 16, 55, 59,
	0x8000u | 6, 49, 51, 44, 0, 2, 28,
	0x8000u | 5, 51, 50, 0, 47, 3,
	0x8000u | 5, 45, 46, 21, 28, 0,
	4, 61, 18, 57, 53,
	0x8000u | 3, 60, 59, 16,
	6, 78, 66, 83, 72, 79, 67,
	8, 67, 72, 6, 15, 68, 70, 82, 81,
	6, 3, 0, 62, 73, 85, 75,
	0x8000u | 3, 74, 85, 62,
	0x8000u | 3, 80, 82, 68,
	0x8000u | 9, 76, 84, 64, 71, 4, 14, 63, 73, 75,
	0x8000u | 7, 84, 77, 71, 65, 1, 5, 66,
	4, 19, 69, 70, 81,
	0x8000u | 3, 19, 8, 26,
	0x8000u | 3, 66, 72, 1
};

Sint16 poly_8D99B0A9D9D4799F591[] = {
	33, 32, 30,
	35, 34, 20,
	37, 38, 40,
	43, 42, 41,
	46, 48, 45,
	51, 50, 49,
	60, 59, 58,
	57, 56, 61,
	80, 82, 81,
	78, 83, 79,
	76, 84, 77,
	74, 85, 75
};

NJS_MESHSET_SADX mesh_8D99B0A9D9D47994E5B[] = {
	{ NJD_MESHSET_TRIMESH | 8, 25, poly_8D99B0A9D9D47990F02, NULL, NULL, NULL, NULL, NULL },
	{ NJD_MESHSET_3 | 10, 12, poly_8D99B0A9D9D4799F591, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR vertex_8D99B0A9D9D47996E78[] = {
	{ 0.1695606f, -0.807658f, -0.7863955f },
	{ 0.6663411f, -0.807658f, 0.0000000007428631f },
	{ -0.09612231f, -1.802464f, -1.304986f },
	{ 0.5563706f, -1.802464f, -1.130151f },
	{ 1.034029f, -1.802464f, -0.6524928f },
	{ 1.208863f, -1.802464f, 0.00000005704274f },
	{ 1.034029f, -1.802464f, 0.6524929f },
	{ 0.5563706f, -1.802464f, 1.130151f },
	{ -0.09612242f, -1.802464f, 1.304986f },
	{ -0.7486152f, -1.802464f, 1.130151f },
	{ -1.226273f, -1.802464f, 0.6524928f },
	{ -1.401108f, -1.802464f, -0.000000155618f },
	{ -1.226273f, -1.802464f, -0.6524928f },
	{ -0.7486154f, -1.802464f, -1.130151f },
	{ 0.4179508f, -0.807658f, -0.3931977f },
	{ 0.4179508f, -0.807658f, 0.3931977f },
	{ -0.7300479f, -0.807658f, -0.5340869f },
	{ -0.8036193f, -0.807658f, 0.0000000007428631f },
	{ -0.7300479f, -0.807658f, 0.5340869f },
	{ 0.1695606f, -0.807658f, 0.7863955f },
	{ -0.7668336f, -0.807658f, 0.2670434f },
	{ -0.2802437f, -0.807658f, -0.6602412f },
	{ -1.345389f, -1.802464f, -0.2079481f },
	{ -1.330202f, -1.802464f, -0.4445447f },
	{ -1.30945f, -1.802464f, 0.445973f },
	{ -1.366141f, -1.802464f, 0.2065197f },
	{ -0.2752894f, -1.802464f, 1.270019f },
	{ -0.5694482f, -1.802464f, 1.186579f },
	{ -0.2752894f, -1.802464f, -1.270019f },
	{ -0.5694484f, -1.802464f, -1.191077f },
	{ -0.7668336f, -0.807658f, -0.2670434f },
	{ -0.2802437f, -0.807658f, 0.6602412f },
	{ -1.30387f, -1.802464f, -0.1304986f },
	{ -1.198969f, -1.802464f, -0.5219942f },
	{ -1.198969f, -1.802464f, 0.5219942f },
	{ -1.30387f, -1.802464f, 0.1304985f },
	{ 0.3772036f, -1.802464f, 1.184432f },
	{ -0.6181166f, -1.802464f, 1.081812f },
	{ -0.226621f, -1.802464f, 1.186713f },
	{ 0.08304459f, -1.802464f, 1.270019f },
	{ -0.2802437f, -0.807658f, 0.6602412f },
	{ 0.425872f, -1.802464f, 1.081812f },
	{ 0.03437617f, -1.802464f, 1.186713f },
	{ 0.1695606f, -0.807658f, 0.7863955f },
	{ 0.08304466f, -1.802464f, -1.270019f },
	{ -0.2802437f, -0.807658f, -0.6602412f },
	{ -0.2266209f, -1.802464f, -1.168556f },
	{ 0.3772036f, -1.802464f, -1.191077f },
	{ -0.6181168f, -1.802464f, -1.063655f },
	{ 0.03437626f, -1.802464f, -1.168556f },
	{ 0.425872f, -1.802464f, -1.063655f },
	{ 0.1695606f, -0.807658f, -0.7863955f },
	{ -0.8751052f, -1.802464f, 1.003661f },
	{ -1.099783f, -1.802464f, 0.7789828f },
	{ -1.099783f, -1.802464f, -0.7789828f },
	{ -0.8751054f, -1.802464f, -1.003661f },
	{ -0.7533646f, -1.802464f, 0.9612772f },
	{ -1.039959f, -1.802464f, 0.6949985f },
	{ -1.039959f, -1.802464f, -0.6949985f },
	{ -0.7533647f, -1.802464f, -0.9612771f },
	{ -0.7300479f, -0.807658f, -0.5340869f },
	{ -0.7300479f, -0.807658f, 0.5340869f },
	{ 0.6892831f, -1.802464f, -1.003661f },
	{ 0.9384971f, -1.802464f, -0.7789829f },
	{ 1.101036f, -1.802464f, -0.4797043f },
	{ 1.173897f, -1.802464f, -0.1727885f },
	{ 1.173897f, -1.802464f, 0.1727886f },
	{ 1.101036f, -1.802464f, 0.4797044f },
	{ 0.9384969f, -1.802464f, 0.7789829f },
	{ 0.6892831f, -1.802464f, 1.003661f },
	{ 0.2937557f, -0.807658f, 0.5897966f },
	{ 0.542146f, -0.807658f, -0.1965989f },
	{ 0.542146f, -0.807658f, 0.1965989f },
	{ 0.2937557f, -0.807658f, -0.5897966f },
	{ 0.5824805f, -1.802464f, -1.010941f },
	{ 0.8637352f, -1.802464f, -0.7038513f },
	{ 0.9728732f, -1.802464f, -0.5219942f },
	{ 1.077774f, -1.802464f, -0.1304985f },
	{ 1.077774f, -1.802464f, 0.1304986f },
	{ 0.9728731f, -1.802464f, 0.5219944f },
	{ 0.8637351f, -1.802464f, 0.7038513f },
	{ 0.5824805f, -1.802464f, 1.010941f },
	{ 0.2937557f, -0.807658f, 0.5897966f },
	{ 0.542146f, -0.807658f, 0.1965989f },
	{ 0.542146f, -0.807658f, -0.1965989f },
	{ 0.2937557f, -0.807658f, -0.5897966f }
};

NJS_VECTOR normal_8D99B0A9D9D4799F6A9[] = {
	{ -0.1712151f, 0.6179599f, -0.7673402f },
	{ 0.9773452f, 0.2116515f, -0.0001909584f },
	{ -0.02316322f, 0.4669919f, -0.8839582f },
	{ 0.4071848f, 0.4303877f, -0.805585f },
	{ 0.783205f, 0.4547134f, -0.4240586f },
	{ 0.903566f, 0.4284489f, 0.00002586143f },
	{ 0.7831625f, 0.4548027f, 0.4240415f },
	{ 0.3950151f, 0.4289177f, 0.8123992f },
	{ -0.02316321f, 0.4669918f, 0.8839582f },
	{ -0.5105444f, -0.006301343f, 0.8598282f },
	{ -0.8017507f, -0.05678484f, 0.5949549f },
	{ -0.9204788f, -0.3885483f, -0.04181989f },
	{ -0.7896336f, -0.01296732f, -0.6134418f },
	{ -0.5189797f, -0.002809167f, -0.854782f },
	{ 0.8522037f, 0.1376538f, -0.5047776f },
	{ 0.8515795f, 0.1384467f, 0.5056134f },
	{ -0.3334571f, 0.7178857f, -0.6111027f },
	{ -0.9864774f, 0.1638739f, -0.002767958f },
	{ -0.7042893f, 0.5999731f, 0.3794851f },
	{ -0.0003986433f, 0.6567f, 0.7541519f },
	{ -0.9088742f, -0.3972417f, 0.1270705f },
	{ -0.06460834f, 0.4616904f, -0.8846852f },
	{ 0.2803758f, -0.2672222f, -0.9219445f },
	{ -0.6651645f, -0.6604902f, 0.3482941f },
	{ -0.008514429f, -0.1333214f, -0.9910364f },
	{ -0.7297239f, -0.5206666f, 0.4431807f },
	{ -0.9756762f, -0.1458647f, -0.1636444f },
	{ -0.08611974f, -0.5125942f, 0.854301f },
	{ -0.2460364f, -0.3678142f, -0.8967602f },
	{ 0.9951575f, -0.002586f, -0.09825894f },
	{ -0.7849612f, -0.3485405f, -0.5122066f },
	{ -0.3377679f, 0.3933995f, 0.8550729f },
	{ 0.2564979f, -0.6720423f, -0.6946711f },
	{ -0.1551569f, -0.5306965f, 0.8332393f },
	{ -0.1262923f, -0.5375605f, -0.8337139f },
	{ 0.1837673f, -0.6577289f, 0.7304947f },
	{ -0.5912982f, 0.1901559f, 0.7837138f },
	{ 0.6477985f, -0.4724556f, 0.5976142f },
	{ -0.9390268f, -0.3112175f, -0.1461923f },
	{ 0.790154f, 0.2110284f, 0.5754336f },
	{ 0.2259834f, 0.9630251f, -0.1466771f },
	{ -0.8802812f, -0.0883771f, 0.4661488f },
	{ 0.9804542f, -0.05731021f, 0.1882154f },
	{ 0.001499113f, 0.9956145f, 0.09353874f },
	{ 0.7315577f, 0.1880541f, -0.6553313f },
	{ -0.2035154f, 0.864499f, -0.4595897f },
	{ -0.8039181f, -0.3367195f, -0.4902402f },
	{ -0.6208474f, 0.2116845f, -0.7548101f },
	{ 0.9486073f, -0.2967486f, -0.109929f },
	{ 0.9607237f, -0.05962321f, -0.2710256f },
	{ -0.8747886f, -0.09300826f, -0.4754937f },
	{ 0.6046029f, 0.795902f, -0.03154717f },
	{ -0.8871573f, -0.4610633f, 0.01929916f },
	{ 0.0837321f, -0.3521129f, 0.9322046f },
	{ -0.04146862f, -0.3168374f, -0.9475729f },
	{ -0.8698256f, -0.4824758f, 0.1030566f },
	{ -0.8417783f, -0.4081774f, -0.3532714f },
	{ 0.2816663f, -0.2678584f, 0.9213664f },
	{ 0.2347112f, -0.2206165f, -0.946699f },
	{ -0.8010372f, -0.4435664f, 0.401981f },
	{ -0.4338986f, 0.8276307f, -0.3560332f },
	{ 0.1380358f, 0.9703973f, 0.1981791f },
	{ 0.9526068f, 0.2061591f, 0.2236935f },
	{ 0.2829515f, 0.2561129f, -0.9243077f },
	{ 0.8490667f, 0.1763265f, 0.4979907f },
	{ 0.5877582f, 0.2170287f, -0.7793837f },
	{ 0.5944253f, 0.2551354f, 0.7626039f },
	{ 0.8437001f, 0.2067692f, -0.4953957f },
	{ 0.2036498f, 0.3189053f, 0.925649f },
	{ 0.9661239f, 0.2311962f, -0.1146858f },
	{ 0.7105253f, 0.5457907f, 0.4441468f },
	{ 0.728211f, 0.5505917f, -0.4081147f },
	{ 0.731481f, 0.5483118f, 0.4053269f },
	{ 0.5839099f, 0.4195757f, -0.6949859f },
	{ 0.7336922f, -0.08153957f, 0.6745718f },
	{ -0.2126176f, -0.07868724f, -0.9739621f },
	{ 0.4613126f, -0.1541894f, 0.873737f },
	{ 0.1955238f, -0.005615395f, -0.9806828f },
	{ 0.1994232f, 0.01985805f, 0.9797122f },
	{ 0.4603569f, -0.1476303f, -0.8753724f },
	{ -0.2513636f, -0.0500723f, 0.9665967f },
	{ 0.7607653f, -0.07115334f, -0.6451153f },
	{ 0.01464413f, 0.99984f, -0.01026693f },
	{ 0.008344311f, 0.9879144f, 0.1547752f },
	{ 0.09197984f, 0.986874f, -0.1327372f },
	{ 0.07220635f, 0.9964862f, -0.04244172f }
};

NJS_MODEL_SADX attach_00139EF8 = { vertex_8D99B0A9D9D47996E78, normal_8D99B0A9D9D4799F6A9, LengthOfArray<Sint32>(vertex_8D99B0A9D9D47996E78), mesh_8D99B0A9D9D47994E5B, material_8D99B0A9D9D47993DDE, LengthOfArray<Uint16>(mesh_8D99B0A9D9D47994E5B), LengthOfArray<Uint16>(material_8D99B0A9D9D47993DDE), { -0.09612226f, -0.9012318f, 0 }, 1.591475f, NULL };

NJS_OBJECT object_00139F24 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00139EF8, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

#pragma warning(pop)