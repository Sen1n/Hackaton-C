// функція видалення багатокутника за індексом
int deletePolygonesFile(FILE* fp, NTYPE k){
    if (fp == NULL){
        fprintf(stderr, "Error: file %s is NULL \n", fp);
        return -1;
    }
    FILE *temp_fp = fopen("temp.dat", "wb");
    if (temp_fp == NULL){
        fprintf(stderr, "Error: couldn't open the temp.dat \n");
        return -1;
    }
    NTYPE r;
    int index=0, deleted=0;
    while (1) {
        if (fread(&r, sizeof(NTYPE), 1, fp) != 1) break;
        if (index != k) {
            fwrite(&r, sizeof(NTYPE), 1, temp_fp);
        }
        else{
            deleted = 1;
        }
        index++;
    }
    fclose(fp);
    fclose(temp_fp);

    if (deleted) {
        remove("polygones.dat");
        rename("temp.dat", "polygones.dat");
        return TRUE;
    } else {
        remove("temp.dat");
        return FALSE;
    }
}

// виведення багатокутника за індексом k
void showPolygoneFile(FILE* fp, NTYPE k) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file %s is NULL \n", fp);
        return -1;
    }

    int num;
    NTYPE index = 0;
    printf("The polygone at index %u:\n", k);
    while (1) {
        if (fread(&num, sizeof(int), 1, fp) != 1) break;
        if (index == k) {
            printf("%d ", num);
        }
        index++;
        if (index > k) break;
    }
    printf("\n");
}

// виведення всіх багатокутників з файлу
void showPolygonesFile(FILE* fp) {
    if (fp == NULL) {
        fprintf(stderr, "Error: file %s is NULL \n", fp);
        return;
    }

    int num;
    printf("All polygones:\n");
    while (1) {
        if (fread(&num, sizeof(int), 1, fp) != 1) break;
        printf("%d ", num);
    }
    printf("\n");
}

// перевірка чи є такий багатокутник у файлі
int isPresentPolygone(FILE* fp, const Polygone* p) {
    Polygone temp;
    if (fp == NULL){
        printf(stderr, "Error: file %s is NULL \n", fp);
        return -1;
    }
    while (1) {
        if (fread(&temp, sizeof(Polygone), 1, fp) != 1) break;
        int count_side = p->n;
        if (temp.n != count_side) {
            continue;
        }
        int res = 1; 
        for (NTYPE i = 0; i < p->n; i++) {
            TVECT a = {temp.vertice[i].x, temp.vertice[i].y};
            TVECT b = {p->vertice[i].x, p->vertice[i].y};
            if (!isEqual2(a, b)) {
                res = 0;
                break;
            }
        }
        if (res) {
            return 1;
        }
    }
    return -1;
}
