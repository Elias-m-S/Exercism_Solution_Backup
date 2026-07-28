#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static char complement(char nucleotide){
    switch (nucleotide){
            case 'G': return 'C';
            case 'C': return 'G';
            case 'T': return 'A';
            case 'A': return 'U';
}
    assert(0);
}

char *to_rna(const char *dna){
size_t rna_size = strlen(dna);
size_t rna_in_heap = rna_size +1;
char *rna = malloc(rna_in_heap);
if (rna == NULL){
    return NULL;
}
for(size_t i=0; i < rna_size ; i++){
    rna[i] = complement(dna[i]);
}
rna[rna_size] = '\0';
return rna;
}

     