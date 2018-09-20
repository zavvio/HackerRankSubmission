// https://www.hackerrank.com/challenges/structuring-the-document
int count_char(char *text, char c) {
    int count = 0, len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == c) count++;
    }
    return count;
}

struct document get_document(char* text) {
    struct document doc;
    int count_paragraph = 0, count_sentence, count_word;
    char *token_p, *saveptr_p;
    char *token_s, *saveptr_s;
    char *token_w, *saveptr_w;
    
    char *buff_s, *buff_p;
    buff_s = (char *) malloc(1005 * sizeof(char));
    buff_p = (char *) malloc(1005 * sizeof(char));
    
    count_paragraph = count_char(text, '\n') + 1;
    // printf("count_paragraph = %d\n", count_paragraph);
    doc.data = (struct paragraph*) calloc(count_paragraph, sizeof(struct paragraph));
    doc.paragraph_count = count_paragraph;
    token_p = strtok_r(text, "\n", &saveptr_p);
    for (int i_paragraph = 0; i_paragraph < count_paragraph; i_paragraph++) {
        count_sentence = count_char(token_p, '.');
        // printf("count_sentence = %d\n", count_sentence);
        doc.data[i_paragraph].data = (struct sentence*) calloc(count_sentence, sizeof(struct sentence));
        doc.data[i_paragraph].sentence_count = count_sentence;
        strcpy(buff_p, token_p);
        token_s = strtok_r(buff_p, ".", &saveptr_s);
        // parsing sentences from a paragraph
        for (int i_sentence = 0; i_sentence < count_sentence; i_sentence++) {
            count_word = count_char(token_s, ' ') + 1;
            // printf("count_word = %d\n", count_word);
            doc.data[i_paragraph].data[i_sentence].data = (struct word*) malloc(count_word * sizeof(struct word));
            doc.data[i_paragraph].data[i_sentence].word_count = count_word;
            strcpy(buff_s, token_s);
            token_w = strtok_r(buff_s, " ", &saveptr_w);
            // parsing words from a sentence
            for (int x = 0; x < count_word; x++) {
                doc.data[i_paragraph].data[i_sentence].data[x].data = (char *) malloc(50 * sizeof(char));
                strcpy(doc.data[i_paragraph].data[i_sentence].data[x].data, token_w);
                // printf("token_w = %s\n", doc.data[i_paragraph].data[i_sentence].data[x].data);
                token_w = strtok_r(NULL, " ", &saveptr_w);
            } // end of parsing words from a sentence
            token_s = strtok_r(NULL, ".", &saveptr_s);
        } // end of parsing sentences from a paragraph
        token_p = strtok_r(NULL, "\n", &saveptr_p);
    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}
