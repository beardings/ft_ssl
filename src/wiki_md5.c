//
// Created by Mykola Ponomarov on 2019-01-12.
//

#include "../includes/ft_ssl.h"

#define FIRST(x, y, z) ((x & y) | (~x & z))
#define SECOND(x, y, z) ((x & z) | (y & ~z))
#define THIRD(x, y, z) (x ^ y ^ z)
#define FOURTH(x, y, z) (y ^ (x | ~z))

#define SHIFT(x, k) ((x << k) | (x >> (32 - k)))

void	first_step(t_ssl *ssl)
{
    A = B + SHIFT((A + FIRST(B, C, D) + ssl->input_int[0] + MD5T[0]), 7);
    D = A + SHIFT((D + FIRST(A, B, C) + ssl->input_int[1] + MD5T[1]), 12);
    C = D + SHIFT((C + FIRST(D, A, B) + ssl->input_int[2] + MD5T[2]), 17);
    B = C + SHIFT((B + FIRST(C, D, A) + ssl->input_int[3] + MD5T[3]), 22);
    A = B + SHIFT((A + FIRST(B, C, D) + ssl->input_int[4] + MD5T[4]), 7);
    D = A + SHIFT((D + FIRST(A, B, C) + ssl->input_int[5] + MD5T[5]), 12);
    C = D + SHIFT((C + FIRST(D, A, B) + ssl->input_int[6] + MD5T[6]), 17);
    B = C + SHIFT((B + FIRST(C, D, A) + ssl->input_int[7] + MD5T[7]), 22);
    A = B + SHIFT((A + FIRST(B, C, D) + ssl->input_int[8] + MD5T[8]), 7);
    D = A + SHIFT((D + FIRST(A, B, C) + ssl->input_int[9] + MD5T[9]), 12);
    C = D + SHIFT((C + FIRST(D, A, B) + ssl->input_int[10] + MD5T[10]), 17);
    B = C + SHIFT((B + FIRST(C, D, A) + ssl->input_int[11] + MD5T[11]), 22);
    A = B + SHIFT((A + FIRST(B, C, D) + ssl->input_int[12] + MD5T[12]), 7);
    D = A + SHIFT((D + FIRST(A, B, C) + ssl->input_int[13] + MD5T[13]), 12);
    C = D + SHIFT((C + FIRST(D, A, B) + ssl->input_int[14] + MD5T[14]), 17);
    B = C + SHIFT((B + FIRST(C, D, A) + ssl->input_int[15] + MD5T[15]), 22);
}

void	second_step(t_ssl *ssl)
{
    A = B + SHIFT((A + SECOND(B, C, D) + ssl->input_int[1] + MD5T[16]), 5);
    D = A + SHIFT((D + SECOND(A, B, C) + ssl->input_int[6] + MD5T[17]), 9);
    C = D + SHIFT((C + SECOND(D, A, B) + ssl->input_int[11] + MD5T[18]), 14);
    B = C + SHIFT((B + SECOND(C, D, A) + ssl->input_int[0] + MD5T[19]), 20);
    A = B + SHIFT((A + SECOND(B, C, D) + ssl->input_int[5] + MD5T[20]), 5);
    D = A + SHIFT((D + SECOND(A, B, C) + ssl->input_int[10] + MD5T[21]), 9);
    C = D + SHIFT((C + SECOND(D, A, B) + ssl->input_int[15] + MD5T[22]), 14);
    B = C + SHIFT((B + SECOND(C, D, A) + ssl->input_int[4] + MD5T[23]), 20);
    A = B + SHIFT((A + SECOND(B, C, D) + ssl->input_int[9] + MD5T[24]), 5);
    D = A + SHIFT((D + SECOND(A, B, C) + ssl->input_int[14] + MD5T[25]), 9);
    C = D + SHIFT((C + SECOND(D, A, B) + ssl->input_int[3] + MD5T[26]), 14);
    B = C + SHIFT((B + SECOND(C, D, A) + ssl->input_int[8] + MD5T[27]), 20);
    A = B + SHIFT((A + SECOND(B, C, D) + ssl->input_int[13] + MD5T[28]), 5);
    D = A + SHIFT((D + SECOND(A, B, C) + ssl->input_int[2] + MD5T[29]), 9);
    C = D + SHIFT((C + SECOND(D, A, B) + ssl->input_int[7] + MD5T[30]), 14);
    B = C + SHIFT((B + SECOND(C, D, A) + ssl->input_int[12] + MD5T[31]), 20);
}

void	third_step(t_ssl *ssl)
{
    A = B + SHIFT((A + THIRD(B, C, D) + ssl->input_int[5] + MD5T[32]), 4);
    D = A + SHIFT((D + THIRD(A, B, C) + ssl->input_int[8] + MD5T[33]), 11);
    C = D + SHIFT((C + THIRD(D, A, B) + ssl->input_int[11] + MD5T[34]), 16);
    B = C + SHIFT((B + THIRD(C, D, A) + ssl->input_int[14] + MD5T[35]), 23);
    A = B + SHIFT((A + THIRD(B, C, D) + ssl->input_int[1] + MD5T[36]), 4);
    D = A + SHIFT((D + THIRD(A, B, C) + ssl->input_int[4] + MD5T[37]), 11);
    C = D + SHIFT((C + THIRD(D, A, B) + ssl->input_int[7] + MD5T[38]), 16);
    B = C + SHIFT((B + THIRD(C, D, A) + ssl->input_int[10] + MD5T[39]), 23);
    A = B + SHIFT((A + THIRD(B, C, D) + ssl->input_int[13] + MD5T[40]), 4);
    D = A + SHIFT((D + THIRD(A, B, C) + ssl->input_int[0] + MD5T[41]), 11);
    C = D + SHIFT((C + THIRD(D, A, B) + ssl->input_int[3] + MD5T[42]), 16);
    B = C + SHIFT((B + THIRD(C, D, A) + ssl->input_int[6] + MD5T[43]), 23);
    A = B + SHIFT((A + THIRD(B, C, D) + ssl->input_int[9] + MD5T[44]), 4);
    D = A + SHIFT((D + THIRD(A, B, C) + ssl->input_int[12] + MD5T[45]), 11);
    C = D + SHIFT((C + THIRD(D, A, B) + ssl->input_int[15] + MD5T[46]), 16);
    B = C + SHIFT((B + THIRD(C, D, A) + ssl->input_int[2] + MD5T[47]), 23);
}

void	fourth_step(t_ssl *ssl)
{
    A = B + SHIFT((A + FOURTH(B, C, D) + ssl->input_int[0] + MD5T[48]), 6);
    D = A + SHIFT((D + FOURTH(A, B, C) + ssl->input_int[7] + MD5T[49]), 10);
    C = D + SHIFT((C + FOURTH(D, A, B) + ssl->input_int[14] + MD5T[50]), 15);
    B = C + SHIFT((B + FOURTH(C, D, A) + ssl->input_int[5] + MD5T[51]), 21);
    A = B + SHIFT((A + FOURTH(B, C, D) + ssl->input_int[12] + MD5T[52]), 6);
    D = A + SHIFT((D + FOURTH(A, B, C) + ssl->input_int[3] + MD5T[53]), 10);
    C = D + SHIFT((C + FOURTH(D, A, B) + ssl->input_int[10] + MD5T[54]), 15);
    B = C + SHIFT((B + FOURTH(C, D, A) + ssl->input_int[1] + MD5T[55]), 21);
    A = B + SHIFT((A + FOURTH(B, C, D) + ssl->input_int[8] + MD5T[56]), 6);
    D = A + SHIFT((D + FOURTH(A, B, C) + ssl->input_int[15] + MD5T[57]), 10);
    C = D + SHIFT((C + FOURTH(D, A, B) + ssl->input_int[6] + MD5T[58]), 15);
    B = C + SHIFT((B + FOURTH(C, D, A) + ssl->input_int[13] + MD5T[59]), 21);
    A = B + SHIFT((A + FOURTH(B, C, D) + ssl->input_int[4] + MD5T[60]), 6);
    D = A + SHIFT((D + FOURTH(A, B, C) + ssl->input_int[11] + MD5T[61]), 10);
    C = D + SHIFT((C + FOURTH(D, A, B) + ssl->input_int[2] + MD5T[62]), 15);
    B = C + SHIFT((B + FOURTH(C, D, A) + ssl->input_int[9] + MD5T[63]), 21);
}

void				md5_wiki(t_ssl *ssl)
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;

    a = A;
    b = B;
    c = C;
    d = D;
    first_step(ssl);
    second_step(ssl);
    third_step(ssl);
    fourth_step(ssl);
    A = a + A;
    B = b + B;
    C = c + C;
    D = d + D;
}