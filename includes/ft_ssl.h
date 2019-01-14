//
// Created by Mykola Ponomarov on 02.01.2019.
//

#ifndef FT_SSL_H
#define FT_SSL_H

# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include "../libft/header/get_next_line.h"
# include <fcntl.h>

#define COMANDS 2 // 5
# define FUNCTIONS 4 // 10

# define P_FLAG 1
# define S_FLAG 2
# define R_FLAG 4
# define Q_FLAG 8

# define A md5_hash[0]
# define B md5_hash[1]
# define C md5_hash[2]
# define D md5_hash[3]
# define MD5T md5_table

static char			        	*comands[COMANDS] = {
        "md5", "sha256"/*, "sha512", "sha224", "sha384"*/
};

unsigned int				md5_hash[4];

static const unsigned int	md5_table[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

unsigned int				sha256_hash[8];

static const unsigned int	sha256_table[64] = {
        0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
        0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
        0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
        0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
        0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
        0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
        0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
        0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
        0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
        0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
        0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
        0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
        0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
        0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
        0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
        0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

typedef struct			s_ssl
{
    int					fd;
    char				*str;
    char				*line;
    char			    comand;
    unsigned int		input_int[16];
    unsigned char		input_char[64];
    unsigned long int	size;
    char                data_f;
    char                usage_f;
    char                flags;
}						t_ssl;

t_ssl                   *init_struct(void);
void                    set_hashes(void);

void		            print_usage(void);
void	            	print_error(char *str);
void                    print_argument(t_ssl *ssl);
void                    print_option(char c, t_ssl *ssl);
void                    print_error_fd(char *file, t_ssl *ssl);
void                    print_error_file(char *file, t_ssl *ssl);

void                    read_from_argv(t_ssl *ssl, char **argv);
void                    read_from_console(t_ssl *ssl);
void	                use_comand(t_ssl *ssl, char str);

void				    parsing_flags(t_ssl *ssl, char **str, int *i);
void		            check_comand(t_ssl *ssl, char *str);
void	                check_file(t_ssl *ssl, char *file);
void				    check_flags(t_ssl *ssl, char **argv, int *i);

void                    fd_md5(t_ssl *ssl);
void                    str_md5(t_ssl *ssl);
void                    fd_sha256(t_ssl *ssl);
void                    str_sha256(t_ssl *ssl);
//void                    fd_sha512(t_ssl *ssl);
//void                    str_sha512(t_ssl *ssl);
//void                    fd_sha224(t_ssl *ssl);
//void                    str_sha224(t_ssl *ssl);
//void                    fd_sha384(t_ssl *ssl);
//void                    str_sha384(t_ssl *ssl);

void				    md5_wiki(t_ssl *ssl);
void	                sha256_wiki(t_ssl *ssl);

void	                print_md5(t_ssl *ssl);
void	                print_sha256(t_ssl *ssl);

unsigned int            reverse_bytes(const unsigned int x, const char bytes);
char			        *i_base(uintmax_t n, short int base);
void				    read_again(t_ssl *ssl);
void		            swipe(unsigned long int *size);

static void				    (*ssl_func[FUNCTIONS])(t_ssl *ssl) = {
        fd_md5, str_md5, fd_sha256, str_sha256/*, fd_sha512, str_sha512, fd_sha224, str_sha224, fd_sha384, str_sha384*/
};

#endif
