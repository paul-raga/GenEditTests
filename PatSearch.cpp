//
// Created by paul on 2/28/23.
//

#include "PatSearch.h"

int KMP(std::string text, std::string pattern) {

    int position=0;
    int m = text.length();
    int n = pattern.length();

    // se pattern è una stringa vuota
    if (n == 0)
    {
        std::cout << "The pattern occurs with shift 0";

    }

    // se la lunghezza del testo è inferiore a quella del pattern
    if (m < n)
    {
       std:: cout << "Pattern not found";

    }

    // next[i] memorizza l'indice della migliore corrispondenza parziale successiva
    int next[n + 1];

    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < m; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n) {
                std::cout << "The pattern occurs at position: " << i - j + 1 << std::endl;
            }
            position=i-j+1;       }
        else if (j > 0)
        {
            j = next[j];
            i--;    // poiché `i` verrà incrementato nella prossima iterazione
        }
    }
    return position;}
