/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:45:44 by gfredes-          #+#    #+#             */
/*   Updated: 2024/06/27 00:54:20 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/**
 * @brief Checks if the character is an alphabetic character.
 * 
 * @param c: The character to check.
 * @return int: 1 if the character is an alphabetic character, 0 otherwise.
 */ 
int				ft_isalpha(int c);

/**
 * @brief Checks if the character is a digit.
 * 
 * @param c: The character to check.
 * @return int: 1 if the character is a digit, 0 otherwise.
 */
int				ft_isdigit(int c);

/**
 * @brief Checks if the character is an alphanumeric character.
 * 
 * @param c: The character to check.
 * @return int: 1 if the character is an alphanumeric character, 0 otherwise.
 */
int				ft_isalnum(int c);

/**
 * @brief Checks if the character is a ASCII character.
 * 
 * @param c: The character to check.
 * @return int: 1 if the character is a ASCII character, 0 otherwise.
 */
int				ft_isascii(int c);

/**
 * @brief Checks if the character is a printable character.
 * 
 * @param c: The character to check.
 * @return int: 1 if the character is a printable character, 0 otherwise.
 */
int				ft_isprint(int c);

/**
 * @brief Computes the length of the string.
 * 
 * @param c: The string to check.
 * @return int: The length of the string.
 */
size_t			ft_strlen(const char *s);

/**
 * @brief Fills len bytes starting at dest with the value c.
 *
 * @param dest: The pointer to the memory that you want to set.
 * @param c: The value that you want to store in each byte.
 * @param len: The number of bytes that you want to set.
 * @return void*: A pointer to the destination buffer (that is, the value 
 * of dst).
 */
void			*ft_memset(void *dest, int c, size_t len);

/**
 * @brief Fills the first n bytes starting at dest with the value 0.
 *
 * @param dest: An existing object that you want to fill with zeroes.
 * @param len: The number of bytes to fill with zeroes.
 */
void			ft_bzero(void *dest, size_t n);

/**
 * @brief Copies len bytes from sorc to dest.
 *
 * @param dest: The pointer to the memory that you want to copy to.
 * @param sorc: The pointer to the memory that you want to copy from.
 * @param len: The number of bytes that you want to copy.
 * @return void*: A pointer to the destination buffer (that is, the value 
 * of dest).
 */
void			*ft_memcpy(void *dest, const void *sorc, size_t len);

/**
 * @brief Copies len bytes from sorc to dest. Copying of overlapping regions 
 * is handled safely.
 *
 * @param dest: The pointer to the memory that you want to copy to.
 * @param sorc: The pointer to the memory that you want to copy from.
 * @param len: The number of bytes that you want to copy.
 * @return void*: A pointer to the destination buffer (that is, the value of 
 * dest).
 */
void			*ft_memmove(void *dest, const void *sorc, size_t len);

/**
 * @brief Copies up to size − 1 characters from the NUL-terminated string sorc 
 * to dest, NUL-terminating the result.
 *
 * @param dest: A pointer to the destination string.
 * @param sorc: A pointer to the source string.
 * @param size: The size of the destination buffer.
 * @return size_t: The length of sorc.
 */
size_t			ft_strlcpy(char *dest, const char *sorc, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will 
 * append at most size − strlen(dst) − 1 bytes, NUL-terminating the result.
 *
 * @param dest: A pointer to the destination string.
 * @param sorc: A pointer to the source string.
 * @param size:	The size of the destination buffer.
 * @return size_t: The total length of the string they tried to create.
 */
size_t			ft_strlcat(char *dest, const char *sorc, size_t size);

/**
 * @brief Converts the letter c to uppercase.
 *
 * @param c: The character to convert.
 * @return int: The uppercase version of c.
 */
int				ft_toupper(int c);

/**
 * @brief Converts the letter c to lowercase.
 *
 * @param c: The character to convert.
 * @return int: The lowercase version of c.
 */
int				ft_tolower(int c);

/**
 * @brief Locates the first occurrence of c (converted to a char) in the string 
 * pointed to by s. The terminating null character is considered to be part of 
 * the string; therefore if c is `\0', the functions locate the terminating 
 * `\0'.
 *
 * @param s: The string to search.
 * @param c: The character to search for.
 * @return char*: A pointer to the located character, or NULL if the character 
 * does not appear in the string.
 */
char			*ft_strchr(char *s, int c);

/**
 * @brief Locates the last occurrence of c (converted to a char) in the string 
 * pointed to by s. The terminating null character is considered to be part of 
 * the string; therefore if c is `\0', the functions locate the terminating 
 * `\0'.
 *
 * @param s: The string to search.
 * @param c: The character to search for.
 * @return char*: A pointer to the located character, or NULL if the character 
 * does not appear in the string.
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first n bytes of s1 and s2.
 *
 * @param s1: The first string to compare.
 * @param s2: The second string to compare.
 * @param n: The number of bytes to compare.
 * @return int: An integer greater than, equal to, or less than 0, according as 
 * the string s1 is greater than, equal to, or less than the string s2.
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char) in 
 * the first n bytes of the buffer pointed to by s.
 *
 * @param s: The buffer that you want to search.
 * @param c: The character that you want to search for.
 * @param n: The number of bytes that you want to search.
 * @return void*: A pointer to the located character, or NULL if could not be 
 * found.
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of s1 and s2.
 *
 * @param s1: The first buffer to compare.
 * @param s2: The second buffer to compare.
 * @param n: The number of bytes to compare.
 * @return int: An integer greater than, equal to, or less than 0, according as 
 * the buffer s1 is greater than, equal to, or less than the buffer s2.
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string needle in 
 * the null-terminated string haystack, where not more than len characters are 
 * searched. Characters that appear after a `\0' character are not searched.
 *
 * @param haystack: The string that you want to search.
 * @param needle: The string that you want to search for.
 * @param len: The number of bytes that you want to search.
 * @return char*: A pointer to the located string, or NULL if could not be 
 * found.
 */
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

/**
 * @brief Converts the string pointed to by str to an int.
 *
 * @param str: A pointer to the string to parse.
 * @return int: The converted integer.
 */
int				ft_atoi(const char *str);

/**
 * @brief Allocates space from the heap for an array of count objects, each of 
 * size bytes, and initializes them to 0.
 *
 * @param count: The number of array elements to allocate.
 * @param size: The size, in bytes, of one array element.
 * @return void*: A pointer to the start of the allocated memory, or NULL if an 
 * error occurred.
 */
void			*ft_calloc(size_t count, size_t size);

/**
 * @brief Creates a duplicate of the string pointed to by s1, and returns a 
 * pointer to the new copy.
 *
 * @param s1: The string to duplicate.
 * @return char*: A pointer to a copy of the string, or NULL if an error 
 * occurred.
 */
char			*ft_strdup(const char *s1);

/**
 * @brief Reserva (con malloc(3)) y devuelve una substring de la string ’s’. La
 * substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.
 *
 * @param s: La string desde la que crear la substring.
 * @param start: El índice del caracter en ’s’ desde el que empezar la 
 * substring.
 * @param len: La longitud máxima de la substring.
 * @return char*: La substring resultante, o NULL si falla.
 */
char			*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Reserva (con malloc(3)) y devuelve una nueva string, formada por la
 * concatenación de ’s1’ y ’s2’.
 *
 * @param s1: La primera string.
 * @param s2: La string a añadir a ’s1’.
 * @return char*: La nueva string resultante, o NULL si falla.
 */
char			*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Elimina todos los caracteres de la string ’set’ desde el principio y
 * desde el final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’.
 * La string resultante se devuelve con una reserva de malloc(3).
 *
 * @param s1: La string que debe ser recortada.
 * @param set:  Los caracteres a eliminar de la string.
 * @return char*: La string recortada. NULL si falla la reserva de memoria.
 */
char			*ft_strtrim(const char *s1, const char *set);

/**
 * @brief Reserva (utilizando malloc(3)) un array de strings resultante de 
 * separar la string ’s’ en substrings utilizando el caracter ’c’ como 
 * delimitador. El array debe terminar con un puntero NULL.
 *
 * @param s: La string a separar.
 * @param c: El caracter delimitador.
 * @return char**: El array de nuevas strings resulatente de la separación. NULL 
 * si falla la reserva de memoria.
 */
char			**ft_split(const char *s, char c);

/**
 * @brief Utilizando malloc(3), genera una string que represente el valor entero
 * recibido como argumento.
 *
 * @param n: El valor entero a convertir.
 * @return char*: La string que represente el número. NULL si falla la reserva 
 * de memoria.
 */
char			*ft_itoa(int n);

/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando como
 * parámetros el índice de cada carácter dentro de ’s’ y el propio carácter.
 * Genera una nueva string con el resultado del uso sucesivo de ’f’.
 *
 * @param s: La string a iterar.
 * @param f: La función a aplicar sobre cada carácter.
 * @return char*: La string creada tras el correcto uso de ’f’ sobre cada 
 * carácter. NULL si falla la reserva de memoria.
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando como 
 * parámetros el índice de cada carácter dentro de ’s’ y la dirección del 
 * propio carácter, que podrá modificarse si es necesario.
 *
 * @param s: La string a iterar. 
 * @param f: La función a aplicar sobre cada carácter.
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Envía el carácter ’c’ al file descriptor especificado.
 *
 * @param c: El carácter a enviar.
 * @param fd: El file descriptor sobre el que escribir.
 */
void			ft_putchar_fd(char c, int fd);

/**
 * @brief Envía la string ’s’ al file descriptor especificado.
 *
 * @param s: La string a enviar.
 * @param fd: El file descriptor sobre el que escribir.
 */
void			ft_putstr_fd(char *s, int fd);

/**
 * @brief Envía la string ’s’ al file descriptor especificado, seguida de un 
 * salto de línea.
 *
 * @param s: La string a enviar.
 * @param fd: El file descriptor sobre el que escribir.
 */
void			ft_putendl_fd(char *s, int fd);

/**
 * @brief Envía el número ’n’ al file descriptor especificado.
 *
 * @param n: El número que enviar.
 * @param fd: El file descriptor sobre el que escribir.
 */
void			ft_putnbr_fd(int n, int fd);

/**
 * @brief Representa un nodo de una lista enlazada.
 *
 * @param content: La información contenida en el nodo.
 * @param next: La dirección del siguiente nodo, o NULL si el siguiente nodo es 
 * el último.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ 
 * se inicializa con el contenido del parámetro ’content’. La variable ’next’, 
 * con NULL.
 *
 * @param content: El contenido con el que crear el nodo.
 * @return t_list*: El nuevo nodo creado.
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Añade el nodo ’new’ al principio de la lista 'lst'.
 *
 * @param lst: La dirección de un puntero al primer nodo de una lista.
 * @param new: Un puntero al nodo que añadir al principio de la lista.
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Cuenta el número de nodos de una lista.
 *
 * @param lst: El primer nodo de la lista.
 * @return int: La longitud de la lista.
 */
int				ft_lstsize(t_list *lst);

/**
 * @brief Devuelve el último nodo de la lista.
 *
 * @param lst: El primer nodo de la lista.
 * @return t_list*: El último nodo de la lista.
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Añade el nodo ’new’ al final de la lista ’lst’.
 *
 * @param lst: La dirección de un puntero al primer nodo de una lista.
 * @param new: Un puntero a un nodo que añadir a la lista.
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Toma como parámetro un nodo ’lst’ y libera la memoria del contenido 
 * utilizando la función ’del’ dada como parámetro, además de liberar el nodo. 
 * La memoria de ’next’ no debe liberarse.
 *
 * @param lst: El nodo a liberar.
 * @param del: Un puntero a la función utilizada para eliminar el contenido del 
 * nodo.
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese 
 * nodo, utilizando la función ’del’ y free(3). Al final, el puntero a la lista 
 * debe ser NULL.
 *
 * @param lst: La dirección de un puntero a un nodo.
 * @param del: Un puntero a la función utilizada para eliminar el contenido de 
 * un nodo.
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada 
 * nodo.
 *
 * @param lst: Un puntero al primer nodo de la lista.
 * @param f: Un puntero a la función que utilizará cada nodo.
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada
 * nodo. Crea una nueva lista resultante de la aplicación correcta y sucesiva
 * de la función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar
 * el contenido de un nodo, si hace falta.
 *
 * @param lst: Un puntero a un nodo.
 * @param f: la dirección de un puntero a una función usada en la iteración de
 * cada elemento de la lista.
 * @param del: un puntero a función utilizado para eliminar el contenido de un
 * nodo, si es necesario.
 * @return t_list*: La nueva lista. NULL si falla la reserva de memoria.
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * @brief Devuelve la línea leída de un file descriptor
 *
 * @param fd: File descriptor del que leer
 * @return Si todo va bien: la línea leída. 
 * En caso de fallo o si la lectura termina: NULL
 */
char			*get_next_line(int fd);

#endif
