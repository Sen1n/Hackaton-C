#pragma once

typedef unsigned NTYPE;
typedef float PTYPE;

#define TRUE  1
#define FALSE 0


typedef struct TPoint{
    PTYPE x;
    PTYPE y;
}TPoint;

typedef struct Polygone{
   NTYPE n; // power of Polynome
   TPoint *vertice;     
}Polygone;


// Vector operations
typedef struct TVECT{
    PTYPE x;
    PTYPE y;
}TVECT;

extern TVECT setVector(TPoint x, TPoint y);

extern PTYPE lengthVector(TVECT v);

extern TVECT addVector(TVECT v1, TVECT v2);

extern TVECT subVector(TVECT v1, TVECT v2);

extern PTYPE scalarMultVector(TVECT v1, TVECT v2);

extern TVECT vectorMultVector(TVECT v1, TVECT v2);

extern TVECT multVector(PTYPE a, TVECT x);


extern int isEqual(PTYPE a, PTYPE b);
extern int isEqual2(TVECT a, TVECT b);
