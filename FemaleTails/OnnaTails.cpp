#include "pch.h"
#include "Tails.h"
#include "Events.h"
#include "FieldUpgrades.h"
#include "lanternapi.h"
#include "cmath"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

const Sint16 MorphVertsT[] = {
	// right ear
	28, 188, 56, 200,
	// left ear
	99, 228, 127, 193,
	// hair (top, middle, bottom)
	169, 176, 162,
	// right whiskers
	9, 1, 3, 7,
	// left whiskers
	80, 72, 74, 78
};

static void __cdecl Tails_Jiggle_mod(ObjectMaster* _this)
{
	NJS_POINT3* _src_points; // esi@4
	float v21; // st7@32
	Sint32 nbPoint; // [sp+14h] [bp-14h]@4
	NJS_VECTOR a2; // [sp+1Ch] [bp-Ch]@29

	EntityData2* v1 = (EntityData2*)_this->Data2;
	EntityData1* v2 = _this->Data1;
	int v3 = v2->CharIndex;

	if (!EntityData1Ptrs[v3])
	{
		CheckThingButThenDeleteObject(_this);
		return;
	}

	EntityData2* v25 = EntityData2Ptrs[v3];
	CharObj2* v4 = GetCharObj2(v2->CharIndex);
	NJS_POINT3* _dst_points = MILES_MODELS[4]->points;
	NJS_OBJECT* v6 = TailsAnimData[v4->AnimationThing.Index].Animation->object;

	if (v6 == *MILES_OBJECTS)
	{
		NJS_MODEL_SADX* v7 = MILES_MODELS[2];
		_src_points = v7->points;
		nbPoint = v7->nbPoint;
	}
	else
	{
		if (v6 != MILES_OBJECTS[1])
		{
			return;
		}

		NJS_MODEL_SADX* v9 = MILES_MODELS[3];
		_src_points = v9->points;
		nbPoint = v9->nbPoint;
	}

	if (!v2->Action)
	{
		v2->Action = 1;
		_this->DeleteSub = Tails_Jiggle_Delete;
	}
	else if (v2->Action == 1)
	{
		float v10 = v25->VelocityDirection.x * v25->VelocityDirection.x
			+ v25->VelocityDirection.y * v25->VelocityDirection.y
			+ v25->VelocityDirection.z * v25->VelocityDirection.z;
		float v11 = squareroot(v10);
		float v12 = v11 + v11;

		if (fabs(v1->VelocityDirection.y) < v12)
		{
			if (v12 < 0.0f)
			{
				v12 = -v12;
			}
			if (v12 > 4.0f)
			{
				v12 = 4.0f;
			}
			v1->VelocityDirection.y = v12;
		}

		if (v1->VelocityDirection.y >= 0.2f || v1->VelocityDirection.y <= -0.2f)
		{
			v1->VelocityDirection.y = v1->VelocityDirection.y * 0.99000001f;
		}
		else
		{
			v1->VelocityDirection.y = 0.0f;
		}

		signed int v13 = (int)fabs(v1->VelocityDirection.y * 512.0f) + 2048;
		if (v13 > 3072)
		{
			v13 = 3072;
		}

		Angle v14 = v13 + v1->field_30;
		v1->field_30 = v14;
		v2->Rotation.z = (int)(v1->VelocityDirection.y * 0.2f * njCos(v14) * 4096.0f);

		njUnitMatrix(TailsMatrix1);
		Angle v15 = v2->Rotation.z;
		if (v15)
		{
			njRotateZ(TailsMatrix1, (unsigned __int16)v15);
		}

		njUnitMatrix(TailsMatrix2);
		Angle v16 = v2->Rotation.z >> 1;
		if (v16)
		{
			njRotateZ(TailsMatrix2, (unsigned __int16)v16);
		}

		if (nbPoint)
		{
			for (auto i : MorphVertsT)
			{
				auto src_points = &_src_points[i - 1];
				auto dst_points = &_dst_points[i - 1];

				if (src_points->y >= -2.9000001f)
				{
					if (src_points->y <= -1.65f || fabs(src_points->z) <= 1.15f)
					{
						if (src_points->y >= -2.0999999f || src_points->x <= 1.3f)
						{
							continue;
						}

						float v22 = src_points->x + 0.25f;
						float v23 = src_points->y;
						a2.z = src_points->z;
						a2.x = v22;
						a2.y = v23;
						njCalcVector(TailsMatrix2, &a2, dst_points);
						v21 = dst_points->x - 0.25f;
					}
					else
					{
						float v19 = src_points->z;
						float v20 = src_points->x + 1.5f;
						a2.y = src_points->y;
						a2.z = v19;
						a2.x = v20;
						njCalcVector(TailsMatrix1, &a2, dst_points);
						v21 = dst_points->x - 1.5f;
					}
					dst_points->x = v21;
				}
				else
				{
					float v18 = src_points->z;
					a2.x = src_points->x + 0.5f;
					a2.z = v18;
					a2.y = src_points->y + 1.5f;
					njCalcVector(TailsMatrix1, &a2, dst_points);
					dst_points->x = dst_points->x - 0.5f;
					dst_points->y = dst_points->y - 1.5f;
				}
			}
		}
	}
	else
	{
		DeleteObjectMaster(_this);
	}

	MILES_OBJECTS[4]->model = MILES_MODELS[4];
	MILES_OBJECTS[5]->model = MILES_MODELS[4];
}

uint16_t Tails_UpperArmIndices_DC[] = {
	0, 2,
	4, 6,
	5, 7,
	1, 3,
};

uint16_t Tails_LowerArmIndices_DC[] = {
	4, 14,
	5, 15,
	1, 11,
	0, 10,
};

uint16_t Tails_KneeIndices_DC[] = {
	0, 2,
	4, 6,
	5, 7,
	1, 3,
};

uint16_t Tails_LegIndices_DC[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Tails_HandIndices_DC[] = {
	0, 15,
	4, 14,
	5, 12,
	1, 13,
};

uint16_t Tails_ShoeIndices_DC[] = {
	2, 3,
	12, 8,
	0, 1,
	1, 0,
	17, 13,
	3, 2,
};

void __cdecl InitTailsWeldInfo_mod()
{
	NJS_OBJECT* v0; // ebp@1
	NJS_OBJECT* v1; // ebp@1
	NJS_OBJECT* v2; // ebp@1
	NJS_OBJECT* v3; // edx@1
	NJS_OBJECT* v4; // edx@1
	NJS_OBJECT* v5; // eax@1

	TailsWeldInfo[0].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[0].ModelA = MILES_OBJECTS[20];
	TailsWeldInfo[0].ModelB = MILES_OBJECTS[21];
	TailsWeldInfo[0].anonymous_5 = 0;
	TailsWeldInfo[0].VertexBuffer = 0;
	TailsWeldInfo[0].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	TailsWeldInfo[0].WeldType = 2;
	TailsWeldInfo[0].VertIndexes = Tails_UpperArmIndices_DC;
	TailsWeldInfo[1].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[1].ModelA = MILES_OBJECTS[21];
	TailsWeldInfo[1].ModelB = MILES_OBJECTS[22];
	TailsWeldInfo[1].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	TailsWeldInfo[1].WeldType = 2;
	TailsWeldInfo[1].anonymous_5 = 0;
	TailsWeldInfo[1].VertexBuffer = 0;
	TailsWeldInfo[1].VertIndexes = Tails_LowerArmIndices_DC;
	TailsWeldInfo[2].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[2].ModelA = MILES_OBJECTS[23];
	v0 = MILES_OBJECTS[24];
	TailsWeldInfo[2].VertIndexes = Tails_UpperArmIndices_DC;
	TailsWeldInfo[2].ModelB = v0;
	TailsWeldInfo[2].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	TailsWeldInfo[2].WeldType = 2;
	TailsWeldInfo[2].anonymous_5 = 0;
	TailsWeldInfo[2].VertexBuffer = 0;
	TailsWeldInfo[3].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[3].ModelA = MILES_OBJECTS[24];
	TailsWeldInfo[3].ModelB = MILES_OBJECTS[25];
	TailsWeldInfo[3].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	TailsWeldInfo[3].WeldType = 2;
	TailsWeldInfo[3].anonymous_5 = 0;
	TailsWeldInfo[3].VertexBuffer = 0;
	TailsWeldInfo[3].VertIndexes = Tails_LowerArmIndices_DC;
	TailsWeldInfo[4].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[4].ModelA = MILES_OBJECTS[26];
	TailsWeldInfo[4].ModelB = MILES_OBJECTS[27];
	TailsWeldInfo[4].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	TailsWeldInfo[4].WeldType = 2;
	TailsWeldInfo[4].anonymous_5 = 0;
	TailsWeldInfo[4].VertexBuffer = 0;
	TailsWeldInfo[4].VertIndexes = Tails_KneeIndices_DC;
	TailsWeldInfo[5].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[5].ModelA = MILES_OBJECTS[27];
	TailsWeldInfo[5].ModelB = MILES_OBJECTS[28];
	TailsWeldInfo[5].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	TailsWeldInfo[5].WeldType = 2;
	TailsWeldInfo[5].anonymous_5 = 0;
	TailsWeldInfo[5].VertexBuffer = 0;
	TailsWeldInfo[5].VertIndexes = Tails_LegIndices_DC;
	TailsWeldInfo[6].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[6].ModelA = MILES_OBJECTS[29];
	TailsWeldInfo[6].ModelB = MILES_OBJECTS[30];
	TailsWeldInfo[6].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	TailsWeldInfo[6].WeldType = 2;
	TailsWeldInfo[6].anonymous_5 = 0;
	TailsWeldInfo[6].VertexBuffer = 0;
	TailsWeldInfo[6].VertIndexes = Tails_KneeIndices_DC;
	TailsWeldInfo[7].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[7].ModelA = MILES_OBJECTS[30];
	TailsWeldInfo[7].ModelB = MILES_OBJECTS[31];
	TailsWeldInfo[7].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	TailsWeldInfo[7].WeldType = 2;
	TailsWeldInfo[7].anonymous_5 = 0;
	TailsWeldInfo[7].VertexBuffer = 0;
	TailsWeldInfo[7].VertIndexes = Tails_LegIndices_DC;
	TailsWeldInfo[8].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[8].ModelA = MILES_OBJECTS[32];
	TailsWeldInfo[8].ModelB = MILES_OBJECTS[33];
	TailsWeldInfo[8].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	TailsWeldInfo[8].WeldType = 2;
	TailsWeldInfo[8].anonymous_5 = 0;
	TailsWeldInfo[8].VertexBuffer = 0;
	TailsWeldInfo[8].VertIndexes = Tails_ShoeIndices_DC;
	TailsWeldInfo[9].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[9].ModelA = MILES_OBJECTS[34];
	v1 = MILES_OBJECTS[35];
	TailsWeldInfo[9].VertIndexes = Tails_ShoeIndices_DC;
	TailsWeldInfo[9].ModelB = v1;
	TailsWeldInfo[9].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	TailsWeldInfo[9].WeldType = 2;
	TailsWeldInfo[9].anonymous_5 = 0;
	TailsWeldInfo[9].VertexBuffer = 0;
	TailsWeldInfo[10].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[10].ModelA = MILES_OBJECTS[36];
	TailsWeldInfo[10].ModelB = MILES_OBJECTS[37];
	TailsWeldInfo[10].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	TailsWeldInfo[10].WeldType = 2;
	TailsWeldInfo[10].anonymous_5 = 0;
	TailsWeldInfo[10].VertexBuffer = 0;
	TailsWeldInfo[10].VertIndexes = Tails_HandIndices_DC;
	TailsWeldInfo[11].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[11].ModelA = MILES_OBJECTS[38];
	TailsWeldInfo[11].ModelB = MILES_OBJECTS[39];
	TailsWeldInfo[11].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	TailsWeldInfo[11].WeldType = 2;
	TailsWeldInfo[11].anonymous_5 = 0;
	TailsWeldInfo[11].VertexBuffer = 0;
	TailsWeldInfo[11].VertIndexes = Tails_HandIndices_DC;
	TailsWeldInfo[12].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[12].ModelA = MILES_OBJECTS[40];
	TailsWeldInfo[12].ModelB = MILES_OBJECTS[41];
	TailsWeldInfo[12].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	TailsWeldInfo[12].WeldType = 2;
	TailsWeldInfo[12].anonymous_5 = 0;
	TailsWeldInfo[12].VertexBuffer = 0;
	TailsWeldInfo[12].VertIndexes = Tails_UpperArmIndices_DC;
	TailsWeldInfo[13].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[13].ModelA = MILES_OBJECTS[41];
	TailsWeldInfo[13].ModelB = MILES_OBJECTS[42];
	TailsWeldInfo[13].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	TailsWeldInfo[13].WeldType = 2;
	TailsWeldInfo[13].anonymous_5 = 0;
	TailsWeldInfo[13].VertexBuffer = 0;
	TailsWeldInfo[13].VertIndexes = Tails_LowerArmIndices_DC;
	TailsWeldInfo[14].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[14].ModelA = MILES_OBJECTS[43];
	TailsWeldInfo[14].ModelB = MILES_OBJECTS[44];
	TailsWeldInfo[14].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	TailsWeldInfo[14].WeldType = 2;
	TailsWeldInfo[14].anonymous_5 = 0;
	TailsWeldInfo[14].VertexBuffer = 0;
	TailsWeldInfo[14].VertIndexes = Tails_UpperArmIndices_DC;
	TailsWeldInfo[15].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[15].ModelA = MILES_OBJECTS[44];
	TailsWeldInfo[15].ModelB = MILES_OBJECTS[45];
	TailsWeldInfo[15].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	TailsWeldInfo[15].WeldType = 2;
	TailsWeldInfo[15].anonymous_5 = 0;
	TailsWeldInfo[15].VertexBuffer = 0;
	TailsWeldInfo[15].VertIndexes = Tails_LowerArmIndices_DC;
	TailsWeldInfo[16].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[16].ModelA = MILES_OBJECTS[46];
	TailsWeldInfo[16].ModelB = MILES_OBJECTS[47];
	TailsWeldInfo[16].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	TailsWeldInfo[16].WeldType = 2;
	TailsWeldInfo[16].anonymous_5 = 0;
	TailsWeldInfo[16].VertexBuffer = 0;
	TailsWeldInfo[16].VertIndexes = Tails_KneeIndices_DC;
	TailsWeldInfo[17].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[17].ModelA = MILES_OBJECTS[47];
	TailsWeldInfo[17].ModelB = MILES_OBJECTS[48];
	TailsWeldInfo[17].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	TailsWeldInfo[17].WeldType = 2;
	TailsWeldInfo[17].anonymous_5 = 0;
	TailsWeldInfo[17].VertexBuffer = 0;
	TailsWeldInfo[17].VertIndexes = Tails_LegIndices_DC;
	TailsWeldInfo[18].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[18].ModelA = MILES_OBJECTS[49];
	TailsWeldInfo[18].ModelB = MILES_OBJECTS[50];
	TailsWeldInfo[18].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	TailsWeldInfo[18].WeldType = 2;
	TailsWeldInfo[18].anonymous_5 = 0;
	TailsWeldInfo[18].VertexBuffer = 0;
	TailsWeldInfo[18].VertIndexes = Tails_KneeIndices_DC;
	TailsWeldInfo[19].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[19].ModelA = MILES_OBJECTS[50];
	v2 = MILES_OBJECTS[51];
	TailsWeldInfo[19].VertIndexes = Tails_LegIndices_DC;
	TailsWeldInfo[19].ModelB = v2;
	TailsWeldInfo[19].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	TailsWeldInfo[19].WeldType = 2;
	TailsWeldInfo[19].anonymous_5 = 0;
	TailsWeldInfo[19].VertexBuffer = 0;
	TailsWeldInfo[20].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[20].ModelA = MILES_OBJECTS[52];
	TailsWeldInfo[20].ModelB = MILES_OBJECTS[53];
	TailsWeldInfo[20].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	TailsWeldInfo[20].WeldType = 2;
	TailsWeldInfo[20].anonymous_5 = 0;
	TailsWeldInfo[20].VertexBuffer = 0;
	TailsWeldInfo[20].VertIndexes = Tails_ShoeIndices_DC;
	TailsWeldInfo[21].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[21].ModelA = MILES_OBJECTS[54];
	TailsWeldInfo[21].ModelB = MILES_OBJECTS[55];
	TailsWeldInfo[21].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	TailsWeldInfo[21].WeldType = 2;
	TailsWeldInfo[21].anonymous_5 = 0;
	TailsWeldInfo[21].VertexBuffer = 0;
	TailsWeldInfo[21].VertIndexes = Tails_ShoeIndices_DC;
	TailsWeldInfo[22].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[22].ModelA = MILES_OBJECTS[56];
	TailsWeldInfo[22].ModelB = MILES_OBJECTS[57];
	TailsWeldInfo[22].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	TailsWeldInfo[22].WeldType = 2;
	TailsWeldInfo[22].anonymous_5 = 0;
	TailsWeldInfo[22].VertexBuffer = 0;
	TailsWeldInfo[22].VertIndexes = Tails_HandIndices_DC;
	TailsWeldInfo[23].BaseModel = MILES_OBJECTS[1];
	TailsWeldInfo[23].ModelA = MILES_OBJECTS[58];
	TailsWeldInfo[23].ModelB = MILES_OBJECTS[59];
	TailsWeldInfo[23].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	TailsWeldInfo[23].WeldType = 2;
	TailsWeldInfo[23].anonymous_5 = 0;
	TailsWeldInfo[23].VertexBuffer = 0;
	TailsWeldInfo[23].VertIndexes = Tails_HandIndices_DC;
	TailsWeldInfo[24].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[24].ModelA = MILES_OBJECTS[37];
	TailsWeldInfo[24].ModelB = 0;
	TailsWeldInfo[24].VertexPairCount = 2;
	TailsWeldInfo[24].WeldType = 4;
	TailsWeldInfo[24].anonymous_5 = 0;
	TailsWeldInfo[24].VertexBuffer = 0;
	TailsWeldInfo[24].VertIndexes = 0;
	TailsWeldInfo[25].BaseModel = *MILES_OBJECTS;
	TailsWeldInfo[25].ModelA = MILES_OBJECTS[39];
	TailsWeldInfo[25].ModelB = 0;
	TailsWeldInfo[25].VertexPairCount = 2;
	TailsWeldInfo[25].WeldType = 5;
	TailsWeldInfo[25].anonymous_5 = 0;
	TailsWeldInfo[25].VertexBuffer = 0;
	TailsWeldInfo[25].VertIndexes = 0;
	TailsWeldInfo[26].BaseModel = *MILES_OBJECTS;
	v3 = MILES_OBJECTS[33];
	TailsWeldInfo[26].ModelB = 0;
	TailsWeldInfo[26].VertexPairCount = 0;
	TailsWeldInfo[26].anonymous_5 = 0;
	TailsWeldInfo[26].VertexBuffer = 0;
	TailsWeldInfo[26].VertIndexes = 0;
	TailsWeldInfo[26].ModelA = v3;
	TailsWeldInfo[26].WeldType = 6;
	TailsWeldInfo[27].BaseModel = *MILES_OBJECTS;
	v4 = MILES_OBJECTS[35];
	TailsWeldInfo[27].ModelB = 0;
	TailsWeldInfo[27].VertexPairCount = 0;
	TailsWeldInfo[27].anonymous_5 = 0;
	TailsWeldInfo[27].VertexBuffer = 0;
	TailsWeldInfo[27].VertIndexes = 0;
	TailsWeldInfo[27].ModelA = v4;
	TailsWeldInfo[27].WeldType = 7;
	TailsWeldInfo[28].BaseModel = *MILES_OBJECTS;
	v5 = MILES_OBJECTS[4];
	TailsWeldInfo[28].ModelB = 0;
	TailsWeldInfo[28].VertexPairCount = 0;
	TailsWeldInfo[28].anonymous_5 = 0;
	TailsWeldInfo[28].VertexBuffer = 0;
	TailsWeldInfo[28].VertIndexes = 0;
	TailsWeldInfo[29].BaseModel = 0;
	TailsWeldInfo[29].ModelA = 0;
	TailsWeldInfo[29].ModelB = 0;
	TailsWeldInfo[29].VertexPairCount = 0;
	TailsWeldInfo[29].VertexBuffer = 0;
	TailsWeldInfo[28].ModelA = v5;
	TailsWeldInfo[28].WeldType = 8;
	TailsWeldInfo[29].VertIndexes = 0;
}

void __cdecl InitNPCTailsWeldInfo_mod()
{
	NJS_OBJECT* v0; // ebp@1
	NJS_OBJECT* v1; // ebp@1
	NJS_OBJECT* v2; // ebp@1
	NJS_OBJECT* v3; // ebx@1
	NJS_OBJECT* v4; // esi@1
	NJS_OBJECT* v5; // eax@1

	NPCTailsWeldInfo[0].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[0].ModelA = MILES_OBJECTS[20];
	NPCTailsWeldInfo[0].ModelB = MILES_OBJECTS[21];
	NPCTailsWeldInfo[0].anonymous_5 = 0;
	NPCTailsWeldInfo[0].VertexBuffer = 0;
	NPCTailsWeldInfo[0].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	NPCTailsWeldInfo[0].WeldType = 2;
	NPCTailsWeldInfo[0].VertIndexes = Tails_UpperArmIndices_DC;
	NPCTailsWeldInfo[1].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[1].ModelA = MILES_OBJECTS[21];
	NPCTailsWeldInfo[1].ModelB = MILES_OBJECTS[22];
	NPCTailsWeldInfo[1].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	NPCTailsWeldInfo[1].WeldType = 2;
	NPCTailsWeldInfo[1].anonymous_5 = 0;
	NPCTailsWeldInfo[1].VertexBuffer = 0;
	NPCTailsWeldInfo[1].VertIndexes = Tails_LowerArmIndices_DC;
	NPCTailsWeldInfo[2].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[2].ModelA = MILES_OBJECTS[23];
	v0 = MILES_OBJECTS[24];
	NPCTailsWeldInfo[2].VertIndexes = Tails_UpperArmIndices_DC;
	NPCTailsWeldInfo[2].ModelB = v0;
	NPCTailsWeldInfo[2].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	NPCTailsWeldInfo[2].WeldType = 2;
	NPCTailsWeldInfo[2].anonymous_5 = 0;
	NPCTailsWeldInfo[2].VertexBuffer = 0;
	NPCTailsWeldInfo[3].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[3].ModelA = MILES_OBJECTS[24];
	NPCTailsWeldInfo[3].ModelB = MILES_OBJECTS[25];
	NPCTailsWeldInfo[3].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	NPCTailsWeldInfo[3].WeldType = 2;
	NPCTailsWeldInfo[3].anonymous_5 = 0;
	NPCTailsWeldInfo[3].VertexBuffer = 0;
	NPCTailsWeldInfo[3].VertIndexes = Tails_LowerArmIndices_DC;
	NPCTailsWeldInfo[4].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[4].ModelA = MILES_OBJECTS[26];
	NPCTailsWeldInfo[4].ModelB = MILES_OBJECTS[27];
	NPCTailsWeldInfo[4].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	NPCTailsWeldInfo[4].WeldType = 2;
	NPCTailsWeldInfo[4].anonymous_5 = 0;
	NPCTailsWeldInfo[4].VertexBuffer = 0;
	NPCTailsWeldInfo[4].VertIndexes = Tails_KneeIndices_DC;
	NPCTailsWeldInfo[5].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[5].ModelA = MILES_OBJECTS[27];
	NPCTailsWeldInfo[5].ModelB = MILES_OBJECTS[28];
	NPCTailsWeldInfo[5].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	NPCTailsWeldInfo[5].WeldType = 2;
	NPCTailsWeldInfo[5].anonymous_5 = 0;
	NPCTailsWeldInfo[5].VertexBuffer = 0;
	NPCTailsWeldInfo[5].VertIndexes = Tails_LegIndices_DC;
	NPCTailsWeldInfo[6].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[6].ModelA = MILES_OBJECTS[29];
	NPCTailsWeldInfo[6].ModelB = MILES_OBJECTS[30];
	NPCTailsWeldInfo[6].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	NPCTailsWeldInfo[6].WeldType = 2;
	NPCTailsWeldInfo[6].anonymous_5 = 0;
	NPCTailsWeldInfo[6].VertexBuffer = 0;
	NPCTailsWeldInfo[6].VertIndexes = Tails_KneeIndices_DC;
	NPCTailsWeldInfo[7].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[7].ModelA = MILES_OBJECTS[30];
	NPCTailsWeldInfo[7].ModelB = MILES_OBJECTS[31];
	NPCTailsWeldInfo[7].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	NPCTailsWeldInfo[7].WeldType = 2;
	NPCTailsWeldInfo[7].anonymous_5 = 0;
	NPCTailsWeldInfo[7].VertexBuffer = 0;
	NPCTailsWeldInfo[7].VertIndexes = Tails_LegIndices_DC;
	NPCTailsWeldInfo[8].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[8].ModelA = MILES_OBJECTS[32];
	NPCTailsWeldInfo[8].ModelB = MILES_OBJECTS[33];
	NPCTailsWeldInfo[8].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	NPCTailsWeldInfo[8].WeldType = 2;
	NPCTailsWeldInfo[8].anonymous_5 = 0;
	NPCTailsWeldInfo[8].VertexBuffer = 0;
	NPCTailsWeldInfo[8].VertIndexes = Tails_ShoeIndices_DC;
	NPCTailsWeldInfo[9].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[9].ModelA = MILES_OBJECTS[34];
	v1 = MILES_OBJECTS[35];
	NPCTailsWeldInfo[9].VertIndexes = Tails_ShoeIndices_DC;
	NPCTailsWeldInfo[9].ModelB = v1;
	NPCTailsWeldInfo[9].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	NPCTailsWeldInfo[9].WeldType = 2;
	NPCTailsWeldInfo[9].anonymous_5 = 0;
	NPCTailsWeldInfo[9].VertexBuffer = 0;
	NPCTailsWeldInfo[10].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[10].ModelA = MILES_OBJECTS[36];
	NPCTailsWeldInfo[10].ModelB = MILES_OBJECTS[37];
	NPCTailsWeldInfo[10].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	NPCTailsWeldInfo[10].WeldType = 2;
	NPCTailsWeldInfo[10].anonymous_5 = 0;
	NPCTailsWeldInfo[10].VertexBuffer = 0;
	NPCTailsWeldInfo[10].VertIndexes = Tails_HandIndices_DC;
	NPCTailsWeldInfo[11].BaseModel = *MILES_OBJECTS;
	NPCTailsWeldInfo[11].ModelA = MILES_OBJECTS[38];
	NPCTailsWeldInfo[11].ModelB = MILES_OBJECTS[39];
	NPCTailsWeldInfo[11].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	NPCTailsWeldInfo[11].WeldType = 2;
	NPCTailsWeldInfo[11].anonymous_5 = 0;
	NPCTailsWeldInfo[11].VertexBuffer = 0;
	NPCTailsWeldInfo[11].VertIndexes = Tails_HandIndices_DC;
	NPCTailsWeldInfo[12].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[12].ModelA = MILES_OBJECTS[40];
	NPCTailsWeldInfo[12].ModelB = MILES_OBJECTS[41];
	NPCTailsWeldInfo[12].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	NPCTailsWeldInfo[12].WeldType = 2;
	NPCTailsWeldInfo[12].anonymous_5 = 0;
	NPCTailsWeldInfo[12].VertexBuffer = 0;
	NPCTailsWeldInfo[12].VertIndexes = Tails_UpperArmIndices_DC;
	NPCTailsWeldInfo[13].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[13].ModelA = MILES_OBJECTS[41];
	NPCTailsWeldInfo[13].ModelB = MILES_OBJECTS[42];
	NPCTailsWeldInfo[13].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	NPCTailsWeldInfo[13].WeldType = 2;
	NPCTailsWeldInfo[13].anonymous_5 = 0;
	NPCTailsWeldInfo[13].VertexBuffer = 0;
	NPCTailsWeldInfo[13].VertIndexes = Tails_LowerArmIndices_DC;
	NPCTailsWeldInfo[14].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[14].ModelA = MILES_OBJECTS[43];
	NPCTailsWeldInfo[14].ModelB = MILES_OBJECTS[44];
	NPCTailsWeldInfo[14].VertexPairCount = (uint8_t)(LengthOfArray(Tails_UpperArmIndices_DC) / 2);
	NPCTailsWeldInfo[14].WeldType = 2;
	NPCTailsWeldInfo[14].anonymous_5 = 0;
	NPCTailsWeldInfo[14].VertexBuffer = 0;
	NPCTailsWeldInfo[14].VertIndexes = Tails_UpperArmIndices_DC;
	NPCTailsWeldInfo[15].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[15].ModelA = MILES_OBJECTS[44];
	NPCTailsWeldInfo[15].ModelB = MILES_OBJECTS[45];
	NPCTailsWeldInfo[15].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LowerArmIndices_DC) / 2);
	NPCTailsWeldInfo[15].WeldType = 2;
	NPCTailsWeldInfo[15].anonymous_5 = 0;
	NPCTailsWeldInfo[15].VertexBuffer = 0;
	NPCTailsWeldInfo[15].VertIndexes = Tails_LowerArmIndices_DC;
	NPCTailsWeldInfo[16].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[16].ModelA = MILES_OBJECTS[46];
	NPCTailsWeldInfo[16].ModelB = MILES_OBJECTS[47];
	NPCTailsWeldInfo[16].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	NPCTailsWeldInfo[16].WeldType = 2;
	NPCTailsWeldInfo[16].anonymous_5 = 0;
	NPCTailsWeldInfo[16].VertexBuffer = 0;
	NPCTailsWeldInfo[16].VertIndexes = Tails_KneeIndices_DC;
	NPCTailsWeldInfo[17].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[17].ModelA = MILES_OBJECTS[47];
	NPCTailsWeldInfo[17].ModelB = MILES_OBJECTS[48];
	NPCTailsWeldInfo[17].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	NPCTailsWeldInfo[17].WeldType = 2;
	NPCTailsWeldInfo[17].anonymous_5 = 0;
	NPCTailsWeldInfo[17].VertexBuffer = 0;
	NPCTailsWeldInfo[17].VertIndexes = Tails_LegIndices_DC;
	NPCTailsWeldInfo[18].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[18].ModelA = MILES_OBJECTS[49];
	NPCTailsWeldInfo[18].ModelB = MILES_OBJECTS[50];
	NPCTailsWeldInfo[18].VertexPairCount = (uint8_t)(LengthOfArray(Tails_KneeIndices_DC) / 2);
	NPCTailsWeldInfo[18].WeldType = 2;
	NPCTailsWeldInfo[18].anonymous_5 = 0;
	NPCTailsWeldInfo[18].VertexBuffer = 0;
	NPCTailsWeldInfo[18].VertIndexes = Tails_KneeIndices_DC;
	NPCTailsWeldInfo[19].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[19].ModelA = MILES_OBJECTS[50];
	v2 = MILES_OBJECTS[51];
	NPCTailsWeldInfo[19].anonymous_5 = 0;
	NPCTailsWeldInfo[19].VertexBuffer = 0;
	NPCTailsWeldInfo[19].VertIndexes = Tails_LegIndices_DC;
	NPCTailsWeldInfo[19].ModelB = v2;
	NPCTailsWeldInfo[19].VertexPairCount = (uint8_t)(LengthOfArray(Tails_LegIndices_DC) / 2);
	NPCTailsWeldInfo[19].WeldType = 2;
	NPCTailsWeldInfo[20].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[20].ModelA = MILES_OBJECTS[52];
	NPCTailsWeldInfo[20].ModelB = MILES_OBJECTS[53];
	NPCTailsWeldInfo[20].anonymous_5 = 0;
	NPCTailsWeldInfo[20].VertexBuffer = 0;
	NPCTailsWeldInfo[20].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	NPCTailsWeldInfo[20].WeldType = 2;
	NPCTailsWeldInfo[20].VertIndexes = Tails_ShoeIndices_DC;
	NPCTailsWeldInfo[21].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[21].ModelA = MILES_OBJECTS[54];
	v3 = MILES_OBJECTS[55];
	NPCTailsWeldInfo[21].anonymous_5 = 0;
	NPCTailsWeldInfo[21].VertexBuffer = 0;
	NPCTailsWeldInfo[21].ModelB = v3;
	NPCTailsWeldInfo[21].VertIndexes = Tails_ShoeIndices_DC;
	NPCTailsWeldInfo[21].VertexPairCount = (uint8_t)(LengthOfArray(Tails_ShoeIndices_DC) / 2);
	NPCTailsWeldInfo[21].WeldType = 2;
	NPCTailsWeldInfo[22].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[22].ModelA = MILES_OBJECTS[56];
	v4 = MILES_OBJECTS[57];
	NPCTailsWeldInfo[22].anonymous_5 = 0;
	NPCTailsWeldInfo[22].VertexBuffer = 0;
	NPCTailsWeldInfo[22].ModelB = v4;
	NPCTailsWeldInfo[22].VertIndexes = Tails_HandIndices_DC;
	NPCTailsWeldInfo[22].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	NPCTailsWeldInfo[22].WeldType = 2;
	NPCTailsWeldInfo[23].BaseModel = MILES_OBJECTS[1];
	NPCTailsWeldInfo[23].ModelA = MILES_OBJECTS[58];
	v5 = MILES_OBJECTS[59];
	NPCTailsWeldInfo[23].anonymous_5 = 0;
	NPCTailsWeldInfo[23].VertexBuffer = 0;
	NPCTailsWeldInfo[24].BaseModel = 0;
	NPCTailsWeldInfo[24].ModelA = 0;
	NPCTailsWeldInfo[23].VertIndexes = Tails_HandIndices_DC;
	NPCTailsWeldInfo[24].ModelB = 0;
	NPCTailsWeldInfo[24].VertexPairCount = 0;
	NPCTailsWeldInfo[24].VertexBuffer = 0;
	NPCTailsWeldInfo[23].ModelB = v5;
	NPCTailsWeldInfo[23].VertexPairCount = (uint8_t)(LengthOfArray(Tails_HandIndices_DC) / 2);
	NPCTailsWeldInfo[23].WeldType = 2;
	NPCTailsWeldInfo[24].VertIndexes = 0;
}

NJS_MATERIAL* Specular1[] = {
	&material_8D9A3AD59B801E09402[0],
	&material_8D9A3AD59B801E09402[1],
	&material_8D9A3AD59B801E09402[2],
	&material_8D9A3AD59B801E09402[3],
	&material_8D9A3AD59B801E09402[4],
	&material_8D9A3AD72768CB60585[0],
	&material_8D9A3AD72768CB60585[1],
	&material_8D9A3AD72768CB60585[2],
	&material_8D9A3AD72768CB60585[3],
	&material_8D9A3AD72768CB60585[4],
};

NJS_MATERIAL* Specular3[] = {
	&material_8D9A38DB7F6FD99F033[0],
	&material_8D9A38DB7F6FD99F033[1],
	&material_8D9A38DB7F6FD99F033[2],
	&material_8D9A38DB7F6FD99F033[3],
	&material_8D9A38DB7F6FD99F033[4],
	&material_8D9A38DB7F6FD99F033[5],
	&material_8D9A38DB7F6FD99F033[6],
	&material_8D9A38DB7F6FD99F033[7],
	&material_8D9A38DB7F6FD99F033[8],
	&material_8D9A38DB7F6FD99F033[9],
	&material_8D9A38DB7F6FD99F033[10],
	&material_8D9A38DB7F6FD99F033[11],
	&material_8D9A38DB7F6FD99F033[12],
	&material_8D9A38DC2BCF3008643[0],
	&material_8D9A38DC9CFA6762473[0],
	&material_8D9A38DD0DD7EF22356[0],
	&material_8D9A38DD6B601FC07FE[0],
	&material_8D9A61D7E0860918219[0],
	&material_8D9A61D7E0860918219[1],
	&material_8D9A61D7E0860918219[2],
	&material_8D9A61D7E0860918219[3],
	&material_8D9A61D7E0860918219[4],
	&material_8D9A61D7E0860918219[5],
	&material_8D9A61D7E0860918219[6],
	&material_8D9A61D7E0860918219[7],
	&material_8D9A61D7E0860918219[8],
	&material_8D9A61D7E0860918219[9],
	&matlist_02F37A50[0],
	&matlist_02F37A50[3],
	&matlist_02F37A50[5],
	&matlist_02F37A50[9],
	&matlist_02F36AE8[0],
	&matlist_02F36AE8[1],
	&matlist_02F36AE8[2],
	&matlist_02F36AE8[3],
};

NJS_MATERIAL* TailsBody[] = {
	&material_8D9A5E8B0F321AF1319[0],
	&material_8D9A5E8B0F321AF1319[1],
	&material_8D9A5E8B0F321AF1319[2],
	&material_8D9A5E8B0F321AF1319[3],
	&material_8D9A5E8B0F321AF1319[4],
	&material_8D9A5E8B0F321AF1319[5],
	&material_8D9A5E8B0F321AF1319[6],
	&material_8D9A5E8B0F321AF1319[7],
};

NJS_MATERIAL* TailsShoes[] = {
	&material_8D935D7C4FE3FB3D443[0],
	&material_8D935D7C4FE3FB3D443[1],
	&material_8D935D7D1C1A0DCCCC2[0],
	&material_8D935D7D1C1A0DCCCC2[1],
	&material_8D935D7CADE8B0B915E[0],
	&material_8D935D7CADE8B0B915E[1],
	&material_8D935D7D63688ADB9A9[0],
	&material_8D935D7D63688ADB9A9[1],
	&material_8D9A3E1EC315EED4C4C[0],
	&material_8D9A3E1EC315EED4C4C[1],
	&material_8D9A3E1F8B51A0D945E[0],
	&material_8D9A3E1F8B51A0D945E[1],
	&material_8D9A3E1F1B75781E151[0],
	&material_8D9A3E1F1B75781E151[1],
	&material_8D9A3E1FE89C9A8654C[0],
	&material_8D9A3E1FE89C9A8654C[1],
	&matlist_0046E670[0],
	&matlist_0046E670[1],
	&matlist_0046E670[2],
	&matlist_0046E670[3],
	&matlist_0046E670[4],
	&matlist_0046E670[5],
	&matlist_0046E670[6],
	&matlist_0046E048[0],
	&matlist_0046E048[1],
	&matlist_0046F4A0[0],
	&matlist_0046F4A0[1],
	&matlist_0046F4A0[2],
	&matlist_0046F4A0[3],
	&matlist_0046F4A0[4],
	&matlist_0046F4A0[5],
	&matlist_0046F4A0[6],
	&matlist_0046EE78[0],
	&matlist_0046EE78[1],
};

bool ForceDiffuse0Specular1(NJS_MATERIAL* material, Uint32 flags)
{
	set_diffuse(0, false);
	set_specular(1, false);
	return true;
}

bool ForceDiffuse0Specular0_Tails(NJS_MATERIAL* material, Uint32 flags)
{
	if (CurrentLevel == 1 && CurrentAct == 1 && TailsAI_ptr == nullptr && EV_MainThread_ptr == nullptr)
	{
		set_diffuse(0, false);
		set_specular(0, false);
	}
	else
	{
		set_diffuse(2, false);
		set_specular(2, false);
	}
	return true;
}

bool ForceDiffuse0Specular1_Tails(NJS_MATERIAL* material, Uint32 flags)
{
	if (CurrentLevel == 1 && CurrentAct == 1 && TailsAI_ptr == nullptr && EV_MainThread_ptr == nullptr)
	{
		set_diffuse(0, false);
		set_specular(1, false);
	}
	else
	{
		set_diffuse(2, false);
		set_specular(3, false);
	}
	return true;
}

bool ForceDiffuse2Specular2(NJS_MATERIAL* material, Uint32 flags)
{
	set_diffuse(2, false);
	set_specular(2, false);
	return true;
}

bool ForceDiffuse2Specular3(NJS_MATERIAL* material, Uint32 flags)
{
	set_diffuse(2, false);
	set_specular(3, false);
	return true;
}

void ForceDiffuse2Specular2_Object(NJS_OBJECT* obj)
{
	if (obj->basicdxmodel)
	{
		for (int q = 0; q < obj->basicdxmodel->nbMat; ++q)
		{
			if (!(obj->basicdxmodel->mats[q].attrflags & NJD_FLAG_IGNORE_LIGHT))
			{
				TemporaryMaterialArray[0] = &obj->basicdxmodel->mats[q];
				material_register(TemporaryMaterialArray, 1, ForceDiffuse2Specular2);
			}
		}
	}
	if (obj->child) ForceDiffuse2Specular2_Object(obj->child);
	if (obj->sibling) ForceDiffuse2Specular2_Object(obj->sibling);
}

void RemoveMaterialColors(NJS_OBJECT* obj)
{
	if (obj->basicdxmodel)
	{
		for (int q = 0; q < obj->basicdxmodel->nbMat; ++q)
		{
			obj->basicdxmodel->mats[q].diffuse.argb.r = 0xFF;
			obj->basicdxmodel->mats[q].diffuse.argb.g = 0xFF;
			obj->basicdxmodel->mats[q].diffuse.argb.b = 0xFF;
		}
	}
	if (obj->child) RemoveMaterialColors(obj->child);
	if (obj->sibling) RemoveMaterialColors(obj->sibling);
}

void Init_Tails()
{
	MILES_OBJECTS[0] = &object_0042AD54;
	MILES_OBJECTS[1] = &object_00437C44;
	MILES_OBJECTS[2] = &object_0043F4B4;
	MILES_OBJECTS[3] = &object_0044148C;
	MILES_OBJECTS[4] = &object_0042ABE8;
	MILES_OBJECTS[5] = &object_00437AD8;
	MILES_OBJECTS[6] = &object_0042AC84;
	MILES_OBJECTS[7] = &object_00437B74;
	MILES_OBJECTS[8] = &object_00426ED0;
	MILES_OBJECTS[9] = &object_00426B90;
	MILES_OBJECTS[10] = &object_00433DC0;
	MILES_OBJECTS[11] = &object_00433A80;
	MILES_OBJECTS[12] = &object_0041E548;
	MILES_OBJECTS[13] = &object_0041EC90;
	MILES_OBJECTS[14] = &object_0041ED2C;
	MILES_OBJECTS[15] = &object_0041E5E4;
	MILES_OBJECTS[16] = &object_0042BC1C;
	MILES_OBJECTS[17] = &object_0042B4D4;
	MILES_OBJECTS[18] = &object_0042BBE8;
	MILES_OBJECTS[19] = &object_0042B4A0;
	MILES_OBJECTS[20] = &object_00424D00;
	MILES_OBJECTS[21] = &object_00424E94;
	MILES_OBJECTS[22] = &object_0042674C;
	MILES_OBJECTS[23] = &object_00422FD8;
	MILES_OBJECTS[24] = &object_0042316C;
	MILES_OBJECTS[25] = &object_00424A14;
	MILES_OBJECTS[26] = &object_0042182C;
	MILES_OBJECTS[27] = &object_004219BC;
	MILES_OBJECTS[28] = &object_00422CF0;
	MILES_OBJECTS[29] = &object_004200CC;
	MILES_OBJECTS[30] = &object_0042025C;
	MILES_OBJECTS[31] = &object_00421598;
	MILES_OBJECTS[32] = &object_004225C8;
	MILES_OBJECTS[33] = &object_00421FE4;
	MILES_OBJECTS[34] = &object_00420E70;
	MILES_OBJECTS[35] = &object_00420884;
	MILES_OBJECTS[36] = &object_00425E88;
	MILES_OBJECTS[37] = &object_00425C40;
	MILES_OBJECTS[38] = &object_00424158;
	MILES_OBJECTS[39] = &object_00423F10;
	MILES_OBJECTS[40] = &object_00431BF0;
	MILES_OBJECTS[41] = &object_00431D84;
	MILES_OBJECTS[42] = &object_0043363C;
	MILES_OBJECTS[43] = &object_0042FEC8;
	MILES_OBJECTS[44] = &object_0043005C;
	MILES_OBJECTS[45] = &object_00431904;
	MILES_OBJECTS[46] = &object_0042E71C;
	MILES_OBJECTS[47] = &object_0042E8AC;
	MILES_OBJECTS[48] = &object_0042FBE0;
	MILES_OBJECTS[49] = &object_0042CFBC;
	MILES_OBJECTS[50] = &object_0042D14C;
	MILES_OBJECTS[51] = &object_0042E488;
	MILES_OBJECTS[52] = &object_0042F4B8;
	MILES_OBJECTS[53] = &object_0042EED4;
	MILES_OBJECTS[54] = &object_0042DD60;
	MILES_OBJECTS[55] = &object_0042D774;
	MILES_OBJECTS[56] = &object_00432D78;
	MILES_OBJECTS[57] = &object_00432B30;
	MILES_OBJECTS[58] = &object_00431048;
	MILES_OBJECTS[59] = &object_00430E00;
	MILES_OBJECTS[60] = &object_0046E63C;
	MILES_OBJECTS[61] = &object_0046F46C;
	MILES_OBJECTS[62] = &object_0041FE04;
	MILES_OBJECTS[63] = &object_0042CCF4;
	MILES_OBJECTS[64] = &object_0046EE44;
	MILES_OBJECTS[65] = &object_0046FC84;
	MILES_OBJECTS[66] = &object_0042AC1C;
	MILES_OBJECTS[67] = &object_0042ABE8;
	MILES_OBJECTS[68] = &object_00437B0C;
	MILES_OBJECTS[69] = &object_00437AD8;
	MILES_OBJECTS[70] = &object_0044C724;
	MILES_ACTIONS[0]->object = &object_00437C44;
	MILES_ACTIONS[1]->object = &object_00437C44;
	MILES_ACTIONS[2]->object = &object_00437C44;
	MILES_ACTIONS[3]->object = &object_00437C44;
	MILES_ACTIONS[4]->object = &object_00437C44;
	MILES_ACTIONS[5]->object = &object_00437C44;
	MILES_ACTIONS[6]->object = &object_00437C44;
	MILES_ACTIONS[7]->object = &object_00437C44;
	MILES_ACTIONS[8]->object = &object_00437C44;
	MILES_ACTIONS[9]->object = &object_00437C44;
	MILES_ACTIONS[10]->object = &object_00437C44;
	MILES_ACTIONS[11]->object = &object_0042AD54;
	MILES_ACTIONS[12]->object = &object_0042AD54;
	MILES_ACTIONS[13]->object = &object_0042AD54;
	MILES_ACTIONS[14]->object = &object_0042AD54;
	MILES_ACTIONS[15]->object = &object_0042AD54;
	MILES_ACTIONS[16]->object = &object_0042AD54;
	MILES_ACTIONS[17]->object = &object_00437C44;
	MILES_ACTIONS[18]->object = &object_00437C44;
	MILES_ACTIONS[19]->object = &object_00437C44;
	MILES_ACTIONS[20]->object = &object_00437C44;
	MILES_ACTIONS[21]->object = &object_0042AD54;
	MILES_ACTIONS[22]->object = &object_0042AD54;
	MILES_ACTIONS[23]->object = &object_0042AD54;
	MILES_ACTIONS[24]->object = &object_0042AD54;
	MILES_ACTIONS[25]->object = &object_0042AD54;
	MILES_ACTIONS[26]->object = &object_0042AD54;
	MILES_ACTIONS[27]->object = &object_0042AD54;
	MILES_ACTIONS[28]->object = &object_0042AD54;
	MILES_ACTIONS[29]->object = &object_0042AD54;
	MILES_ACTIONS[30]->object = &object_0042AD54;
	MILES_ACTIONS[31]->object = &object_0042AD54;
	MILES_ACTIONS[32]->object = &object_0042AD54;
	MILES_ACTIONS[33]->object = &object_0042AD54;
	MILES_ACTIONS[34]->object = &object_0042AD54;
	MILES_ACTIONS[35]->object = &object_0042AD54;
	MILES_ACTIONS[36]->object = &object_0042AD54;
	MILES_ACTIONS[37]->object = &object_0042AD54;
	MILES_ACTIONS[38]->object = &object_0042AD54;
	MILES_ACTIONS[39]->object = &object_0042AD54;
	MILES_ACTIONS[40]->object = &object_0042AD54;
	MILES_ACTIONS[41]->object = &object_0042AD54;
	MILES_ACTIONS[42]->object = &object_0042AD54;
	MILES_ACTIONS[43]->object = &object_0042AD54;
	MILES_ACTIONS[44]->object = &object_0042AD54;
	MILES_ACTIONS[45]->object = &object_0042AD54;
	MILES_ACTIONS[46]->object = &object_0042AD54;
	MILES_ACTIONS[47]->object = &object_0042AD54;
	MILES_ACTIONS[48]->object = &object_0042AD54;
	MILES_ACTIONS[49]->object = &object_0042AD54;
	MILES_ACTIONS[50]->object = &object_0042AD54;
	MILES_ACTIONS[51]->object = &object_0042AD54;
	MILES_ACTIONS[52]->object = &object_0042AD54;
	MILES_ACTIONS[53]->object = &object_00437C44;
	MILES_ACTIONS[54]->object = &object_00437C44;
	MILES_ACTIONS[55]->object = &object_0042AD54;
	MILES_ACTIONS[56]->object = &object_0042AD54;
	MILES_ACTIONS[57]->object = &object_0042AD54;
	MILES_ACTIONS[58]->object = &object_0042AD54;
	MILES_ACTIONS[59]->object = &object_0042AD54;
	MILES_ACTIONS[60]->object = &object_0042AD54;
	MILES_ACTIONS[61]->object = &object_0042AD54;
	MILES_ACTIONS[62]->object = &object_0042AD54;
	MILES_ACTIONS[63]->object = &object_0042AD54;
	MILES_ACTIONS[64]->object = &object_0043F4B4;
	MILES_ACTIONS[65]->object = &object_0044148C;
	MILES_ACTIONS[66]->object = &object_0042AD54;
	MILES_ACTIONS[67]->object = &object_0042AD54;
	MILES_ACTIONS[68]->object = &object_0042AD54;
	MILES_ACTIONS[69]->object = &object_0042AD54;
	MILES_ACTIONS[70]->object = &object_0042AD54;
	MILES_ACTIONS[71]->object = &object_0042AD54;
	MILES_ACTIONS[72]->object = &object_0042AD54;
	MILES_ACTIONS[73]->object = &object_0042AD54;
	MILES_ACTIONS[74]->object = &object_0042AD54;
	MILES_ACTIONS[75]->object = &object_0042AD54;
	MILES_ACTIONS[76]->object = &object_0042AD54;
	MILES_ACTIONS[77]->object = &object_0042AD54;
	MILES_ACTIONS[78]->object = &object_0042AD54;
	MILES_ACTIONS[79]->object = &object_0042AD54;
	MILES_ACTIONS[80]->object = &object_0042AD54;
	MILES_ACTIONS[81]->object = &object_0042AD54;
	MILES_ACTIONS[82]->object = &object_0042AD54;
	MILES_ACTIONS[83]->object = &object_0042AD54;
	MILES_ACTIONS[85]->object = &object_0042AD54;
	MILES_ACTIONS[86]->object = &object_0042AD54;
	MILES_ACTIONS[87]->object = &object_0042AD54;
	MILES_ACTIONS[88]->object = &object_0042AD54;
	MILES_ACTIONS[91]->object = &object_0042AD54;
	MILES_ACTIONS[92]->object = &object_0042AD54;
	MILES_ACTIONS[93]->object = &object_0042AD54;
	MILES_ACTIONS[94]->object = &object_0042AD54;
	MILES_ACTIONS[95]->object = &object_0042AD54;
	MILES_ACTIONS[96]->object = &object_0042AD54;
	MILES_ACTIONS[97]->object = &object_0042AD54;
	MILES_ACTIONS[110]->object = &object_0042AD54;
	MILES_ACTIONS[111]->object = &object_0042AD54;
	MILES_ACTIONS[112]->object = &object_0042AD54;
	MILES_ACTIONS[113]->object = &object_0042AD54;
	MILES_MODELS[0] = &attach_0041FDD8;
	MILES_MODELS[1] = &attach_0042CCC8;
	MILES_MODELS[2] = &attach_0042ABBC;
	MILES_MODELS[3] = &attach_00437AAC;
	MILES_MODELS[4] = &attach_0044517C;
	MILES_MODELS[5] = &attach_0041E51C;
	MILES_MODELS[6] = &attach_0041EC64;
	MILES_MODELS[7] = &attach_0042B40C;
	MILES_MODELS[8] = &attach_0042BB54;
	MILES_MODELS[9] = &attach_00445778;
	MILES_MODELS[10] = &attach_00445DA8;
	MILES_MODELS[13] = &attach_004463D8;
	MILES_MODELS[14] = &attach_0046DFE8;
	MILES_MOTIONS[0] = &___MILES_MOTIONS_0;
	WriteData((NJS_OBJECT**)0x7D2186, &object_02707A74); //Jet Anklet model
	WriteJump((void*)0x007C6D80, InitTailsWeldInfo_mod);
	WriteJump((void*)0x007C7560, InitNPCTailsWeldInfo_mod);
	//Material fixes for "Watch out! You're gonna crash! AH!" (Thanks IEA)
	RemoveMaterialColors((NJS_OBJECT*)0x3175528); //Tails' model
	((NJS_OBJECT*)0x317178C)->basicdxmodel->mats[1].attrflags &= ~NJD_FLAG_USE_ALPHA; //Unnecessary alpha in Tails' arm
	((NJS_OBJECT*)0x31708E4)->basicdxmodel->mats[1].attrflags &= ~NJD_FLAG_USE_ALPHA; //Unnecessary alpha in Tails' arm
	((NJS_OBJECT*)0x31793C0)->basicdxmodel->mats[3].attrflags &= ~NJD_FLAG_IGNORE_SPECULAR; //Plane
	((NJS_OBJECT*)0x31793C0)->basicdxmodel->mats[5].attrflags &= ~NJD_FLAG_IGNORE_SPECULAR; //Plane
	((NJS_OBJECT*)0x31793C0)->basicdxmodel->mats[9].attrflags &= ~NJD_FLAG_IGNORE_SPECULAR; //Plane
	//Intro prototype
	WriteData((NJS_OBJECT**)0x03175528, &object_02D75528); //Tails from Sonic story
	WriteData((NJS_OBJECT**)0x03342074, &object_02F3A0D0); //Plane
	WriteData((NJS_OBJECT**)0x03344EAC, &object_02F3A0D0);
	WriteData((NJS_OBJECT**)0x03347734, &object_02F3A0D0);
	WriteData((NJS_OBJECT**)0x0334A8FC, &object_02F3A0D0);
	WriteData((NJS_OBJECT**)0x006F9483, &object_02F3F0E4); //Event head
	WriteData((NJS_OBJECT**)0x0334A910, &object_02F3F0E4);
	WriteData((NJS_OBJECT**)0x0334A924, &object_02F3F0E4);
	WriteData((NJS_OBJECT**)0x0334A938, &object_02F3F0E4);
	WriteData((NJS_MOTION**)0x03375D88, &motion_000395C4); //Event head motions
	WriteData((NJS_MOTION**)0x03375D98, &motion_0002E9C8);
	WriteData((NJS_MOTION**)0x03375DA8, &motion_0002E9C8);
	WriteData((NJS_MOTION**)0x03375DB8, &motion_0002602C);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");
		HMODULE adv03dll = GetModuleHandle(L"ADV03MODELS");
		HMODULE Lantern = GetModuleHandle(L"sadx-dc-lighting");
		NJS_OBJECT** ___MILES_OBJECTS = (NJS_OBJECT**)GetProcAddress(handle, "___MILES_OBJECTS");
		NJS_ACTION** ___MILES_ACTIONS = (NJS_ACTION**)GetProcAddress(handle, "___MILES_ACTIONS");
		NJS_MODEL_SADX** ___MILES_MODELS = (NJS_MODEL_SADX**)GetProcAddress(handle, "___MILES_MODELS");
		NJS_MOTION** ___MILES_MOTIONS = (NJS_MOTION**)GetProcAddress(handle, "___MILES_MOTIONS");
		NJS_OBJECT** ___ADV03_OBJECTS = (NJS_OBJECT**)GetProcAddress(adv03dll, "___ADV03_OBJECTS");
		___ADV03_OBJECTS[31] = &object_00139F24;
		___MILES_MODELS[11]->mats[0].attr_texId = 16;
		___MILES_MODELS[11]->mats[1].attr_texId = 15;
		___MILES_MODELS[11]->mats[2].attr_texId = 17;
		___MILES_MODELS[12]->mats[0].attr_texId = 16;
		___MILES_MODELS[12]->mats[1].attr_texId = 15;
		___MILES_MODELS[12]->mats[2].attr_texId = 17;
		Init_Tails();
		Icons_Init();
		if (Lantern != nullptr)
		{
			material_register(Specular1, LengthOfArray(Specular1), &ForceDiffuse0Specular1);
			material_register(Specular3, LengthOfArray(Specular3), &ForceDiffuse2Specular3);
			material_register(TailsBody, LengthOfArray(TailsBody), &ForceDiffuse0Specular0_Tails);
			material_register(TailsShoes, LengthOfArray(TailsShoes), &ForceDiffuse0Specular1_Tails);
		}
		ReplacePVM("Miles", "Millie");
		ReplacePVM("m_head_1", "ProtoHead");
		ReplacePVM("m_tr_p", "ProtoTornado");
		ReplacePVM("ev_s_t2c_body", "SonicEVProtoTornado");
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}