#pragma once

#include "stdio.h"
#include "stdlib.h"

#include "Predicat.h"


// Tasks
extern int inputPolygone(FILE* fp, Polygone* p);

extern int freePolygone(Polygone* p);

// if fp==NULL - print to console
extern int writePolygones(FILE* fp, Polygone* p, NTYPE n);

// delete k-th Polygone, 
// returns FALSE if not deleted
extern int deletePolygonesFile(FILE* fp, NTYPE k);

extern void showPolygoneFile(FILE* fp, NTYPE k);

extern void showPolygonesFile(FILE* fp);

int isEqualPolygone(const Polygone* p1,const Polygone* p2);

extern int isPresentPolygone(FILE* fp, const Polygone* p);

extern PTYPE perimeterPolygone(const Polygone* p);

extern PTYPE areaPolygone(const Polygone* p);

extern int isConvexPolygone(const Polygone* p);

extern int maxPerimeterPolygone(FILE* fp, Polygone* p);

extern int minAreaPolygone(FILE* fp, Polygone* p);

extern NTYPE numberConvexPolygones(FILE* fp);

extern NTYPE conditionPolygones(FILE* fp, predicatPolygone Q, const char* fname);

extern NTYPE pointsPolygones(FILE* fp, TPoint p);

//18




