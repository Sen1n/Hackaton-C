#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Polygone.h"

TVECT setVector(TPoint x, TPoint y){
    TVECT v = {x.x - y.x, x.y-y.y};
    return v;
}

// (a)
int inputPolygone(FILE* fp, Polygone* p){

    NTYPE n;
    
    if(fp)
        fscanf(fp,"%u",&n);    
    else{
        printf("N=");
        fscanf(stdin,"%u",&n);
    }

    if(n<=2) return FALSE;
    
    p->n = n;
    p->vertice = (TPoint*) malloc(n * 2 * sizeof(TPoint));
    int scan_res = 0;
    for(NTYPE i=0;i<n;i++){
        if(!fp){
            printf("x,y=");
            scan_res = fscanf(stdin,"%f %f",&p->vertice[i].x, &p->vertice[i].y);
        }
        else{
            scan_res = fscanf(fp,"%f %f",&p->vertice[i].x, &p->vertice[i].y);
        }
        if(scan_res!=2) return FALSE;
    }

    return TRUE;
}



int freePolygone(Polygone* p) {
    if (p->vertice != NULL) {
        free(p->vertice);
        p->vertice = NULL;
    }
    return 0;
}

// (b)
int writePolygones(FILE* fp, Polygone* p, NTYPE n) {
    if (fp == NULL) return 0;

    fwrite(&n, sizeof(NTYPE), 1, fp);

    for (NTYPE i = 0; i < n; i++) {
        fwrite(&p[i].n, sizeof(NTYPE), 1, fp);
        fwrite(p[i].vertice, sizeof(TPoint), p[i].n, fp);
    }

    return 1;
}
// Векторний добуток, який можна замінити векторним добутком Роми.
float crossProduct(TPoint p1, TPoint p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

// Знаходимо опуклий багатокутник.
int isConvexPolygone(const Polygone* p) {

    if (p->n < 3) {
        return FALSE;
    }

    bool direction = false;
    for (NTYPE i = 0; i < p->n; i++) {
        TPoint v1 = { p->vertice[(i + 1) % p->n].x - p->vertice[i].x,
                      p->vertice[(i + 1) % p->n].y - p->vertice[i].y };
        TPoint v2 = { p->vertice[(i + 2) % p->n].x - p->vertice[(i + 1) % p->n].x,
                      p->vertice[(i + 2) % p->n].y - p->vertice[(i + 1) % p->n].y };

        float crossProd = crossProduct(v1, v2);

        if (i == 0) {
            direction = (crossProd > 0);
        }
        else {
            if ((crossProd > 0) != direction) {
                return FALSE;
            }
        }
    }

    return TRUE;
}

// Знаходимо кількість опуклих багатокутників. 

NTYPE numberConvexPolygones(FILE* fp) {

    if (fp == NULL) {
        return 0;
    }

    Polygone current;
    NTYPE count = 0;

    rewind(fp);

    while (fread(&current, sizeof(Polynome), 1, fp) == 1) {
        if (isConvexPolygone(&current)) {
            count++;
        }
    }
    return count;
}