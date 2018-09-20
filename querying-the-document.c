// https://www.hackerrank.com/challenges/querying-the-document
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return *(*(*(document + n - 1) + m - 1) + k - 1);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return *(*(document + m - 1) + k - 1);
}

char*** kth_paragraph(char**** document, int k) {
    return *(document + k - 1);
}

int count_char(char *text, char c) {
    int count = 0, len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == c) count++;
    }
    return count;
}

char**** get_document(char* text) {
    char ****doc = NULL;
    char p[MAX_PARAGRAPHS][MAX_CHARACTERS];
    int count_paragraph = 0, count_sentence, count_word;
    char *token_p, *saveptr_p;
    char *token_s, *saveptr_s;
    char *token_w, *saveptr_w;
    
    char *buff_s, *buff_p;
    buff_s = (char *) malloc(1005 * sizeof(char));
    buff_p = (char *) malloc(1005 * sizeof(char));
    
    count_paragraph = count_char(text, '\n') + 1;
    // printf("count_paragraph = %d\n", count_paragraph);
    doc = (char ****) calloc(count_paragraph, sizeof(char ***));
    token_p = strtok_r(text, "\n", &saveptr_p);
    for (int i_paragraph = 0; i_paragraph < count_paragraph; i_paragraph++) {
        count_sentence = count_char(token_p, '.');
        // printf("count_sentence = %d\n", count_sentence);
        doc[i_paragraph] = (char ***) calloc(count_sentence, sizeof(char **));
        strcpy(buff_p, token_p);
        token_s = strtok_r(buff_p, ".", &saveptr_s);
        // parsing sentences from a paragraph
        for (int i_sentence = 0; i_sentence < count_sentence; i_sentence++) {
            count_word = count_char(token_s, ' ') + 1;
            // printf("count_word = %d\n", count_word);
            doc[i_paragraph][i_sentence] = (char **) malloc(count_word * sizeof(char *));
            strcpy(buff_s, token_s);
            token_w = strtok_r(buff_s, " ", &saveptr_w);
            // parsing words from a sentence
            for (int x = 0; x < count_word; x++) {
                doc[i_paragraph][i_sentence][x] = (char *) malloc(50 * sizeof(char));
                strcpy(doc[i_paragraph][i_sentence][x], token_w);
                // printf("token_w = %s\n", doc[i_paragraph][i_sentence][x]);
                token_w = strtok_r(NULL, " ", &saveptr_w);
            } // end of parsing words from a sentence
            token_s = strtok_r(NULL, ".", &saveptr_s);
        } // end of parsing sentences from a paragraph
        token_p = strtok_r(NULL, "\n", &saveptr_p);
    }
    return doc;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
