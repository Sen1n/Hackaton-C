#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Polygone.h"

TVECT setVector(TPoint x, TPoint y){
    TVECT v = {x.x - y.x, x.y-y.y};
    return v;
}



extern int inputPolygone(FILE* fp, Polygone* p){

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

int writePolygones(FILE* fp, Polygone* p, NTYPE n){
    return fwrite(p,sizeof(*p),n,fp);
}