#include "pch.h"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

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

void Init_Tails()
{
	HMODULE hm = GetModuleHandle(L"CHRMODELS_orig");
	NJS_OBJECT** MILES_OBJECTS = (NJS_OBJECT**)GetProcAddress(hm, "___MILES_OBJECTS");

	WriteJump((void*)0x007C6D80, InitTailsWeldInfo_mod);
	WriteJump((void*)0x007C7560, InitNPCTailsWeldInfo_mod);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		Init_Tails();
		ReplacePVM("Miles", "OnnaTails")
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}