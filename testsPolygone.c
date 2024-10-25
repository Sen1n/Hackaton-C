#include "testsPolygone.h"
#include "Polygone.h"

int testVectors(){
    // simple tests for vector functions 
    TVECT v1 = {1.f,2.f};
    TPoint p1 = {0.f,0.f};
    TPoint p2 = {3.f,4.f};
    TVECT v2 = setVector(p1,p2);

    PTYPE r1 = lengthVector(v1);

    if(!isEqual(r1,5)) return FALSE;

    TVECT r2 = addVector(v1,v2);
    TVECT v3 = {3.f,6.f};
    if(!isEqual2(r2,v3)) return FALSE;

    printf("vector tests passed");
    return TRUE;
}

int testInputPolygone(){
    // Test 1 : cOnsole input
    Polygone p0;
    int r1 = inputPolygone(NULL, &p0);
    if(r1!= TRUE) return FALSE;
    freePolygone(&p0);

    // Test 2 : file input
    FILE* fp = fopen("1.txt","rt");
    Polygone p;
    int r2 = inputPolygone(fp, &p);
    if(r2!= TRUE) return FALSE;

    Polygone p2;
    p2.n =3;
    p2.vertice = (TPoint*) calloc(6,sizeof(TPoint));
    p2.vertice[1].x = 0;
    p2.vertice[1].y = 1;
    
    p2.vertice[2].x = 1;
    p2.vertice[2].x = 0;

    if(!isEqualPolygone(&p,&p2)) return FALSE; 

    freePolygone(&p);
    freePolygone(&p2);

    // Test 3 : file input - bad file
    fp = fopen("xxx.txt","rt");
    Polygone p3;
    int r4 = inputPolygone(fp, &p);
    if(r4!= FALSE) return FALSE;

    freePolygone(&p3);
    printf("Input tests passed");

    return TRUE;
}